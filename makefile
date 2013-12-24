SRCDIR=src
LIBDIR=lib
BINDIR=bin
INCLUDEDIR=include
CC = gcc
AR = ar
CFLAGS=-Wall -pedantic -g -std=c99  -I$(INCLUDEDIR)  
LDFLAGS= -L$(LIBDIR)
EXEC=CorrecteurOrthographique

all :  $(BINDIR)/$(EXEC)

$(BINDIR)/$(EXEC) : $(SRCDIR)/main.o $(SRCDIR)/charger.o $(SRCDIR)/correcteur.o 
	$(SRCDIR)/deserialisation.o $(SRCDIR)/dictionnaire.o $(SRCDIR)/mot.o 
	$(SRCDIR)/sauvegarder.o $(SRCDIR)/serialisation.o $(SRCDIR)/unefile.o
	$(CC)  -o $@ $^ $(LDFLAGS)

$(SRCDIR)/%.o : $(SRCDIR)/%.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean :
	rm -rf $(BINDIR)/*
	rm -rf $(LIBDIR)/*
	rm -rf $(SRCDIR)/*.o
