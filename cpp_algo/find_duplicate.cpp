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

int main(){
    std::vector<int> nums = {2,1,2};
    
    std::cout << findDuplicate(nums) << std::endl;
    
    return 0;
}