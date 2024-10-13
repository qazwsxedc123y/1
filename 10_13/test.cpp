#define  _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<unordered_set>
#include<unordered_map>

using namespace std;




//class Solution {
//public:
//    double triangleArea(int x1, int y1, int x2, int y2, int x3, int y3)
//    {
//        return 0.5 * abs(x1 * y2 + x2 * y3 + x3 * y1 - x1 * y3 - x2 * y1 - x3 * y2);
//    }
//    double largestTriangleArea(vector<vector<int>>& points)
//    {
//        int n = points.size();
//        double ret = 0;
//        for (int i = 0; i < n; i++)
//        {
//            for (int j = i + 1; j < n; j++)
//            {
//                for (int k = j + 1; k < n; k++)
//                {
//                    ret = max(ret, triangleArea(points[i][0], points[i][1], points[j][0], points[j][1], points[k][0], points[k][1]));
//                }
//            }
//        }
//        return ret;
//    }
//};

//class Solution {
//public:
//    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
//        int n = grid.size();
//        vector<int> rowMax(n);
//        vector<int> colMax(n);
//        for (int i = 0; i < n; i++)
//        {
//            for (int j = 0; j < n; j++)
//            {
//                rowMax[i] = max(rowMax[i], grid[i][j]);
//                colMax[j] = max(colMax[j], grid[i][j]);
//            }
//        }
//        int ret = 0;
//        for (int i = 0; i < n; i++)
//        {
//            for (int j = 0; j < n; j++)
//            {
//                ret += min(rowMax[i], colMax[j]) - grid[i][j];
//            }
//        }
//        return ret;
//    }
//};

//class Solution {
//public:
//    vector<int> numberOfLines(vector<int>& widths, string s) {
//        int line = 1;
//        int sum = 0;
//        for (int i = 0; i < s.size(); i++)
//        {
//            if (sum + widths[s[i] - 'a'] > 100)
//            {
//                line++;
//                sum = 0;
//            }
//            sum += widths[s[i] - 'a'];
//        }
//        return { line,sum };
//    }
//};

//const static string MORSE[] = {
//        ".-", "-...", "-.-.", "-..", ".", "..-.", "--.",
//        "....", "..", ".---", "-.-", ".-..", "--", "-.",
//        "---", ".--.", "--.-", ".-.", "...", "-", "..-",
//        "...-", ".--", "-..-", "-.--", "--.."
//};
//class Solution {
//public:
//    int uniqueMorseRepresentations(vector<string>& words) {
//        unordered_set<string> seen;
//        for (auto& word : words)
//        {
//            string code;
//            for (auto& e : word)
//            {
//                code.append(MORSE[e - 'a']);
//            }
//            seen.emplace(code);
//        }
//        return seen.size();
//    }
//};