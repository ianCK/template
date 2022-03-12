
const int kN = int(1E5 + 10);

int k[kN];
vector<int> v[kN];
int st[kN], ed[kN];
int a[kN];
int h[kN];
int q[kN], q_now = 1, q_back = 1;
// k=0的人, 等著被算的
// q_now -> 下一個要算的人
// q_back -> 現在q的尾巴

//      v
// q = [4, 8, 6, 7, 1, 2, 3, 5]

int p[kN];

int main() {
	int n; scanf("%d", &n);

	// i : a[st[i] ~ ed[i]]
	// idx: 1 2 3 4 5 6 7 8
	// p  : 3 5 5 3 x 2 2 1

	for (int i = 1, now = 1; i <= n; i++) {
		// 第i行
		scanf("%d", &k[i]);
		st[i] = now;
		for (int j = 1; j <= k[i]; j++) {
			// i -> a[now]
			scanf("%d", &a[now]);
			p[a[now]] = i;
			now++;
		}
		ed[i] = now - 1;

		// v[i][0] ~ v[i][k[i] - 1]

		//for (int j = 0; j < k[i]; j++) {
		//	// k個數字 a[i][1] ~ a[i][k[i]]
		//	scanf("%d", &v[i][j]);
		//	//int tmp; scanf("%d", &tmp);
		//	//v[i].push_back(tmp); // v[i][k[i]]
		//}
	}

	// sum of k = n - 1

	// int : +- 2E9
	// long long int : +- 9E18

	// calculate h

	for (int i = 1; i <= n; i++) {
		if (k[i] == 0) {
			q[q_back] = i;
			q_back++;
		}
	}

	for (int i = 1; i <= n; i++) {
		int now_id = q[q_now]; 
		q_now++;

		// calculate h[now_id];
		for (int j = st[now_id]; j <= ed[now_id]; j++) {
			h[now_id] = max(h[now_id], h[a[j]] + 1);
		}

		// p[now_id]
		k[p[now_id]]--;

		if (k[p[now_id]] == 0) {
			q[q_back] = p[now_id];
			q_back++;
		}
	}

	long long int ans = 0;
	for (int i = 1; i <= n; i++) ans += h[i];
	printf("%lld\n", ans);
}
