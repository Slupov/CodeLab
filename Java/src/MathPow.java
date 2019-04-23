/**
 * @author Stoyan Lupov
 * @date 08/04/2019
 * @url https://leetcode.com/problems/powx-n/
 **/

public class MathPow {
    public static void main(String[] args) {
        System.out.println(myPow(2.0000, -2));
    }

    public static double myPow(double x, int n) {
        if (n < 0) return myPow(1 / x, -(n + 1)) * (1 / x);

        if (n == 1) return x;
        if (n == 0) return 1;

        return (n % 2 == 0) ? myPow(x * x, n / 2) : myPow(x * x, n / 2) * x;
    }
}
