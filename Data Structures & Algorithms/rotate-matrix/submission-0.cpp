class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for(int i=0;i<(n/2);i++)
            for(int j=0;j<n;j++)
                swap(matrix[i][j], matrix[n-i-1][j]);

        for(int i=0;i<n;i++)
            for(int j=i;j<n;j++)
                swap(matrix[i][j], matrix[j][i]);
    }
};


// 1 2 3
// 4 5 6
// 7 8 9

// 7 4 1
// 8 5 2
// 9 6 3

// 7 8 9
// 4 5 6
// 1 2 3

// 10 11 12 13
// 14 15 16 17
// 18 19 20 21
// 22 23 24 25

// 22 18 14 10
// 23 19 15 11
// 24 20 16 12
// 25 21 17 13

// 22 23 24 25
// 18 19 20 21
// 14 15 16 17
// 10 11 12 13