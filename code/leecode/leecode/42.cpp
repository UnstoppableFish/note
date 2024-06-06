#include<vector>
#include<stdio.h>
#include<string>
#include<unordered_map>
#include<algorithm>
#include<stack>
using namespace std;

//动态规划
// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int n = height.size();
//         if(n == 0){
//             return 0;
//         }
//         int left[n];
//         int right[n];
        
//         left[0] = height[0];
//         for(int i = 1;i < n;i++){
//             left[i] = max(left[i - 1],height[i]);
//         }

//         right[n - 1] =height[n - 1];
//         for(int j = n-2;j >= 0;j--){
//             right[j] = max(right[j + 1],height[j]);
//         }

//         int ans = 0;
//         for(int i = 0;i < n;i++){
//             ans += min(left[i],right[i]) - height[i];
//         }
//         return ans;
//     }

// };

//双指针
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n == 0){
            return 0;
        }
        int left = 0;
        int right = n - 1;
        int leftmax = 0;
        int rightmax = 0;
        int ans = 0;
        while(left < right){
            leftmax = max(leftmax,height[left]);
            rightmax = max(rightmax,height[right]);
            if(height[left] < height[right]){
                ans += leftmax - height[left];
                left++;
            }
            else{
                ans += rightmax - height[right];
                right--;
            }
        }
        return ans;
    }
};