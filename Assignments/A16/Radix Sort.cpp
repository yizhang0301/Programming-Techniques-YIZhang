#include <iostream>
#include<ctime>
using namespace std;

int max(int A[], int n) 
{
    int maxData = A[0];
    for (int i = 1; i < n; ++i)
    {
        if (maxData < A[i])
            maxData = A[i];
    }
    int cout = 1;
    int p = 10;
    while (maxData >= p)
    {
        maxData /= 10;
        ++cout;
    }
    return cout;
    }
void radixsort(int A[], int n) //基数排序
{
    int cout= max(A, n);
    int *tmp = new int[n];
    int *count = new int[10]; //计数器
    int i, j, k;
    int radix = 1;
    for(i = 1; i <= 10; i++) 
    {
        for(j = 0; j < 10; j++)
            count[j] = 0; 
        for(j = 0; j < n; j++)
        {
            k = (A[j] / radix) % 10; 
            count[k]++;
        }
        for(j = 1; j < 10; j++)
            count[j] = count[j - 1] + count[j]; 
        for(j = n - 1; j >= 0; j--) 
        {
            k = (A[j] / radix) % 10;
            tmp[count[k] - 1] = A[j];
            count[k]--;
        }
        for(j = 0; j < n; j++) 
            A[j] = tmp[j];
        radix = radix * 10;
    }
    delete []tmp;
    delete []count;
}

int main()
{

    int i;
    int A[10]={3, 17, 5, 41, 4, 1, 2, 9, 7, 10};
    clock_t startTime,endTime;
    startTime = clock();//计时开始
    max(A,10);
    radixsort(A,10);
    for(i=0;i<10;i++)
    cout<<A[i]<<"  ";
    cout<<endl;
    endTime = clock();//计时结束
    cout << "The run time is: " <<(double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
}