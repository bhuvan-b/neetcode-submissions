class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<float> st;
        vector<pair<int, int>> vect;
        for(int i=0;i<position.size();i++)
        {
            vect.push_back({position[i], speed[i]});
            // st.insert(((target-position[i])/speed[i] )+ ((target-position[i])%speed[i]!=0));
        }

        sort(vect.rbegin(), vect.rend());

        for(int i=0;i<vect.size();i++)
        {
            float time = (float)(target-vect[i].first)/vect[i].second;
            // cout << time << endl;
            if(!st.empty() && time<=st.top())
            {
                continue;
            }
            st.push(time);
        }

        return st.size();
    }
};

