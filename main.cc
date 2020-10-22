#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1000010;
const int inf = 1e8;
const int mod = 1000000007;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:

    int dfs(TreeNode* root, bool is_root, int& require) {
        if (root->left == nullptr && root->right == nullptr) {
            require = 1;
            return 0;
        } else if (root->left == nullptr || root->right == nullptr) {
            if (root->left == nullptr) {
                root->left = root->right;
                root->right = nullptr;
            }

            int ans = dfs(root->left, false, require);
            if (is_root && require) {
                ans += 1;
            }
            return ans;
        } else {
            int require_left = 0;
            int require_right = 0;
            int left = dfs(root->left, false, require_left);
            int right = dfs(root->right, false, require_right);
            int ans = left + right;
            
            if (left > 0 && right > 0) {
                require = 0;
            } else if (left == 0 && right == 0) {
                ans += 1;
                require = 1;
            } else if (left == 0 || right == 0) {
                require = 1;
            }
            return ans;
        }
    }


    int navigation(TreeNode* root) {
        int require = 0;

        int ans = dfs(root, true, require);
        if (ans == 0 && require) {
            ans += 1;
        }

        return ans;
    }
};

int main() {
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Solution s;

    return 0;
}
