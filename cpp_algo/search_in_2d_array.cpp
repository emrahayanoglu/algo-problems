#include <iostream>
#include <utility>
#include <vector>

std::pair<int, int> searchIn2d(std::vector<std::vector<int>>& nums, int rows, int cols, int el){
    if(nums.size() == 0)
        return std::make_pair(-1,-1);
    
    if(nums[0].size() == 0)
        return std::make_pair(-1,-1);
    
    //Binary Search in 2d Array
    int left = 0;
    int right = (rows*cols) - 1;
    
    while(left <= right){
        int mid = (left + right) / 2;
        int midX = mid / cols;
        int midY = mid % cols;
        if(nums[midX][midY] < el){
            left = mid + 1;
        }
        else if(nums[midX][midY] > el){
            right = mid - 1;
        }
        else{
            return std::make_pair(midX, midY);
        }
    }
    
    return std::make_pair(-1,-1);
}

int main(){
    std::vector<std::vector<int>> nums = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    
    auto res = searchIn2d(nums, 3, 4, 6);
    std::cout << res.first << " " << res.second << std::endl;
    
    res = searchIn2d(nums, 3, 4, 14);
    std::cout << res.first << " " << res.second << std::endl;
    
    std::vector<std::vector<int>> nums2;
    
    res = searchIn2d(nums2, 3, 4, 14);
    std::cout << res.first << " " << res.second << std::endl;
    
    return 0;
}