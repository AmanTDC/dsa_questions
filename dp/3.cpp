 int maxSquare(int n, int m, vector<vector<int>> mat){
        int maxi = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i>0&&j>0&&mat[i][j]==1)
                    mat[i][j] = 1+min(mat[i][j-1],min(mat[i-1][j-1],mat[i-1][j]));
                maxi = max(maxi,mat[i][j]);
        
            }
        }
        return maxi;
    }