template <typename T, bool (*cmp)(T, T) = std::less<T>()> struct Double_Heap {
	vector<T> val;

	void shirnk_to_fit() {}
	int size() const {}
	bool empty() const {}
	T top() const {}
	T bot() const {}
};
