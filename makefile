CC=clang
SDIR=src
ODIR=bin
IDIRFLAG=-I./$(SDIR)

include *.mk

compile: outFolder compileNetwork

outFolder:
	mkdir -p $(ODIR)

clean:
	rm -rf $(ODIR)
