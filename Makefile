CC := g++
SRCDIR := src
TSTDIR := tests
OBJDIR := build
BINDIR := bin

MAIN := program/main.cpp

SRCEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(OBJDIR)/%,$(SOURCES:.$(SRCEXT)=.o))

CFLAGS := -g -Wall -O3 -std=c++11
INC := -I include/

$(OBJDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<

main: $(OBJECTS)
	@mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) $(INC) $(MAIN) $^ -o $(BINDIR)/tp2virtual

all: main

run: main
	$(BINDIR)/tp2virtual lru ./arquivos/compilador.log 4 128

run_valgrind: main
	valgrind $(BINDIR)/tp2virtual lru ./arquivos/compilador.log 4 128

clean:
	$(RM) -r $(OBJDIR)/* $(BINDIR)/*