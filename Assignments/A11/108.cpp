/**
* YI　ZHANG
* CMPS 4883
* 2021/8/31
*/
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
using namespace std;

int matrix[100][100];
int sum[100];
int num;
int getmaxsum()
{
	int max = 0, x = 0;
	for (int i = 0; i < num; i++)
	{
		if (x >= 0) x += sum[i];
		else x = sum[i];
		max = max > x ? max : x;
	}
	return max;
}
int main()
{
	cin >> num;
	int Msum = 0;
	int t;
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			cin >> matrix[i][j];
			sum[j] = matrix[i][j];
		}
		t = getmaxsum();
		Msum = Msum > t ? Msum : t;
		for (int j = i - 1; j >= 0; j--)
		{
			for (int k = 0; k < num; k++)
				sum[k] += matrix[j][k];
			t = getmaxsum();
			Msum = Msum > t ? Msum : t;
		}
	}
	cout << Msum << endl;
	return 0;
}