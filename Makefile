SRCDIR=./src
BUILDDIR=./build
OBJDIR=$(BUILDDIR)/obj
INCDIR=./include

CC=gcc
CFLAGS=-Wall -I$(INCDIR)

.PHONY: test

SRCPAT=$(SRCDIR)/%.c
OBJPAT=$(OBJDIR)/%.o

SRCS=$(wildcard $(SRCDIR)/*.c)
OBJS=$(SRCS:$(SRCPAT)=$(OBJPAT))

all: $(OBJDIR) $(OBJS)

$(OBJPAT): $(SRCPAT)
	$(CC) -c $(CFLAGS) $< -o $@

$(SRCPAT): $(INCDIR)/%.h

$(OBJDIR):
	mkdir -p $@

TESTDIR=./test
TBUILDDIR=$(BUILDDIR)/$(TESTDIR)
TOBJDIR=$(TBUILDDIR)/obj

TSRCPAT=$(TESTDIR)/%.c
TOBJPAT=$(TOBJDIR)/%.o

TSRCS=$(wildcard $(TESTDIR)/*.c)
TOBJS=$(TSRCS:$(TSRCPAT)=$(TOBJPAT))

test:
	$(MAKE) all
	$(MAKE) $(TOBJDIR) $(TOBJS)

$(TOBJPAT): $(TSRCPAT)
	$(CC) -c -o $@ $(CFLAGS) $<
	$(CC) $(CFLAGS) -o $(TBUILDDIR)/$* $@ $(OBJS)

$(TOBJDIR):
	mkdir -p $@

clean:
	@rm -rf $(BUILDDIR)

