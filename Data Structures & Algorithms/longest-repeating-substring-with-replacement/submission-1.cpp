class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> vect;
        int l=0, r=0, ans=0;

        unordered_set<char> st;
        for(int i=0;i<s.length();i++)
        {
            st.insert(s[i]);
        }

        for(auto &it: st)
        {
            int l=0, r=0;
            unordered_map<char, int> mp;
            while(l<=r && r<s.length())
            {
                mp[s[r]]++;
                // cout << s[r] << " " << it << endl;
                if((r-l+1-mp[it])<=k)
                {
                    ans=max(ans, r-l+1);
                    // r++;
                }
                else
                {
                    while(s[l]==it)
                    {
                        mp[s[l]]--;
                        l++;
                    }
                    mp[s[l]]--;
                    l++;
                }
                r++;
            }
        }
        return ans;
    }
};

// AACAAABBBCDBBBAAAAA