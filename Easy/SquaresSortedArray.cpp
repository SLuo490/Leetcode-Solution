class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> result (A.size());
        int left = 0;
        int right = A.size() -1;
        int position = A.size()-1;
        
        while (left <= right) {
            int left_squared = A[left] * A[left];
            int right_squared = A[right] * A[right];
            
            if (left_squared >= right_squared) {
                result[position] = left_squared;
                position--;
                left++;
                
            } else {
                result[position] = right_squared;
                position--;
                right--;
            }
            
        }
        return result;
    }
    
};
