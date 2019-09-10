import java.util.Arrays;

/**
 * @author Stoyan Lupov
 * @date 27/03/2019
 **/
public class LongestIncreasingSubsequence {
    public static void main(String[] args) {
        lengthOfLIS(new int[]{0, 8, 4, 12, 2});
    }

    /** Using dynamic programming - calculating the LIS up to index (i + 1) taking into account the longest increasing
     * subsequence until index (i) **/
    public int lengthOfLISDP(int[] nums) {
        if (nums.length == 0) {
            return 0;
        }

        int[] dp = new int[nums.length];
        dp[0] = 1;

        int maxans = 1;
        for (int i = 1; i < dp.length; i++) {
            int maxval = 0;

            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    maxval = Math.max(maxval, dp[j]);
                }
            }

            dp[i] = maxval + 1;
            maxans = Math.max(maxans, dp[i]);
        }
        return maxans;
    }

    public static int lengthOfLIS(int[] nums) {

        //stores the increasing subsequence formed by including the currently encountered element.
        int[] dp = new int[nums.length];
        int len = 0;

        for (int num : nums) {
            int i = Arrays.binarySearch(dp, 0, len, num);

            //not found => get the index where it would be nested into the array if it was a part of it
            if (i < 0) {
                i = -(i + 1);
            }

            dp[i] = num;

            if (i == len) {
                len++;
            }
        }

        return len;
    }
}
