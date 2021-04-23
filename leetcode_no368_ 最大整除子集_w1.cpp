/* ------------------------------------------------------------------|
给你一个由 无重复 正整数组成的集合 nums ，请你找出并返回其中最大的整除子集 answer ，子集中每一元素对 (answer[i], answer[j]) 都应当满足：
answer[i] % answer[j] == 0 ，或
answer[j] % answer[i] == 0
如果存在多个有效解子集，返回其中任何一个均可。

 

示例 1：

输入：nums = [1,2,3]
输出：[1,2]
解释：[1,3] 也会被视为正确答案。
示例 2：

输入：nums = [1,2,4,8]
输出：[1,2,4,8]
 

提示：

1 <= nums.length <= 1000
1 <= nums[i] <= 2 * 109
nums 中的所有整数 互不相同

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/largest-divisible-subset
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
-------------------------------------------------------------------*/

/*	动态规划法
*
*	执行用时：40 ms, 在所有 C++ 提交中击败了98.25%的用户
*	内存消耗：8.5 MB, 在所有 C++ 提交中击败了65.69%的用户
*/

#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}

};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

vector<int> largestDivisibleSubset(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<int> dp(n, 1);
    int maxlen = 1;
    int maxval = 1;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] % nums[j] == 0) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        if (dp[i] > maxlen) {
            maxval = nums[i];
            maxlen = dp[i];
        }
    }
    vector<int> res;
    if (maxlen == 1) {
        res.emplace_back(nums[0]);
    }
    else {
        for (int i = n - 1; i >= 0; --i) {
            if (dp[i] == maxlen && maxval % nums[i] == 0) {
                res.emplace_back(nums[i]);
                maxlen--;
                maxval = nums[i];
            }
            if (maxlen == 0) {
                break;
            }
        }
    }
    return res;
}

int main() {
    vector<int> nums = { 1,2,3 };
    largestDivisibleSubset(nums);
}