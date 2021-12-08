#include <iostream>
#include<ctime>
#include <stack>
#include <queue>
#include <iostream>
#include <vector>
#include <list>
using namespace std;
void insert(list<int>& bucket,int val)
{
    auto iter = bucket.begin();
    while(iter != bucket.end() && val >= *iter) ++iter;
    bucket.insert(iter,val);
}

void BS(vector<int>& arr)
{
    int len = arr.size();
    if(len <= 1)
        return;
    int min = arr[0],max = min;
    for(int i=1;i<len;++i)
    {
        if(min>arr[i]) min = arr[i];
        if(max<arr[i]) max = arr[i];
    }
    int k = 10;
    int bucketsNum = (max - min)/k + 1;
    vector<list<int>> buckets(bucketsNum);
    for(int i=0;i<len;++i)
    {
        int value = arr[i];
        insert(buckets[(value-min)/k],value);
    }
    int index = 0;
    for(int i=0;i<bucketsNum;++i)
    {
        if(buckets[i].size())
        {
            for(auto& value:buckets[i])
                arr[index++] = value;
        }
    }
}
int main()
{
    vector<int> A={3, 17, 5, 41, 4, 1, 2, 9, 7, 10};
     clock_t startTime,endTime;
    startTime = clock();//计时开始
    BS(A);
    for(auto value:A)
        cout<<value<<" ";
    cout<<endl;
    endTime = clock();//计时结束
    cout << "The run time is: " <<(double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;

    return 0;
}
