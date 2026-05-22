class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int l=0;int r=m*n-1;
        while (l<=r){
            if (r-l<2){
                if (matrix[l/n][l%n]==target) return true;
                else if (matrix[r/n][r%n]==target) return true;
                else break;
            }
            int t=(l+r)/2;
            if (matrix[t/n][t%n]==target) return true;
            else if (target>matrix[t/n][t%n]) l=t;
            else r=t;
        }
        return false;
    }
};
