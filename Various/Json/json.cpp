class JsonObject;
void JsonOut(JsonObject* ele);

class Number {
	public:
		double num;

		Number(double x) : num(x) {}
		void out() const {printf("%lf", num);}
};

class String {
	public:
		string str;

		String(string s) : str(s) {}
		void out() const {printf("\""); for (char c : str) printf("%c", c); printf("\"");}
};

class Array {
	public:
		vector<JsonObject*> vec;

		void push_back(JsonObject* ele) {vec.push_back(ele);}
		void out() const {
			printf("[");

			bool first = true;
			for (JsonObject* ele : vec) {
				if (first) first = false;
				else printf(",");

				JsonOut(ele);
			}

			printf("]");
			return ;
		}
};

class Object {
	public:
		map<string, JsonObject*> ma;

		void insert(string str, JsonObject* ele) {ma[str] = ele;}
		void out() const {
			printf("{");
			bool first = true;
			for (auto [str, ele] : ma) {
				if (first) first = false;
				else printf(",");

				printf("\"");
				for (char c : str) printf("%c", c);
				printf("\"");

				printf(":");
				JsonOut(ele);
			}
			printf("}");
			return ;
		}
};

class JsonObject {
	public:
		enum class tType {OBJECT, ARRAY, STRING, NUMBER};

		tType t_type;
		union {
			Object* obj;
			Array*  arr;
			String* str;
			Number* num;
		};

		JsonObject(Object* _obj) : t_type(tType::OBJECT), obj(_obj) {}
		JsonObject(Array*  _arr) : t_type(tType::ARRAY),  arr(_arr) {}
		JsonObject(String* _str) : t_type(tType::STRING), str(_str) {}
		JsonObject(Number* _num) : t_type(tType::NUMBER), num(_num) {}

		void out() const {
			switch (t_type) {
				case tType::OBJECT :
					obj -> out();
					break;
				case tType::ARRAY :
					arr -> out();
					break;
				case tType::STRING :
					str -> out();
					break;
				case tType::NUMBER :
					num -> out();
					break;
			}
			return ;
		}
};

void JsonOut(JsonObject* ele) {return ele -> out();}

JsonObject* NumToJson(double num) {return new JsonObject(new Number(num));}
JsonObject* StrToJson(string str) {return new JsonObject(new String(str));}
