#include<iostream>
#include<vector>
    using namespace std;
    int searchInsert(vector<int>& nums, int target){
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;  // Avoids overflow

        if (nums[mid] == target){
            return mid;
        }
        else if (nums[mid] < target){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }

    return left;  // Correct insertion position
}

    int main(){
        vector<int> nums = {1, 3,5,6};
        int target= 2;
        int ans = searchInsert(nums,target);
        cout<<ans;
    }
