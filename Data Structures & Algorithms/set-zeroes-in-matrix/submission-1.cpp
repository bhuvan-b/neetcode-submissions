class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> rows, cols;

        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[i].size();j++)
            {
                if(matrix[i][j]==0)
                {
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }

        for(auto it=rows.begin();it!=rows.end();it++)
        {
            for(int j=0;j<matrix[*it].size();j++)
            {
                matrix[*it][j] = 0;
            }
        }

        for(auto it=cols.begin();it!=cols.end();it++)
        {
            for(int j=0;j<matrix.size();j++)
            {
                matrix[j][*it] = 0;
            }
        }

    }
};

// 0 1 2 0
// 3 4 5 2
// 1 3 1 5

// 0 0 0 0
// 0 4 5 2
// 0 3 1 5
