#include <iostream>
#include <vector>
#include <tuple>
#include <string>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
 
    // Fills lps[] for given pattern pat[0..M-1]
    int computeLPSArray(string s)
    {
        int i = 1;
        int j = 0;
        int M = s.size();
        vector<int> lps;
        // int lps[M] = {0};
        // lps[0] = 0;
        lps.push_back(0);
        int same = 1;
        char c = s[0];
        int m=0;

        while (i < M){
            if (c == s[i]){
                same += 1;
            }
            if (s[i] == s[j]){              
                if (j<lps.size() and lps[j] != 0) {
                    lps.push_back(lps[j]);
                    // lps[i] = lps[j];
                    j++;
                }
                else {
                    j++;
                    lps.push_back(j);
                    // lps[i] = j;
                    // m = max(m, lps[i]);
                }
                   
                i++;
            }
            else {
                if (j!=0){
                    j = lps[j-1];
                }
                else {
                    lps.push_back(j);
                    // lps[i] = j;
                    // m = max(m, lps[i]);
                    i++;
                }               
                
            }
        }
        // m = lps[M-1];
        // if (same == M && same > 1) return 1;
        // else if (m>1 && M%m == 0) return 1;
        // else return 0;
        j = 0;
        int val = lps[M-1];
        if (val == 0) return 0;
        for(int i=0;i<M;i++){
            if(j==val) j=0;
            if(s[i]!=s[j]) return 0;
            j++;
        }
        return 1;
    }
        
                 
};

int main() {
    Solution s;
    char txt[] = "ABABDABACDABABCABAB";
    // char pat[] = "ABABABAB";
    string pat = "abaababaab";
    // string pat = "ABABABAB";
    int res;
    res = s.computeLPSArray(pat);
    return 0;
} 