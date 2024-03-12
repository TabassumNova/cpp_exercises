#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

class Solution {
public:

    
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> result;
        int arr[mat.size()];
        int arr_idx[mat.size()];
        for (int i=0; i<mat.size(); i++){
            int count = 0;
            for (int j=0; j<mat[i].size(); j++){
                if (mat[i][j] == 1){
                    count += 1;
                }
            }
            arr[i] = count;
            arr_idx[i] = i;
        }
        int temp;
        for (int i=0; i<mat.size(); i++){
            for (int j=0; j<mat.size()-i; j++){
                if (arr[j] > arr[j+1]){
                    temp = arr_idx[j];
                    arr_idx[j] = arr_idx[j+1];
                    arr_idx[j+1] = temp;
                    temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;

                }
                if (arr[j] == arr[j+1] && arr_idx[j]>arr_idx[j+1] ){
                    temp = arr_idx[j];
                    arr_idx[j] = arr_idx[j+1];
                    arr_idx[j+1] = temp;

                }
            }
        }
        for (int i=0; i<k; i++){
            result.push_back(arr_idx[i]);
        }
        return result;
    }
        
                 
};

int main() {
    Solution s;
    vector<int> result;
    vector<vector<int>> mat({{1,1,0,0,0},{1,1,1,1,0},{1,0,0,0,0},{1,1,0,0,0},{1,1,1,1,1}});
    int k = 3;
    result = s.kWeakestRows(mat, k);
    return 0 ;
} 