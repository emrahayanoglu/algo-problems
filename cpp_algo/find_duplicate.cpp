#include <iostream>
#include <vector>
#include <set>

int findDuplicate(std::vector<int>& nums){
    std::set<int> checker;
    
    for(auto it: nums){
        auto it_checker = checker.find(it);
        if(it_checker != checker.end()){
            return it;    
        }
        checker.insert(it);
    }
}

int findDuplicate(int nums[], int length){
    
    for(int i = 0; i < length; i++){
        if(nums[abs(nums[i]) - 1] < 0){
            return nums[i];
        }
        nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];
    }
    
    return -1;
}



int main(){
    std::vector<int> nums = {2,1,2};
    int arrayNums[] = {2,1,2};
    std::cout << findDuplicate(nums) << std::endl;
    std::cout << findDuplicate(arrayNums, 3) << std::endl;
    
    return 0;
}