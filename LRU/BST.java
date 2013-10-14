
class Node {
  int val;
  Node left, right;
}

//Assumption: left.val < this.val <= right.val

public class BST {
  int ans = 0;
  Node root;
  
  // If current node is valid BST, then it will return number of nodes in current subtree. If not, it will return -1;
  int isBst(Node nd) {
    if(nd == null)
      return 0;

    int leftNodes = isBst(nd.left);
    int rightNodes = isBst(nd.right);

    // If any of child node is not valid BST, this will also not be a valid BST.
    if(leftNodes == -1 || rightNodes == -1) 
      return -1;

    // If current node is greater than left node then it has a invalid subtree.
    if(nd.left != null && nd.left.val >= nd.val)
      return -1;

    // Same case for right subtree.
    if(nd.right != null && nd.val > nd.right.val)
      return -1;

    // Now this node has a valid BST.
    int ret = 1 + leftNodes + rightNodes;
    ans = Math.max(ret, ans);
    return ret;
  }
}
