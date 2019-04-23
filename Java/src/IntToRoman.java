import java.util.HashMap;
import java.util.Map;

/**
 * @author Stoyan Lupov
 * @date 10/04/2019
 **/
public class IntToRoman {
    public static void main(String[] args) {

    }

    public String intToRoman(int num) {

        int[] values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        String[] romanStrs = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < values.length; i++) {
            while (num >= values[i]) {
                num -= values[i];
                sb.append(romanStrs[i]);
            }
        }

        return sb.toString();
    }

    public int romanToInt(String s) {
        Map<Character, Integer> map = new HashMap<Character, Integer>(){{
            put('M', 1000);
            put('D', 500);
            put('C', 100);
            put('L', 50);
            put('X', 10);
            put('V', 5);
            put('I', 1);
        }};

        int result = 0;
        for (int i = 0; i < s.length() - 1; i++) {
            int val1 = map.get(s.charAt(i));
            int val2 = map.get(s.charAt(i + 1));

            if (val1 > val2){
                result += val1;
            }
            else{
                result += val2 - val1;
                ++i;
            }
        }

        return result;
    }
}
