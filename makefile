IDIR =lib
CC=g++
CFLAGS=-g -Wall -I$(IDIR)

ODIR=obj
SDIR=src

TARGET=analisador

_DEPS = SLR-parser.hpp grammar-constants.hpp
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = SLR-parser.o main.o grammar-constants.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

# Test object
TESTER=test

_DEPS_T = grammar.hpp SLR-parser.hpp grammar-constants.hpp
DEPS_T = $(patsubst %,$(IDIR)/%,$(_DEPS_T))

_OBJ_T = grammar.o SLR-parser.o grammar-constants.o tester.o
OBJ_T = $(patsubst %,$(ODIR)/%,$(_OBJ_T))



$(ODIR)/%.o: $(SDIR)/%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)



test:
$(ODIR)/%.o: $(SDIR)/%.cpp $(DEPS_T)
	$(CC) -c -o $@ $< $(CFLAGS)
$(TESTER): $(OBJ_T)
	$(CC) -o $@ $^ $(CFLAGS)



.PHONY: clean

clean:
	rm -f $(ODIR)/*.o
	rm -f $(TARGET) 2> /dev/null
	rm -f $(TESTER) 2> /dev/null