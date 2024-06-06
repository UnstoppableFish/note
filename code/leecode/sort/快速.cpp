#include <iostream>

using namespace std;
int arr[7] = {30,5,30,14,5,30,3};
void qsort(int left,int right){
    if (left > right) return;
            int a = arr[left];
            int l = left;
            int r = right;
            while(l < r){
                while (l < r && arr[r] >= a) {
                    r--;
                }
                while(l < r && arr[l] <= a){
                    l++;
                }
                if(l < r){
                    swap(arr[l],arr[r]);
                }
            }
            swap(arr[left],arr[l]);
            qsort(left,r - 1);
            qsort(r + 1,right);
        }


int main(){
    int len = sizeof(arr)/sizeof(arr[0]);
    qsort(0,6);
    for(int i = 0;i < len;i++){
        cout << arr[i] << " ";
    }
    return 0;
}