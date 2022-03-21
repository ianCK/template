#include "C:\Users\ianli\Desktop\CP\template\CommonInclude\CommonInclude.h"

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

// using Mint = Mod_Int<kMod>;

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
	string outputExe = "a.exe";
	for (int i = 1; i < argc; i++) {
		if (string(argv[i]) == "-DEBUG") _system_debug = true;
		else if (string(argv[i]) == "-o") outputExe = string(argv[++i]);
		else cppfile = string(argv[i]);
	}

	if (cppfile == "") {
		cout << "No cppfile\n";
		return 0;
	}

	vector<string> objects = readObjectList();

	string objectsStr = "";
	for (const string& str : objects) objectsStr += str + " ";

	System(gcc + " " + cppflags + " " + objectsStr + " " + cppfile + " -o " + outputExe);
}
