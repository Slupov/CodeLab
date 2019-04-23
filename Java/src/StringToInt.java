/**
 * @author Stoyan Lupov
 * @date 08/04/2019
 * @url https://leetcode.com/problems/string-to-integer-atoi/
 **/
public class StringToInt {
    static final int ASCII_CORRECTION = 48;

    public static void main(String[] args) {
        System.out.println(myAtoi("-91283472332"));
    }

    public static int myAtoi(String str) {
        str = str.trim();

        long result = 0;
        long unit = 1;
        int sign = 1;

        for (int i = str.length() - 1; i >= 0; --i) {
            char currentChar = str.charAt(i);

            if (!Character.isDigit(currentChar)) {
                if ((0 == i)) {
                    if ('-' == currentChar) {
                        sign = -1;
                    } else if ('+' == currentChar) {
                        sign = 1;
                    }
                    else {
                        unit = 1;
                        result = 0;
                    }
                } else {
                    unit = 1;
                    result = 0;
                }
            } else {
                result += unit * (currentChar - ASCII_CORRECTION);
                unit *= 10;
            }
        }

        result *= sign;

        if (result > Integer.MAX_VALUE) {
            result = Integer.MAX_VALUE;
        } else if (result < Integer.MIN_VALUE) {
            result = Integer.MIN_VALUE;
        }

        return (int) result;
    }
}
