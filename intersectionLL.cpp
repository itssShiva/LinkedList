#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==nullptr||headB==nullptr)return nullptr;
        ListNode* t1=headA;
        ListNode* t2=headB;
        while(t1!=t2){
            t1=t1->next;
            t2=t2->next;
            if(t1==t2)return t1;
            if(t1==nullptr)t1=headB;
            if(t2==nullptr)t2=headA;
        }
        return t1;
    }
};

int main() {
    ListNode* common = new ListNode(8);
    common->next = new ListNode(10);

    ListNode* headA = new ListNode(3);
    headA->next = new ListNode(7);
    headA->next->next = common;

    ListNode* headB = new ListNode(99);
    headB->next = new ListNode(1);
    headB->next->next = common;

    Solution s;
    ListNode* res = s.getIntersectionNode(headA, headB);
    if(res) cout << res->val;
    else cout << "No intersection";
    return 0;
}
