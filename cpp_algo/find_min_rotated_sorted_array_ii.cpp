#include <iostream>
#include <utility>
#include <vector>

int findMinInRotatedSortedII(std::vector<int>& nums){
    if(nums.size() == 0)
        return -1;
    
    //Binary Search in Sorted Rotated Array
    //Implemented using following idea: One half has to be sorted
    int left = 0;
    int right = nums.size() - 1;
    
    while(left <= right){
        //Duplicate value but different indices case
        while(nums[left]==nums[right] && left != right){
            left++;
        }
        
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
    
    std::cout << findMinInRotatedSortedII(nums) << std::endl;
    
    std::vector<int> nums2;
    std::cout << findMinInRotatedSortedII(nums2) << std::endl;
    
    std::vector<int> nums3 = {1,3};
    std::cout << findMinInRotatedSortedII(nums3) << std::endl;
    
    std::vector<int> nums4 = {3,1};
    std::cout << findMinInRotatedSortedII(nums4) << std::endl;
    
    std::vector<int> nums5 = {1,3,1,1,1};
    std::cout << findMinInRotatedSortedII(nums5) << std::endl;
    
    std::vector<int> nums6 = {5,6,7,1,1,2,2,2,3,3,3,4,4,4};
    std::cout << findMinInRotatedSortedII(nums6) << std::endl;
    
    std::vector<int> nums7 = {3,1,3};
    std::cout << findMinInRotatedSortedII(nums7) << std::endl;
    
    return 0;
}