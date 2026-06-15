class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length()>s2.length())
            return false;

        unordered_map<char, int> mp1, mp2;

        for(int i=0;i<s1.length();i++)
            mp1[s1[i]]++;

        int l=0, r=0;

        while(l<=r && r<s2.length())
        {
            mp2[s2[r]]++;
            if(r-l+1<s1.length())
            {
                r++;
                continue;
            }
            bool yes=true;
            for(char c='a';c<='z';c++)
            {
                if(mp1[c]!=mp2[c])
                {
                    yes=false;
                    break;
                }
            }
            if(yes)
                return true;
            r++;
            mp2[s2[l]]--;
            l++;
        }

        return false;
    }
};
