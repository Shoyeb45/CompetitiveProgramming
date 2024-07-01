package Tree;

public class CheckBT {
    public static void inorder(Node root) {
        if(root != null) {
            inorder(root.left);
            System.out.print(root.data + " ");
            inorder(root.right);
        }
    }
    public static void preorder(Node root) {
        if(root != null) {
            System.out.print(root.data + " ");
            preorder(root.left);
            preorder(root.right);
        }
    }
    public static void main(String[] args) {
        Node root = new Node(1);
        
        Node n1 = new Node(2);
        Node n2 = new Node(25);
        root.left = n1;
        root.right = n2;

        Node n3 = new Node(4);
        Node n4 = new Node(8);
        n1.left = n3;
        n1.right = n4;
        
        System.out.println("Inorder");
        inorder(root);
        System.out.println();
        System.out.println("Preorder");
        preorder(root);
    }    
}
