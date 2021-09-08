/**
* YI　ZHANG
* CMPS 4883
* 2021/9/7
*/
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

vector<int> v;   //vector for
int minCycle;   //create cycle 

int main()
{
	int num1, num2, num3;
	 //  read each 3 data for a group
	while (cin >> num1 >> num2 >> num3, num1 || num2 || num3) {
		v.clear();

		v.push_back(num1);
		minCycle = num1;

		v.push_back(num2);
		if (num2 < minCycle) minCycle = num2;

		if (num3) {
			//checking next int at end of loop
			v.push_back(num3);
			if (num3 < minCycle) minCycle = num3;

			while (cin >> num3, num3 != 0) {
				v.push_back(num3);
				if (num3 < minCycle) minCycle = num3;
			}
		}

		int ans = get_res();
		//print 5 hour failure message
		if (ans == -1) cout << "Signals fail to synchronise in 5 hours\n";
		//get time and print out timeframe
		else {
			int h, m;
			h = ans / 3600;
			ans %= 3600;

			m = ans / 60;
			ans %= 60;

			cout.fill('0');
			cout << setw(2) << h << ':'<< setw(2) << m << ':'<< setw(2) << ans << '\n';
		}
	}

	return 0;
}

int get_res()
{
	int time = minCycle * 2;
	int sz = v.size();
	int cnt = 0;
	//find answer in 1-18000 s 
	while (cnt < sz && time <= 18000) {
		for (cnt = 0; cnt < sz; ++cnt) {
			if (!(time % (v[cnt] * 2) < v[cnt] - 5)) break;
		}
		++time;
	}

	if (--time <= 18000 && cnt == sz) return time;
	else return -1;
}

