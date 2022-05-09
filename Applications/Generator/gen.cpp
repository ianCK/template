#include <bits/stdc++.h>
using namespace std;

void copy_file(fstream &input, fstream &output) {
	string s;
	while (getline(input, s)) output << s << "\n";
	return ;
}

bool file_exists(string s) {
	ifstream f(s.c_str());
	return f.good();
}

void generate(string fileName) {
    if (fileName.find(".cpp") == string::npos) fileName += ".cpp";

    if (file_exists(fileName)) {
        cout << "File \"" << fileName << "\" already exists. Are you sure to replace it? (yes/no)" << endl;
        string ans; cin >> ans;
        if (ans != "yes") {
            cout << "Generate ignored\n";
            return ;
        }
    }

    string source_name = "C:\\Users\\ianli\\Desktop\\CP\\template\\single_case.cpp";

    fstream input(source_name.c_str(), ios::in), output(fileName.c_str(), ios::out);
    copy_file(input, output);
    return ;
}

int main(int argc, const char* argv[]) {
    vector<string> fileNames;

    for (int i = 1; i < argc; i++) fileNames.push_back(string(argv[i]));

    if (fileNames.empty()) {
        string fileName;
        cout << "File name = ?.cpp\n"; cin >> fileName;
        fileNames.push_back(fileName);
    }

    for (const string& s : fileNames) generate(s);
}
