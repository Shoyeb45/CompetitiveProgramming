class Solution {
    public int[][] generateMatrix(int n) {
        int[][] a = new int[n][n];
        int rowStart = 0 , colStart = 0, colEnd = n - 1, rowEnd = n - 1;
        int k = 1;

        while(rowStart <= rowEnd && colStart <= colEnd) {

            for(int j = colStart ; j <= colEnd ; j++) {
                a[rowStart][j] = k;
                k++;
            }
            rowStart++;

            for(int i = rowStart ; i <= rowEnd ; i++) {
                a[i][colEnd] = k;
                k++;
            }
            colEnd--;

            for(int j = colEnd ; j >= colStart ; j--) {
                a[rowEnd][j] = k;
                k++;
            }
            rowEnd--;

            for(int i = rowEnd ; i >= rowStart; i--) {
                a[i][colStart] = k;
                k++;
            }
            colStart++;
        }

        return a;
    }
}