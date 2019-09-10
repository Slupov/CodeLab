import java.util.*;

/**
 * @author Stoyan Lupov
 * @date 12/04/2019
 * @brief Searches through an array for a triplet which sums to 0
 * @url https://leetcode.com/problems/3sum/
 **/
public class SumOf3 {
    public static void main(String[] args) {
        SumOf3 s = new SumOf3();
        s.threeSum(new int[]{-1, 0, 1, 2, -1, -4});
    }

    /**
     * @brief The idea is to sort an input array and then run through all indices of a possible first element of a
     * triplet. For each possible first element we make a standard bi-directional 2Sum sweep of the remaining part of
     * the array. Also we want to skip equal elements to avoid duplicates in the answer without making a set or
     * something like that.
     * **/
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> res = new LinkedList<>();

        final int K = 0;

        for (int i = 0; i < nums.length - 2; i++) {

            //first element OR not duplicating elements
            if (i == 0 || (i > 0 && nums[i] != nums[i - 1])) {
                int lo = i + 1, hi = nums.length - 1, sum = K - nums[i];

                while (lo < hi) {

                    //found exact complement
                    if (nums[lo] + nums[hi] == sum) {
                        res.add(Arrays.asList(nums[i], nums[lo], nums[hi]));

                        //skip equals from the left
                        while (lo < hi && nums[lo] == nums[lo + 1]) lo++;

                        //skip equals from the right
                        while (lo < hi && nums[hi] == nums[hi - 1]) hi--;

                        //update pointers
                        lo++;
                        hi--;
                    }
                    //pair is lower than complement
                    else if (nums[lo] + nums[hi] < sum) lo++;
                    //pair is higher than complement
                    else hi--;
                }
            }
        }

        return res;
    }
}
