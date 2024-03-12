#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

class Solution {
public:

    tuple<bool, int> recurse(vector<int>& nums, int s, int start, int end){
        bool found = false;
        int current = start + (end - start)/2;
        int curr_idx;
        int idx=0;

        if (current == 0 and nums[current] == s){
            found = true;
            idx = current;
            return make_tuple(found, idx);
        }
    
        while (!found || current==0) {

            if (nums[current] == s) {
                found = true;
                idx = current;
            }

            else if (nums[current] > s) {
                tie(found, idx) = recurse(nums, s, start, current-1);

            }

            else if (nums[current] < s) {
                tie(found, idx) = recurse(nums, s, current+1, end);
            }
        }

        return make_tuple(found, idx);

    }
    
    int binary_search(vector<int>& nums, int s) {
        bool found = false;
        int idx=0;

        tie(found, idx) = recurse(nums, s, 0, nums.size()-1);     
 
        return idx; 
    }

    int binary_search1(vector<int>& nums, int s) {
        int left = 0;
        int right = nums.size() -1;
        int middle;

        while (left <= right){
            middle = left + (right - left)/2;

            if (nums[middle] == s){
                return middle;
            }

            else if (nums[middle] < s){
                left = middle + 1;
            }

            else {
                right = middle - 1;
            }
        }
 
        return -1; 
    }
        
                 
};

int main() {
    Solution s;
    int result;
    vector<int> v({1,3,4,6,8,10,11,13,14});
    int search = 14;
    result = s.binary_search1(v, search);
    return 0 ;
} 