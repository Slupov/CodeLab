import java.util.Scanner;

/**
 * @author Stoyan Lupov
 * @date 26/03/2019
 * @url https://leetcode.com/problems/add-digits/
 **/
public class AddDigits {
    public static void main(String[] args) {
        System.out.println(addDigits(new Scanner(System.in).nextInt()));
    }

    //Find digital root by formula (https://en.wikipedia.org/wiki/Digital_root)
    public static int addDigits(int num) {
        return num - 9 * ((num - 1) / 9);
    }
}
