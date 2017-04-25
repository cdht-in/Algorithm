package algo;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by conghui on 4/24/17.
 */

/*


Given a list of unique words, find all pairs of distinct indices (i, j) in the given list, so that the concatenation of the two words, i.e. words[i] + words[j] is a palindrome.

Example 1:
Given words = ["bat", "tab", "cat"]
Return [[0, 1], [1, 0]]
The palindromes are ["battab", "tabbat"]
Example 2:
Given words = ["abcd", "dcba", "lls", "s", "sssll"]
Return [[0, 1], [1, 0], [3, 2], [2, 4]]
The palindromes are ["dcbaabcd", "abcddcba", "slls", "llssssll"]

 */

public class PalindromePairs
{
    public boolean isPalinmdrme(String word)
    {
        if (word.length() == 0)
        {
            return false;
        }

        if (word.length() == 1)
        {
            return true;
        }

        for (int i = 0; i < word.length() / 2; i++)
        {
            if (word.charAt(i) != word.charAt(word.length() - 1 - i))
            {
                return false;
            }
        }

        return true;
    }

    public List<List<Integer>> palindromePairs(String[] words)
    {
        List<List<Integer>> ret = new ArrayList<List<Integer>>();
        for (int i = 0; i < words.length; i++)
        {
            for (int j = i + 1; j < words.length; j++)
            {
                String word = words[i] + words[j];

                if (isPalinmdrme(word))
                {
                    List<Integer> index = new ArrayList<Integer>();
                    index.add(i);
                    index.add(j);
                    ret.add(index);
                }

                word = words[j] + words[i];

                if (isPalinmdrme(word))
                {
                    List<Integer> index = new ArrayList<Integer>();
                    index.add(j);
                    index.add(i);
                    ret.add(index);
                }
            }
        }

        return ret;
    }

    public static void main(String[] args) throws Exception
    {
        PalindromePairs palindromePairs = new PalindromePairs();

        String[] words = {"bat", "tab", "cat"};

        String[] words1 = {"abcd", "dcba", "lls", "s", "sssll"};
        List<List<Integer>> ret = palindromePairs.palindromePairs(words1);
        for (List<Integer> each : ret)
        {
            System.out.println(each);
        }
    }

}
