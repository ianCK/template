CXX = g++
CXXFLAGS = -O3 -Wall -std=c++17

OBJECTS = Max.o Min.o

OBJECTRULE = $(CXX) $(CXXFLAGS) -c -o $@ $(@:.o=.cpp)

all: $(OBJECTS)

Max.o : Monoid.h Max.h Max.cpp
	$(OBJECTRULE)

Min.o : Monoid.h Min.h Min.cpp
	$(OBJECTRULE)

clean:
	rm $(OBJECTS)
