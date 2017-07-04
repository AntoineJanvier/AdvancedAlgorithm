package binarytree;

/**
 * Created by Antoine Janvier
 * on 04/07/17.
 */
public class BinaryTree<T extends Comparable<T>> {
    BinaryNode<T> root;

    public BinaryTree(BinaryNode<T> root) {
        this.root = root;
    }

    int getHeight() {
        return getHeight(root);
    }

    private int getHeight(BinaryNode<T> node) {
        if (node == null) return 0;
        return 1 + Math.max(
                getHeight(node.left),
                getHeight(node.right)
        );
    }

    private int getSize() {
        return getSize(root);
    }

    private int getSize(BinaryNode<T> node) {
        if (node == null) return 0;
        return 1 + getSize(node.left) + getSize(node.right);
    }

    public boolean isComplete() {
        int height = getHeight();
        int size = getSize();
        return (Math.pow(2, height) - 1 == size);
    }

    public boolean isBinarySearchTree() {
        return isBinarySearchTree(root, null, null);
    }

    private boolean isBinarySearchTree(BinaryNode<T> node, BinaryNode<T> min, BinaryNode<T> max) {
        return node == null || !((min != null && min.value.compareTo(node.value) == 1) || (max != null && max.value.compareTo(node.value) == -1)) && isBinarySearchTree(node.left, min, node) && isBinarySearchTree(node.right, node, max);
    }
}
