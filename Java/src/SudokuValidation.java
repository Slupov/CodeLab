/**
 * @author Stoyan Lupov
 * @date 11/04/2019
 **/
public class SudokuValidation {

    public static void main(String[] args) {
        SudokuValidation sv = new SudokuValidation();

        char[][] test1 = new char[][]{
                new char[]{'8', '3', '.', '.', '7', '.', '.', '.', '.'},
                new char[]{'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                new char[]{'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                new char[]{'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                new char[]{'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                new char[]{'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                new char[]{'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                new char[]{'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                new char[]{'.', '.', '.', '.', '8', '.', '.', '7', '9'}
        };

        char[][] test2 = new char[][]{
                new char[]{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                new char[]{'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                new char[]{'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                new char[]{'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                new char[]{'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                new char[]{'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                new char[]{'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                new char[]{'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                new char[]{'.', '.', '.', '.', '8', '.', '.', '7', '9'}
        };


        sv.isValidSudoku(test2);

    }

    public boolean isValidSudoku(char[][] board) {
        final int SUDOKU_LEN = 9;

        //every row, column, square is represented by a bit mask (integer)
        int[] rowsMasks = new int[SUDOKU_LEN];
        int[] columnsMasks = new int[SUDOKU_LEN];
        int[] squaresMasks = new int[SUDOKU_LEN];

        int curentValue = 0;
        int currentSquareIdx = 0;

        for (int i = 0; i < SUDOKU_LEN; i++) {
            for (int j = 0; j < SUDOKU_LEN; j++) {

                if (board[i][j] == '.') {
                    continue;
                }

                curentValue = Character.getNumericValue(board[i][j]);
                currentSquareIdx = squareNumber(i, j, 3, 3);

                //check in row
                if (isBitEnabled(rowsMasks[i], curentValue - 1)) {
                    return false;
                } else {
                    rowsMasks[i] = setBitEnabled(rowsMasks[i], curentValue - 1);
                }

                //check in col
                if (isBitEnabled(columnsMasks[j], curentValue - 1)) {
                    return false;
                } else {
                    columnsMasks[j] = setBitEnabled(columnsMasks[j], curentValue - 1);
                }

                //check in square
                if (isBitEnabled(squaresMasks[currentSquareIdx], curentValue - 1)) {
                    return false;
                } else {
                    squaresMasks[currentSquareIdx] = setBitEnabled(squaresMasks[currentSquareIdx], curentValue - 1);
                }
            }
        }

        return true;
    }

    public int squareNumber(int row, int col, int width, int numMajorCols) {
        int majorRow = row / width;  // zero based majorRow
        int majorCol = col / width;  // zero based majorCol

        return majorCol + majorRow * numMajorCols;
    }

    public boolean isBitEnabled(int mask, int bitIdx) {
        return (mask & (1 << bitIdx)) != 0;
    }

    public int setBitEnabled(int mask, int bitIdx) {
        return mask | (1 << bitIdx);
    }
}
