#include <iostream>
#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class solution{
    public:
        void swap(int &a,int &b){
            int temp;
            temp = a;
            a = b;
            b = temp;
        }
        void sort(int arr[],int len){
            int begin = 0;
            int end = len - 1;
            while(begin < end){
                int max = begin;
                int min = begin;
                for(int i = begin ;i <= end;i++){
                    if(arr[i] >= arr[max]){
                        max = i;
                    }
                    if(arr[i] <= arr[min]){
                        min = i;
                    }
                }
                swap(arr[min],arr[begin]);
                if(max == begin){
                    max = min;
                }
                swap(arr[max],arr[end]);
                begin++;
                end--;
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