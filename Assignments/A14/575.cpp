#include <iostream>
#include <cmath>
#include <string>
using namespace std;
int main() {
	string s;
	while(cin >> s && s[0] != '0') {
		int x = 0;
		for(int i = 1; i <= s.size(); i++) {
			x = x + (s[s.size() - i] - '0') * ((1 << i) - 1);
		}
		cout << x << endl;
	}
	return 0;
}
