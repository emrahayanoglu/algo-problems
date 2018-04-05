#include <iostream>
#include <utility>
#include <vector>

bool searchInRotatedSortedII(std::vector<int>& nums, int el){
    if(nums.size() == 0)
        return false;
    
    //Binary Search in Sorted Rotated Array
    //Implemented using following idea: One half has to be sorted
    int left = 0;
    int right = nums.size() - 1;
    
    while(left <= right){
        int mid = (left + right) / 2;
        if(nums[mid] == el)
        {
            return true;
        }
        else if(nums[left] < nums[mid]){
            //Sorted
            if(el >= nums[left] && el < nums[mid]){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        else if(nums[left] > nums[mid])
        {
            if(el >= nums[mid] && el <= nums[right]){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        else
        {
            left++;
        }
    }
    
    return false;
}

int main(){
    std::vector<int> nums = {4,5,6,7,8,9,10,11,12,1,2,3};
    
    std::cout << searchInRotatedSortedII(nums, 6) << std::endl;
    std::cout << searchInRotatedSortedII(nums, 14) << std::endl;
    std::cout << searchInRotatedSortedII(nums, 2) << std::endl;
    
    std::cout << searchInRotatedSortedII(nums, 6) << std::endl;
    std::cout << searchInRotatedSortedII(nums, 4) << std::endl;
    std::cout << searchInRotatedSortedII(nums, 3) << std::endl;
    
    std::vector<int> nums2;
    std::cout << searchInRotatedSortedII(nums2, 14) << std::endl;
    
    std::vector<int> nums3 = {1,3};
    std::cout << searchInRotatedSortedII(nums3, 1) << std::endl;
    std::cout << searchInRotatedSortedII(nums3, 3) << std::endl;
    
    std::vector<int> nums4 = {1,3,1,1,1};
    std::cout << searchInRotatedSortedII(nums4, 1) << std::endl;
    std::cout << searchInRotatedSortedII(nums4, 3) << std::endl;
    
    return 0;
}