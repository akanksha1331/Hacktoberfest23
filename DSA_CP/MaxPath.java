// 124. Binary Tree Maximum Path Sum

// A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

//The path sum of a path is the sum of the node's values in the path.

//Given the root of a binary tree, return the maximum path sum of any non-empty path.

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class MaxPath {
    private int maxSum = Integer.MIN_VALUE;
    public int maxPathSum(TreeNode root) {
        findMaxPathSum(root);
        return maxSum;
    }

    public int findMaxPathSum(TreeNode root) {
        if (root == null) {
            return 0;
        }

        int leftMax = Math.max(0, findMaxPathSum(root.left));
        int rightMax = Math.max(0, findMaxPathSum(root.right));

        maxSum = Math.max(maxSum, leftMax + rightMax + root.val);

        return root.val + Math.max(leftMax, rightMax);
    }
}