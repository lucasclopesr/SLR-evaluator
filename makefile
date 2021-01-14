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


$(ODIR)/%.o: $(SDIR)/%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o
	rm $(TARGET)