#include <iostream>
#include <utility>
#include <vector>

std::pair<int,int> searchForRange(std::vector<int>& nums, int el){
    if(nums.size() == 0)
        return std::make_pair(-1,-1);
    
    int left = 0;
    int right = nums.size() - 1;
    
    while(left <= right){
        int mid = (left + right) / 2;
        
        if(nums[mid] == el){
            //Handle Duplicates
            int cur = mid;
            while(cur >= 0 && nums[cur] == el){
                cur--;
            }
            int leftFound = cur + 1;
            
            cur = mid;
            while(cur < nums.size() && nums[cur] == el){
                cur++;
            }
            
            int rightFound = cur - 1;
            
            return std::make_pair(leftFound,rightFound);
        }
        else if(nums[mid] > el){
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    
    return std::make_pair(-1,-1);
}

int main(){
    std::vector<int> nums = {5,7,7,8,8,10};
    auto res = searchForRange(nums, 8);
    std::cout << res.first << "-" << res.second << std::endl;
    
    return 0;
}