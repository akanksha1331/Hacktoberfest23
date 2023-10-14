// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

// Example 1:

// Input: n = 3
// Output: ["((()))","(()())","(())()","()(())","()()()"]
// Example 2:

// Input: n = 1
// Output: ["()"]

// Constraints:
// 1 <= n <= 8

//Solution

class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> res = new ArrayList();
        findAll("(", 1, 0, res, n);

        return res;
    }

    void findAll(String current, int op, int cl, List<String> res, int n) {
        if (current.length() == 2 * n) {
            res.add(current);
            return;
        }
        if (op < n)
            findAll(current + "(", op + 1, cl, res, n);
        if (cl < op)
            findAll(current + ")", op, cl + 1, res, n);
    }
}

// github.com/manisanghsharma