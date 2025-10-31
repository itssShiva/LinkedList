#include <bits/stdc++.h>
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyNode = new ListNode(-1);
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        ListNode* curr = dummyNode;
        int carry = 0;
        while (t1 != nullptr || t2 != nullptr) {
            int sum = carry;
            if (t1) sum += t1->val;
            if (t2) sum += t2->val;
            ListNode* newNode = new ListNode(sum % 10);
            carry = sum / 10;
            curr->next = newNode;
            curr = curr->next;
            if (t1) t1 = t1->next;
            if (t2) t2 = t2->next;
        }
        if (carry) {
            ListNode* newNode2 = new ListNode(carry);
            curr->next = newNode2;
        }
        return dummyNode->next;
    }
};

ListNode* createList(vector<int> nums) {
    if (nums.empty()) return nullptr;
    ListNode* head = new ListNode(nums[0]);
    ListNode* curr = head;
    for (int i = 1; i < nums.size(); i++) {
        curr->next = new ListNode(nums[i]);
        curr = curr->next;
    }
    return head;
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    vector<int> num1 = {2, 4, 3};
    vector<int> num2 = {5, 6, 4};
    ListNode* l1 = createList(num1);
    ListNode* l2 = createList(num2);
    Solution sol;
    ListNode* result = sol.addTwoNumbers(l1, l2);
    printList(result);
    return 0;
}
