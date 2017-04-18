package algo;

import java.util.ArrayList;
import java.util.List;
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
        int maxLen = 0;

        List<Stack<Integer>> powerSet = new ArrayList<Stack<Integer>>();

        for (int j = 0; j < nums.length; j++)
        {

            List<Stack<Integer>> subsets = new ArrayList<Stack<Integer>>();
            for (Stack each : powerSet)
            {
                Integer top = (Integer) each.peek();
                if (nums[j] > top)
                {
                    Stack<Integer> subSet = (Stack<Integer>) each.clone();
                    subSet.push(nums[j]);

                    subsets.add(subSet);
                }
            }

            Stack<Integer> stack = new Stack<Integer>();
            stack.push(nums[j]);

            powerSet.add(stack);

            powerSet.addAll(subsets);
        }

        for (Stack each : powerSet)
        {
            maxLen = Math.max(each.size(), maxLen);
        }

        return maxLen;
    }

    public static void main(String[] args) throws Exception
    {
        List<int[]> tests = new ArrayList<int[]>();

        tests.add(new int[]{2, 15, 3, 7, 8, 6, 18});
        tests.add(new int[]{2, 5, 3, 4});

        LongestIncreasingSubsequence longestIncreasingSubsequence = new LongestIncreasingSubsequence();

        for (int i = 0; i < tests.size(); i++)
        {
            System.out.println(longestIncreasingSubsequence.lengthOfLIS(tests.get(i)));
        }


    }

}
