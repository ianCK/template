CXX = g++
CXXFLAGS = -O3 -Wall -std=c++17

OBJECTS = DSU.o 

OBJECTRULE = $(CXX) $(CXXFLAGS) -c -o $@ $(@:.o=.cpp)

all: $(OBJECTS)

DSU.o : DSU.h DSU.cpp
	$(OBJECTRULE)

clean:
	rm $(OBJECTS)

