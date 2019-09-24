package collections.arraylist;

import java.util.Arrays;
import java.util.Random;
import java.util.concurrent.ThreadLocalRandom;
import java.util.stream.Stream;

public class Sortings {

    public static void bubbleSort(int[] arr) {
        // bubble sort
        for (int i = 0; i < arr.length - 1; i++) {
            for (int j = 0; j < arr.length - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {

                    //swap
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    public static void insertionSort(int[] arr) {
        //insertion sort
        for (int i = 1; i < arr.length; i++) {
            int picked = arr[i];

            int j = i - 1;
            while (j >= 0 && picked < arr[j]) {
                arr[j + 1] = arr[j];
                --j;
            }

            arr[j + 1] = picked;
        }
    }

    public static void selectionSort(int[] arr) {
        //selection sort
        for (int i = 0; i < arr.length; i++) {
            int swapIdx = i;

            //find current min
            for (int j = i + 1; j < arr.length; j++) {
                if (arr[j] < arr[swapIdx]) {
                    swapIdx = j;
                }
            }

            //simple swap
            int temp = arr[i];
            arr[i] = arr[swapIdx];
            arr[swapIdx] = temp;
        }
    }

    public static void mergeSort(int[] arr, int from, int to) {
        //merge sort
        if (from >= to) return;

        int mid = (from + to) / 2;

        mergeSort(arr, from, mid);
        mergeSort(arr, mid + 1, to);

        merge(arr, from, mid, to);
    }

    public static void merge(int[] arr, int from, int mid, int to) {
        // sizes
        int n1 = mid - from + 1;
        int n2 = to - mid;

        //temp arrays
        int left[] = new int[n1];
        int right[] = new int[n2];

        for (int i = 0; i < n1; i++) {
            left[i] = arr[from + i];
        }

        for (int i = 0; i < n2; i++) {
            right[i] = arr[mid + 1 + i];
        }

        int lPtr = 0, rPtr = 0, origPtr = from;

        while (lPtr < n1 && rPtr < n2) {
            if (left[lPtr] < right[rPtr]) {
                arr[origPtr++] = left[lPtr++];
            } else {
                arr[origPtr++] = right[rPtr++];
            }
        }

        //add leftovers from left
        while (lPtr < n1) {
            arr[origPtr++] = left[lPtr++];
        }

        //add leftovers from right
        while (rPtr < n2) {
            arr[origPtr++] = right[rPtr++];
        }
    }

    public static void shuffleArr(int[] arr) {
        Random rnd = ThreadLocalRandom.current();
        for (int i = arr.length - 1; i > 0; i--) {
            int index = rnd.nextInt(i + 1);

            // Simple swap
            int a = arr[index];
            arr[index] = arr[i];
            arr[i] = a;
        }

        System.out.println("Array shuffled");
        System.out.println(Arrays.toString(arr));
    }

    public static void main(String[] args) {
        int[] arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

        shuffleArr(arr);

        //------------ BUBBLE SORT ------------
        bubbleSort(arr);
        System.out.println(Arrays.toString(arr));

        shuffleArr(arr);

        //------------ INSERTION SORT ------------
        insertionSort(arr);
        System.out.println(Arrays.toString(arr));

        shuffleArr(arr);

        //------------ SELECTION SORT ------------
        selectionSort(arr);
        System.out.println(Arrays.toString(arr));

        shuffleArr(arr);

        //------------ MERGE SORT ------------
        mergeSort(arr, 0, arr.length - 1);
        System.out.println(Arrays.toString(arr));

        Stream.generate(Math::random).limit(5).forEach(System.out::println);
    }
}