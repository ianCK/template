#include "C:\Users\ianli\Desktop\CP\template\CommonInclude\CommonInclude.h"

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

#include "C:\Users\ianli\Desktop\CP\template\Various\Fast_IO\Fast_IO.cpp"
#include "C:\Users\ianli\Desktop\CP\template\Various\Useful_Functions\Useful_Functions.cpp"
#include "C:\Users\ianli\Desktop\CP\template\Various\Debug\Debug.cpp"

#include "C:\Users\ianli\Desktop\CP\template\DS\BIT\Max.h"
#include "C:\Users\ianli\Desktop\CP\template\DS\BIT\Min.h"

BIT_max<int> bit;
template<> short BIT_min<short>::defaultValue() const {return 0x3f3f;}
BIT_min<short> b2;

int main() {

	bit.init(10);
	for (int i = 1; i <= 10; i++) bit.fix(i, i * i - i * 5);
	for (int i = 1; i <= 10; i++) Debug(i, bit.ask(i));

	NL;

	b2.init(10);
	for (int i = 1; i <= 10; i++) b2.fix(i, i * i - i * 5);
	for (int i = 1; i <= 10; i++) Debug(i, b2.ask(i));

}
