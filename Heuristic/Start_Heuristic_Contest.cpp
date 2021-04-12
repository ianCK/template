#include <bits/stdc++.h>
using namespace std;

void System_wait() {while (!system(NULL));}
void System(const char *c) {
	System_wait();
	system(c);
	return ;
}
void System(string s) {return System(s.c_str());}

int main() {
	System("Xcopy /E /I C:\\Users\\ianli\\Desktop\\CP\\template\\Heuristic\\Written_Codes Written_Codes");
}
