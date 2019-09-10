/**
 * @author Stoyan Lupov
 * @date 10/04/2019
 * @url https://leetcode.com/problems/longest-palindromic-substring/solution/
 **/
public class LongestPalindromeSubstring {
    public static void main(String[] args) {
        longestPalindrome("babad");
    }

    public static String longestPalindrome(String s) {
        int start = 0;
        int end = 0;

        if (s == null || s.equals("")){
            return "";
        }

        //expand each possible palindrome middle and get the best size
        for (int i = 0; i < s.length(); i++) {

            //for odd sized palindromes
            int p1 = calculatePalindromeSize(s, i, i);

            //for even sized palindromes
            int p2 = calculatePalindromeSize(s, i, i + 1);

            int len = Math.max(p1, p2);

            if (len > end - start) {
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }

        return s.substring(start, end + 1);
    }

    public static int calculatePalindromeSize(String s, int midL, int midR){
        int l = midL;
        int r = midR;

        while(l >= 0 && r < s.length()){
            //check for palindrome end condition
            if (s.charAt(l) != s.charAt(r)){
                break;
            }

            --l;
            ++r;
        }

        return r - l - 1;
    }
}
