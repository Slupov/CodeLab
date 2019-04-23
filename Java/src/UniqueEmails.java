import java.util.HashSet;
import java.util.Set;

/**
 * @author Stoyan Lupov
 * @date 27/03/2019
 * @url https://leetcode.com/problems/unique-email-addresses/solution/
 **/
public class UniqueEmails {
    public static void main(String[] args) {
        numUniqueEmails(new String[]{"testemail@leetcode.com","testemail1@leetcode.com","testemail+david@lee.tcode.com"});
    }

    public static int numUniqueEmails(String[] emails) {
        Set<String> seen = new HashSet<String>();

        for (String e : emails) {
            int delimiterIdx = e.indexOf("@");

            String local = e.substring(0, delimiterIdx);
            String domain = e.substring(delimiterIdx);

            if (local.contains("+")) {
                local = local.substring(0, local.indexOf('+'));
            }

            local = local.replace(".", "");
            seen.add(local + domain);
        }

        return seen.size();
    }
}
