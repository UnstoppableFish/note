#include <iostream>
#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class solution{
    public:
        void sort(int arr[],int len){
            for(int i = 0;i < len;i++)//总共需要拍多少次
            {
                for(int j = 0;j < len - i - 1;j++)//最大的数已经放在了最后，所以j < len - i - 1，-i是减少排序次数，-1是因为防止溢出
                {
                    if(arr[j] > arr[j+1]){
                        swap(arr[j],arr[j+1]);
                    }
                }
            }
        }
};

int main(){
    int arr[] = {10,5,30,14,5,30,3};
    int len = sizeof(arr)/sizeof(arr[0]);
    solution as;
    as.sort(arr,len);
    for(int i = 0;i < len;i++){
        cout << arr[i] << " ";
    }
    return 0;
}