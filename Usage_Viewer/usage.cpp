// Compile flags -Wall -Wextra -Wshadow -D_GLIBCXX_ASSERTIONS -DDEBUG -ggdb3 -fmax-errors=2
#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define F first
#define S second
#define MP make_pair
#define MTP make_tuple
typedef long long int ll;

constexpr int kN = int(1E5 + 10);
// constexpr int kMod = 998244353;
// constexpr int kInf = 0x3f3f3f3f;
// constexpr ll kInf = 0x3f3f3f3f3f3f3f3f;
// constexpr double kPi = acos(-1);
// constexpr double kEps = 1E-9;

template <typename T> T ABS(T n) {return n >= 0 ? n : -n;}

#include "C:\Users\ianli\Desktop\CP\template\Various\Fast_IO\Fast_IO.cpp"
#include "C:\Users\ianli\Desktop\CP\template\Various\Useful_Functions\Useful_Functions.cpp"

void Assert(string s, bool val) {
	if (!val) cout << s << "\n";
	assert(val);
	return ;
}

void Show_File(string path) {
	cout << "Show_File : " << path << "\n";
	fstream input;
	input.open(path.c_str(), ios::in);

	string s;
	while (getline(input, s)) cout << s << "\n";
	
	input.close();
	return ;
}
vector<pair<string, vector<string>>> database;

void Output_Database() {
	// for debugging
	for (pair<string, vector<string>> i : database) {
		cout << "< " << i.F << "\n";
		for (string j : i.S) cout << "* " << j << "\n";
		cout << ">\n";
	}
	return ;
}

void Get_Database() {
	fstream input;
	input.open("C:\\Users\\ianli\\Desktop\\CP\\template\\Usage_Viewer\\database", ios::in);

	string s;
	pair<string, vector<string>> cur;
	while (getline(input, s)) {
		if (s[0] == '<') cur = MP(s.substr(2), vector<string>());
		else if (s[0] == '>') database.PB(cur);
		else if (s[0] == '*') cur.S.PB(s.substr(2));
		else Assert("Wrong file format", false);
	}

	input.close();
	return ;
}

void Update_Database() {
	sort(database);
	fstream output;
	output.open("C:\\Users\\ianli\\Desktop\\CP\\template\\Usage_Viewer\\database", ios::out);
	for (pair<string, vector<string>> i : database) {
		output << "< " << i.F << "\n";
		sort(i.S);
		for (string j : i.S) output << "* " << j << "\n";
		output << ">\n";
	}
	output.close();
	return ;
}

int Select_Directory() {
	int directory_count = int(database.size());
	Assert("Sorry, there is no avalible usage file", directory_count);

	cout << "Select Directory\n";
	for (int i = 1; i <= directory_count; i++) cout << "(" << i << ") " << database[i - 1].F << "\n";

	int ans; cin >> ans;
	Assert("Input should be 1 ~ " + to_string(directory_count), 1 <= ans && ans <= directory_count);
	return ans;
}

int Select_File(int directory) {
	int file_count = int(database[directory - 1].S.size());
	Assert("Sorry, there is no avalible usage file in this directory", file_count);

	cout << "Select File\n";
	for (int i = 1; i <= file_count; i++) cout << "(" << i << ") " << database[directory - 1].S[i - 1] << "\n";

	int ans; cin >> ans;
	Assert("Input should be 1 ~ " + to_string(file_count), 1 <= ans && ans <= file_count);
	return ans;
}

void Delete_Directory() {
	int directory = Select_Directory();
	cout << "Delete Directory " << database[directory - 1].F << "\n";
	database.erase(database.begin() + (directory - 1));
	return ;
}
void Create_Directory() {
	cout << "Directory Name ?\n";
	string directory_name; cin >> directory_name;
	database.PB(MP(directory_name, vector<string>()));
	return ;
}

void Delete_File() {
	int directory = Select_Directory();
	cout << "Directory " << database[directory - 1].F << "\n";
	int file = Select_File(directory);
	cout << "Delete File " << database[directory - 1].S[file - 1] << "\n";
	database[directory - 1].S.erase(database[directory - 1].S.begin() + (file - 1));
	return ;
}
void Insert_File() {
	int directory = Select_Directory();
	cout << "Directory " << database[directory - 1].F << "\n";

	cout << "File Name ?\n";
	string file_name; cin >> file_name;
	database[directory - 1].S.PB(file_name);
	return ;
}

void Manage_Database() {
	cout << "Select Mode\n";
	cout << "(1) Delete a Directory\n";
	cout << "(2) Create a Directory\n";
	cout << "(3) Delete a File\n";
	cout << "(4) Insert a File\n";

	int Mode; cin >> Mode;
	Assert("Input should be 1 ~ 4", 1 <= Mode && Mode <= 4);

	switch (Mode) {
		case 1 :
			Delete_Directory();
			break;
		case 2 :
			Create_Directory();
			break;
		case 3 :
			Delete_File();
			break;
		case 4 :
			Insert_File();
			break;
		default :
			Assert("Unexpected Error", false);
	}

	Update_Database();
	return ;
}

void Read_Usage_Files() {
	int directory = Select_Directory();
	cout << "Directory " << database[directory - 1].F << "\n";
	int file = Select_File(directory);
	cout << "File " << database[directory - 1].S[file - 1] << "\n";

	Show_File("C:\\Users\\ianli\\Desktop\\CP\\template\\" + database[directory - 1].F + "\\" + database[directory - 1].S[file - 1] + "\\Usage");
	return ;
}

int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//freopen("file_name", "r", stdin);
	//freopen("file_name", "w", stdout);
	//fstream input, output;
	//input.open("file_name", ios::in);
	//output.open("file_name", ios::out);
	Get_Database();
	cout << "Mode ?\n";
	cout << "(1) Manage current Usage files\n";
	cout << "(2) Read Usage files\n";

	int Mode; cin >> Mode;

	// Absolute path = C:\Users\ianli\Desktop\CP\template

	/*
	 * db file format
	 * < [Directory name]
	 * > (end of directory)
	 * * [file_name]
	 *
	 * example :
	 * < DS
	 * * BIT
	 * >
	 */

	Assert("Input should be 1 ~ 2", 1 <= Mode && Mode <= 2);
	switch (Mode) {
		case 1 :
			Manage_Database();
			break;
		case 2 :
			Read_Usage_Files();
			break;
		default :
			Assert("Unexpected Error", false);
	}

	//input.close();
	//output.close();
}
