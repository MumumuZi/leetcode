#include <vector>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        vector<TreeNode*> stack;
        while(stack.size() != 0 || root != nullptr){
            if(root != nullptr){
                stack.push_back(root);
                result.push_back(root->val);
                root = root->left;
            }else{
                TreeNode* node = stack[stack.size()-1];
                stack.erase(stack.end()-1);
                cout << (node->right != nullptr);
                if(node->right != nullptr){
                    root = node->right;
                }
            }
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    TreeNode node3 = TreeNode(3, nullptr, nullptr);
    TreeNode node2 = TreeNode(2, &node3, nullptr);
    TreeNode root = TreeNode(1, nullptr, &node2);
    auto result = Solution().preorderTraversal(&root);
    for(auto i : result){
        cout << i << endl;
    }
    return 0;
}
