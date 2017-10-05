MATHROOT=$(SDIR)/math
MATH_OFILES=$(subst $(MATHROOT),bin,$(patsubst %.c,%.o,$(wildcard $(MATHROOT)/*.c)))

compileMath: outFolder $(MATH_OFILES)

$(ODIR)/%.o: $(MATHROOT)/%.c $(MATHROOT)/%.h
	$(CC) -c $< -o $@ $(CFLAGS) $(IDIRFLAG)
	
checkMath:
	$(CC) -fsyntax-only $(wildcard $(MATHROOT)/*.c) $(IDIRFLAG)