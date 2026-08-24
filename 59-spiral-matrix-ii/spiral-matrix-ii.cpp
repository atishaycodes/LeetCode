class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int top=0, right=n-1, bottom= n-1, left= 0;
        int curr = 1;
        while(curr<=n*n){
        for(int l=left; l<=right; l++){
            matrix[top][l] = curr++;
        }
        top++;
        for(int t = top; t<=bottom; t++){
            matrix[t][right] = curr++;
        }
        right--;
        for(int r = right; r>=left; r--){
            matrix[bottom][r] = curr++;
        }
        bottom--;
        for(int b = bottom; b>=top; b--){
            matrix[b][left] = curr++;
        }
        left++;
        }
        return matrix;

    }
};