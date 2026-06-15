class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        queue<char> q;
        int len=0, ans=0;

        for(int i=0;i<s.length();i++)
        {
            while(mp[s[i]]>0 && !q.empty())
            {
                char c=q.front();
                q.pop();
                mp[c]--;
                len--;
            }
            mp[s[i]]++;
            q.push(s[i]);
            len++;
            ans=max(ans, len);
        }
        return ans;
    }
};
