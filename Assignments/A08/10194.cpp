/**
* YI　ZHANG
* CMPS 4883
* 2021/8/31
*/
#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

struct Team {
	int num; 
    int j, k,  l, m, i;
    int t;
	string n;
}te[50];

bool cmp(Team a, Team b) {
	if (a.num != b.num)
		return a.num > b.num;
	if (a.k != b.k)
		return a.k > b.k;
	if ((a.m - a.i) != (b.m - b.i))
		return (a.m - a.i) > (b.m - b.i);
	if (a.m != b.m)
		return a.m > b.m;
	if (a.j != b.j)
		return a.j < b.j;
	string ta, tb;
	for (int i = 0; i < a.n.size(); i++)
		ta += toupper(a.n[i]);
	for (int i = 0; i < b.n.size(); i++)
		tb += toupper(b.n[i]);
	return ta < tb;
}

int main() {
	int n;
	cin >> n;
	getchar();
	while (n--) {
		string name;
		int t, j;
		getline(cin, name);
		cout << name << endl;
		scanf("%d\n", &t);
		for (int i = 0; i < t; i++) {
			getline(cin, te[i].n);
			te[i].num = te[i].j = te[i].k = te[i].t = te[i].l = te[i].m = te[i].i = 0;
		}
		scanf("%d\n", &j);
		for (int i = 0; i < j; i++) {
			string t1, t2;
			int n1, n2;
			int s1, s2;
			char tmp;
			while ((tmp = getchar()) != '#')
				t1 += tmp;
			scanf("%d@%d#", &s1, &s2);
			getline(cin, t2);
			for (int i = 0; i < t; i++)
				if (t1 == te[i].n) {
					n1 = i;
					break;
				}
			for (int i = 0; i < t; i++)
				if (t2 == te[i].n) {
					n2 = i;
					break;
				}

			te[n1].j++;
			te[n2].j++;
			te[n1].m += s1;
			te[n1].i += s2;
			te[n2].m += s2;
			te[n2].i += s1;
			if (s1 > s2) {
				te[n1].num += 3;
				te[n1].k++;
				te[n2].l++;
			}
			else if (s1 < s2) {
				te[n2].num += 3;
				te[n2].k++;
				te[n1].l++;
			}
			else {
				te[n1].num++;
				te[n2].num++;
				te[n1].t++;
				te[n2].t++;
			}
		}
		sort (te, te + t, cmp);
		for (int i = 0; i < t; i++) {
			printf("%d) ", i + 1);
			cout << te[i].n;
			printf(" %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n", te[i].num, te[i].j, te[i].k, te[i].t, te[i].l, te[i].m - te[i].i, te[i].m, te[i].i);
		}
		if (n)
			cout << endl;
	}
	return 0;
}