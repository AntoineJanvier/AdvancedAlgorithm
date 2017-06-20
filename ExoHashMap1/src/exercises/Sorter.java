package exercises;

import java.util.HashMap;

/**
 * Created by Antoine Janvier
 * on 20/06/17.
 */
class Sorter {

    private HashMap<Integer, String> hm;
    private int number_inserted;

    Sorter() {
        this.hm = new HashMap<>();
        this.number_inserted = 0;
    }

    void print_hashmap() {
        this.hm.forEach((key, value) -> System.out.println(key + ". " + value));
    }
    void insertWord(String word) {
        this.hm.put(this.number_inserted + 1, word);
        this.number_inserted++;
    }
}
