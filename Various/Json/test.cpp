#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define F first
#define S second
#define MP make_pair
#define MTP make_tuple
#define R Read
#define RD Read_Digit
#define RP Read_P
#define RS Read_String
#define RL Read_Loop
#define RLD Read_Loop_Digit
#define RLP Read_Loop_P
#define RLS Read_Loop_String
#ifdef ONLINE_JUDGE
	#define Debug(...) ;
	#define Debug_Array(n,x) ;
	#define Debugln_Array(n,x) ;
	#define NL ;
#else
	#define Debug(...) {printf("(%s) = ",(#__VA_ARGS__)),_print(__VA_ARGS__),printf("\n");}
	#define Debug_Array(n,x) {printf("%s :",(#x));for(int i=1;i<=n;i++)printf(" "),_print(x[i]);printf("\n");}
	#define Debugln_Array(n,x) {for(int i=1;i<=n;i++){printf("%s",(#x));printf("[%d] = ", i);_print(x[i]);printf("\n");}}
	#define NL {printf("\n");}
#endif
typedef long long int ll;
typedef unsigned long long int ull;

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
#include "C:\Users\ianli\Desktop\CP\template\Various\Json\json.cpp"

JsonObject* make_Oper(int qty) {
	Array* arr = new Array();
	Object* obj = new Object();

	obj -> insert("ProductionQty", NumToJson(qty));

	arr -> PB(new JsonObject(obj));
	return new JsonObject(arr);
}

JsonObject* Batch(string startTime, string endTime, int spec_id, string spec_name, int qty) {
	Object* obj = new Object();

	obj -> insert("StartTime"    , StrToJson(startTime));
	obj -> insert("EndTime"      , StrToJson(  endTime));
	obj -> insert("SpecID"       , NumToJson(  spec_id));
	obj -> insert("SpecName"     , StrToJson(spec_name));
	obj -> insert("OperationList", make_Oper(qty));

	return new JsonObject(obj);
}

JsonObject* BatchSequence() {
	Array* arr = new Array();
	Object* obj = new Object();

	arr -> PB(Batch("2022/06/01 00:00:00", "2022/06/02 00:30:00", 1, "typeA", 5));
	obj -> insert("BatchSequence", new JsonObject(arr));

	return new JsonObject(obj);
}

Array* RowArray() {
	Array* arr = new Array();
	arr -> PB(BatchSequence());
	return arr;
}

JsonObject* RowInfo() {
	return new JsonObject(RowArray());
}

int main() {
	Object* obj = new Object();
	obj -> insert("ParamName", StrToJson("Solver"));
	obj -> insert("RowInfo"  , RowInfo());
	obj -> out();
}
