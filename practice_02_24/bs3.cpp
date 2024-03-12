#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

class Solution {
public:

    int maximumCount(vector<int>& nums) {
        int p = 0, n = 0;
        for(auto &i: nums){
            if(i>0)p++;
            else if(i<0)n++;
        }return max(p,n);
    }

    int maximumCount_binary_search(vector<int>& nums) {
        int res;
        int left = 0;
        int right = nums.size() - 1;
        int middle;
         
        int b_found = false;
        int boundary = 0;
        int pos = 0;
        int neg = 0;
        // middle = (right - left)/2;
        int count_zero = 0;

        while (!b_found || left <= right){
            boundary = left + (right - left)/2;

            if ((nums[boundary]<0 && nums[boundary+1]>0) || (nums[boundary]>0 && nums[boundary-1]<0)){
                b_found = true;
                neg = boundary+1;
                pos = nums.size() - boundary - 1;
                if (neg>pos) return neg;
                else return pos;
            }

            if (nums[boundary] == 0){
                count_zero += 1;
            }

            if (nums[boundary] < 0){
                left = boundary + 1;
                // boundary += 1;
            }

            if (nums[boundary] > 0){
                right = boundary - 1;
                // boundary -= 1 
            }

            // if (nums[middle] == 0){
            //     neg += middle; 
            // }

        }
        
        // return res;
    }

    

        
                 
};

int main() {
    Solution s;
    int result;
    
    vector<int> nums({-3,-2,-1,1,1,2,3});
    result = s.maximumCount(nums);
    return 0 ;
} 