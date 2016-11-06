import java.util.*;

public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) {val = x;}
}

public class Solution {
    public HashMap<TreeNode, Integer> noNode = new HashMap<TreeNode, Integer>();
    public int rob(TreeNode root) {
        if(root == null)
            return 0;
        noNode.put(root, 0);
        int noLeft = 0;
        int resLeft = 0;
        if(root.left != null) {
            resLeft = rob(root.left);
            noLeft = noNode.get(root.left);
        }
        int noRight = 0;
        int resRight = 0;
        if(root.right != null) {
            resRight = rob(root.right);
            noRight = noNode.get(root.right);
        }
        root.val += noLeft + noRight;
        noNode.replace(root, resLeft + resRight);
        return root.val > noNode.get(root) ? root.val : noNode.get(root);
    }
}

