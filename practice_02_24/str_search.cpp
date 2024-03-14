#include <iostream>
#include <vector>
#include <tuple>
#include <string>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    
    void KMPSearch(char* pat, char* txt)
    {
        int M = strlen(pat);
        int N = strlen(txt);

        // int* lps;

        int* lps = computeLPSArray(pat, M);
        cout << lps[3] <<endl;

        int i=0;
        int j=0;
        while (i < N){
            if (txt[i] == pat[j]){
                i++;
                j++;
            }
            if (j == M){
                cout << "Found pattern at index "<< to_string(i - j) << endl;
                j = lps[j-1];
            }
            else if (i<N && txt[i] != pat[j]){
                if (j != 0){
                    j = lps[j-1];
                }
                else {
                    i++;
                }
            }
        }
    }
 
    // Fills lps[] for given pattern pat[0..M-1]
    int* computeLPSArray(char* pat, int M)
    {
        int i = 1;
        int j = 0;
        // int lps[M];
        int* lps = new int[M];
        lps[0] = 0;

        while (i < M){
            if (pat[i] == pat[j]){
                j++;
                lps[i] = j;
                i++;
            }
            else {
                if (j!=0){
                    j = lps[j-1];
                }
                else {
                    lps[i] = j;
                    i++;
                }
                
                
            }
        }
        return lps;
    }
        
                 
};

int main() {
    Solution s;
    char txt[] = "ABABDABACDABABCABAB";
    char pat[] = "ABB";
    s.KMPSearch(pat, txt);
    return 0;
} 