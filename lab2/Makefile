# Define the compiler and the linker. The linker must be defined since
# the implicit rule for linking uses CC as the linker. g++ can be
# changed to clang++.
CXX = g++
CC  = $(CXX)

# Generate dependencies in *.d files
DEPFLAGS = -MT $@ -MMD -MP -MF $*.d

# Define preprocessor, compiler, and linker flags. Uncomment the # lines
# if you use clang++ and wish to use libc++ instead of GNU's libstdc++.
# -g is for debugging.
CPPFLAGS =  -std=c++11 -I.
CXXFLAGS =  -O2 -Wall -Wextra -pedantic-errors -Wold-style-cast 
CXXFLAGS += -std=c++11 
CXXFLAGS += -g
CXXFLAGS += $(DEPFLAGS)
LDFLAGS =   -g 
#CPPFLAGS += -stdlib=libc++
#CXXFLAGS += -stdlib=libc++
#LDFLAGS +=  -stdlib=libc++

# Targets
PROGS = trigram spell test_edit_distance


all: $(PROGS)


# Targets rely on implicit rules for compiling and linking

trigram: mainTrigram.o trigram.o
	g++ -o trigram mainTrigram.o trigram.o

trigram.o: trigram.cc trigram.h
	g++ -c trigram.cc -o trigram.o

mainTrigram.o: mainTrigram.cc trigram.h
	g++ -c mainTrigram.cc -o mainTrigram.o

spell: spell.o dictionary.o word.o edit_distance.o
	g++ -o spell spell.o dictionary.o word.o edit_distance.o

spell.o: spell.cc dictionary.h word.h
	g++ -c spell.cc -o spell.o

dictionary.o: dictionary.cc dictionary.h
	g++ -c dictionary.cc -o dictionary.o

word.o: word.cc word.h
	g++ -c word.cc -o word.o

test_edit_distance: test_edit_distance.o edit_distance.o
	g++ -o test_edit_distance test_edit_distance.o edit_distance.o

test_edit_distance.o: test_edit_distance.cc edit_distance.h
	g++ -c test_edit_distance.cc -o test_edit_distance.o

edit_distance.o: edit_distance.cc edit_distance.h
	g++ -c edit_distance.cc -o edit_distance.o


# Phony targets
.PHONY: all test clean distclean



# Standard clean
clean:
	rm -f *.o $(PROGS)

distclean: clean
	rm *.d


# Include the *.d files
SRC = $(wildcard *.cc)
-include $(SRC:.cc=.d)
