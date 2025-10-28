#include <bits/stdc++.h>
using namespace std;

/* Definition of singly linked list: */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() {
        val = 0;
        next = NULL;
    }
    ListNode(int data1) {
        val = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1) {
        val = data1;
        next = next1;
    }
};

class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode *zeroHead = new ListNode(-1);
        ListNode *oneHead = new ListNode(-1);
        ListNode *twoHead = new ListNode(-1);

        ListNode *zero = zeroHead;
        ListNode *one = oneHead;
        ListNode *two = twoHead;
        ListNode *temp = head;

        while (temp != nullptr) {
            if (temp->val == 0) {
                zero->next = temp;
                zero = temp;
            } else if (temp->val == 1) {
                one->next = temp;
                one = temp;
            } else {
                two->next = temp;
                two = temp;
            }
            temp = temp->next;
        }

        zero->next = (oneHead->next) ? oneHead->next : twoHead->next;
        one->next = twoHead->next;
        two->next = nullptr;

        ListNode *newHead = zeroHead->next;
        delete zeroHead;
        delete oneHead;
        delete twoHead;

        return newHead;
    }
};

void printList(ListNode *head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Create the linked list: 1 -> 0 -> 2 -> 1 -> 0
    ListNode *head = new ListNode(1);
    head->next = new ListNode(0);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);
    head->next->next->next->next = new ListNode(0);

    cout << "Original list: ";
    printList(head);

    Solution obj;
    ListNode *sortedHead = obj.sortList(head);

    cout << "Sorted list:   ";
    printList(sortedHead);

    return 0;
}
