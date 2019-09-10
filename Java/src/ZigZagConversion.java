/**
 * @author Stoyan Lupov
 * @date 10/04/2019
 * @url https://leetcode.com/problems/zigzag-conversion/
 **/
public class ZigZagConversion {
    public static void main(String[] args) {
        convert("PAYPALISHIRING", 6);
    }

    public static String convert(String s, int numRows) {
        StringBuilder sb = new StringBuilder();

        if (numRows == 1) return s;

        int cycleFactor = 2 * (numRows - 1);
        int n = s.length();

        for (int row = 0; row < numRows; row++) {

            //append whole row
            for (int i = 0; row + i < n; i+= cycleFactor) {
                sb.append(s.charAt(row + i));

                //middle rows need another character to be added
                if ((row > 0 && row < numRows - 1) && (i + cycleFactor - row) < n){
                    sb.append(s.charAt(i + cycleFactor - row));
                }
            }
        }

        return sb.toString();
    }
}
