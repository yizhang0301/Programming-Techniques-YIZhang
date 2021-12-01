#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int main() {
int i =2;
//0010
int L = ~i;
cout << L << endl;
L = ~L;
cout << L;


int arr[5] = {1,2,3,4,5};
printf("arr is: ");
for(int i = 0; i < 5; i++){
  printf("%d\t",arr[i]);
}
memset(arr, 0, sizeof arr);
printf("arr change: ");
for(int i = 0; i < 5; i++){
  printf("%d\t",arr[i]);
}
memset(arr, -1, sizeof arr);
printf("arr change1: ");
for(int i = 0; i < 5; i++){
  printf("%d\t",arr[i]);
}
memset(arr, 1, sizeof arr);
printf("arr change2: ");
for(int i = 0; i < 5; i++){
  printf("%d\t",arr[i]);
}
} 