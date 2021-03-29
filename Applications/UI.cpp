#include <conio.h>
#include <iostream>
#include <fstream>
#include <time.h>
using namespace std;

constexpr int FPS = 10;
constexpr int KEY_UP = 72;
constexpr int KEY_DOWN = 80;
constexpr int KEY_LEFT = 75;
constexpr int KEY_RIGHT = 77;
constexpr int ENTER = 13;

void System(string s) {
	while (!system(NULL));
	system(s.c_str());
	return ;
}

string Folder_name[100], Current_directory;
int Folder_count = 1;

void Flush(int position) {
	System("CLS");
	for (int i = 1; i <= Folder_count; i++) {
		if (i == position) cout << " -> ";
		else cout << "    ";
		cout << "| " << Folder_name[i] << "\n";
	}
	cout.flush();
	return ;
}

void Fetch() {
	fstream f;
	System("cd " + Current_directory + " && cd > tmp");
	f.open(Current_directory + "\\tmp");
	f >> Current_directory;
	f.close();
	System("del " + Current_directory + "\\tmp");

	System("dir " + Current_directory + " /B > tmp");
	Folder_count = 2;
	Folder_name[1] = "..";
	f.open("tmp");
	while (f >> Folder_name[Folder_count]) Folder_count++;
	Folder_count--;
	f.close();

	System("del tmp");
	return ;
}

int main() {
	System("cd > tmp");
	fstream f;
	f.open("tmp");
	f >> Current_directory;
	f.close();
	System("del tmp");

	Fetch();
	char key;
	int nxt_flush = 0, position = 1;
	Flush(position);
	while (true) {
		if (_kbhit()) {
			switch (_getch()) {
				case KEY_UP :
					position = max(1, position - 1);
					break;
				case KEY_DOWN :
					position = min(Folder_count, position + 1);
					break;
				case ENTER :
					Current_directory += "\\" + Folder_name[position];
					position = 1;
					Fetch();
					break;
				case 'q':
					return 0;
			}
			Flush(position);
		}
	}
}
