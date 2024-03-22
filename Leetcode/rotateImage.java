class Solution {
    public void transpose(int [][] matrix){
        for (int i = 0; i < matrix[0].length; i++) {
            for (int j = i; j < matrix.length; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
    }
    public void swap(int[][] matrix){
        int k = matrix[0].length - 1;
        int j = 0;
        while (j < k) {
                for (int i = 0; i < matrix.length; i++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[i][k];
                matrix[i][k] = temp;
            }
            k--;
            j++;
        }
    }
    public void rotate(int[][] matrix) {
        transpose(matrix);
        swap(matrix);
    }
    
}