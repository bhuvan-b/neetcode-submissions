class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp, tf;

        if(t.length()>s.length())
            return "";

        for(int i=0;i<t.length();i++)
            tf[t[i]]++;

        int l=0, r=0, mn=INT_MAX, uniq=tf.size(), scnt=0;
        pair<int, int> res;

        while(l<=r && r<s.length())
        {
            mp[s[r]]++;

            if(tf.find(s[r])!=tf.end() && mp[s[r]]==tf[s[r]])
            {
                scnt++;
            }

            while(scnt==uniq)
            {
                if(r-l+1<mn)
                {
                    mn=r-l+1;
                    res = {l,r};
                    cout << l << " " << r << endl;
                }

                mp[s[l]]--;
                if(tf.find(s[l])!=tf.end() && mp[s[l]]<tf[s[l]])
                {
                    scnt--;
                }
                l++;
            }
            r++;
        }
        // cout << mn << endl;
        if(mn==INT_MAX)
            return "";
        return s.substr(res.first,mn);
    }
};
