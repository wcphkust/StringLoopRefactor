LOOPS_FOLDER:=../gdLoops
GP_FOLDER:=../gadgets
ITERATIVE_DEEPNING_FOLDER:=../iterativeDeepening
PROGS:=$(wildcard $(LOOPS_FOLDER)/*.c)
IMPORTANT_FILES:=Makefile verify synthesize genResults.sh showFileAndProg.sh compare nativeBenchmark
IMPORTANT_FILES+=uploadCexp.sh uploadNativeRuns.sh timingResults.sh printTodo.sh runCompareExp.sh

PARA:=

all: .baseExperiment .verifyExperiment .strCompareExperiment .nativeCompareExperiment .iterativeDeepening .GPoptimize .GPexplore


%.gdLoops: $(addprefix $(LOOPS_FOLDER)/, $(IMPORTANT_FILES)) 
	rm -rf $@
	mkdir -p $@
	cp $(PROGS) $@
	cp -r $^ $@

.baseExperiment: baseExperiment.gdLoops
	make -C $< TIME=7200 PROGRAM_SIZE=10 EXAMPLE_SIZE=4 GADGETS='M R C P N B Z X E S I F' synth $(PARA)
	touch $@

.verifyExperiment: baseExperiment.gdLoops .baseExperiment
	make -C $< TIME=7200 PROGRAM_SIZE=10 EXAMPLE_SIZE=7 GADGETS='M R C P N B Z X E S I F' ver $(PARA)
	touch $@

.strCompareExperiment: baseExperiment.gdLoops .baseExperiment
	cd $< ; ./runCompareExp.sh
	touch $@

.nativeCompareExperiment: baseExperiment.gdLoops .baseExperiment
	make -C $< native_comp $(PARA)
	touch $@

#================================Iterative Deepening====================================

iterativeDeepening: $(addprefix $(ITERATIVE_DEEPNING_FOLDER)/, Makefile plotSynth.sh runAll.sh)
	rm -rf $@
	mkdir -p $@
	cp $^ $@

.iterativeDeepening: iterativeDeepening .baseExperiment
	make -C $< do EXP_NAME=30s.exp TIME=30 LOOPS_FOLDER=../baseExperiment.gdLoops
	make -C $< do EXP_NAME=3min.exp TIME=180 LOOPS_FOLDER=../baseExperiment.gdLoops
	make -C $< do EXP_NAME=10min.exp TIME=600 LOOPS_FOLDER=../baseExperiment.gdLoops
	make -C $< do EXP_NAME=1h.exp TIME=3600 LOOPS_FOLDER=../baseExperiment.gdLoops
	touch $@

#================================GP optimization====================================

GP.%: $(addprefix $(GP_FOLDER)/, Makefile optimize.py printResult.sh transform.py visualize.py)
	rm -rf $@
	mkdir -p $@
	cp $^ $@
	sed -i '/^LOOPS_FOLDER:=/c\LOOPS_FOLDER:=../baseExperiment.gdLoops' $@/Makefile

.GPoptimize: GP.optimize
	cd $< ; DOMAIN_MAX=2 ACQUISITION=EI ./optimize.py
	touch $@


.GPexplore: GP.explore
	cd $< ; DOMAIN_MAX=4 ACQUISITION=LCB ./optimize.py
	touch $@


#================================Clean=====================================

.PHONY: clean all
clean:
	rm -rf .baseExperiment baseExperiment.gdLoops	
	rm -rf .verifyExperiment .strCompareExperiment .nativeCompareExperiment
	
