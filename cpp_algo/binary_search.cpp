#include <iostream>
#include <vector>
#include <algorithm>

int binarySearch(std::vector<int>& nums, int el){
    int left = 0;
    int right = nums.size() - 1;
    while(left <= right){
        int mid = (left + right) / 2;

        if(nums[mid] == el){
            return mid;
        }
        else if(nums[mid] < el){
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return -1;
}

int main(){
    std::vector<int> nums = {1,6,3,8,3,2,9,10};

    std::sort(nums.begin(), nums.end());

    std::cout << binarySearch(nums, 5) << std::endl;
    std::cout << binarySearch(nums, 6) << std::endl;

    return 0;
}