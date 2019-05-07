/**
 * encoding: utf-8
 * @author: siru
 * @create on: 2019-05-07 15:30:10
 * @update on: 2019-05-07 15:50:31
 */
import java.util.List;
import java.util.LinkedList;
import java.util.Map;
import java.util.HashMap;

public class Solution {

    private List<String> queue;
    private Map<Character, String> map;
    
    public List<String> letterCombinations(String digits) {

        if (digits.isEmpty())
            return new LinkedList<>();

        propertiesInit();

        queue.add("");
        while (queue.get(0).length() < digits.length()) {
            String baseString = queue.remove(0);
            int curLength = baseString.length();
            String direction = map.get(digits.charAt(curLength));
            
            for (int i = 0; i < direction.length(); i ++)    
                queue.add(baseString + direction.charAt(i));
        }
        
        return queue;
    }
    
    private void propertiesInit() {

        queue = new LinkedList<>();
        map = new HashMap<>();
        
        map.put('2', "abc");
        map.put('3', "def");
        map.put('4', "ghi");
        map.put('5', "jkl");
        map.put('6', "mno");
        map.put('7', "pqrs");
        map.put('8', "tuv");
        map.put('9', "wxyz");
    }

    public static void main(String[] args) {

        List<String> res = (new Solution()).letterCombinations("23");
        System.out.println(res);
    }
}