/**
 * @author Stoyan Lupov
 * @date 09/04/2019
 * @url https://leetcode.com/problems/game-of-life/
 **/
public class GameOfLife {
    private static int LIVE = 1;
    private static int DEAD = 0;

    private static int NEW_LIVE = 11; //from 0 to 1
    private static int NEW_DEAD = 10; //from 1 to 0

    public static void main(String[] args) {
        gameOfLife(new int[][]{
                {0, 1, 0},
                {0, 0, 1},
                {1, 1, 1},
                {0, 0, 0}
        });
    }

    public static void gameOfLife(int[][] board) {
        //set temporary states for next generation
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[i].length; j++) {
                processCell(i, j, board);
            }
        }

        //apply temporary states to become permanent
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[i].length; j++) {
                if (board[i][j] == NEW_DEAD) {
                    board[i][j] = DEAD;
                } else if (board[i][j] == NEW_LIVE) {
                    board[i][j] = LIVE;
                }
            }
        }
    }

    private static void processCell(int r, int c, int[][] board) {
        final int LIVE_N = getLiveNeighbours(r, c, board);

        //check if cell is alive
        if (LIVE == board[r][c]) {
            //1.Any live cell with fewer than two live neighbors dies, as if caused by under-population.
            //3.Any live cell with more than three live neighbors dies, as if by over-population..
            if (LIVE_N < 2 || LIVE_N > 3) {
                board[r][c] = NEW_DEAD;
            }
        } else {
            //4.Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction
            if (LIVE_N == 3) {
                board[r][c] = NEW_LIVE;
            }
        }
    }

    private static int getLiveNeighbours(int r, int c, int[][] board) {
        int count = 0;

        for (int i = r - 1; i < r + 2; i++) {
            //invalid row
            if (i < 0 || i >= board.length) {
                continue;
            }

            for (int j = c - 1; j < c + 2; j++) {
                //invalid col OR same cell
                if ((j < 0 || j >= board[i].length) || (i == r && j == c)) {
                    continue;
                }

                if (LIVE == board[i][j] || NEW_DEAD == board[i][j]) {
                    ++count;
                }
            }
        }

        return count;
    }
}
