using namespace std;

struct ListNode {
   int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr) return nullptr;
        ListNode* odd = new ListNode(head->val);
        if (head->next == nullptr) return odd;
        ListNode* even = new ListNode(head->next->val);
        ListNode* root = head->next->next;
        while(root != nullptr){
            odd->next = root;
            if (root->next == nullptr) break;
            even->next = root->next;
            root = root->next->next;
        }
        odd->next = even;
        return odd;
    }
};