//Determine Whether Matrix Can Be Obtained By Rotation

    //rotate the matrix
    void rotate(vector<vector<int>>& mat)
    {
        int n = mat.size();
        //transpose matrix
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                swap(mat[i][j],mat[j][i]);
            }
        }
        //reverse row 
        for (int i = 0; i < n; i++)
        {
            reverse(mat[i].begin(),mat[i].end());
        }
        return;
    }
    
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        //if matrix is equal to the target matrix, return true 
        if (mat == target)
        {
            return true;
        }
        //3 rotation and check each one
        int deg = 3;
        //rotate 90, check, rotate 90 check, rotate 90 and check
        while (deg--)
        {
            //rotate matrix
            rotate(mat);
            //return true if it is equal
            if (mat == target)
            {
                return true;
            }
        }
        return false;
    }
