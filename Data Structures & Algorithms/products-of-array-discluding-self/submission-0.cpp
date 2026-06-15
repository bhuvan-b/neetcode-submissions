class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> vect1(nums), vect2(nums);

        for(int i=1;i<vect1.size();i++)
        {
            vect1[i] = vect1[i]*vect1[i-1];
            // cout << vect1[i] << " ";
        }

        // cout <<  "\n";

        for(int i=vect2.size()-2;i>=0;i--)
        {
            vect2[i] = vect2[i]*vect2[i+1];
            // cout << vect2[i] << " ";
        }

        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            int left=1, right=1;
            if(i-1<0)
                right=vect2[i+1];
            else if(i+1>=nums.size())
                left=vect1[i-1];
            else
            {
                left=vect1[i-1];
                right=vect2[i+1];
            }
            ans.push_back(left*right);
        }

        return ans;
    }
};
