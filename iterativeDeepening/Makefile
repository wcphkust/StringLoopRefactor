LOOPS_FOLDER:=../gdLoops
SYNTHESIZED_LOOPS:=$(wildcard $(LOOPS_FOLDER)/*.prog)
SYNTHESIZED_PROGS=$(notdir $(SYNTHESIZED_LOOPS))
SYNTH_PROGS:=$(SYNTHESIZED_PROGS:.prog=.c)
EXP_NAME=1h.exp
TIME=3600

$(EXP_NAME)/%.dir: $(addprefix $(LOOPS_FOLDER)/, Makefile verify synthesize genResults.sh showFileAndProg.sh)
	rm -rf $@
	mkdir -p $@
	cp $(addprefix $(LOOPS_FOLDER)/, $(SYNTH_PROGS)) $@
	cp -r $^ $@

$(EXP_NAME)/%.dir/synth: $(EXP_NAME)/%.dir
	$(MAKE) -C $(dir $@) synth TIME=$(TIME) PROGRAM_SIZE=$(notdir $(basename $<)) -j2
	touch $@

do: $(addprefix $(EXP_NAME)/,$(addsuffix .dir/synth,$(shell seq 1 10)))

%.dat: %.exp
	cd $< ; ../plotSynth.sh | sort -n > ../$@

EXPERIMENTS=$(wildcard *.exp)
plot: $(EXPERIMENTS:.exp=.dat)
	cp $^ ~/paper/19-string-loops/graphs	
	
clean:
	rm -rf *.dir
