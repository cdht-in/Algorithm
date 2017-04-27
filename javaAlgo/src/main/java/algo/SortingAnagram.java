package algo;

import java.util.*;

/**
 * Created by conghui on 4/26/17.
 */


/*
*
* 1. Sorting a list of words such anagrams are grouped together.
Input: ["abc","test","vac", "bac", "london", "cba", "cav", "lon", "pst"]
Output: ["abc", "bac", "cba", "vac", "cav", "london", "test", "lon", "pst"]
*
* */
public class SortingAnagram
{

    public List<String> sortAnagrams(List<String> words)
    {
        Map<String, List<String>> permToGroup = new HashMap<String, List<String>>();

        for (String word : words)
        {
            char[] chars = word.toCharArray();
            Arrays.sort(chars);
            String sorted = new String(chars);

            if (!permToGroup.containsKey(sorted))
            {
                permToGroup.put(sorted, new ArrayList<String>());
            }

            permToGroup.get(sorted).add(word);
        }


        List<String> ret = new ArrayList<String>();
        for (Map.Entry kv : permToGroup.entrySet())
        {
            List<String> perms = (List<String>) kv.getValue();
            for (String perm : perms)
            {
                ret.add(perm);
            }
        }

        return ret;
    }

    public static void main(String[] args) throws Exception
    {
        List<String> words = Arrays.asList(new String[]{"abc", "test", "vac", "bac", "london", "cba", "cav", "lon", "pst"});

        SortingAnagram sortingAnagram = new SortingAnagram();
        List<String> ret = sortingAnagram.sortAnagrams(words);
        for (String each : ret)
        {
            System.out.println(each);
        }

    }

}
