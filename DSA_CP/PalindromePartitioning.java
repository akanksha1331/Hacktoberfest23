// Leetcode 131 : Palindrome Partitioning

//Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

class PalindromePartitioning {
    public List<List<String>> partition(String s) {
        List<List<String>> res = new ArrayList<>();
        helper(s, res, new ArrayList<>(), 0);
        return res;
    }

    public void helper(String s, List<List<String>> res, List<String> currentList, int start) {
        if (start == s.length()) {
            res.add(new ArrayList<>(currentList));
            return;
        }

        for (int end = start + 1; end <= s.length(); end++) {
            String substring = s.substring(start, end);
            if (isPalindrome(substring)) {
                currentList.add(substring);
                helper(s, res, currentList, end);
                currentList.remove(currentList.size() - 1);
            }
        }
    }

    public boolean isPalindrome(String str) {
        int left = 0;
        int right = str.length() - 1;
        
        while (left < right) {
            if (str.charAt(left) != str.charAt(right)) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
}
