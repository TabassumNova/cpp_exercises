#include <iostream>
#include <vector>
#include <tuple>
#include <string>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        

        vector<int> pat_lps = computeLPSArray(pattern);

        return res;
        
    }
 
    // Fills lps[] for given pattern pat[0..M-1]
    vector<int> computeLPSArray(string s)
    {
        int i = 1;
        int j = 0;
        int M = s.size();
        vector<int> lps;
        lps.push_back(0);

        while (i < M){
            if (s[i] == s[j]){
                j++;
                lps.push_back(j);
                i++;
            }
            else {
                if (j!=0){
                    j = lps[j-1];
                }
                else {
                    lps.push_back(j);
                    i++;
                }               
            }
        }
        return lps;
    }
        
                 
};

int main() {
    Solution s;
    vector<string> words = {"abc","deq","mee","aqq","dkd","ccc"};
    string pattern = "abb";
    vector<string> res;
    res = s.findAndReplacePattern(words, pattern);
    return 0;
} 