package binarytree;

/**
 * Created by Antoine Janvier
 * on 04/07/17.
 */
public class BinaryTree<T> {
    private BinaryNode<T> root;

    public BinaryTree(BinaryNode<T> root) {
        this.root = root;
    }

    private int getHeight() {
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
}
