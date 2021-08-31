/**
* YI　ZHANG
* CMPS 4883
* 2021/8/31
*/

#include <iostream>
#define endl "\n"

using namespace std;

int main() {
	int B = 0, A = 0;
	while (cin >> A >> B) {
	long long num = B - A;		
		if (A > B)
        {
            num = A - B;
            cout << num << endl;
        }
        else
        {
            num = B - A;
            cout << num << endl;
        }
	   
	}
	return 0;
}
