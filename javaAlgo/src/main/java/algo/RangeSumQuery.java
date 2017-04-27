package algo;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by conghui on 4/26/17.
 */


/*

* Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

Example:
Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
Note:
You may assume that the array does not change.
There are many calls to sumRange function.

*
* */
public class RangeSumQuery
{
    private List<Integer> indexSum;

    public RangeSumQuery(int[] nums)
    {
        int sum = 0;
        indexSum = new ArrayList<Integer>();
        for (int i = 0; i < nums.length; i++)
        {
            sum += nums[i];
            indexSum.add(sum);
        }

    }

    public int sumRange(int i, int j)
    {
        assert (i >= 0 && j < indexSum.size());

        if (i == 0)
        {
            return indexSum.get(j);
        }

        return indexSum.get(j) - indexSum.get(i - 1);

    }

    public static void main(String[] args) throws Exception
    {
    }

}
