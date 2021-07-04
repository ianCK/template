#define SIV static inline void
#define ID isdigit
#define W while
#define TT template <typename T>
#define TTX template <typename T, typename ...Ta>
#define TX template <typename ...Ta>

bool Fast_IO_activated = false;
bool IOS_activated = false;
static inline char Z_G() {
	static bool pre = Fast_IO_activated = true;
	static char buf[1 << 16], *p = buf, *end = buf;
	if (p == end) {
		if ((end = buf + fread(buf, 1, 1 << 16, stdin)) == buf) return '\0';
		p = buf;
	}
	return *p++;
}

TT SIV Read_P(T &n) {
	char c;
	W (!ID(c = Z_G())) ;
	n = int(c - '0');
	W (ID(c = Z_G())) n = n * 10 + int(c - '0');
}

TT SIV Read(T &n) {
	char c;
	bool neg = false;
	W (!ID(c = Z_G())) if (c == '-') neg = true;
	n = int(c - '0');
	W (ID(c = Z_G())) n = n * 10 + int(c - '0');
	if (neg) n = -n;
}

TT SIV Read_Digit(T &n) {
	char c;
	W (!ID(c = Z_G())) ;
	n = int(c - '0');
}

SIV Read_String(string &s) {
	char c = Z_G();
	W (c == ' ' or c == '\n') c = Z_G();
	W (c != ' ' and c != '\n') {
		s += c;
		c = Z_G();
	}
}

TTX SIV Read(T &n, Ta&... Fa) {Read(n); Read(Fa...);}
TTX SIV Read_Digit(T &n, Ta&... Fa) {Read_Digit(n); Read_Digit(Fa...);}
TTX SIV Read_P(T &n, Ta&... Fa) {Read_P(n); Read_P(Fa...);}
TX SIV Read_String(string &s, Ta&... Fa) {Read_String(s); Read_String(Fa...);}

TT SIV Read_Loop_i(int i, T *a) {Read(a[i]);}
TTX SIV Read_Loop_i(int i, T *a, Ta*... Fa) {Read(a[i]); Read_Loop_i(i, Fa...);}
TX SIV Read_Loop(int n, Ta*... Fa) {for (int i = 1; i <= n; i++) Read_Loop_i(i, Fa...);}

TT SIV Read_Loop_Digit_i(int i, T *a) {Read_Digit(a[i]);}
TTX SIV Read_Loop_Digit_i(int i, T *a, Ta*... Fa) {Read_Digit(a[i]); Read_Loop_Digit_i(i, Fa...);}
TX SIV Read_Loop_Digit(int n, Ta*... Fa) {for (int i = 1; i <= n; i++) Read_Loop_Digit_i(i, Fa...);}

TT SIV Read_Loop_P_i(int i, T *a) {Read_P(a[i]);}
TTX SIV Read_Loop_P_i(int i, T *a, Ta*... Fa) {Read_P(a[i]); Read_Loop_P_i(i, Fa...);}
TX SIV Read_Loop_P(int n, Ta*... Fa) {for (int i = 1; i <= n; i++) Read_Loop_P_i(i, Fa...);}

SIV Read_Loop_String_i(int i, string *a) {Read_String(a[i]);}
TX SIV Read_Loop_String_i(int i, string *a, Ta*... Fa) {Read_String(a[i]); Read_Loop_String_i(i, Fa...);}
TX SIV Read_Loop_String(int n, Ta*... Fa) {for (int i = 1; i <= n; i++) Read_Loop_String_i(i, Fa...);}

template <int mul, typename T> SIV Read(T &n) {
	char c;
	bool neg = false;
	W (!ID(c = Z_G())) if (c == '-') neg = true;
	n = int(c - '0');
	W (ID(c = Z_G())) n = n * 10 + int(c - '0');

	int cnt = 0;

	if (c == '.') {
		W (ID(c = Z_G())) {
			n = n * 10 + int(c - '0');
			cnt++;
		}
	}

	W (cnt++ < mul) n = n * 10;

	if (neg) n = -n;
}

template <int mul, typename T> SIV Read_P(T &n) {
	char c;
	W (!ID(c = Z_G())) ;

	n = int(c - '0');
	W (ID(c = Z_G())) n = n * 10 + int(c - '0');

	int cnt = 0;

	if (c == '.') {
		W (ID(c = Z_G())) {
			n = n * 10 + int(c - '0');
			cnt++;
		}
	}

	W (cnt++ < mul) n = n * 10;
}

template <int mul, typename T, typename... Ta> SIV Read(T &n, Ta&... Fa) {Read<mul>(n); Read<mul>(Fa...);}
template <int mul, typename T, typename... Ta> SIV Read_P(T &n, Ta&... Fa) {Read_P<mul>(n); Read_P<mul>(Fa...);}

void IOS() {
	IOS_activated = true;
	ios::sync_with_stdio(false); cin.tie(0);
}
void Freopen(const char *in, const char *out) {freopen(in, "r", stdin); freopen(out, "w", stdout);} 

TT void Print(T x) {
	if (x < 0) {
		printf("-");
		x = -x;
	}
	if (x == 0) printf("0");
	else {
		static int val[100];
		int idx = -1;
		W (x) {
			val[++idx] = x % 10;
			x /= 10;
		}
		W (idx >= 0) printf("%d", val[idx--]);
	}
} 
#undef SIV
#undef ID
#undef W
#undef TT
#undef TTX
#undef TX
