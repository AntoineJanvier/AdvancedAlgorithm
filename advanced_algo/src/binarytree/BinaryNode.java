package binarytree;

/**
 * Created by Antoine Janvier
 * on 04/07/17.
 */
public class BinaryNode<T> {
    BinaryNode<T> left;
    BinaryNode<T> right;

    T value;

    BinaryNode(T value) {
        this.value = value;
    }

    public BinaryNode(BinaryNode<T> left, BinaryNode<T> right, T value) {
        this.left = left;
        this.right = right;
        this.value = value;
    }
}
