#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    
    vector<int> bubble_sort(vector<int>& nums) {
        int temp = 0;
        bool swapped;
        for (int i=0; i<nums.size()-1; i++){
            for (int j=0; j<nums.size()-i-1; j++){
                if (nums[j] > nums[j+1]){
                    temp = nums[j];
                    nums[j] = nums[j+1];
                    nums[j+1] = temp;
                    swapped = true;
                }

            }
            // if (swapped == false)
            //     break;
        }
        
        return nums;          
    }
};

int main() {
    Solution s;
    vector<int> result;
    vector<int> v({5,10,1,5,2});
    result = s.bubble_sort(v);
    return 0 ;
} 