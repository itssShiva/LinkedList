#include <bits/stdc++.h>
using namespace std;

/* Your ListNode and Solution classes */
class ListNode {
public:
    int data;
    ListNode* prev;
    ListNode* next;

    ListNode(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class Solution {
public:
    ListNode* reverseDLL(ListNode* head) {
        ListNode *last = nullptr;
        ListNode* current = head;
        while (current != nullptr) {
            last = current->prev;
            current->prev = current->next;
            current->next = last;
            current = current->prev;
        }

        if (last != nullptr)
            head = last->prev;
        return head;
    }
};

// helper to print DLL
void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// helper to append a node at the end
void appendNode(ListNode*& head, int val) {
    ListNode* newNode = new ListNode(val);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    ListNode* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

int main() {
    // build a sample doubly linked list: 1 <-> 2 <-> 3 <-> 4
    ListNode* head = nullptr;
    appendNode(head, 1);
    appendNode(head, 2);
    appendNode(head, 3);
    appendNode(head, 4);

    cout << "Original list: ";
    printList(head);

    Solution sol;
    head = sol.reverseDLL(head);

    cout << "Reversed list: ";
    printList(head);

    // free memory (optional for small demo)
    ListNode* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
