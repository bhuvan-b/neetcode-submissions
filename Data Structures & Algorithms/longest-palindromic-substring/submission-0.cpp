class Solution {
public:
    string longestPalindrome(string s) {
        int st=0, mx_len=0;
        for(int i=0;i<s.length();i++)
        {
            int l=i, r=i;
            while(l>=0 && r<s.length() && s[l]==s[r])
            {
                int len = r-l+1;
                if(len>mx_len)
                {
                    mx_len = r-l+1;
                    st = l;
                }
                l--;
                r++;
            }

            l=i, r=i+1;
            while(l>=0 && r<s.length() && s[l]==s[r])
            {
                int len = r-l+1;
                if(len>mx_len)
                {
                    mx_len = r-l+1;
                    st = l;
                }
                l--;
                r++;
            }
        }
        // cout << st << " " << mx_len << endl;
        return s.substr(st, mx_len);

    }
};
