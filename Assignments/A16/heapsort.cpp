#include <iostream>
#include<ctime>
#include <stack>
#include <queue>
using namespace std;
void HeapAdjust (int A[], int length, int k)
{
	int tmp = A[k];
	int i=2*k+1;
	while (i<length) {
		if (i+1<length && A[i]>A[i+1]) //选取最小的结点位置
			++i;
		if (tmp < A[i]) //不用交换
			break;
		A[k] = A[i]; //交换值
		k = i; //继续查找
		i = 2*k+1;
	}
	A[k] = tmp;
}
 
void HeapSort (int A[], int length)
{
	if (A == NULL || length <= 0)
		return;
	for (int i=length/2-1; i>=0; --i) {
		HeapAdjust(A, length, i); //从第二层开始建堆
	}
 
	for (int i=length-1; i>=0; --i) {
		swap(A[0], A[i]);
		HeapAdjust(A, i, 0); //从顶点开始建堆, 忽略最后一个
	}
 
	return;
}
 
int main (void)
{
	int A[] = {3, 17, 5, 41, 4, 1, 2, 9, 7, 10};
  clock_t startTime,endTime;
  startTime = clock();//计时开始
	
	HeapSort(A, 10);
	for (int i=0; i<10; ++i) {
		cout << A[i] << " ";
	}
 
	cout << endl;
  endTime = clock();//计时结束
  cout << "The run time is: " <<(double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
	return 0;
}
