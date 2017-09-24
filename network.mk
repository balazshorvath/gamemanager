NEWTORKROOT=$(SDIR)/network

compileNetwork: outFolder $(ODIR)/tcp.o
	cd $(NEWTORKROOT)
	mv *.o $(ODIR)
	cd -

$(ODIR)/tcp.o: $(NEWTORKROOT)/tcp.c $(NEWTORKROOT)/tcp.h $(NEWTORKROOT)/networktypes.h
	$(CC) -c $< -I./$(SDIR)

checkNetwork:
	$(CC) -fsyntax-only $(wildcard $(NEWTORKROOT)/*.c) $(IDIRFLAG)
