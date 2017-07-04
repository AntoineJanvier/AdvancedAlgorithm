package binarytree;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by Antoine Janvier
 * on 04/07/17.
 */
public class BinaryTreePrinter<T extends  Comparable<T>> {

    public void prettyPrint(BinaryTree<T> tree) {
        List<BinaryNode<T>> list = new ArrayList<>();
        list.add(tree.root);
        System.out.println();
        System.out.println();
        System.out.println(" -------------- ");
        print(list, tree.getHeight());
        System.out.println(" -------------- ");
        System.out.println();
        System.out.println();
    }

    private void print(List<BinaryNode<T>> levelNodes, int level) {
        List<BinaryNode<T>> nodes = new ArrayList<>();
        printIndentForLevel(level);

        for (BinaryNode node: levelNodes) {
            System.out.print(node == null ? " " : node.value);
            printSpacingBetweenNodes(level);
            if(level>1){
                nodes.add(node == null ? null : node.left);
                nodes.add(node == null? null : node.right);
            }
        }
        System.out.println();
        if(level > 1){
            print(nodes, level-1);
        }
    }

    private void printIndentForLevel(int level){
        for (int i = (int) (Math.pow(2,level-1)); i >0; i--) {
            System.out.print(" ");
        }
    }

    private void printSpacingBetweenNodes(int level){
        for (int i = (int) ((Math.pow(2,level-1))*2)-1; i >0; i--) {
            System.out.print(" ");
        }
    }
}
