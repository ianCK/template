#!/bin/fish
for f in **/_lib.cpp
	echo '#include <bits/stdc++.h>' > tmp.cpp
	echo 'using namespace std;' >> tmp.cpp
	if echo $f | grep _geometry >/dev/null
		if echo $f | grep -v misc >/dev/null
			echo '#include "_geometry/000-misc/_lib.cpp"' >> tmp.cpp
		end
	end
	if echo $f | grep _math >/dev/null
		if echo $f | grep -v misc >/dev/null
			echo '#include "_math/misc/_lib.cpp"' >> tmp.cpp
		end
	end
	cat $f >> tmp.cpp
	echo "---$f---"
	clang++ -DDEBUG=1 -Weverything -Wno-global-constructors -Wno-exit-time-destructors -Wno-missing-variable-declarations -Wno-missing-prototypes -Wno-c++98-compat-pedantic -Wno-comma -Wno-sign-conversion -Wno-shadow-field-in-constructor -Wno-padded -Wno-unused-function -Wno-unused-macros -Wno-unused-parameter -Wno-unused-const-variable -std=c++17 -c -o tmp.o tmp.cpp
	rm tmp.cpp tmp.o
end
