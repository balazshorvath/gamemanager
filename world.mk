WORLDROOT=$(SDIR)/world
WORLD_OFILES=$(subst $(WORLDROOT),$(ODIR),$(patsubst %.c,%.o,$(wildcard $(WORLDROOT)/*.c)))

compileWorld: outFolder $(WORLD_OFILES)

$(ODIR)/%.o: $(WORLDROOT)/%.c $(WORLDROOT)/%.h
	$(CC) -c $< -o $@ $(CFLAGS) $(IDIRFLAG)
	
checkWorld:
	$(CC) -fsyntax-only $(wildcard $(WORLDROOT)/*.c) $(IDIRFLAG)
