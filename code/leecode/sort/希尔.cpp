#include <iostream>
#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class solution{
    public:
        void sort(int arr[],int len){
            int gap = len;
            while(gap > 1){
                gap = gap / 3 + 1;
                for(int i = 0;i < len - gap;i++){
                    int end = i;
                    int temp = arr[end + gap];
                    while(end >= 0){
                        if(temp <= arr[end]){
                            arr[end + gap] = arr[end];
                            end -= gap;
                        }
                        else{
                            break;
                        }
                    }
                    arr[gap + end] = temp;
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