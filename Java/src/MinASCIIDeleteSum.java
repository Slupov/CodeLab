/**
 * @author Stoyan Lupov
 * @date 26/03/2019
 * @url https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/
 **/

//TODO UNDERSTAND SOLUTION
    
public class MinASCIIDeleteSum {
    public static void main(String[] args) {
        minimumDeleteSum("sea", "eat");
    }

    //Let dp[i][j] be the answer to the problem for the strings s1[i:], s2[j:].
    public static int minimumDeleteSum(String s1, String s2) {
        int[][] dp = new int[s1.length() + 1][s2.length() + 1];

        //iterate over first string
        for (int i = s1.length() - 1; i >= 0; i--) {
            dp[i][s2.length()] = dp[i + 1][s2.length()] + s1.codePointAt(i);
        }

        //iterate over second string
        for (int j = s2.length() - 1; j >= 0; j--) {
            dp[s1.length()][j] = dp[s1.length()][j + 1] + s2.codePointAt(j);
        }

        for (int i = s1.length() - 1; i >= 0; i--) {
            for (int j = s2.length() - 1; j >= 0; j--) {

                if (s1.charAt(i) == s2.charAt(j)) {
                    dp[i][j] = dp[i + 1][j + 1];
                } else {
                    dp[i][j] = Math.min(dp[i + 1][j] + s1.codePointAt(i),
                            dp[i][j + 1] + s2.codePointAt(j));
                }
            }
        }

        return dp[0][0];
    }
}
