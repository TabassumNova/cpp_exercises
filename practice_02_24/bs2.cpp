#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

class Solution {
public:

    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        vector<int> result;
        int temp;
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
        }

        // nums = sort(begin(nums), end(nums));
        for (int i=0; i<queries.size(); i++){
            vector<int> temp;
            int sum = 0;
            int count = 0;
            for (int j=0; j<nums.size(); j++){
                if (nums[j] <= queries[i]){
                    sum += nums[j];

                    if (sum <= queries[i]){
                        count += 1;
                    }
                    else {
                        sum -= nums[j];
                    }
                }
            }
            result.push_back(count);

        }
        return result;
    }

        
                 
};

int main() {
    Solution s;
    vector<int> result;
    
    vector<int> nums({4,5,2,1});
    vector<int> queries({3,10,21});
    // int result[queries.size()];
    result = s.answerQueries(nums, queries);
    return 0 ;
} 