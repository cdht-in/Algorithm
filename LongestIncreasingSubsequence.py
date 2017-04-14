#!/usr/bin/python
# -*- coding: utf-8 -*-

'''

created at 4/6/17 9:14 PM


For example,
Given [10, 9, 2, 5, 3, 7, 101, 18],
The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that there may be more than one LIS combination, it is only necessary for you to return the length.

Your algorithm should run in O(n2) complexity.

Follow up: Could you improve it to O(n log n) time complexity?

'''

from Queue import PriorityQueue


class Solution(object):
    def lengthOfLIS(self, nums):

        q = PriorityQueue()
        maxLen = 0

        for num in nums:

            if q.qsize() == 0:
                q.put((-num, num))
            else:

                while q.qsize() > 0:
                    prio, head = q.get()
                    if head < num:
                        q.put((prio, head))
                        break

                q.put((-num, num))

        if q.qsize() > maxLen:
            maxLen = q.qsize()

        return maxLen

    def lengthOfLISN2(self, nums):

        if len(nums) == 0:
            return 0

        maxLen1 = 1
        for i in xrange(len(nums)):
            numi = nums[i]
            stack = [numi]
            for numj in nums[i + 1:]:

                if numj > stack[len(stack) - 1]:
                    stack.append(numj)

                maxLen1 = max(len(stack), maxLen1)

        reversedNum = list(reversed(nums))
        maxLen2 = 1
        for i in xrange(len(reversedNum)):
            numi = reversedNum[i]
            stack = [numi]
            for numj in reversedNum[i + 1:]:

                if numj < stack[len(stack) - 1]:
                    stack.append(numj)

                maxLen2 = max(len(stack), maxLen2)

        return max(maxLen1, maxLen2)


if __name__ == "__main__":
    # nums = [10, 9, 2, 5, 3, 7, 101, 18]
    # nums1 = [1, 3, 6, 7, 9, 4, 10, 5, 6]
    # nums2 = [2, 5, 3, 4]
    # nums3 = [3, 2, 1]

    # not working
    nums4 = [2, 15, 3, 7, 8, 6, 18]
    solution = Solution()

    # print solution.lengthOfLISN2(nums)
    # print solution.lengthOfLISN2(nums1)
    # print solution.lengthOfLISN2(nums2)
    # print solution.lengthOfLISN2(nums3)
    print solution.lengthOfLISN2(nums4)
