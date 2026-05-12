class NumMatrix {
    vector<vector<int>> m;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        m=matrix;
        vector<int> colSum(matrix[0].size(),0);
        for (int row=0;row<matrix.size();row++){
            int rowSum=0;
            for (int col=0;col<matrix[0].size();col++){
                /*cout << endl<<"element "<<matrix[row][col] << endl;
                for (int num:colSum) cout << num<<" ";*/
                rowSum+=matrix[row][col];
                m[row][col]=colSum[col]+rowSum;
                colSum[col]+=rowSum;
            }

        }

    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        /*for (auto row:m){
            for (auto num:row){
                cout << num<<" ";
            }
            cout <<endl;
        }*/
        int ans = m[row2][col2];
        if (row1==0 && col1==0){
            
        } else if (row1!=0 && col1!=0) {
            ans-=m[row2][col1-1];
            ans-=m[row1-1][col2];
            ans+=m[row1-1][col1-1];
            
        } else {
            if (row1==0) ans-=m[row2][col1-1];
            if (col1==0) ans-=m[row1-1][col2];
        }
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */