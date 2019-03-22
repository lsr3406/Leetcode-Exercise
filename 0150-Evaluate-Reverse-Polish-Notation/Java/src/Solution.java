/**
 * encoding: utf-8
 * @author: siru
 * @create on: 2019-03-22 17:13:34
 * @update on: 2019-03-22 17:29:06
 */
import java.util.Stack;

class Solution {

    // 150. Evaluate Reverse Polish Notation
    // https://leetcode.com/problems/evaluate-reverse-polish-notation/

    public int evalRPN(String[] tokens) {

        Stack<Integer> record = new Stack<>();
        for (String s: tokens) {
            if (isOperator(s)) {
                try {
                    int res = calculate(record.pop(), record.pop(), s);
                    record.push(res);
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
            else {  // is Number
                record.push(Integer.parseInt(s));
            }
        }
        return record.peek();
    }

    public boolean isOperator(String s) {
        if (s.length() > 1)
            return false;
        return s.equals("+") || s.equals("-") || s.equals("*") || s.equals("/");
    }

    public int calculate(int num1, int num2, String op) {
        switch (op) {
            case "+":
                return num2 + num1;
            case "-":
                return num2 - num1;
            case "*":
                return num2 * num1;
            case "/":
                return num2 / num1;
            default:
                throw new IllegalArgumentException("Illegal operator");
        }
    }

    public static void main(String[] args) {
        String[] tokens = {"2", "1", "+", "3", "*"};

        int res = (new Solution()).evalRPN(tokens);
        System.out.println(res);
    }
}
