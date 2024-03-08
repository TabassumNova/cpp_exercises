#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    
    vector<int> insertion_sort(vector<int>& nums) {
        int key = 0;
        int j = 0;
        int temp = 0;
        for (int i=1; i<nums.size(); i++){
            key = nums[i];
            j = i-1;
            while (j>=0 && nums[j]>key){
                temp = nums[j+1];
                nums[j+1] = nums[j];
                nums[j] = temp;
                j -= 1;
            }          
        }
        return nums; 
    }
        
                 
};

int main() {
    Solution s;
    vector<int> result;
    vector<int> v({5,10,1,5,2});
    result = s.insertion_sort(v);
    return 0 ;
} 