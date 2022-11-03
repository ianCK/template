#include <CommonInclude/CommonInclude.h>

<<<<<<< Updated upstream:Compile/Compile.cpp
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
		else ret.PB(templatePath + line);
	}

	return ret;
}

int main(int argc, const char* argv[]) {
	if (argc != 2) {
		cout << "Usage: compile sol.cpp\n"; 
		return 0;
	}

	string cppfile = string(argv[1]);

	vector<string> objects = readObjectList();

	string objectsStr = "";
	for (const string& str : objects) objectsStr += str + " ";

	System(gcc + " " + cppflags + " " + objectsStr + " " + cppfile);
=======
static const string localIncludePrefix = "#include <";
static const string templatePath = "C:\\Users\\ianli\\Desktop\\CP\\template\\";

bool IsInclude( string line )
{
    static const string include = "#include";
    return line.substr( 0, include.length() ) == include;
}

string ExtractPath( string line )
{
    size_t lpos = line.find( '"' );
    size_t rpos = line.find( '"', lpos + 1 );

    if( lpos == string::npos or rpos == string::npos )
    {
        lpos = line.find( '<' );
        rpos = line.find( '>', lpos + 1 );
    }

    assert( lpos != string::npos and rpos != string::npos );

    return line.substr( lpos + 1, rpos - lpos - 1 );
}

bool IsTemplateInclude( string line )
{
    size_t lpos = line.find( '<' );
    return lpos != string::npos and isupper( line[lpos + 1] );
}

bool IsLocalInclude( string line )
{
    return line.find( '"' ) != string::npos;
}

// void outputFile(fstream& output, string path) {
//     static set<string> se;
// 
//     se.insert(path);
//     cerr << path << endl;
// 
//     output << "// --- Start of " << path << " --- \n";
// 
//     fstream file(path, ios::in);
// 
//     string line;
//     while (getline(file, line)) {
//         if (line.substr(0, localIncludePrefix.length()) == localIncludePrefix) {
//             string path;
//             bool start = false;
//             for (char c : line) {
//                 if (c == '>') break;
//                 if (start) path += c;
//                 if (c == '<') start = true;
//             }
// 
//             makeGood(path);
// 
//             if (isLocal(path)) {
//                 path = templatePath + path;
//                 if (se.find(path) == se.end()) outputFile(output, path);
//                 continue;
//             }
//             else output << line << "\n";
//         }
//         else if (line == "#pragma once") continue;
//         else output << line << "\n";
//     }
// 
//     output << "// --- End of " << path << " --- \n";
//     return ;
// }

int main( int argc, const char** argv )
{
    if( argc < 2 )
    {
        cout << "Usage: FileMerger A.cpp [B.cpp ...]\n";
        return 0;
    }

    vector<string> cppFiles;

    string outputFile = "export.cpp";

    for( int i = 1; i < argc; i++ )
    {
        string s = string( argv[i] );
        if( s == "-o" )
        {
            outputFile = string( argv[++i] );
        }
        else if( IsCppFile( s ) )
        {
            cppFiles.push_back( s );
        }
    }

    string currentPath = filesystem::current_path().string();
    cout << "currentPath = " << currentPath << endl;

    fstream output( outputFile, ios::out );
    output << "// Merged by FileMerger.exe\n";

    // outputFile(output, path);

    output.close();

    system( "CLIP < " + outputFile );
    cout << "Clipped to clipboard\n";
>>>>>>> Stashed changes:Applications/FileMerger/FileMerger.cpp
}
