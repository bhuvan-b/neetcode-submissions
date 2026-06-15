class Solution {
public:
    bool isPalindrome(string s) {
        
        int i=0,j=s.length()-1;

        while(i<j)
        {
            if(!isalpha(tolower(s[i])) && !isdigit(tolower(s[i])))
            {
                i++;
                continue;
            }
            if(!isalpha(tolower(s[j])) && !isdigit(tolower(s[j])))
            {
                j--;
                continue;
            }
            if(tolower(s[i])==tolower(s[j]))
            {
                // cout << s[i] << " " << s[j] << endl;
                i++;
                j--;
            }
            else
                return false;
        }

        return true;
    }
};
