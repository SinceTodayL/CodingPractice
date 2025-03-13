#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            int len = s.size();
            s = " " + s;
            unordered_map<char, int> um;
            int ans = 0;
            int ptr = 0;
            for(int i = 1; i <= len; ++i){
                if(um.find(s[i]) != um.end()){
                    ans = max(ans, i - max(um[s[i]], ptr));
                    ptr = max(um[s[i]], ptr);
                    um[s[i]] = i;
                }
                else{
                    ans = max(ans, i - ptr);
                    um[s[i]] = i;
                }
            }
            return ans;
        }
    };