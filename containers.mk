CONTAINERSROOT=$(SDIR)/containers
CONTAINERS_OFILES=$(subst $(CONTAINERSROOT),$(ODIR),$(patsubst %.c,%.o,$(wildcard $(CONTAINERSROOT)/*.c)))

compileContainers: outFolder $(CONTAINERS_OFILES)

$(ODIR)/%.o: $(CONTAINERSROOT)/%.c $(CONTAINERSROOT)/%.h
	$(CC) -c $< -o $@ $(CFLAGS) $(IDIRFLAG)
	
checkContainers:
	$(CC) -fsyntax-only $(wildcard $(CONTAINERSROOT)/*.c) $(IDIRFLAG)
