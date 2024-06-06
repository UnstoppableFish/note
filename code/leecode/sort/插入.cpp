#include <iostream>
#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class solution{
    public:
        void sort(int arr[],int len){
            for(int i = 0;i < len - 1;i++){
                int end = i;
                int temp = arr[end + 1];
                while(end >= 0){
                    if(temp <= arr[end]){
                        arr[end + 1] = arr[end];
                        end--;
                    }
                    else{
                        break;
                    }
                }
                arr[end + 1] = temp;
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