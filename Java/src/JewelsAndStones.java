import java.io.BufferedReader;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

/**
 * @author Stoyan Lupov
 * @date 26/03/2019
 * @url https://leetcode.com/problems/jewels-and-stones/
 **/
public class JewelsAndStones {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        //type of stones
        String J = scanner.nextLine();

        //stones in possession
        String S = scanner.nextLine();

        System.out.println(J);
        System.out.println(S);

        numJewelsInStones(J,S);
    }

    //Lambda -> Super slow (~44ms)
    public static int numJewelsInStones(String J, String S) {
        return (int)S.chars().mapToObj(i -> (char)i)
                .filter(c -> J.contains(c + ""))
                .count();
    }

    //HashSet -> ~1ms
    public static int numJewelsInStones2(String J, String S) {
        Set<Character> s = new HashSet();

        for (char j : J.toCharArray()){
            s.add(j);
        }

        int count = 0;
        for (char stone : S.toCharArray()) {
            if (s.contains(stone)) count++;
        }

        return count;
    }

}
