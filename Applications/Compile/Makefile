CXX = g++
CXXFLAGS = -O3 -Wall -std=c++17 -Wl,-stack,10485760 -I C:\\Users\\ianli\\Desktop\\CP\\template\\

EXE = compile.exe

all: $(EXE)

compile.exe : Compile.cpp
	$(CXX) $(CXXFLAGS) -o $@ Compile.cpp
	mv -f compile.exe ../

clean:
	rm $(EXE)
