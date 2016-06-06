# Project Name
PRJNAME=uint128
VERSION := 0.4

# Filepaths
SRCDIR=src
INCDIR=inc
LIBDIR=lib
BINDIR=../Executable
INSTALL=/usr/bin

# Toolchain
CC=g++

# Find source files
C_FILES := $(shell find -L $(SRCDIR) -name '*.cpp')
O_FILES := $(C_FILES:.cpp=.o)

# Find header dirs
INC=$(shell find -L $(INCDIR) -name '*.h' -exec dirname {} \; | uniq)
INC+=$(shell find -L $(LIBDIR) -name '*.h' -exec dirname {} \; | uniq)
INCLUDES=$(INC:%=-I%)

# Compiler Flags
PFLAGS=-fPIC -O3 -g -lm
LDFLAGS:=$(shell dpkg-buildflags --get LDFLAGS)
CFLAGS=-shared -Wl,-soname,lib$(PRJNAME).so -D_GNU_SOURCE
EFLAGS=-fno-inline  -O0
LFLAGS=-lrt

# Compiling Process
all: lib$(PRJNAME).so.$(VERSION) clean

lib$(PRJNAME).so.$(VERSION): $(O_FILES)
	$(CC) $(PFLAGS) $(LDFLAGS) $(INCLUDES) $(CFLAGS) -o $(BINDIR)/$@ $^ $(EFLAGS) $(LFLAGS)

%.o: %.c
	$(CC) $(PFLAGS) -c $(INCLUDES) -o $@ $< $(LFLAGS)

clean:
	$(RM) $(SRCDIR)/*.o

cleanall:
	$(RM) $(SRCDIR)/*.o
	$(RM) $(BINDIR)/*

install:
	cp $(BINDIR)/lib$(PRJNAME).so.$(VERSION) /usr/lib/
	cp $(INCDIR)/uint128.h /usr/include/
	ln -s /usr/lib/lib$(PRJNAME).so.$(VERSION) /usr/lib/lib$(PRJNAME).so
	ldconfig

uninstall:
	rm /usr/lib/lib$(PRJNAME).so
	rm /usr/lib/lib$(PRJNAME).so.*.*
	rm /usr/include/uint128.h
	ldconfig