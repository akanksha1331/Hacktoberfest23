/*
Given a string s, find the length of the longest 
substring
 without repeating characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/
//Solution:
class Longest-substring-without-repeating-characters {
    public int lengthOfLongestSubstring(String s) {
        if(s.length()==0){return 0;}
        int len=1;
        int l=0; int r=0;
        HashMap<Character, Integer> mpp= new HashMap<>();
        while(r<s.length()){
            if(mpp.containsKey(s.charAt(r))){
                l=Math.max(mpp.get(s.charAt(r))+1, l);

            }
            mpp.put(s.charAt(r),r);
            len=Math.max(len, r-l+1);
            r++;
        }
        return len;
    }
}
