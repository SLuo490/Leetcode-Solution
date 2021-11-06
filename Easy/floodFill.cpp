/*
An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.
You are also given three integers sr, sc, and newColor. You should perform a flood fill on the image starting from the pixel image[sr][sc].
To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with newColor.
Return the modified image after performing the flood fill.

Example 1:
Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, newColor = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
Explanation: From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel), all pixels connected by a path of the same color as the starting pixel (i.e., the blue pixels) are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected to the starting pixel.

Example 2:
Input: image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, newColor = 2
Output: [[2,2,2],[2,2,2]]
*/


class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        //if the image position is the newColor, then just return image
        if (image[sr][sc] == newColor) {
            return image; 
        }
        
        //DFS
        fill (image, sr, sc, image[sr][sc], newColor); 
        
        return image; 
    }
    
    void fill (vector<vector<int>>& image, int i, int j, int color, int newColor) {
        //base case: out of bound
        if (i < 0 || i >= image.size() || j < 0 || j >= image[i].size() || image[i][j] != color) {
            return;
        }
        
        //turn image to newColor
        image[i][j] = newColor; 
        
        //recursive
        fill(image, i + 1, j, color, newColor); 
        fill(image, i - 1, j, color, newColor); 
        fill(image, i, j + 1, color, newColor); 
        fill(image, i, j - 1, color, newColor); 
    }
};
