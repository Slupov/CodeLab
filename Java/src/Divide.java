/**
 * @author Stoyan Lupov
 * @date 08/04/2019
 * @url https://leetcode.com/problems/divide-two-integers/
 **/
public class Divide {
    public static void main(String[] args) {

    }

    //TODO: SEE https://www.geeksforgeeks.org/divide-two-integers-without-using-multiplication-division-mod-operator/
    public static int divide(int dividend, int divisor) {
        // Calculate sign of divisor i.e., sign will be negative only if either one of them
        // is negative otherwise it will be positive
        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;

        // remove sign of operands
        dividend = Math.abs(dividend);
        divisor = Math.abs(divisor);

        // Initialize the quotient
        int quotient = 0, temp = 0;

        // test down from the highest bit and accumulate the tentative value for
        // valid bit 1<<31 behaves incorrectly and gives Integer
        // Min Value which should not be the case, instead 1L<<31 works correctly.
        for (int i = 31; i >= 0; --i) {

            if (temp + (divisor << i) <= dividend) {
                temp += divisor << i;
                quotient |= 1L << i;
            }
        }

        return (sign * quotient);
    }
}
