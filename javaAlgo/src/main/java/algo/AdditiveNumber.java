package algo;

import java.math.BigInteger;

/**
 * Created by conghui on 4/30/17.
 */


/*
*
* Additive number is a string whose digits can form additive sequence.

A valid additive sequence should contain at least three numbers. Except for the first two numbers, each subsequent number in the sequence must be the sum of the preceding two.

For example:
"112358" is an additive number because the digits can form an additive sequence: 1, 1, 2, 3, 5, 8.

1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
"199100199" is also an additive number, the additive sequence is: 1, 99, 100, 199.
1 + 99 = 100, 99 + 100 = 199
Note: Numbers in the additive sequence cannot have leading zeros, so sequence 1, 2, 03 or 1, 02, 3 is invalid.

Given a string containing only digits '0'-'9', write a function to determine if it's an additive number.

Follow up:
How would you handle overflow for very large input integers?

Credits:
Special thanks to @jeantimex for adding this problem and creating all test cases.

Subscribe to see which companies asked this question.
*
* */


public class AdditiveNumber
{

    private boolean isAdditiveNumber(int start, String firstPart, String secondPart, String s)
    {
        if (start == s.length())
        {
            return true;
        }

        BigInteger sum = (new BigInteger(firstPart)).add(new BigInteger(secondPart));

        String sumStr = sum.toString();
        if (s.startsWith(sumStr, start) && isAdditiveNumber(start + sumStr.length(), secondPart, sumStr, s))
        {
            return true;
        }

        return false;
    }

    public boolean isAdditiveNumber(String num)
    {
        for (int i = 0; i < num.length(); i++)
        {
            String firstPart = num.substring(0, i + 1);

            if (firstPart.length() > 1 && firstPart.charAt(0) == '0')
            {
                continue;
            }

            for (int j = i + 1; j < num.length(); j++)
            {

                String secondPart = num.substring(i + 1, j + 1);

                if (secondPart.length() > 1 && secondPart.charAt(0) == '0')
                {
                    continue;
                }

                if (j + 1 < num.length() && isAdditiveNumber(j + 1, firstPart, secondPart, num))
                {
                    return true;
                }
            }
        }

        return false;

    }

    public static void main(String[] args) throws Exception
    {
        AdditiveNumber additiveNumber = new AdditiveNumber();
        String num = "101";
        System.out.println(additiveNumber.isAdditiveNumber(num));
    }

}
