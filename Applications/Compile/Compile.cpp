#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define F first
#define S second
#define MP make_pair
#define MTP make_tuple
#define R Read
#define RD Read_Digit
#define RP Read_P
#define RS Read_String
#define RL Read_Loop
#define RLD Read_Loop_Digit
#define RLP Read_Loop_P
#define RLS Read_Loop_String
#ifdef ONLINE_JUDGE
	#define Debug(...) ;
	#define Debug_Array(n,x) ;
	#define Debugln_Array(n,x) ;
	#define NL ;
#else
	#define Debug(...) {printf("(%s) = ",(#__VA_ARGS__)),_print(__VA_ARGS__),printf("\n");}
	#define Debug_Array(n,x) {printf("%s :",(#x));for(int i=1;i<=n;i++)printf(" "),_print(x[i]);printf("\n");}
	#define Debugln_Array(n,x) {for(int i=1;i<=n;i++){printf("%s",(#x));printf("[%d] = ", i);_print(x[i]);printf("\n");}}
	#define NL {printf("\n");}
#endif
typedef long long int ll;
typedef unsigned long long int ull;

constexpr int kN = int(1E5 + 10);
// constexpr int kMod = 998244353;
// constexpr int kMod = int(1E9 + 7);
// constexpr int kInf = 0x3f3f3f3f;
// constexpr ll kInf = 0x3f3f3f3f3f3f3f3f;
// constexpr double kPi = acos(-1);
// constexpr double kEps = 1E-9;
// constexpr int dx[4] = {0, 0, 1, -1};
// constexpr int dy[4] = {1, -1, 0, 0};
// constexpr int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
// constexpr int dy[8] = {1, -1, 1, -1, -1, 1, 0, 0};

#include "C:\Users\ianli\Desktop\CP\template\Various\Fast_IO\Fast_IO.cpp"
#include "C:\Users\ianli\Desktop\CP\template\Various\Useful_Functions\Useful_Functions.cpp"
#include "C:\Users\ianli\Desktop\CP\template\Various\Debug\Debug.cpp"
#include "C:\Users\ianli\Desktop\CP\template\Heuristic\System.cpp"

static const string gcc = "g++";
static const string cppflags = "-Wall -std=c++17 -O3";

static const string templatePath = "C:\\Users\\ianli\\Desktop\\CP\\template\\";
static const string objectListPath = "objectList";
static const string commentPrefix = "#";

vector<string> readObjectList() {
	vector<string> ret;

	fstream file(templatePath + objectListPath, ios::in);

	string line;
	while (getline(file, line)) {
		if (line.substr(0, commentPrefix.length()) == commentPrefix) continue;
		else if (line == "") continue;
		else ret.PB(templatePath + line);
	}

	return ret;
}

int main(int argc, const char* argv[]) {
	string cppfile = "";
	for (int i = 1; i < argc; i++) {
		if (string(argv[i]) == "-DEBUG") _system_debug = true;
		else cppfile = string(argv[i]);
	}

	if (cppfile == "") {
		cout << "No cppfile\n";
		return 0;
	}

	vector<string> objects = readObjectList();

	string objectsStr = "";
	for (const string& str : objects) objectsStr += str + " ";

	System(gcc + " " + cppflags + " " + objectsStr + " " + cppfile);
}
