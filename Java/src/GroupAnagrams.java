import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * @author Stoyan Lupov
 * @date 16/04/2019
 * @url https://leetcode.com/problems/group-anagrams/
 **/
public class GroupAnagrams {
    public static void main(String[] args) {
        GroupAnagrams ga = new GroupAnagrams();
        ga.groupAnagrams(new String[]{"eat","tan","four","tea","ate","ruof","nat","bat"});
    }

    public List<List<String>> groupAnagrams(String[] strs) {
        int[] primes = new int[]{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79,
                83, 89, 97, 101, 103};

        //key   - calculated unique number for an anagram
        //value - the index of the corresponding anagram group in the resulting array
        Map<Integer, Integer> map = new HashMap<>();
        List<List<String>> result = new ArrayList<>();

        int key = 0;

        //iterate every string
        for (String str : strs) {
            key = 1;

            //iterate every character in a string
            for (int i = 0; i < str.length(); i++) {
                key *= primes[str.charAt(i) - 'a'];
            }

            List<String> groupRef;

            if (map.containsKey(key)) {
                //make the list reference point to the correct group in the result
                groupRef = result.get(map.get(key));
            } else {
                //create a new group and add it to the resulting collection
                groupRef = new ArrayList<>();
                result.add(groupRef);

                //add the new calculated key in the map
                map.put(key, result.size() - 1);
            }

            //update the new group with the current anagram"t
            groupRef.add(str);
        }

        return result;
    }
}