#include<iostream>
#include"include/function.hpp"
using namespace std;

int main()
{
    int len;
    cout << "len: ";
    cin >> len;

    int* arr = new int[len]; // 动态分配数组大小

    cout << "array,splited by space: ";
    for (int i = 0; i < len; i++) {
        cin >> arr[i];
    }

    bubbleSort(arr, len);

    cout << "Sorted array: ";
    for (int i = 0; i < len; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr; // 别忘了释放动态数组
    return 0;
}
