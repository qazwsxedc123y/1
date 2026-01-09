class Solution {
public:
    int binary_l(vector<int>& nums, int target) // 第一个大于等于 target 的位置
    {
        int left = 0, right = nums.size() - 1;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        return left;
    }

    int binary_r(vector<int>& nums, int target) // 第一个大于 target 的位置
    {
        int left = 0, right = nums.size();
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        return left;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) return { -1, -1 };

        int left_idx = binary_l(nums, target);
        // 检查是否找到target
        if (nums[left_idx] != target) {
            return { -1, -1 };
        }

        int right_idx = binary_r(nums, target) - 1;
        return { left_idx, right_idx };
    }
};