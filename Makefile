SRCDIR=./src
BUILDDIR=./build
OBJDIR=$(BUILDDIR)/obj
INCDIR=./include

CC=gcc
CFLAGS=-I$(INCDIR)

.PHONY: test

SOURCE_PATTERN=$(SRCDIR)/%.c
OBJECT_PATTERN=$(BUILDDIR)/%.o

SOURCE_FILES=$(wildcard $(SRCDIR)/*.c)
OBJECT_FILES=$(SOURCE_FILES:$(SOURCE_PATTERN)=$(OBJECT_PATTERN))

all: $(OBJECT_FILES)

$(OBJECT_PATTERN): $(SOURCE_PATTERN) $(OBJDIR)
	$(CC) -c $(CFLAGS) $< -o $@

$(SOURCE_PATTERN): $(INCDIR)/%.h

$(OBJDIR):
	mkdir -p $@

TESTDIR=./test

SRC_TEST_PATTERN=$(TESTDIR)/%.c
OBJ_TEST_PATTERN=$(BUILDDIR)/$(TESTDIR)/%.o

SRC_TEST_FILES=$(wildcard $(TESTDIR)/*.c)
OBJ_TEST_FILES=$(SRC_TEST_FILES:$(SRC_TEST_PATTERN)=$(OBJ_TEST_PATTERN))

test: $(OBJ_TEST_FILES)

$(OBJ_TEST_PATTERN): $(SRC_TEST_PATTERN)
	$(CC) -c -o $@ $(CFLAGS) $<
	$(MAKE) all

clean:
	@rm -rf $(BUILDDIR)

