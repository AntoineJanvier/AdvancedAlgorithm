package binarytree;

/**
 * Created by Antoine Janvier
 * on 04/07/17.
 */
public class Main {
    public static void main(String[] args) {


        BinaryNode<Integer> root = new BinaryNode<>(1);
        root.left = new BinaryNode<>(2);
        root.right = new BinaryNode<>(3);

        root.left.left = new BinaryNode<>(4);
        root.left.right = new BinaryNode<>(5);
    }
}
