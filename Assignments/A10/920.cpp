#include <iostream>
#include<algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>

using namespace std;

struct P
{
	int x, y;
	P(int a = 0, int b = 0) :x(a), y(b) {}
}pt[1000];
bool checkP(P a, P b) { return a.x < b.x || (a.x == b.x && a.y > b.y); }

int main()
{
	int  i, j, n, t;
	double pnum;
	cin >> t;
	while (t--)
	{
		pnum = 0.0;
		cin >> n;
		for (i = 0; i < n; i++)
		{
			cin >> pt[i].x >> pt[i].y;
		}
		sort(pt, pt + n, checkP);
		int py = 0;
		for (i = n - 1; i >= 0; i--)
		{
			while (i >= 0 && pt[i].y <= py) i--;
			if (i < 0) break;
			pnum += 1.0 * (pt[i].y - py) / cos(atan2(1.0 * (pt[i + 1].x - pt[i].x), 1.0 * (pt[i].y - pt[i + 1].y)));
			py = pt[i].y;
			
		}
		
        cout << pnum << endl;
	}
	return 0;
}
