#include <CommonInclude\CommonInclude.h>

bool systemDebug = false;

void SystemWait() { while ( !system( NULL ) ); }

void System( const char *c )
{
	SystemWait();
    if( systemDebug ) cerr << string( c ) << endl;
	system( c );
	return ;
}

void System( string s ) { return System( s.c_str() ); }

static const string gcc = "g++";
static const string cppflags = "-Wall -std=c++17 -O3 -Wl,-stack,10485760 -I C:/Users/ianli/Desktop/CP/template/";

static const string templatePath = "C:/Users/ianli/Desktop/CP/template/";
static const string commentPrefix = "#";

int main(int argc, const char* argv[]) {
    string arguments = "";

    for( int i = 1; i < argc; i++ )
    {
        string s = string( argv[i] );
        if( s == "--DEBUG" ) systemDebug = true;
        else arguments += " " + s;
    }

    System( gcc + " " + cppflags + " " + arguments );
}
