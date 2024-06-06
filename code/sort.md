## 冒泡排序
```
#include <iostream>
#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class solution{
    public:
        void qsort(int arr[],int l,int r){
            for(int i = 0;i < r;i++){
                for(int j = 0;j < r - 1 - i;j++){
                    if(arr[j] > arr[j + 1]){
                        swap(arr[j],arr[j + 1]);
                    }
                }
            }
        }
};

int main(){
    int arr[] = {10,5,30,14,5,30,3};
    int len = sizeof(arr)/sizeof(arr[0]);
    solution as;
    as.qsort(arr,0,len);
    for(int i = 0;i < len;i++){
        cout << arr[i] << " ";
    }
    return 0;
}
```

## 选择排序

```
#include <iostream>
#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class solution{
    public:
        void qsort(int arr[],int l,int r){
            for(int i = 0;i < r;i++){
                int temp = i;
                for(int j = i + 1;j < r;j++){
                    if(arr[j] < arr[i]){
                        temp = j;
                    }
                }
                if(temp != i){
                    swap(arr[i],arr[temp]);
                }
            }
        }
};

int main(){
    int arr[] = {10,5,30,14,5,30,3};
    int len = sizeof(arr)/sizeof(arr[0]);
    solution as;
    as.qsort(arr,0,len);
    for(int i = 0;i < len;i++){
        cout << arr[i] << " ";
    }
    return 0;
}
```

## 插入排序

```
#include <iostream>
#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class solution{
    public:
        void qsort(int arr[],int l,int r){
            for(int i = 0;i < r - 1;i++){
                int key = arr[i + 1];
                int j = i;
                while(j >= 0 && key <= arr[j]){
                    arr[j + 1] = arr[j];
                    --j;
                }
                arr[j + 1] = key;
                
            }
        }
};

int main(){
    int arr[] = {10,5,30,14,5,30,3};
    int len = sizeof(arr)/sizeof(arr[0]);
    solution as;
    as.qsort(arr,0,len);
    for(int i = 0;i < len;i++){
        cout << arr[i] << " ";
    }
    return 0;
}
```

## 希尔排序
```
#include <iostream>
#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class solution{
    public:
        void qsort(int arr[],int l,int r){
            int gap = r;
            while(gap > 1){
                gap = gap / 3 + 1;
                for(int i = 0;i < r - gap;i++){
                    int j = i;
                    int temp = arr[i + gap];
                    while(j >= 0 && temp <= arr[j]){
                        arr[j + gap] = arr[j];
                        j = j - gap;
                    }
                    arr[j + gap] = temp;
                }
            }
        }
};

int main(){
    int arr[] = {10,5,30,14,5,30,3};
    int len = sizeof(arr)/sizeof(arr[0]);
    solution as;
    as.qsort(arr,0,len);
    for(int i = 0;i < len;i++){
        cout << arr[i] << " ";
    }
    return 0;
}
```

## 快速排序

```
#include <iostream>
#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class solution{
    public:
        void qsort(int arr[],int l,int r){
            int st = arr[l];
            int left = l;
            int right  = r;
            while(l < r){
                while(l < r && arr[right] >= st){
                    --right;
                }
                arr[left] = arr[right];
                while(l < r && arr[left] <= st){
                    ++left;
                }
                arr[right] = arr[left];
            }
            arr[left] = st;
            qsort(arr,l,left - 1);
            qsort(arr,left + 1,r);
        }
};

int main(){
    int arr[] = {10,5,30,14,5,30,3};
    int len = sizeof(arr)/sizeof(arr[0]);
    solution as;
    as.qsort(arr,0,len);
    for(int i = 0;i < len;i++){
        cout << arr[i] << " ";
    }
    return 0;
}

```

### 堆排序
堆排序（Heapsort）是指利用堆这种数据结构所设计的一种排序算法。堆积是一个近似完全二叉树的结构，并同时满足堆积的性质：即子结点的键值或索引总是小于（或者大于）它的父节点。堆排序可以说是一种利用堆的概念来排序的选择排序。分为两种方法：

    大顶堆：每个节点的值都大于或等于其子节点的值，在堆排序算法中用于升序排列；
    小顶堆：每个节点的值都小于或等于其子节点的值，在堆排序算法中用于降序排列；

堆排序的平均时间复杂度为 Ο(nlogn)。

堆排序分为两个主要步骤：建堆（Build Heap）和堆调整排序（Heapify and Sort）。
建堆是将数组转化为一个最大堆（或最小堆），堆调整排序则是通过不断取出堆顶元素（即当前最大或最小元素）并与末尾元素交换，然后重新调整堆，直到整个数组有序。
```
#include <iostream>
#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class solution{
    public:
        void qsort(int arr[],int l,int r){
            int dad = l;
            int son = 2 * dad + 1;
            while(son <= r){
                if(son + 1 <= r && arr[son] < arr[son + 1]){
                    ++son;
                }
                if(son <= r && arr[dad] >= arr[son]){
                    return;
                }else{
                    swap(arr[son],arr[dad]);
                    dad = son;
                    son = 2 *dad + 1;
                }
            }

        }
        void firstsort(int arr[],int len){
            for(int i = len / 2 - 1;i >= 0;i--){
                qsort(arr,i,len - 1);
            }
            for(int i = len - 1;i > 0;i--){
                swap(arr[0],arr[i]);
                qsort(arr,0,i-1);
            }
        }
};

int main(){
    int arr[] = {10,5,30,14,5,30,3};
    int len = sizeof(arr)/sizeof(arr[0]);
    solution as;
    as.firstsort(arr,len);
    for(int i = 0;i < len;i++){
        cout << arr[i] << " ";
    }
    return 0;
}
```

## 归并排序
归并排序是用分治思想，分治模式在每一层递归上有三个步骤：
● 分解（Divide）：将n个元素分成个含n/2个元素的子序列。
● 解决（Conquer）：用合并排序法对两个子序列递归的排序。
● 合并（Combine）：合并两个已排序的子序列已得到排序结果。

```
class solution{
    public:
        void qsort(int arr [],int l,int mid ,int r){
            vector<int> temp(r - l + 1);
            int i = l;
            int j = mid + 1;
            int k = 0;
            while(j <= r && i <= mid){
                if(arr[i] <= arr[j]){
                    temp[k++] = arr[i++];
                }else{
                    temp[k++] = arr[j++];
                }
            }

            while(i <= mid){
                temp[k++] = arr[i++];
            }
            while(j <= r){
                temp[k++] = arr[j++];
            }

            for(int i  = 0;i < temp.size();i++){
                arr[l + i] = temp[i];
            }
        }

        void heapsort(int arr[],int left,int right){
            if(left < right){
                int mid = left + (right - left) / 2;
                heapsort(arr,left,mid);
                heapsort(arr,mid + 1,right);
                qsort(arr,left,mid,right);
            }else{
                return;
            }

        }
};

int main(){
    int arr[] = {10,5,30,14,5,30,3};
    int len = sizeof(arr)/sizeof(arr[0]);
    solution as;
    as.heapsort(arr,0,len - 1);
    for(int i = 0;i < len;i++){
        cout << arr[i] << " ";
    }
    return 0;
}
```
