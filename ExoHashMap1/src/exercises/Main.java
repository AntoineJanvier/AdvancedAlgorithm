package exercises;

import java.util.Scanner;

import static exercises.CHOICES.*;

/**
 * Created by Antoine Janvier
 * on 20/06/17.
 */

enum CHOICES {
    PENDING,
    ADD,
    PRINT,
    QUIT
}

public class Main {
    public static void main(String[] args) {

        Sorter sorter = new Sorter();
        CHOICES choice = PENDING;
        Scanner scanner = new Scanner(System.in);

        while (choice != QUIT) {
            print_menu();
            choice = CHOICES.valueOf(scanner.next().toUpperCase());
            switch (choice) {
                case ADD:
                    System.out.print("Word : ");
                    String new_word = scanner.next();
                    sorter.insertWord(new_word);
                    break;
                case PRINT:
                    sorter.print_hashmap();
                    break;
                default:
                    System.out.println("NOPE");
            }
        }
    }

    private static void print_menu() {
        System.out.println("MENU\n");
        System.out.println("ADD. Add a word");
        System.out.println("PRINT. Print all words");
        System.out.println("\nQUIT. Quit\n");
        System.out.print("Your choice : ");
    }
}
