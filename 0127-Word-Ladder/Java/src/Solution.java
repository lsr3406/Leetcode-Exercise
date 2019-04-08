import javafx.util.Pair;

import java.util.*;

public class Solution {

    public int ladderLength(String beginWord, String endWord, List<String> wordList) {

        // 初始化邻接表
        Map<String, ArrayList<String>> map = new HashMap<>();
        int l = beginWord.length();

        // 构造邻接表
        for (int i = 0; i < wordList.size(); i ++) {

            String word = wordList.get(i);
            for (int j = 0; j < l; j ++) {

                String key = word.substring(0, j) + "*" + word.substring(j+1, l);
                ArrayList<String> transformations = map.getOrDefault(key, new ArrayList<>());

                transformations.add(word);
                map.put(key, transformations);
            }
        }

        // 根据邻接表进行广度优先遍历
        Queue<Pair<String, Integer>> queue = new LinkedList<>();
        queue.add(new Pair<>(beginWord, 1));

        Map<String, Boolean> visited = new HashMap<>();
        visited.put(beginWord, true);

        while (!queue.isEmpty()) {

            Pair<String,Integer> cur = queue.remove();
            String curWord = cur.getKey();
            Integer curLevel = cur.getValue();

            for (int i = 0; i < l; i ++) {

                String key = curWord.substring(0, i) + "*" + curWord.substring(i+1, l);
                ArrayList<String> steps;
                steps = map.getOrDefault(key, new ArrayList<>());

                for (int j = 0; j < steps.size(); j ++) {
                    String next = steps.get(j);

                    if (next.equals(endWord))
                        return curLevel + 1;

                    if (!visited.containsKey(next)) {
                        visited.put(next, true);
                        queue.add(new Pair<>(next, curLevel + 1));
                    }
                }
            }
        }
        return 0;
    }

    public static void main(String[] args) {
        String beginWord = "hit";
        String endWord = "cog";
        List<String> wordList = Arrays.asList("hot", "dot", "dog", "lot", "log", "cog");

        int res = (new Solution()).ladderLength(beginWord, endWord, wordList);
        System.out.println(res);
    }
}
