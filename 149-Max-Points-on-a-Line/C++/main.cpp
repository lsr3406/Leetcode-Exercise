/**
 * encoding: utf-8
 * @author: siru
 * @create on: 2019-03-03 18:51:37
 * @update on: 2019-03-03 22:23:37
 */
#include <iostream>
#include <cassert>
#include <math.h>
#include <vector>
#include <map>

using namespace std;

// 149. Max Points on a Line
// https://leetcode.com/problems/max-points-on-a-line

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:

    /**
     * 设置一个映射表, key 为表征直线斜率的一个数据对, value 表示满足这种斜率的点有多少对.
     * 最后根据三角形数的特征来推导返回值公式.
     */
    int maxPoints(vector<Point>& points) {

        if (points.size() == 0)
            return 0;

        int res = 1;
        for (int i = 0; i < points.size(); i ++) {

            map<pair<int,int>, int> record;
            int samePoint = 0;
            for (int j = 0; j < points.size(); j ++) {

                if (points[i].x == points[j].x && points[i].y == points[j].y)
                    samePoint ++;
                else
                    record[getKey(points[i], points[j])]++;
            }

            res = max(res, samePoint);

            for (map<pair<int,int>,int>::iterator iter = record.begin() ; iter != record.end() ; iter ++)
                res = max( res , iter->second + samePoint );
        }

        return res;
    }

    pair<int, int> getKey(Point& a, Point& b) {

        int dx = a.x - b.x;
        int dy = a.y - b.y;

        if (dx == 0)
            return make_pair(0, 1);
        if (dy == 0)
            return make_pair(1, 0);

        if (dx < 0) {
            dx = -dx;
            dy = -dy;
        }
        standardize(dx, dy);

        return make_pair(dx, dy);
    }

    void standardize(int& dx, int& dy) {

        int a = abs(dx), b = abs(dy);

        if (a < b)
            swap(a, b);

        while (a % b != 0) {
            int temp = a;
            a = b;
            b = temp % b;
        }

        dx /= b;
        dy /= b;
    }
};

int main(int argc, char const *argv[]) {

    //  23 /  10 =  2,  23 %  10 =  3
    //  23 / -10 = -2,  23 % -10 =  3
    // -23 /  10 = -2, -23 %  10 = -3
    // -23 / -10 =  2, -23 % -10 = -3

    vector<Point> points;

    // points.push_back(Point(1, 1));
    // points.push_back(Point(3, 2));
    // points.push_back(Point(5, 3));
    // points.push_back(Point(4, 1));
    // points.push_back(Point(2, 3));
    // points.push_back(Point(1, 4));

    // points.push_back(Point(0, 0));
    // points.push_back(Point(1, 0));
    // points.push_back(Point(0, 0));

    points.push_back(Point(84,250));
    points.push_back(Point(0,0));
    points.push_back(Point(1,0));
    points.push_back(Point(0,-70));
    points.push_back(Point(0,-70));
    points.push_back(Point(1,-1));
    points.push_back(Point(21,10));
    points.push_back(Point(42,90));
    points.push_back(Point(-42,-230));

    // points.push_back(Point(1, 1));
    // points.push_back(Point(1, 1));
    // points.push_back(Point(2, 2));
    // points.push_back(Point(2, 2));

    cout << Solution().maxPoints(points) << endl;

    return 0;
}
