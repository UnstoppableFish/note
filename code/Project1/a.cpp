#include <iostream>
#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<int>arr = { 10,5,5,30,3 };
void qsort( int l, int r) {
    if (l > r) return;
    int left = l;
    int right = r;
    int po = arr[l];
    while (left < right) {
        while (left < right && po <= arr[right]) {
            right--;
        }
        arr[left] = arr[right];
        while (left < right && po >= arr[left]) {
            left++;
        }
        arr[right] = arr[left];
    }
    arr[left] = po;
    qsort( l, left - 1);
    qsort(left + 1, r);
}
int main() {
    
    
    qsort(0, arr.size()-1);
    for (int i = 0; i < arr.size()-1; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}