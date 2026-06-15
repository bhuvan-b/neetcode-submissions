class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        queue<char> q;
        int len=0, ans=0, l=0, r=0;

        while(l<=r && r<s.length())
        {
            while(mp[s[r]]>0)
            {
                mp[s[l]]--;
                l++;
            }
            mp[s[r]]++;
            ans=max(ans, r-l+1);
            r++;
        }
        return ans;
    }
};
