CXX = g++
CXXFLAGS = -O3 -Wall -std=c++17 -Wl,-stack,10485760 -I C:\\Users\\ianli\\Desktop\\CP\\template\\

EXE = gen.exe

all: $(EXE)

gen.exe : gen.cpp
	$(CXX) $(CXXFLAGS) -o $@ $(@:%.exe=%.cpp)
	mv -f $@ ../

clean:
	rm $(EXE)

