// 101. Symmetric Tree

// Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

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
class SymmetricTree {
    public boolean isSymmetric(TreeNode root) {
        if(root == null){
            return true;
        }
        return Symm(root.right , root.left);
    }

    public boolean Symm(TreeNode n1 , TreeNode n2){
        if(n1 == null && n2 == null){
            return true;
        }
        if(n1 == null || n2 == null){
            return false;
        }
        return n1.val == n2.val && Symm(n1.left,n2.right) && Symm(n1.right,n2.left);
    }
}