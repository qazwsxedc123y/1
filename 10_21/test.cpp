#define  _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        vector<int> ret; // �洢���
        int n = nums.size(); // ���鳤��
        vector<int> cnt(101, 0); // ���ڴ洢����������Ƶ�Σ���Χ��[-50, 50]��ƫ��50ʹ���Ϊ[0, 100]

        for (int left = 0, right = 0; right < n; right++) {
            // ������
            cnt[nums[right] + 50]++;

            // �����ڴ�С���ڵ���kʱ����ʼ������
            if (right - left + 1 >= k) {
                // ���㵱ǰ���ڵ�x����Сֵ
                int count = 0;
                for (int i = 0; i <= 100; i++)
                {
                    count += cnt[i]; // �ۼƵ�ǰ������С�ڵ���i�����ָ���
                    if (count >= x)
                    { // �ҵ���x����С����
                        ret.push_back(i - 50 < 0 ? i - 50 : 0); // �ǵü�ƫ��
                        break;
                    }
                }

                // �������ڣ��Ƴ�leftԪ��
                cnt[nums[left] + 50]--;
                left++;
            }
        }

        return ret;
    }
};
