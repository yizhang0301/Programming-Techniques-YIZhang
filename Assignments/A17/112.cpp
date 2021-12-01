#include <iostream>
using namespace std;
int n;
bool check;
char x;
void D(int sum,int &root) {
 
	cin >> x;
	bool sign = false;
	int num = 0;
 
	int L = 1;
	int R = 1;	
	if(x == '-') {
		sign = true;
		cin >> x;
	}
 
	while( x >= '0' && x <= '9') {
		num = num*10 + (x - '0');
		root = 0;
		cin >> x;
	}
 
	if(sign == true) {
		num = -num;
	}
	if( x == '(') {
		D(sum+num,L);
		cin >> x;
	}
	if( x == '(') {
		D(sum+num,R);
		cin >> x;
	}
	if( x == ')' && L==1 && R==1 && root==false && n==sum+num) {
		check = true;
	}
}
int main() {
	char x;
	while(cin >> n) {
		check = false;
		cin >> x;
		int root = 1;
		D(0,root);
		if(check) {
			cout<<"yes"<<endl;
		}
		else {
			cout<<"no"<<endl;
		}
	}
	return 0;
}
