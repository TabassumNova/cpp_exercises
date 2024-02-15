#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> v(0);
        v.push_back(first);
        int temp = first;
        for (int i: encoded) {
            temp = temp ^ i;
            v.push_back(temp);
        }
        return v;
    }

    
};

int main() {
    Solution s;
    vector<int> result(0);
    vector<int> v({1,2,3});
    result = s.decode(v, 1);
    return 0 ;
} 
