CXX = g++
CXXFLAGS = -O3 -Wall -std=c++17

OBJECTS = SOS.o Add.o Xor.o Mul.o

OBJECTRULE = $(CXX) $(CXXFLAGS) -c -o $@ $(@:.o=.cpp)

all: $(OBJECTS) test

SOS.o : SOS.h SOS.cpp
	$(OBJECTRULE)

Add.o : SOS.o Add.h Add.cpp
	$(OBJECTRULE)

Xor.o : SOS.o Xor.h Xor.cpp
	$(OBJECTRULE)

Mul.o : SOS.o Mul.h Mul.cpp
	$(OBJECTRULE)

test:
	compile.exe test.cpp

clean:
	rm $(OBJECTS)

