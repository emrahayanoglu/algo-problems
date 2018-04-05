#include <iostream>
#include <utility>
#include <vector>

int searchInRotatedSorted(std::vector<int>& nums, int el){
    if(nums.size() == 0)
        return -1;
    
    //Binary Search in Sorted Rotated Array
    //Implemented using following idea: One half has to be sorted
    int left = 0;
    int right = nums.size() - 1;
    
    while(left <= right){
        int mid = (left + right) / 2;
        if(nums[mid] == el)
        {
            return mid;
        }
        else if(nums[left] <= nums[mid]){
            //Sorted
            if(el >= nums[left] && el < nums[mid]){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        else
        {
            if(el >= nums[mid] && el <= nums[right]){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
    }
    
    return -1;
}

int main(){
    std::vector<int> nums = {4,5,6,7,8,9,10,11,12,1,2,3};
    
    std::cout << searchInRotatedSorted(nums, 6) << std::endl;
    std::cout << searchInRotatedSorted(nums, 14) << std::endl;
    std::cout << searchInRotatedSorted(nums, 2) << std::endl;
    
    std::cout << searchInRotatedSorted(nums, 6) << std::endl;
    std::cout << searchInRotatedSorted(nums, 4) << std::endl;
    std::cout << searchInRotatedSorted(nums, 3) << std::endl;
    
    std::vector<int> nums2;
    std::cout << searchInRotatedSorted(nums2, 14) << std::endl;
    
    std::vector<int> nums3 = {1,3};
    std::cout << searchInRotatedSorted(nums3, 1) << std::endl;
    std::cout << searchInRotatedSorted(nums3, 3) << std::endl;
    
    std::vector<int> nums4 = {3,1};
    std::cout << searchInRotatedSorted(nums4, 1) << std::endl;
    std::cout << searchInRotatedSorted(nums4, 3) << std::endl;
    
    return 0;
}