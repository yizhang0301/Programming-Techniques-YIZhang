#include<iostream>
using namespace std;
int gsum(int x);

int main()
{
    int x,max,y,i,t,min1,max1;
    while(cin>>x>>y)
    {
        if(x>y)
            max1=x,min1=y;
        else
            min1=x,max1=y;
        max=0;
        for(i=min1;i<=max1;i++)
        {
            t=gsum(i);
            max=(t>max)?t:max;
        }
        cout<<x<<" "<<y<<" "<<max<<endl;
    }
    return 0;

}
int gsum(int x)
{
    int i=1;
    while(x!=1)
    {
        if(x%2)
            x=3*x+1;
        else
            x/=2;
        i++;
    }
    return i;
}