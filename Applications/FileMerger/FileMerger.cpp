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

static const string localIncludePrefix = "#include \"";

void makeGood(string& str) {
	for (char& c : str) if (c == '/') c = '\\';
	return ;
}

bool hasPrefix(const string& lhs, string rhs) {
	return lhs.substr(0, rhs.length()) == rhs;
}

bool isRelativePath(string path) {
	if (hasPrefix(path, "C:")) return false;
	return true;
}

string makeAbsolutePath(string directoryPath, string filePath) {
	makeGood(directoryPath);
	makeGood(filePath);

	bool working = true;
	while (working) {
		working = false;
		if (hasPrefix(filePath, ".\\")) {
			working = true;
			filePath = filePath.substr(2);
		}
		if (hasPrefix(filePath, "..\\")) {
			working = true;
			directoryPath.pop_back();
			while (directoryPath.back() != '\\') directoryPath.pop_back();
			filePath = filePath.substr(3);
		}
	}

	return directoryPath + filePath;
}

void outputFile(fstream& output, string path) {
	static set<string> se;
	if (se.find(path) != se.end()) return ;

	se.insert(path);
	cerr << path << endl;

	string directoryPath = path;
	while (directoryPath.back() != '\\') directoryPath.pop_back();

	output << "// --- Start of " << path << " --- \n";

	fstream file(path, ios::in);

	string line;
	while (getline(file, line)) {
		if (hasPrefix(line, localIncludePrefix)) {
			string path = line.substr(localIncludePrefix.length());
			path.pop_back();

			if (isRelativePath(path)) path = makeAbsolutePath(directoryPath, path); 

			if (se.find(path) == se.end()) {
				outputFile(output, path);
			}

			if (path.back() == 'h') {
				path.pop_back();
				path += "cpp";
				outputFile(output, path);
			}

			continue;
		}
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
	makeGood(current_path);
	cerr << "current_path = " << current_path << endl;

	string path = makeAbsolutePath(current_path, string(argv[1]));
	fstream output("export.cpp", ios::out);
	output << "// Merged by FileMerger.exe\n";

	outputFile(output, path);

	output.close();

	system("CLIP < export.cpp");
	cout << "Clipped to clipboard\n";
}
