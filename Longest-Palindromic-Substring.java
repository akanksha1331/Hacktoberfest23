/*
Given a string, we have to find the longest palindromic substring(substring is a sequence of characters that is contiguous within a string. For example, the string “Interviewbit”, “er”, “view”, “bit”,…etc are substrings, but not “tr” as both these characters are not continuous. Whereas palindrome is a word that reads the same backward as forwards. Examples include abba, zzzz, xyyx
*/

import java.util.*;
import java.lang.*;
import java.io.*;
class Main {
    public static int longestPalSubstr(String str)
    {
        // get length of input String
        int n = str.length();
    
        // All subStrings of length 1
        // are palindromes
        int maxLength = 1, start = 0;
    
        // Nested loop to mark start and end index
        for (int i = 0; i < str.length(); i++) {
            for (int j = i; j < str.length(); j++) {
                int flag = 1;
    
                // Check palindrome
                for (int k = 0; k < (j - i + 1) / 2; k++)
                    if (str.charAt(i + k) != str.charAt(j - k))
                        flag = 0;
    
                // Palindrome
                if (flag!=0 && (j - i + 1) > maxLength) {
                    start = i;
                    maxLength = j - i + 1;
                }
            }
        }
    
        // return length of LPS
        return maxLength;
    }
    public static void main(String args[]) {
        // Your code goes here
        String s = "Hello";
        System.out.println(longestPalSubstr(s));
    }
}
