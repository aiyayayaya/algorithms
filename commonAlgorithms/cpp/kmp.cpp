#include <vector.h>

vector<int> buildPrefix(vector<int> &v){
    vector<int> kmp(v.size() + 1);
    for (int slow = 0, fast = 1; fast < v.size(); fast++){
        if (v[slow] == v[fast]){
            kmp[fast + 1] = ++slow;
        } else if (slow != 0){
            slow = kmp[slow]
            --fast;
        }
    }
    return kmp;
}

/* got from a specific leetcode questions, needs to be generalized.
*/
bool canChoose(vector<vector<int>>& g, vector<int>& nums, int i = 0, int j = 0) {
    if (i >= g.size())
        return true;
    auto kmp = buildPrefix(g[i]);
    for (int k = 0; j <= nums.size() - g[i].size(); ++k) {
        if (k == g[i].size())
            return canChoose(g, nums, i + 1, j + k);   
        if (nums[j + k] != g[i][k]) {
            j += max(1, k - kmp[k]);
            k = kmp[k] - 1;            
        }
    }
    return false;
}