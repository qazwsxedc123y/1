#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        vector<vector<int>> ret;
        for (int i = 0; i < n; i++)
        {
            int l = intervals[i][0], r = intervals[i][1];
            // гажиЕў
            if (ret.empty() || ret.back()[1] < l)
            {
                ret.push_back({ l, r });
            }
            else
            {
                ret.back()[1] = max(ret.back()[1], r);
            }
        }
        return ret;
    }
};