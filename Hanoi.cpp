#include<iostream>
#include"include/function.hpp"
int main()
{
    int arr[8] = {1,5,4,8,7,6,3,2};
    int len = sizeof(arr)/sizeof(arr[0]);

    bubbleSort(arr,len);
    for(int i = 0; i < len ; i++)
    {
        cout<<arr[i]<< " ";
    }
    cout<<endl;

    return 0;

}