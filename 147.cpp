#include <vector>
#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *n) : val(x), next(n) {}
};

void p_node(ListNode* result){
    cout << "now ";
    while(result != nullptr){
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;
}

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(head == nullptr) return head;
        vector<ListNode*> cache{head};
        ListNode* root = head;
        int left = 0, right = 0, midden = 0;
        ListNode* tmp = nullptr;
        ListNode* tmp2 = nullptr;;
        while(head->next != nullptr){
            if(head->next->val > head->val){
                head = head->next;
                cache.push_back(head);
                continue;
            }
            left = 0;
            right = cache.size()-1;
            while (left != right){
                midden = left + (right-left)/2;
                if(cache[midden]->val >= head->next->val){
                    right = midden;
                }else{
                    left = midden + 1;
                }
            }
            tmp = head->next;
            head->next = tmp->next;
            tmp->next = cache[left];

            tmp->next = cache[left];
            if(left == 0){
                root = tmp;
            }else{
                cache[left-1]->next = tmp;
            }
            cache.insert(cache.begin()+left, tmp);
        }
        return root;
    }
};



int main(){
    // 4->2->1->3
    ListNode n1 = ListNode(1, nullptr);
    ListNode n2 = ListNode(4, &n1);
    ListNode n3 = ListNode(2, &n2);
    ListNode n4 = ListNode(3, &n3);
    ListNode* result = Solution().insertionSortList(&n4);
    while(result != nullptr){
        cout << result->val;
        result = result->next;
    }
    cout << endl;
}