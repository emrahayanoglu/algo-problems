#include <iostream>
#include <utility>
#include <vector>

std::pair<int, int> searchIn2dII(std::vector<std::vector<int>>& nums,  int el){
    if(nums.size() == 0)
        return std::make_pair(-1,-1);
    
    if(nums[0].size() == 0)
        return std::make_pair(-1,-1);
        
        
    int rows = nums.size();
    int cols = nums[0].size();
    
    //Binary Search in 2d Array
    int i = rows - 1;
    int j = 0;
    
    while(i >= 0 && j < cols){
        if(nums[i][j] < el){
            j++;
        }
        else if(nums[i][j] > el){
            i--;
        }
        else{
            return std::make_pair(i, j);
        }
    }
    
    return std::make_pair(-1,-1);
}

int main(){
    std::vector<std::vector<int>> nums = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    
    auto res = searchIn2dII(nums, 6);
    std::cout << res.first << " " << res.second << std::endl;
    
    res = searchIn2dII(nums, 15);
    std::cout << res.first << " " << res.second << std::endl;
    
    res = searchIn2dII(nums, 35);
    std::cout << res.first << " " << res.second << std::endl;
    
    std::vector<std::vector<int>> nums2;
    
    res = searchIn2dII(nums2, 50);
    std::cout << res.first << " " << res.second << std::endl;
    
    return 0;
}