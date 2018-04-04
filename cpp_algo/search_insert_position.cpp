#include <iostream>
#include <vector>

int getInsertPosition(std::vector<int>& nums, int el){
    int left = 0;
    int right = nums.size() - 1;
    
    while(left <= right){
        int mid = (left + right) / 2;
        
        if(nums[mid] == el){
            return mid;
        }
        else if(nums[mid] > el){
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    
    return left;
}

int main(){
    std::vector<int> nums = {2,3,5,7,8,9,11,13,15,17,18,20};
    
    std::cout << getInsertPosition(nums, 6) << std::endl;
    std::cout << getInsertPosition(nums, 13) << std::endl;
    std::cout << getInsertPosition(nums, 16) << std::endl;
    
    return 0;
}