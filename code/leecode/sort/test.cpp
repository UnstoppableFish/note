#include <iostream>
#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class solution{
    public:
        void qsort(int arr [],int len){
            int k = len;
            while(k > 1){
                k = k / 3 + 1;
                for(int i = 0;i < len - k;i++){
                    int key = arr[i + k];
                    int j = i;
                    while(j >= 0 && arr[j] >= key){
                        arr[j + k] = arr[j];
                        j -= k;
                    }
                    arr[j + k] = key;
                }
            }

            
            
        }
};

int main(){
    int arr[] = {10,5,30,14,5,30,3};
    int len = sizeof(arr)/sizeof(arr[0]);
    solution as;
    as.qsort(arr,len);
    for(int i = 0;i < len;i++){
        cout << arr[i] << " ";
    }
    return 0;
}