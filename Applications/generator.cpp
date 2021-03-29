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

int main(int argc, const char* argv[]) {
	fstream input, output;
	string file_name, source_name;

	if (argc == 2) file_name = argv[1];
	else {
		cout << "File name = ?.cpp\n";
		cin >> file_name;
	}

	if (file_name.find(".cpp") != int(file_name.size() - 4)) file_name += ".cpp";

	if (file_exists(file_name)) {
		cout << "File " << file_name << " already exists. Are you sure to replace it?(yes/no)\n";
		string ans; cin >> ans;
		if (ans != "yes") {
			cout << "Generator ended\n";
			return 0;
		}
	}

	source_name = "C:\\Users\\ianli\\Desktop\\CP\\template\\single_case.cpp";

	input.open(source_name.c_str(), ios::in);
	output.open(file_name.c_str(), ios::out);
	copy_file(input, output);

	return 0;
}
