/**
* YI　ZHANG
* CMPS 4883
* 2021/8/31
*/
#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        vector<int>  a(3000);
        vector<int>  b(3000);
        cin>>a[0];
        for(int i=1;i<n;i++)
        {
            cin>>a[i];
            b[i]=abs(a[i]-a[i-1]);
        }
        sort(b.begin()+1,b.begin()+n);
        int sum=0;
        for(int j=1;j<n;j++)
        {
            if(b[j]==j)
            sum++;
        }
        if(sum==n-1)
            cout<<"Jolly"<<endl;
        else
            cout<<"Not jolly"<<endl;
    }
    return 0;
}
