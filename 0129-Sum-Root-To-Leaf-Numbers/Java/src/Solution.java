/**
 * encoding: utf-8
 * @author: siru
 * @create on: 2019-04-27 12:25:30
 * @update on: 2019-04-27 12:25:58
 */
import java.lang.StringBuilder;
import java.util.List;
import java.util.ArrayList;

public class Solution {
    
    List<String> numberList;
    StringBuilder number;
    
    public int sumNumbers(TreeNode root) {
        
        if (root == null)
            return 0;
        
        numberList = new ArrayList<>();
        number = new StringBuilder();
        record(root);
        
        int sum = 0;
        for (String s: numberList) {
            sum += Integer.parseInt(s);
        }
        return sum;
    }
    
    private void record(TreeNode node) {
        
        number.append(node.val);
        
        if (node.left == null) {
            if (node.right == null) {
                numberList.add(number.toString());
                number.deleteCharAt(number.length() - 1);
                return;
            }
            else {
                record(node.right);
            }
        }
        else {
            record(node.left);
            if (node.right != null)
                record(node.right);
        }
        
        number.deleteCharAt(number.length() - 1);
        return;
    }
}