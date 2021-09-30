/**
* YI　ZHANG
* CMPS 4883
* 2021/8/31
*/
#include <iostream>
#include <string.h>
using namespace std;
typedef int row[100];
class hanoi
{
private:
	int x , y;
	int num;
	int array[3][100];
	int lth[3];
public:
	hanoi(int a = 1, int b = 1)
	{
		x = a;
		y = b;
	}
	int input()
	{
		cin >> x >> y;
		if (x == 0 && y == 0)
			return 0;
		memset(array, 0, sizeof(array));
		memset(array + 1, 0, sizeof(array + 1));
		memset(array + 2, 0, sizeof(array + 2));
		for (int i = x; i > 0; i--)
			array[0][x - i] = i;
		memset(lth, 0, sizeof(lth));
		lth[0] = x;
		lth[1] = 0;
		lth[2] = 0;
		num = 1;
		return 1;
	}
	void array_output(row& a)
	{
		int* p = a;
		if (*p)
			cout << *p;
		p++;
		while (*p)
		{
			cout << " " << *p;
			p++;
		}
		cout << endl;
	}
	void move(row& a, row& b, int& numa, int& numb)
	{
		b[numb++] = a[--numa];
		a[numa] = 0;
	}
	void output()
	{	
	
		cout << "A=>   ";
		array_output(array[0]);
		cout << "B=>   ";
		array_output(array[1]);
		cout << "C=>   ";
		array_output(array[2]);
		cout << endl;

	}
	int  cacus(int k, int& start, int& index, int& alternate)
	{
		if (num > y)
			return 0;
		else {
			if (k == 1)
			{
				move(array[start], array[index], lth[start], lth[index]);
				output();
				num++;
				return 1;
			}
			else
			{
				int temp = cacus(k - 1, start, alternate, index);
				if (temp == 0)
					return 0;
				if (num > y)
					return 1;
				move(array[start], array[index], lth[start], lth[index]);
				output();
				num++;
				if (temp == 0)
					return 0;
				temp = cacus(k - 1, alternate, index, start);
				if (temp == 0)
					return 0;
			}
			return 1;
		}
	}
	void print()
	{
		int start = 0, index = 2, alternate = 1;
		output();
		cacus(x, start, index, alternate);
	}

};
int main()
{
	hanoi test;
	int count = 0;
	while (test.input())
	{
		count++;
		cout << "Problem #" << count << endl << endl;
		test.print();
	}
	return 0;
}