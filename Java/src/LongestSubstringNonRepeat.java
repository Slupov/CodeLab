import java.util.HashMap;
import java.util.Map;

/**
 * @author Stoyan Lupov
 * @date 10/04/2019
 * @url https://leetcode.com/problems/longest-substring-without-repeating-characters/
 **/
public class LongestSubstringNonRepeat {
    public static void main(String[] args) {
        lengthOfLongestSubstring("abcabcbb");
    }

    public static  int lengthOfLongestSubstring(String s) {
        int result = 0;

        Map<Character, Integer> numberIndexes = new HashMap<Character, Integer>();

        //i - the window's starting index
        //j - the window's ending index
        for (int j = 0, i = 0; j < s.length(); j++) {

            if (numberIndexes.containsKey(s.charAt(j))) {
                //restrict window's starting index to skip current substring until repeated character
                i = Math.max(i, numberIndexes.get(s.charAt(j)) + 1);
            }

            //update result with new window size
            result = Math.max(result, j - i + 1);

            //add / update character index in the map
            numberIndexes.put(s.charAt(j), j);
        }

        return result;
    }
}
