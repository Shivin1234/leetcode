#include<iostream>
#include <unordered_set>
using namespace std;

class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            unordered_set<char> seen;
            int lft=0,ans=0;
            for(int rgt=0;rgt<s.size();rgt++){
                while(seen.count(s[rgt])){
                    seen.erase(s[lft]);
                    lft++;
                }
                seen.insert(s[rgt]);
                ans=max(ans,rgt-lft+1);
            }
            return ans;
        }
    };
    int main() {
        string s;
        cout << "Enter a string: ";
        cin >> s;
        Solution sol;
        cout << "Length of longest substring without repeating characters: "<<sol.lengthOfLongestSubstring(s) << endl;
        return 0;
    }