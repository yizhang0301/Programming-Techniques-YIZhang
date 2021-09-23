/**
* YI　ZHANG
* CMPS 4883
* 2021/8/31
*/
#include<map>
#include<iostream>
#include<string>
#include<cstdio>

using namespace std;
string s;
int t,num;
map<string,int> A;
map<string,int>::iterator i;
int main()
{
    scanf("%d\n",&t);
    while(t--)
    {
        num=0;
        A.clear();
        while(1)
        {
            getline(cin,s);
            if(s[0]=='\0')
                break;
            num++;
            A[s]++;
        }
        for(i=A.begin();i!=A.end();i++)
        {
            double ans=(i->second)*100.0/num;
            printf("%s %.4lf\n",i->first.c_str(),ans);
        }
        if(t)
            puts("");
    }
    return 0;
}