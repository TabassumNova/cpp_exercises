#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    
    string sentense_sort(string s) {
        int idx;
        string tempStr = "";
        string full_str = s;
        int prev_idx = 0;
        string arr[10];
        for (int i=0; i<s.length(); i++){
            auto found = full_str.find(" ");
            if (found != string::npos){
                idx = int(full_str[found-1]) - int('0');
                tempStr.append(s, prev_idx, found-1);
                arr[idx-1] = tempStr;
                prev_idx += found + 1;
                i = prev_idx;
                full_str = "";
                full_str.append(s, prev_idx, s.length());
                // full_str = "";
                tempStr = "";
                
            }
            else {
                idx = full_str[full_str.length()-1] - int('0');
                tempStr.append(full_str, 0, full_str.length()-1);
                arr[idx-1] = tempStr;
                full_str = "";
                break;
            }
           
        }
        for (int j=0; j<10; j++){
            if (arr[j] != ""){
                full_str += arr[j] + ' ';
            } 
            else {
                s = "";
                s.append(full_str, 0, full_str.length()-1);
                break;

            }          

        }
        return s; 
    }
        
                 
};

int main() {
    Solution s;
    
    // char result[] = "";
    // char s[] = "is2 sentence4 This1 a3";
    string result = "";
    string str = "QcGZ4 TFJStgu3 HvsRImLBfHd8 PaGqsPNo9 mZwxlrYzanuVOUZoyNjt1 fzhdtYIen6 mV7 LKuaOtefsixxo5 pwdEK2";
    result = s.sentense_sort(str);
    return 0 ;
} 