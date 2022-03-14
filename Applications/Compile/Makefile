CXX = g++
CXXFLAGS = -O3 -Wall -std=c++17

EXE = compile.exe

all: $(EXE)

compile.exe : Compile.cpp
	$(CXX) $(CXXFLAGS) -o $@ Compile.cpp

clean:
	rm $(EXE)

