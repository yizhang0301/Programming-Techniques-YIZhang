#include <iostream>
#include <vector>
#include<ctime>
using namespace std;

int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[low];
    int i = low + 1, j = high;
    while (true) {
        while (i < high && arr[i] < pivot) i++;
        while (j > low && arr[j] > pivot) j--;
        if (i >= j) break;
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
    swap(arr[low], arr[j]);
    return j;
}

void quicksort(vector<int> &arr, int low, int high) {
    if (low >= high) return;
    int position = partition(arr, low, high);
    quicksort(arr, low, position - 1);
    quicksort(arr, position + 1, high);
}

void sort(vector<int> &arr) {
    quicksort(arr, 0, arr.size() - 1);
}

// 测试
int main() {
    clock_t startTime,endTime;
    startTime = clock();
    vector<int> arr = {3, 17, 5, 41, 4, 1, 2, 9, 7, 10};
    for (int n : arr) cout << n << " ";
    cout << endl;

    sort(arr);

    for (int n : arr) cout << n << " ";
    endTime = clock();//计时结束
    cout << "The run time is: " <<(double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
   
}