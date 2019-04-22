import java.util.LinkedList;
import java.util.List;
import java.util.Stack;

public class Solution {

    private List<String> ipAddresses;
    private int[] currentIP;

    public List<String> restoreIpAddresses(String s) {

        ipAddresses = new LinkedList<>();
        currentIP = new int[4];

        searchAddressByDFS(s, 0, 0);
        return ipAddresses;
    }

    /**
     * 递归算法
     * @param s 整个字符串
     * @param si 当前检索到的位置, {0, 1, ..., s.length-1}
     * @param seg 当前需考虑的 ip 段, {0, 1, 2, 3}
     */
    public void searchAddressByDFS(String s, int si, int seg) {

        int remainingLength = s.length() - si;

        // 找到了一个
        if (seg == 4 && remainingLength == 0) {
            ipAddresses.add(currentIP[0] + "." + currentIP[1] + "." + currentIP[2] + "." + currentIP[3]);
            return;
        }

        // 一些无解的情况
        if (seg >= 4 || si >= s.length()
          || (4 - seg) * 3 < remainingLength
          || (4 - seg) > remainingLength)
            return;

        // 0
        if (s.charAt(si) == '0') {
            currentIP[seg] = 0;
            searchAddressByDFS(s, si + 1, seg + 1);
            return;
        }

        // 其他, 截取长度为 1, 2, 3
        int d = Math.min(3, remainingLength);
        for (int i = 1; i <= d; i ++) {

            int segNum = Integer.parseInt(s.substring(si, si + i));
            if (segNum < 0 || segNum > 255)
                break;

            currentIP[seg] = segNum;
            searchAddressByDFS(s, si + i, seg + 1);
        }
    }

    public static void main(String[] args) {

        String ipString = "25525511135";

        List<String> res = (new Solution()).restoreIpAddresses(ipString);
        System.out.println(res);
    }
}
