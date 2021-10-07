
#include <iostream>
using namespace std;
const int maxn = 10000;
int main(){
    long long int array[maxn];
    array[0] = 1;
    array[1] = 1;
    for(int i=2; i<maxn; i++){
       array[i] = array[i-1] + array[i-2];
    }
    int num;
    while( (cin >> num) && (num) )
    {
       cout << array[num] << endl;
    }
    
    return 0;

}