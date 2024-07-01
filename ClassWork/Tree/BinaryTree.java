package Tree;

class Node {
   int data;
   Node left;
   Node right;
   Node parent;

   Node(int val) {
    this.data = val;
    this.left = this.right = this.parent = null;
   }
}
