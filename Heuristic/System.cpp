bool _system_debug = false;
void System_wait() {while (!system(NULL));}

void System(const char *c) {
	System_wait();
	if (_system_debug) printf("System : %s\n", c);
	system(c);
	return ;
}

void System(string s) {return System(s.c_str());}
