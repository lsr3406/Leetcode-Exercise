/**
 * encoding: utf-8
 * @author: siru
 * @create on: 2019-07-09 14:19:04
 * @update on: 2019-07-09 15:24:47
 */
import java.util.List;
import java.util.ArrayList;

public class Solution {

    private static final String[][] hours = {
        {"0"},  // 0
        {"1", "2", "4", "8"},  // 1
        {"3", "5", "6", "9", "10"},  // 2
        {"7", "11"}  // 3
    };
    private static final String[][] minutes = {
        {"00"},  // 0
        {"01", "02", "04", "08", "16", "32"},  // 1
        {"03", "05", "06", "09", "10", "12", "17", "18", "20", "24", "33", "34", "36", "40", "48"},  // 2
        {"07", "11", "13", "14", "19", "21", "22", "25", "26", "28", "35", "37", "38", "41", "42", "44", "49", "50", "52", "56"},  // 3
        {"15", "23", "27", "29", "30", "39", "43", "45", "46", "51", "53", "54", "57", "58"},  // 4
        {"31", "47", "55", "59"},  // 5
    };

    public List<String> readBinaryWatch(int num) {
        
        if (num < 0 || num > 8)
            return new ArrayList<String>();
            // throw new IllegalArgumentException("The num must be larger than 0 and less than 8.");

        List<String> res = new ArrayList<>();
        for (int hourCount = 0; hourCount < Solution.hours.length; hourCount ++) {

            int minuteCount = num - hourCount;
            if (minuteCount < 0 || minuteCount >= Solution.minutes.length)
                continue;

            for (int i = 0; i < Solution.hours[hourCount].length; i ++) {
                for (int j = 0; j < Solution.minutes[minuteCount].length; j ++) {

                    String newTime = Solution.hours[hourCount][i] + ":" + Solution.minutes[minuteCount][j];
                    res.add(newTime);
                }
            }
        }
        return res;
    }

    public static void main(String[] args) {
        List<String> res = (new Solution()).readBinaryWatch(6);
        System.out.println(res);
    }
}
