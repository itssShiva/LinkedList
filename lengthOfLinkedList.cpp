#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    int getLength(ListNode* head) {
        if (head == nullptr) return 0;
        int count = 1;
        ListNode* temp = head;
        while (temp->next != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }
};

int main() {
    ListNode* head = new ListNode(4);
    head->next = new ListNode(5);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(9);

    Solution sol;
    int len = sol.getLength(head);

    cout << "Length of linked list = " << len << endl;

    ListNode* curr = head;
    while (curr) {
        ListNode* next = curr->next;
        delete curr;
        curr = next;
    }

    return 0;
}
