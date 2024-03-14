#include <iostream>
#include <vector>
#include <tuple>
#include <string>
#include <bits/stdc++.h>
#include <map>

using namespace std;

class Solution {
public:

    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;

        map<char, char> mp;
        // map<char, char>::iterator i;

        for (string w:words){
            map<char, char> mp;
            int i;
            for (i=0; i<w.size(); i++){
                // mp[pattern[i]] = w[i];
                // i = mp.contains(pattern[i]);
                if (mp.find(pattern[i]) == mp.end()){
                    mp[pattern[i]] = w[i];
                }
                else {
                    if (mp[pattern[i]] != w[i]){
                        cout << "not matched " << mp[pattern[i]] << w[i] <<endl;
                        break;
                    }
                    else cout << "matched " << mp[pattern[i]] << w[i] <<endl;
                }
            }
            if (i == w.size()) res.push_back(w);
        }

        // map<int, std::string> example = {{1, "One"}, {2, "Two"}, 
        //                              {3, "Three"}, {42, "Don\'t Panic!!!"}};

        // if(example.find(42) == example.end()) {
        //     std::cout << "Found\n";
        // } else {
        //     std::cout << "Not found\n";
        // }       
        

        vector<int> pat_lps = computeLPSArray(pattern);

        return res;
        
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