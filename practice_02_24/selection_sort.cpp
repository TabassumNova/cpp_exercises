#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    
    vector<int> selection_sort(vector<int>& nums) {
        int min_idx;
        int min_elm;
        int temp =0;

        for (int i=0; i<nums.size()-1; i++){
            min_elm = nums[i];
            min_idx = i;
            for (int j = i+1; j<nums.size(); j++){
                if (nums[j] < min_elm){
                    min_elm = nums[j];
                    min_idx = j;
                }            
            }
            if (min_idx != i){
                temp = nums[i];
                nums[i] = nums[min_idx];
                nums[min_idx] = temp;
            }
            

        }
        return nums; 
    }
        
                 
};

int main() {
    Solution s;
    vector<int> result;
    vector<int> v({5,10,1,5,2});
    result = s.selection_sort(v);
    return 0 ;
} 