TESTDIR = ./test
SRCDIR = ./src
INCDIR = ./include
BINDIR = ./output

TESTFILES = $(wildcard $(TESTDIR)/*_test.c)
BINFILES = $(patsubst $(TESTDIR)/%.c,$(BINDIR)/%.o,$(TESTFILES))

INCFLAGS = $(addprefix -I,$(TESTDIR) $(SRCDIR) $(INCDIR))
CFLAGS = $(INCFLAGS)

all:
	-mkdir $(BINDIR)
	$(MAKE) build

build: $(BINFILES)

$(BINDIR)/%_test.o: $(TESTDIR)/%_test.c $(SRCDIR)/%.c $(INCDIR)/%.h
	@$(CC) -o $@ $(CFLAGS) $^
	@echo "File '$@' builded"

clean:
	@rm -rf $(BINDIR)

