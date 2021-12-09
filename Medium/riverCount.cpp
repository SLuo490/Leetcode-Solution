#include <vector>
using namespace std;

int dfs(vector<vector<int>>& matrix, int i, int j) {
	// out of bound
	if (i < 0 || i >= matrix.size() || j < 0 || j >= matrix[0].size() || matrix[i][j] != 1) {
		return 0; 
	}
	
	matrix[i][j] = 0; 
	int count = 1; 
	
	count += dfs(matrix, i + 1, j); 
	count += dfs(matrix, i - 1, j); 
	count += dfs(matrix, i, j + 1); 
	count += dfs(matrix, i, j - 1); 

	return count; 
}


vector<int> riverSizes(vector<vector<int>> matrix) {
  // Write your code here.
 	vector<int> res; 
	int count = 0, row = matrix.size(), col = matrix[0].size(); 
	
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (matrix[i][j] == 1) {
				res.push_back(dfs(matrix, i, j)); 
			}
		}
	}
	return res; 
}
