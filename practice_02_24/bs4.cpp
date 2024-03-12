#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

class Solution {
public:
    bool check_valid(int mid, vector<int>& weights, int days){
        
        int sum = 0;
        int d = 1;

        for (int x:weights){
            sum += x;

            if (x>mid) return false;

            if (sum > mid){
                d++;
                sum = x;
            }
        }
        if (d <= days) return true;
        else return false;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int result;
        bool valid = false;
        int left = 1;
        int right = 0;
        int mid;
        int max = 0;

        for (int x: weights){
            right += x;
        }
        result = right;
        while (right >= left){
            mid = left + (right - left)/2;
            
            valid = check_valid(mid, weights, days);
            if (valid){
                result = mid;
                right = mid-1;
            }
            else left = mid+1;

        }
        return result;
    }  
        
                 
};

int main() {
    Solution s;
    int result;
    int days = 4;
    
    vector<int> nums({1,2,3,1,1});
    result = s.shipWithinDays(nums, days);
    return 0 ;
} 