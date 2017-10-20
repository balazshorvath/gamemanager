NEWTORKROOT=$(SDIR)/network
NETWORK_OFILES=$(subst $(NEWTORKROOT),$(ODIR),$(patsubst %.c,%.o,$(wildcard $(NEWTORKROOT)/*.c)))

compileNetwork: outFolder $(NETWORK_OFILES)

$(ODIR)/%.o: $(NEWTORKROOT)/%.c $(NEWTORKROOT)/%.h $(NEWTORKROOT)/networktypes.h
	$(CC) -c $< -o $@ $(CFLAGS) $(IDIRFLAG)
	
checkNetwork:
	$(CC) -fsyntax-only $(wildcard $(NEWTORKROOT)/*.c) $(IDIRFLAG)
