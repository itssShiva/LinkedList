#include <iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int value) : val(value), next(nullptr) {}
};

class Solution {
public:
    bool searchKey(ListNode* head, int key) {
        ListNode* temp = head;
        while (temp != nullptr) {     
            if (temp->val == key) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
};

int main() {
   
    ListNode* head = new ListNode(4);
    head->next = new ListNode(5);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(9);

    Solution sol;

    int key;
    cout << "Enter key to search: ";
    cin >> key;

    if (sol.searchKey(head, key)) {
        cout << "Key " << key << " found in the list.\n";
    } else {
        cout << "Key " << key << " not found in the list.\n";
    }

  
    ListNode* curr = head;
    while (curr) {
        ListNode* next = curr->next;
        delete curr;
        curr = next;
    }

    return 0;
}
