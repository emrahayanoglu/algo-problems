#include <iostream>
#include <vector>

int findPeakElement(std::vector<int>& nums){
    for(int i = 0; i < nums.size() - 1; i++)
    {
        if(nums[i] > nums[i+1]){
            return i;
        }
    }
    
    return nums.size() - 1;
}

int main(){
    std::vector<int> nums = {2,1,2};
    std::cout << findPeakElement(nums) << std::endl;
    
    std::vector<int> nums1 = {1,1,2,1};
    std::cout << findPeakElement(nums1) << std::endl;
    
    return 0;
}