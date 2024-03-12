#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int res;
        int left = 0;
        int right = arr.size() -1;
        int mid;

        while (right >= left){
            mid = left + (right - left)/2;

            if (arr[mid+1]<arr[mid] && arr[mid-1]<arr[mid]){
                return mid;
            }

            else if (arr[mid+1]>arr[mid]) left = mid+1;

            else if (arr[mid-1]>arr[mid]) right = mid-1;
        }
        return res;
    }  
        
                 
};

int main() {
    Solution s;
    int result;
    
    vector<int> nums({24,69,100,99,79,78,67,36,26,19});
    result = s.peakIndexInMountainArray(nums);
    return 0 ;
} 