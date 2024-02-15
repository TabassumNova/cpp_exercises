#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> leftSum(0);
        vector<int> rightSum(0);
        vector<int> v(0);

        leftSum.push_back(0);    
        for (int i=1; i<nums.size(); i++) {
            int sum = 0;
            for (int j=i-1; j>=0; j--) {
                sum += nums[j];
            }
            leftSum.push_back(sum);
        }

        for (int i=0; i<nums.size(); i++) {
            int sum = 0;
            for (int j=i+1; j<nums.size(); j++) {
                sum += nums[j];
            }
            rightSum.push_back(sum);
        }

        for (int i=0; i<nums.size(); i++) {
            v.push_back(abs(leftSum[i] - rightSum[i]));
        }


        return v;
    }
    

    
};

int main() {
    Solution s;
    vector<int> result(0);
    vector<int> v({10,4,8,3});
    result = s.leftRightDifference(v);
    return 0 ;
} 
