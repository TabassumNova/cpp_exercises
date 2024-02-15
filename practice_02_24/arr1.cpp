#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    int convertToBinary(unsigned int n) {
            int count = 0;
            if (n / 2 != 0) {
                count += convertToBinary(n / 2);
            }
            if (n % 2 == 1) {
                count += 1;
            }
            return count;
        }

    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int total = 0;
        for (int i=0; i<nums.size(); i++){
            int bin_num = 0;
            bin_num = convertToBinary(i);
            if (bin_num == k) {
                total += nums[i];
            }
        }
        
        return total;          
    }
};

int main() {
    Solution s;
    int result;
    vector<int> v({5,10,1,5,2});
    result = s.sumIndicesWithKSetBits(v, 1);
    return 0 ;
} 
