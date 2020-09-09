CLANG=clang
STR_CLANG=/opt/llvm34/bin/clang-3.4
KLEE_FLAGS:=-search=dfs -use-merge -exit-on-error-type=Assert -libc=uclibc -only-output-states-covering-new -rewrite-equalities=false  -watchdog
STR_KLEE=/artefact/str.KLEE/bin/klee-str

TIME=20
PROGRAM_SIZE=7
EXAMPLE_SIZE=4
GADGETS=M R C P N B Z X E S I F

DEFINES:=$(if $(GADGETS), -DCUSTOM_VOCAB $(foreach CHAR,$(GADGETS),-D$(CHAR)),)
DEFINES+=-DPROGRAM_MAX_SIZE=$(PROGRAM_SIZE) 
DEFINES+=-DEXAMPLE_MAX_SIZE=$(EXAMPLE_SIZE)
#$(info $(DEFINES))


%.bc:  %.c
	$(CLANG) -Ibasic/ -c -emit-llvm -g -D MAIN_FUNC -o  $@ $<

%.synth.bc:  %.c
	$(CLANG) -Isynthesize/ -c -emit-llvm -g -D MAIN_FUNC $(DEFINES) -o $@ $<

%.verify.bc:  %.c
	$(CLANG) -Iverify/ -c -emit-llvm -g -D MAIN_FUNC $(DEFINES)  -o $@ $<

compare.bc: compare/main.c synthesize/interpreter.c
	$(CLANG) -c -emit-llvm -g $(DEFINES) -o $@ $<

compare.str.bc: compare/main.c synthesize/interpreter.c
	$(STR_CLANG) -c -emit-llvm -g $(DEFINES) -o $@ $<

%.nostr: compare.bc %.prog
	klee -libc=uclibc -search=dfs -solver-backend=z3 -only-output-states-covering-new -max-time=$(TIME) -output-dir=$@ $< "$(word 2,$^)" 

%.str: compare.str.bc %.prog
	$(STR_KLEE) -search=dfs -solver-backend=z3 -no-output -only-output-states-covering-new -max-time=$(TIME) -output-dir=$@ $< "$(word 2,$^)" 

%.compare: %.nostr %.str
	klee-stats --table-format=plain $<| awk '{print $$1 " " $$3}' | tail -n-1 > $@
	$(STR_KLEE)-stats --table-format=plain $(word 2,$^) | awk '{print $$1 " " $$3}' | tail -n-1 >> $@
	grep 'external: str' $(word 2,$^)/warnings.txt && echo "Error!" >> $@ || true

%.compare.clean: 
	rm -rf $(@:.clean=) $(@:.compare.clean=.str) $(@:.compare.clean=.nostr) compare.bc



%.run: %.bc	
	rm -rf $@
	klee -libc=uclibc -max-time=20 -output-dir=$@ $<

%.synth: %.synth.bc	
	rm -rf $@
	klee $(KLEE_FLAGS) -max-time=$(TIME) -write-paths -output-dir=$@ $< | tee $@.output 
	mv $@.output $@/program

%.prog: %.synth
	cat  $</program | tr '\n' '\032' | grep -a 'FOUND the program' |	sed 's/.*FOUND the program: \(.\+\)END!.*/\1/g' | tr '\032' '\n' > $@ 
	test -s $@ || rm -f $@


PROG_PREF:=

%.verify: %.verify.bc	$(PROG_PREF)%.prog
	rm -rf $@
	klee $(KLEE_FLAGS) -max-time=$(TIME) -output-dir=$@ $< "$(word 2,$^)" 
	test -e $@/test*.assert.err && touch $@.err || true
	! test -e $@/test*.assert.err


loops:=$(filter-out main.c,$(wildcard *.c))

synth: $(loops:.c=.prog)

progs:=$(wildcard $(PROG_PREF)*.prog)
ver: $(notdir $(progs:.prog=.verify))
comp: $(notdir $(progs:.prog=.compare))
comp_clean: $(notdir $(progs:.prog=.compare.clean))

all: $(loops:.c=.run)

PERF=/data/Random/perf/linux-4.4.0/tools/perf/perf
%.profile: %.synth.bc
	rm -fr $@
	$(PERF) record -F 99 -a -g -- klee $(KLEE_FLAGS) -max-time=$(TIME) -write-paths -output-dir=$@ $<

%.perf: %.profile
	$(PERF) script --pid $(shell grep PID: $</info | cut -f2 -d ' ') > out.perf
	/data/Random/FlameGraph/stackcollapse-perf.pl out.perf > out.folded
	cat out.folded | /data/Random/FlameGraph/flamegraph.pl > klee.svg

PROG_COMPILER:=/artefact/loops/gdLoops/compile.py

%.prog.c: %.prog $(PROG_COMPILER)
	$(PROG_COMPILER) $< > $@

%.native.o: %.c %.prog.c
	gcc -O3 -InativeBenchmark/ -D MAIN_FUNC -o  $@ $^

%.native.run: %.native.o
	./$< > $@

native_comp: $(notdir $(progs:.prog=.native.run))
