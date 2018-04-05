#include <iostream>
#include <utility>
#include <vector>

int findMinInRotatedSorted(std::vector<int>& nums){
    if(nums.size() == 0)
        return -1;
    
    //Binary Search in Sorted Rotated Array
    //Implemented using following idea: One half has to be sorted
    int left = 0;
    int right = nums.size() - 1;
    
    while(left <= right){
        int mid = (left + right) / 2;
        
        if(nums[left] <= nums[right])
            return left;
            
        if(nums[left] <= nums[mid])
            left = mid + 1;
        else
            right = mid;
    }
    
    return -1;
}

int main(){
    std::vector<int> nums = {4,5,6,7,8,9,10,11,12,1,2,3};
    
    std::cout << findMinInRotatedSorted(nums) << std::endl;
    
    std::vector<int> nums2;
    std::cout << findMinInRotatedSorted(nums2) << std::endl;
    
    std::vector<int> nums3 = {1,3};
    std::cout << findMinInRotatedSorted(nums3) << std::endl;
    
    std::vector<int> nums4 = {3,1};
    std::cout << findMinInRotatedSorted(nums4) << std::endl;
    
    return 0;
}