class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int mw=heights.size(), ans=0;

        for(int i=0;i<heights.size();i++)
        {
            int pos=i, width=1, l=i-1, r=i+1, ht=heights[pos];
            int area = ht*width;

            while(width<mw)
            {
                if(l>=0 && r<heights.size())
                {
                    if(heights[r]>heights[l])
                    {
                        ht=min(ht, heights[r]);
                        r++;
                    }
                    else
                    {
                        ht=min(ht, heights[l]);
                        l--;
                    }
                }
                else if(r<heights.size())
                {
                    ht=min(ht, heights[r]);
                    r++;
                }
                else
                {
                    ht=min(ht, heights[l]);
                    l--;
                }
                width++;
                area=max(area,width*ht);
            }
            ans=max(ans, area);
        }

        return ans;
    }
};
