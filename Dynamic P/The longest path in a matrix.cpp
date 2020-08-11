// Returns length of the longest path beginning with mat[i][j]. 
// This function mainly uses lookup table dp[n][n] 
int findLongestFromACell(int i, int j, int mat[n][n], int dp[n][n]) 
{ 
    if (i < 0 || i >= n || j < 0 || j >= n) 
        return 0; 
  
    // If this subproblem is already solved 
    if (dp[i][j] != -1) 
        return dp[i][j]; 
  
    // To store the path lengths in all the four directions 
    int x = INT_MIN, y = INT_MIN, z = INT_MIN, w = INT_MIN; 
  
    // Since all numbers are unique and in range from 1 to n*n, 
    // there is atmost one possible direction from any cell 
    if (j < n - 1 && ((mat[i][j] + 1) == mat[i][j + 1])) 
        x = 1 + findLongestFromACell(i, j + 1, mat, dp); 
  
    if (j > 0 && (mat[i][j] + 1 == mat[i][j - 1])) 
        y = 1 + findLongestFromACell(i, j - 1, mat, dp); 
  
    if (i > 0 && (mat[i][j] + 1 == mat[i - 1][j])) 
        z = 1 + findLongestFromACell(i - 1, j, mat, dp); 
  
    if (i < n - 1 && (mat[i][j] + 1 == mat[i + 1][j])) 
        w = 1 + findLongestFromACell(i + 1, j, mat, dp); 
  
    // If none of the adjacent fours is one greater we will take 1 
    // otherwise we will pick maximum from all the four directions 
    return dp[i][j] = max(x, max(y, max(z, max(w, 1)))); 
} 
