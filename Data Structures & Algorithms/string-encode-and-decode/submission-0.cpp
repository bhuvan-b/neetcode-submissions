class Solution {
public:

    string encode(vector<string>& strs) {
        string enc = "";
        for(int i=0;i<strs.size();i++)
        {
            enc = enc + "[[";
            enc = enc + strs[i];
            enc = enc + "]]";
        }

        return enc;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int i=0;
        string str="";
        while(i<s.length())
        {
            if(s[i]=='[' && ((i+1)<s.length()) && s[i+1]=='[')
            {
                i+=2;
                continue;
            }
            else if(s[i]==']' && ((i+1)<s.length()) && s[i+1]==']')
            {
                ans.push_back(str);
                str="";
                i+=2;
            }
            else
            {
                str=str+s[i];
                i++;
            }
        }
        return ans;
    }
};
