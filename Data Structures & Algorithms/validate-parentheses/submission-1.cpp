class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> mp = {
            {'(',')'}, {'[',']'}, {'{','}'}
        };
        stack<char> st;

        for(int i=0;i<s.length();i++)
        {
            if(mp.count(s[i]))
                st.push(s[i]);
            else
            {
                if(st.empty())
                    return false;
                    
                char tp = st.top();
                if(mp[tp]!=s[i])
                    return false;
                st.pop();
            }
        }

        if(st.empty())
            return true;

        return false;
    }
};
