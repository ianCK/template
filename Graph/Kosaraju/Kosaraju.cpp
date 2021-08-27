// not completed

void dfs1(int cur) {
	went[cur] = true;
	for (int i : graph[cur]) if (!went[i]) dfs1(i);
	dfs1_idx[++dfs1_clock] = cur;
}

void dfs2(int cur) {
	went[cur] = true;
	for (int i : ngraph[cur]) if (!went[i]) {
		dsu.Merge(cur, i);
		dfs2(i);
	}
}

for (int i = 1; i <= n; i++) if (!went[i]) dfs1(i);
went.reset();
for (int i = n; i >= 1; i--) if (!went[dfs1_idx[i]]) dfs2(dfs1_idx[i]);

