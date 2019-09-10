/**
 * @url https://leetcode.com/problems/game-of-life/
 * **/
public class SetZeroesMatrix {
    public static void main(String[] args) {
        setZeroes(new int[][]{
                {1, 1, 1},
                {0, 1, 2}});
    }

    public static void setZeroes(int[][] matrix) {
        final int R = matrix.length;
        final int C = matrix[0].length;
        boolean isCol = false;

        //iterate over matrix once and set first cell in column to 0 if column contains 0 AND first cell of row if
        //row contains 0
        for (int i = 0; i < R; i++) {

            //check if first column of matrix should be set to 0 first
            if (matrix[i][0] == 0) {
                isCol = true;
            }

            for (int j = 1; j < C; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        //iterate inside of matrix and set columns and rows to 0
        for (int i = 1; i < R; i++) {
            for (int j = 1; j < C; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // See if the first row needs to be set to zero as well
        if (matrix[0][0] == 0) {
            for (int j = 0; j < C; j++) {
                matrix[0][j] = 0;
            }
        }

        // See if the first column needs to be set to zero as well
        if (isCol) {
            for (int i = 0; i < R; i++) {
                matrix[i][0] = 0;
            }
        }
    }
}