import java.util.ArrayList;
import java.util.Iterator;

/**
 * @author Stoyan Lupov
 * @date 08/04/2019
 * @url https://leetcode.com/problems/simplify-path/
 **/
public class SimplifyPath {
    public static void main(String[] args) {

    }

    public String simplifyPath(String path) {

        String[] splitted = path.split("/");
        ArrayList<String> list = new ArrayList<String>();

        for (int i = 0; i < splitted.length; i++) {
            String command = splitted[i];

            switch (command) {
                case "..":
                    if (list.size() > 0)
                        list.remove(list.size() - 1);
                    break;
                case ".":
                case "":
                    break;
                default:
                    list.add(command);
                    break;
            }
        }

        String output = "";

        Iterator iterator = list.iterator();
        while (iterator.hasNext()) {
            output = output + "/" + iterator.next();
        }

        return (output == "") ? "/" : output;
    }
}
