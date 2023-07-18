bool searchMatrix(vector<vector<int>>& mat, int target) {
     bool f=0;
    int m=mat.size(),n=mat[0].size(), i=m-1,j=0;
    while(i>=0 && j<=n-1)
    {
        if(mat[i][j]>target)
            i--;
        else if(mat[i][j]<target)j++;
        else if(mat[i][j]==target)
        {
            f=1;break;
        }
    }
    return f?true:false;    
}
