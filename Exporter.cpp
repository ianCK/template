#include <bits/stdc++.h>
using namespace std;

void Insert_File(fstream &output, const char cd[]) {
	cout << "Insert File " << cd << endl;
	output << "\n// Included from " << cd << "\n";
	string s;
	fstream library;
	
	library.open(cd, ios::in);
	
	while (getline(library, s)) {
		if (s.substr(0, 10) == "#include \"") {
			string tmp = s.substr(10, s.find("\"", 11) - 10);
			Insert_File(output, tmp.c_str());
		}
		else output << s << "\n";
	}

	library.close();

	output << "// End of " << cd << "\n";
	return ;
}

int main(int argc, const char* argv[]) {
	if (argc < 2) {
		cout << "Usage: Exporter input.cpp [output.cpp = export.cpp]\n"; 
		cout << "Path = C:\\Users\\ianli\\Desktop\\CP\\template\n"; 
		return 0;
	}
	fstream output;
	if (argc == 2) output.open("export.cpp", ios::out);
	else output.open(argv[2], ios::out);

	output << "// Exported by Exporter.exe" << endl;

	Insert_File(output, argv[1]);

	output.close();

	cout << "Done. Exported to export.cpp\n";

	system("CLIP < export.cpp");
	cout << "Clipped to clipboard\n";
}
