#include <iostream>
#include <utility>
#include <vector>

int firstBadVersion(std::vector<bool>& versions){
    if(versions.size() == 0)
        return -1;
        
    if(!versions[0])
        return 0;
    
    //Special Binary Search
    int left = 0;
    int right = versions.size() - 1;
    
    while(left <= right){
        int mid = (left + right) / 2;
        
        if(versions[mid])
        {
            left = mid + 1;   
        }
        else
        {
            if((mid - 1) >= 0 && versions[mid-1])
                return mid;
            right = mid - 1;               
        }
    }
    
    return -1;
}

int main(){
    std::vector<bool> nums = {true,true,true,true,false,false,false};
    std::cout << firstBadVersion(nums) << std::endl;
    
    std::vector<bool> nums2;
    std::cout << firstBadVersion(nums2) << std::endl;
    
    std::vector<bool> nums3 = {true,false};
    std::cout << firstBadVersion(nums3) << std::endl;
    
    std::vector<bool> nums4 = {false,false};
    std::cout << firstBadVersion(nums4) << std::endl;
    
    std::vector<bool> nums5 = {true,true,false,false,false};
    std::cout << firstBadVersion(nums5) << std::endl;
    
    std::vector<bool> nums6 = {true,true,true,true,false};
    std::cout << firstBadVersion(nums6) << std::endl;
    
    std::vector<bool> nums7 = {true,true,true,true,true};
    std::cout << firstBadVersion(nums7) << std::endl;
    
    return 0;
}