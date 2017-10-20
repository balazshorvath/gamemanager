CC=clang
SDIR=src
ODIR=bin
IDIRFLAG=-I./$(SDIR)

include *.mk

compile: outFolder compileNetwork compileMath

check: checkNetwork checkMath

outFolder:
	mkdir -p $(ODIR)

clean:
	rm -rf $(ODIR)
