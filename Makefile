files:=$(wildcard *.bc)
$(info $(files))
all: $(files:.bc=.loopinfo)

%.loopinfo: %.bc
	LoopFinder/LoopFind/findLoops.sh $< 2> $@

clean:
	rm -f $(files:.bc=.loopinfo)
