/**
 * encoding: utf-8
 * @author: siru
 * @create on: 2019-03-24 09:18:05
 * @update on: 2019-03-24 09:59:41
 */
import java.util.Stack;
import java.lang.StringBuilder;

class Solution {

    // 71. Simplify Path
    // https://leetcode.com/problems/simplify-path/

    public String simplifyPath(String path) {

        String[] records = path.split("/");
        Stack<String> stack = new Stack<>();

        for (String item: records) {
            if (item.equals("..")) {
                if (!stack.isEmpty())
                    stack.pop();
            }
            else if (item.equals("") || item.equals("."))
                continue;
            else
                stack.push(item);
        }

        StringBuilder res = new StringBuilder();
        for (String item: stack) {
            res.append("/" + item);
        }
        return res.length() > 0 ? res.toString() : "/";
    }

    public static void main(String[] args) {
        
        String path = "/home/";
        System.out.println(path);

        String res = (new Solution()).simplifyPath(path);
        System.out.println(res);
    }
}