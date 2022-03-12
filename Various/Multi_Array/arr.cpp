// notes
// Arr2 is fast
// while Arr3 and Arr4 are slow

template <typename T> class Arr2 {
	private:
		int d1;
		T** val;

	public:
		Arr2(int n = 0, int m = 0);
		~Arr2();
		T* operator [] (int x);
		const T* operator [] (int x) const;
};

template <typename T> Arr2<T>::Arr2(int n, int m) : d1(n) {
	val = new T* [n];
	for (int i = 0; i < n; i++) val[i] = new T [m];
}
template <typename T> ~Arr2() {
	for (int i = 0; i < d1; i++) delete [] val[i];
	delete [] val;
}

template <typename T> T* Arr2<T>::operator [] (int x) {return val[x];}
template <typename T> const T* Arr2<T>::operator [] (int x) const {return val[x];}

// ---

template <typename T> class Arr3 {
	private:
		Arr2<T>* val;

	public:
		Arr3(int x, int y, int z);
		Arr2<T>& operator [] (int x);
		const Arr2<T>& operator [] (int x) const;
};

template <typename T> Arr3<T>::Arr3(int x, int y, int z) {
	val = new Arr2<T> [x];
	for (int i = 0; i < x; i++) val[i] = Arr2<T>(y, z);
}
template <typename T> Arr2<T>& Arr3<T>::operator [] (int x) {return val[x];}
template <typename T> const Arr2<T>& Arr3<T>::operator [] (int x) const {return val[x];}

// ---

template <typename T> class Arr4 {
	private:
		Arr3<T>** val;

	public:
		Arr4(int p, int q, int r, int s);
		Arr3<T>& operator [] (int x);
		const Arr3<T>& operator [] (int x) const;
};

template <typename T> Arr4<T>::Arr4(int p, int q, int r, int s) {
	val = new Arr3<T>* [p];
	for (int i = 0; i < p; i++) val[i] = new Arr3<T>(q, r, s);
}
template <typename T> Arr3<T>& Arr4<T>::operator [] (int x) {return *val[x];}
template <typename T> const Arr3<T>& Arr4<T>::operator [] (int x) const {return *val[x];}
