#define  _CRT_SECURE_NO_WARNINGS

class Solution {
public:
    int candy(vector<int>& ratings) {
        int ret = 0;
        // 左右两边统计，分别统计至少几个糖果才可以满足
        int n = ratings.size();
        vector<int> dp(n, 1);
        for (int i = 1; i < n; i++)
        {
            if (ratings[i] > ratings[i - 1])
            {
                dp[i] = dp[i - 1] + 1;
            }
        }

        for (int i = n - 2; i >= 0; i--)
        {
            if (ratings[i] > ratings[i + 1])
            {
                dp[i] = max(dp[i], dp[i + 1] + 1);
            }
        }

        for (int i = 0; i < n; i++)
        {
            ret += dp[i];
        }
        return ret;
    }
};

class Solution {
public:
    int candy(vector<int>& ratings) {
        int ret = 0;
        // 左右两边统计，分别统计至少几个糖果才可以满足
        int n = ratings.size();
        vector<int> f(n, 1); // 左 -》 右
        vector<int> g(n, 1); // 右 -》 左
        for (int i = 1; i < n; i++)
        {
            if (ratings[i] > ratings[i - 1])
            {
                f[i] = f[i - 1] + 1;
            }
        }

        for (int i = n - 2; i >= 0; i--)
        {
            if (ratings[i] > ratings[i + 1])
            {
                g[i] = g[i + 1] + 1;
            }
        }

        for (int i = 0; i < n; i++)
        {
            ret += max(f[i], g[i]);
        }
        return ret;
    }
};


class Solution {
public:
    int candy(vector<int>& ratings) {
        int ret = 0;
        // 连续上/下台阶次数？
        // 单次下一次不计算
        int n = ratings.size();
        ret += n;
        // 统计连续上下台阶次数
        // 但是如果是峰值，且两边连续大于1有问题
        for (int i = 1; i < n; i++)
        {
            int count = 0;
            if (ratings[i] > ratings[i - 1]) // 统计上
            {
                while (i < n && ratings[i] > ratings[i - 1])
                {
                    count++;
                    i++;
                    ret += count;
                }
            }
            else
            {
                while (i < n && ratings[i] < ratings[i - 1])
                {
                    count++;
                    i++;
                    ret += count;
                }
            }
        }
        return ret;
    }
};
