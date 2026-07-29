#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    unordered_set<int> hash1;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        hash1.insert(t);
    }
    for (int i = 0; i < m; i++)
    {
        int t;
        cin >> t;
        hash1.insert(t);
    }
    vector<int> v;
    for (auto it : hash1)
    {
        int t = it;
        v.push_back(t);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
}
// 64 Î»Êä³öÇëÓÃ printf("%lld")