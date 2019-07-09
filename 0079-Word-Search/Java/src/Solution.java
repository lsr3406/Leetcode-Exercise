/**
 * encoding: utf-8
 * @author: siru
 * @create on: 2019-07-09 21:09:40
 * @update on: 2019-07-09 21:40:22
 */


public class Solution {

    private char[][] board;
    private boolean[][] visited;
    private int width;
    private int height;
    private int[][] direction = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    public boolean exist(char[][] board, String word) {

        this.board = board;
        this.height = board.length;
        this.width = board[0].length;

        // visited 初始化
        visited = new boolean[height][width];

        // 遍历起点
        for (int y = 0; y < height; y ++) {
            for (int x = 0; x < width; x ++) {

                // 找到一个起点
                if (board[y][x] == word.charAt(0)) {

                    // 清空 visited 数组
                    for (int i = 0; i < height; i ++)
                        for (int j = 0; j < width; j ++)
                            visited[i][j] = false;

                    visited[y][x] = true;
                    if (dfs(x, y, word, 1))
                        return true;

                    visited[y][x] = false;
                }
            }
        }

        return false;
    }

    /**
     * dfs
     * @param  x     当前点坐标, axis = 1
     * @param  y     当前点坐标, axis = 0
     * @param  word  待查单词
     * @param  index 下一个要考察的索引
     * @return       是否找到完整的单词
     */
    private boolean dfs(int x, int y, String word, int index) {

        if (index == word.length())
            return true;

        for (int i = 0; i < direction.length; i ++) {
            int newX = x + direction[i][0];
            int newY = y + direction[i][1];

            if (isValid(newX, newY) && word.charAt(index) == board[newY][newX] && !visited[newY][newX]) {

                visited[newY][newX] = true;
                if (dfs(newX, newY, word, index + 1))
                    return true;

                visited[newY][newX] = false;
            }
        }
        return false;
    }

    private boolean isValid(int x, int y) {
        return x >= 0 && x < width && y >= 0 && y < height;
    }

    public static void main(String[] args) {

        char[][] board = {
            {'A','B','C','E'},
            {'S','F','C','S'},
            {'A','D','E','E'}
        };

        String word1 = "ABCCED";
        String word2 = "SEE";
        String word3 = "ABCB";

        Solution solution = new Solution();

        System.out.println(solution.exist(board, word1));
        System.out.println(solution.exist(board, word2));
        System.out.println(solution.exist(board, word3));
    }
}
