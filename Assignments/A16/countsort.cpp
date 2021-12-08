#include <iostream>
#include <cstring>
#include<ctime>
using namespace std;

bool ctsort(int A[],int size){
    if(NULL==A||size<0)
        return false;
    int k = A[0];
    for(int i=1;i<size;i++)
        if(A[i]>k)k=A[i];
    k++;

    int* counts = new int[k];
    int* tmp = new int[size];//存放排序的结果
 
    for(int i=0;i<k;i++)
        counts[i]=0;
 
  
    for(int i=0;i<size;i++)
        counts[A[i]] = counts[A[i]]+1;

    for(int i=1;i<k;i++)
        counts[i] = counts[i] + counts[i-1];

    for(int i=size-1;i>=0;i--){

        tmp[counts[A[i]]-1] = A[i];
        counts[A[i]] = counts[A[i]] -1;
    }
    memcpy(A,tmp,size*sizeof(int));
    delete[] counts;
    delete[] tmp;
    return true;
}
 
int main(){
   clock_t startTime,endTime;
     startTime = clock();//计时开始
    int A[] = {3, 17, 5, 41, 4, 1, 2, 9, 7, 10};
    ctsort(A,10);
    
    for(int i=0;i<10;i++)
        cout<<A[i]<<" ";
        endTime = clock();//计时结束
    cout << "The run time is: " <<(double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
}
