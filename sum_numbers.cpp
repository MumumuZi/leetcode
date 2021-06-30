#include <vector>
#include <cmath>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}
};

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int result = 0;
        vector<int> child_deeps;
        vector<pair<TreeNode*, vector<int>>> stack;
        while (stack.size() != 0 || root != nullptr)
        {
            if (root != nullptr){
                stack.emplace_back(root, vector<int>{0});
                root = root->left;
            }else{
                auto& n = stack[stack.size()-1];
                for(auto i : child_deeps){
                    n.second.emplace_back(i + 1);
                }
                if (n.first->right != nullptr){
                    root = n.first->right;
                    n.first->right = nullptr;
                    child_deeps = {};
                }else{
                    if(n.second.size() > 1){
                        n.second.erase(n.second.begin());
                    }
                    for(auto i : n.second){
                        result += n.first->val*pow(10, i);
                    }
                    child_deeps = n.second;
                    stack.erase(stack.end()-1);
                }
            }
        }
        return result;
    }
};

/*
     1
    /  \
    2    0
   /  \   \
  3    4   5
      /
     6 
*/
//
int main(int argc, char const *argv[])
{
    TreeNode n3 = TreeNode(3, nullptr, nullptr);
    TreeNode n6 = TreeNode(6, nullptr, nullptr);
    TreeNode n4 = TreeNode(4, &n6, nullptr);
    TreeNode n2 = TreeNode(2, &n3, &n4);
    TreeNode n5 = TreeNode(5, nullptr, nullptr);
    TreeNode n0 = TreeNode(0, nullptr, &n5);
    TreeNode n1 = TreeNode(1, &n2, &n0);
    int result = Solution().sumNumbers(&n1);
    cout << result << endl;
    return 0;
}
