class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> left(height.size()), right(height.size());
        int lmax=0, rmax=0;
        for(int i=0;i<height.size();i++)
        {
            lmax=max(lmax, height[i]);
            left[i]=lmax;
        }
        for(int i=height.size()-1;i>=0;i--)
        {
            rmax=max(rmax, height[i]);
            right[i]=rmax;
        }
        int ans=0;
        for(int i=0;i<height.size();i++)
        {
            if(i-1<0 || i+1>=height.size())
                continue;
            int area = max(0, min(left[i-1], right[i+1])-height[i]);
            ans+=area;
        }

        return ans;

    }
};
