package algo;

import java.util.Stack;

/**
 * Created by conghui on 4/13/17.
 * <p>
 * <p>
 * <p>
 * <p>
 * <p>
 * <p>
 * For example,
 * Given [10, 9, 2, 5, 3, 7, 101, 18],
 * The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that there may be more than one LIS combination, it is only necessary for you to return the length.
 * <p>
 * Your algorithm should run in O(n2) complexity.
 * <p>
 * Follow up: Could you improve it to O(n log n) time complexity?
 * <p>
 * https://leetcode.com/problems/longest-increasing-subsequence/#/description
 */

public class LongestIncreasingSubsequence
{
    public int lengthOfLIS(int[] nums)
    {
        if (nums.length == 0)
        {
            return 0;
        }

        int maxLen = 1;
        Stack<Integer> stack = new Stack();
        for (int i = 0; i < nums.length; i++)
        {

            stack.clear();
            stack.push(nums[i]);
            for (int j = i + 1; j < nums.length; j++)
            {
                Integer top = stack.peek();
                if (nums[j] > top.intValue())
                {
                    stack.push(nums[j]);
                }

                maxLen = Math.max(stack.size(), maxLen);

            }
        }

        return maxLen;
    }

    public static void main(String[] args) throws Exception
    {
        int[] nums4 = new int[]{2, 15, 3, 7, 8, 6, 18};

        LongestIncreasingSubsequence longestIncreasingSubsequence = new LongestIncreasingSubsequence();
        System.out.println(longestIncreasingSubsequence.lengthOfLIS(nums4));
    }

}
