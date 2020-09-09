LOOPS_FOLDER:=../gdLoops
PROGS:=$(wildcard $(LOOPS_FOLDER)/*.c)
TIME=120
PROG_SIZE=5
EXP_NAME=exp-$(shell echo $(GADGETS) | tr -d ' ')-$(TIME)s-$(PROG_SIZE)

all: $(EXP_NAME)

#Transforming interpreter is fine even for optimization as it gets removed by the preprocessor anyway

$(EXP_NAME): $(addprefix $(LOOPS_FOLDER)/, Makefile verify synthesize genResults.sh showFileAndProg.sh)
	rm -rf $@
	mkdir -p $@
	cp $(PROGS) $@
	cp -r $^ $@
	mv $(EXP_NAME)/synthesize/interpreter.c $(EXP_NAME)/synthesize/interpreter.c.backup
	./transform.py < $(EXP_NAME)/synthesize/interpreter.c.backup > $(EXP_NAME)/synthesize/interpreter.c
	$(MAKE) -C $@ synth TIME=$(TIME) PROGRAM_SIZE=$(PROG_SIZE) GADGETS='$(GADGETS)'  -j4
