import java.util.ArrayList;
import java.util.Collections;
/**
 * @brief Written during proxiad interview
 * */
public class MergeSort {

    public static void merge(ArrayList<Integer> arr, int from, int mid, int to) {
        ArrayList<Integer> left = new ArrayList<>();
        ArrayList<Integer> right = new ArrayList<>();

        int n1 = mid - from + 1;
        int n2 = to - mid;

        // populate left & right
        for (int i = 0; i < n1; i++) {
            left.add(arr.get(from + i));
        }

        for (int i = 0; i < n2; i++) {
            right.add(arr.get(mid + i + 1));
        }

        // merging two halves
        int lPtr = 0;
        int rPtr = 0;
        int origPtr = from;

        while (lPtr < n1 && rPtr < n2) {
            if (left.get(lPtr) < right.get(rPtr)) {
                arr.set(origPtr, left.get(lPtr));
                ++lPtr;
            } else {
                arr.set(origPtr, right.get(rPtr));
                ++rPtr;
            }

            ++origPtr;
        }

        //add leftovers from left
        while (lPtr < n1) {
            arr.set(origPtr, left.get(lPtr));
            ++lPtr;
            ++origPtr;
        }

        //add leftovers from right
        while (rPtr < n2) {
            arr.set(origPtr, right.get(rPtr));
            ++rPtr;
            ++origPtr;
        }
    }

    public static void mergeSort(ArrayList<Integer> arr, int from, int to) {
        //recursion bottom
        if (from >= to) {
            return;
        }

        int m = (from + to) / 2;

        mergeSort(arr, from, m);
        mergeSort(arr, m + 1, to);

        merge(arr, from, m, to);
    }

    public static boolean binarySearch(ArrayList<Integer> arr, int from, int to, Integer searchedValue) {
        //recursion bottom
        if (from >= to){
            return false;
        }

        int mid = (from + to) / 2;

        if (arr.get(mid).equals(searchedValue)){
            System.out.println("Found value: " + searchedValue + " at index " + mid);
            return true;
        }

        //check left
        binarySearch(arr, from, mid, searchedValue);
        binarySearch(arr, mid + 1, to, searchedValue);

        //default case
        return false;
    }

    public static void main(String[] args) {
        ArrayList<Integer> arr = new ArrayList<>();

        arr.add(6);
        arr.add(1);
        arr.add(3);
        arr.add(2);
        arr.add(7);
        arr.add(4);
        arr.add(5);

//        Collections.shuffle(arr);

        System.out.println(arr);

        mergeSort(arr, 0, arr.size() - 1);
        System.out.println(arr);

        binarySearch(arr, 0, arr.size() - 1, 5);
    }
}
