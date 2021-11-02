#include <iostream>
#include <cmath>
#include <string>
using namespace std;
  int main()
  {
   int a,b,sum,i,n;
   cin >> n;
   for (int i = 1;i <=n;i++)
      {
       sum=0;
       cin >> a >> b;
      for(;a<=b;a++)
         {
          if(a%2==1)
            sum+=a;
         }
      cout << "Case "<< i << ": "<< sum << endl;
     } 
  return 0;
 }