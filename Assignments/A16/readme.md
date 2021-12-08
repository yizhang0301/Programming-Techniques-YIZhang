

## Sort 
Calculate the approximate time of different sorts, run 10 times for each type Calculate the average time
Use clock() to calculate the running time and output:
```cpp
clock_t startTime,endTime;
startTime = clock();//time start

********
endTime = clock();//time end
cout << "The run time is: "<<(double)(endTime-startTime) / CLOCKS_PER_SEC << "s" << endl;
```
## Time Difference
size 10  : {3, 17, 5, 41, 4, 1, 2, 9, 7, 10}
|   #   | sort |avg sec(5 times) |
| :---: | ----------- | ---------------------- |
|1| qucik sort(int)|  6.6e-05s |
|2| count sort(int)|  3.8e-05s |
|3| Radix Sort(int)|   7e-05s  |
|4| Heap Sort(int) |   7.1e-05s|
|5| bucket sort(int)| 6.7e-05s |



|   #   | file |
| :---: |---------------------- |
|1|[reandme](https://github.com/yizhang0301/4883-Programming-Techniques-YIZhang/blob/main/Assignments/A16/readme.md)|
|2|[qucik sort](https://github.com/yizhang0301/4883-Programming-Techniques-YIZhang/blob/main/Assignments/A16/qiucksort.cpp)|
|3|[count sort](https://github.com/yizhang0301/4883-Programming-Techniques-YIZhang/blob/main/Assignments/A16/countsort.cpp)|
|4|[Radix Sort](https://github.com/yizhang0301/4883-Programming-Techniques-YIZhang/blob/main/Assignments/A16/Radix%20Sort.cpp)|
|5|[bucket sort](https://github.com/yizhang0301/4883-Programming-Techniques-YIZhang/blob/main/Assignments/A16/bucketsort.cpp)|
|6|[Heap Sort](https://github.com/yizhang0301/4883-Programming-Techniques-YIZhang/blob/main/Assignments/A16/heapsort.cpp)|
