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

static const string localIncludePrefix = "#include \"";

bool isRelativePath(string path) {
	if (path.length() >= 2 and path[0] == 'C' and path[1] == ':') return false;
	return true;
}

vector<string> allDependencies(string filePath) {

	string directoryPath = filePath;
	while (directoryPath.back() != '\\') directoryPath.pop_back();

	vector<string> ret;

	fstream file(filePath, ios::in);

	string line;
	while (getline(file, line)) {
		if (line.substr(0, localIncludePrefix.length()) == localIncludePrefix) {
			string path = line.substr(localIncludePrefix.length());
			path.pop_back();

			if (isRelativePath(path)) path = directoryPath + path; 

			ret.PB(path);
		}
	}

	file.close();

	return ret;
}

vector<string> collectFiles(string path) {
	vector<string> ret;

	set<string> processed;
	queue<string> toBeProcessed;

	toBeProcessed.push(path);

	while (!toBeProcessed.empty()) {
		string path = toBeProcessed.front(); toBeProcessed.pop();

		if (processed.find(path) != processed.end()) continue;

		processed.insert(path);
		ret.PB(path);
		for (const string& str : allDependencies(path)) {
			toBeProcessed.push(str);
			if (str.back() == 'h') {
				string tmp = str;
				tmp.pop_back();
				tmp += "cpp";
				toBeProcessed.push(tmp);
			}
		}
	}

	return ret;
}

void outputFile(fstream& output, string path) {
	output << "// --- Start of " << path << " --- \n";

	fstream file(path, ios::in);

	string line;
	while (getline(file, line)) {
		if (line.substr(0, localIncludePrefix.length()) == localIncludePrefix) continue;
		else if (line == "#pragma once") continue;
		else output << line << "\n";
	}

	output << "// --- End of " << path << " --- \n";
	return ;
}

int main(int argc, const char* argv[]) {
	if (argc != 2) {
		cout << "Usage: FileMerger sol.cpp\n"; 
		return 0;
	}

	string current_path = filesystem::current_path().string() + "\\";
	Debug(current_path);

	string path = current_path + string(argv[1]);
	vector<string> allFiles = collectFiles(path);

	for (const string& str : allFiles) Debug(str);

	map<string, vector<string>> graph;
	for (const string& str : allFiles) graph[str] = allDependencies(str);

	map<string, int> deg;
	for (const string& str : allFiles) deg[str] = int(graph[str].size());

	map<string, vector<string>> dependants;
	for (auto [str, vec] : graph) for (const string& dep : vec) dependants[dep].PB(str);

	fstream output("export.cpp", ios::out);
	output << "// Merged by FileMerger.exe\n";

	queue<string> qu;
	for (const string& str : allFiles) if (deg[str] == 0) qu.push(str);
	while (!qu.empty()) {
		string path =  qu.front(); qu.pop();

		outputFile(output, path);

		for (const string& str : dependants[path]) if (!--deg[str]) qu.push(str);
	}

	output.close();

	system("CLIP < export.cpp");
	cout << "Clipped to clipboard\n";
}
