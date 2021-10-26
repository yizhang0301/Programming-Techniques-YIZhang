/**
* YI　ZHANG
* CMPS 4883
* 2021/10/26
*/
#include <cstdio>
#include <fstream>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int num = 110;
const int INF = 0x3fffffff;
class MM
{
public:
	void init(int n, int e, int t)
	{
		this->n = n;
		this->e = e;
		this->t = t;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (i != j)
					f[i][j] = INF;
				else
					f[i][j] = 0;
			}
		}
	}

	void jiaEdge(int u, int v, int t)
	{
		f[u - 1][v - 1] = t;
	}

	int floyd_warshall()
	{
		memcpy(array, f, sizeof(f));
		for (int k = 0; k < n; k++)
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (array[i][k] != INF && array[k][j] != INF)
					{
						array[i][j] = min(array[i][k] + array[k][j], array[i][j]);
					}
				}
			}
		}

		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			if (array[i][e - 1] <= t)
			{
				ans++;
			}
		}
		return ans;
	}

private:
	int n, e, t;
	int f[num][num];
	int array[num][num];

};

int main()
{
    MM mm;

	int cases;
	cin >> cases;
	while (cases--)
	{
		int n, e, t, m;
		cin >> n >> e >> t;
		mm.init(n, e, t);
		cin >> m;
		while (m--)
		{
			int u, v, t;
			cin >> u >> v >> t;
			mm.jiaEdge(u, v, t);
		}

		int ans = mm.floyd_warshall();
		cout << ans << endl;
		if (cases) cout << endl;
	}



	return 0;
}
