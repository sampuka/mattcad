IDIR = include

SDIR = src
CC = g++
CFLAGS = -I$(IDIR) -g -Wall -Wextra -pedantic -std=c++11
LFLAGS = -pthread -lsfml-graphics -lsfml-window -lsfml-system

ODIR = $(SDIR)/obj
LDIR = lib

LIBS =

#_DEPS = Mattcad.hpp Entity.hpp VariableSet.hpp
#DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = mattcad.o Mattcad.o Entity.o VarSetEntity.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

mattcad: $(OBJ)
	$(CC) -o $@ $(CFLAGS) $(LFLAGS) $(LIBS) $(OBJ)

$(ODIR)/mattcad.o: $(SDIR)/mattcad.cpp $(IDIR)/Mattcad.hpp
	$(CC) -c -o $(ODIR)/mattcad.o $(CFLAGS) $(SDIR)/mattcad.cpp

$(ODIR)/Mattcad.o: $(SDIR)/Mattcad.cpp $(IDIR)/Mattcad.hpp $(IDIR)/Entity.hpp
	$(CC) -c -o $(ODIR)/Mattcad.o $(CFLAGS) $(SDIR)/Mattcad.cpp

$(ODIR)/Entity.o: $(SDIR)/Entity.cpp $(IDIR)/Entity.hpp
	$(CC) -c -o $(ODIR)/Entity.o $(CFLAGS) $(SDIR)/Entity.cpp

$(ODIR)/VarSetEntity.o: $(SDIR)/VarSetEntity.cpp $(IDIR)/VarSetEntity.hpp $(IDIR)/Entity.hpp $(SDIR)/VarSetEntity.cpp
	$(CC) -c -o $(ODIR)/VarSetEntity.o $(CFLAGS) $(SDIR)/VarSetEntity.cpp


#$(ODIR)/%.o: $(SDIR)/%.cpp $(DEPS)
#	$(CC) -c -o $@ $< $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o $(SDIR)/*~ mattcad $(IDIR)/*~
	rmdir $(ODIR)

$(shell mkdir -p $(ODIR))
