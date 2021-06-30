#include <vector>
#include <set>
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class TreeNode{
public:
    TreeNode(int _val, TreeNode* _left, TreeNode* _right) : 
        val(_val), left(_left), right(_right){}
    int val;
    TreeNode* left;
    TreeNode* right;
};

vector<int> pre_order(TreeNode* root){
    vector<int> result;
    stack<TreeNode*> stk;
    TreeNode* cur = root;
    while(!stk.empty() || cur != nullptr){
        if (cur != nullptr){
            stk.push(cur);
            result.push_back(cur->val);
            cur = cur->left;
        }else{
            TreeNode* n = stk.top();
            stk.pop();
            if (n->right != nullptr){
                cur = n->right;
            }
        }
    }
    return result;
}

vector<int> in_order(TreeNode* root){
    vector<int> result;
    stack<TreeNode*> stk;
    TreeNode* cur = root;
    while(!stk.empty() || cur != nullptr){
        if (cur != nullptr){
            stk.push(cur);
            cur = cur->left;
        }else{
            TreeNode* n = stk.top();
            result.push_back(n->val);
            stk.pop();
            if (n->right != nullptr){
                cur = n->right;
            }
        }
    }
    return result;
}

vector<int> post_order(TreeNode* root){
    vector<int> result;
    stack<TreeNode*> stk;
    TreeNode* cur = root;
    while(!stk.empty() || cur != nullptr){
        if (cur != nullptr){
            stk.push(cur);
            cur = cur->left;
        }else{
            TreeNode* n = stk.top();
            if (n->right == nullptr){
                result.push_back(n->val);
                stk.pop();
            }else{
                cur = n->right;
                n->right = nullptr;
            }
        }
    }
    return result;
}


vector<int> bfs(TreeNode* root){
    vector<int> result;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()){
        TreeNode* n = q.front();
        q.pop();
        result.push_back(n->val);
        if (n->left != nullptr){
            q.push(n->left);
        }
        if (n->right != nullptr){
            q.push(n->right);
        }
    }
    return result;
}

int main(){
    TreeNode n7 = TreeNode(7, nullptr, nullptr);
    TreeNode n6 = TreeNode(6, nullptr, nullptr);
    TreeNode n5 = TreeNode(5, &n6, &n7);
    TreeNode n4 = TreeNode(4, nullptr, nullptr);
    TreeNode n3 = TreeNode(3, nullptr, nullptr);
    TreeNode n2 = TreeNode(2, &n4, &n5);
    TreeNode n1 = TreeNode(1, &n2, &n3);
    vector<int> r = bfs(&n1);
    for(auto& v : r){
        cout << v;
    }
    cout << endl;
}