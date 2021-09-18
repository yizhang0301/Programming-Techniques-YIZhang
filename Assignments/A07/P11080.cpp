#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
int n, m;
int cl, fl;
int v[200];
vector<int> g[200];

bool check(int num)
{
	fl++;
	if (v[num] == 1) cl++;
	for (int i = 0; i < g[num].size(); i++)
	{
		int x = g[num][i];
		if (v[x] == v[num]) {
			return false;
		}
		if (v[x] == 3 - v[num]) {
			continue;
		}
		v[x] = 3 - v[num];
		if (!check(x)) {
			return false;
		}
	}
	return true;
}
int main() {
	int t;
	cin >> t;
	while (t-- && cin >> n >> m)
	{
		for (int i = 0; i < n; i++) g[i].clear();
		while (m--)
		{
			int a, b;
			cin >> a >> b;
			g[a].push_back(b);
			g[b].push_back(a);
		}
		memset(v, 0, sizeof(v));

		int ans = 0;
		for (int i = 0; i < n; i++) if (!v[i])
		{
			fl = cl = 0;
			v[i] = 1;
			if (!check(i)) { ans = -1; break; }
			ans += max(min(cl, fl - cl), 1);
		}

		cout << ans << endl;
	}


	return 0;
}
