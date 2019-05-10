import java.util.*;

public class Solution {

    private List<List<String>> res;
    private Map<String, Boolean> isPalindrome;
    private List<List<String>> stack;

    public List<List<String>> partition(String s) {

        res = new ArrayList<>();
        isPalindrome = new HashMap<>();
        stack = new ArrayList<>();

        List<String> firstRecord = new ArrayList<>();
        firstRecord.add(s);

        stack.add(firstRecord);
        dfs();

        return res;
    }

    private void dfs() {

        while (!stack.isEmpty()) {

            List<String> newRecord = stack.remove(stack.size() - 1);
            String lastString = newRecord.get(newRecord.size() - 1);

            if (isPalindrome(lastString)) {
                List<String> newRes = new ArrayList<>(newRecord);
                Collections.copy(newRes, newRecord);
                res.add(newRes);
            }
            newRecord.remove(newRecord.size() - 1);

            for (int i = 1; i < lastString.length(); i ++) {
                String left = lastString.substring(0, i);
                assert left.length() > 0;

                if (!isPalindrome(left))
                    continue;

                String right = lastString.substring(i);
                assert right.length() > 0;

                List<String> next = new ArrayList<>(newRecord);
                Collections.copy(next, newRecord);

                next.add(left);
                next.add(right);
                stack.add(next);
            }
        }
    }

    private boolean isPalindrome(String str) {

        Boolean res = isPalindrome.get(str);
        if (res != null)
            return res;

        int l = 0;
        int r = str.length() - 1;

        while (l < r) {
            if (str.charAt(l) != str.charAt(r)) {
                isPalindrome.put(str, false);
                return false;
            }
            l ++;
            r --;
        }
        isPalindrome.put(str, true);
        return true;
    }

    public static void main(String[] args) {

        String string = "aab";
        List<List<String>> res = (new Solution()).partition(string);
        System.out.println(res);
    }
}
