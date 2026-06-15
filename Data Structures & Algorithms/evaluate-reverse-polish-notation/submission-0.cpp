class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i=0;i<tokens.size();i++)
        {
            if(isnumber(tokens[i]))
                st.push(stoi(tokens[i]));
            else
            {
                int num2=st.top();
                st.pop();
                int num1=st.top();
                st.pop();
                st.push(func(num1, num2, tokens[i]));
            }
        }

        return st.top();
    }

    bool isnumber(string st)
    {
        return !(st=="+" || st=="-" || st=="*" || st=="/" );
    }

    int func(int num1, int num2, string op)
    {
        if(op=="+")
            return num1+num2;
        if(op=="-")
            return num1-num2;
        if(op=="*")
            return num1*num2;
        if(op=="/")
            return num1/num2;
    }
};
