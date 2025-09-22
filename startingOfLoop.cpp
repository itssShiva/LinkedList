#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
            if (slow == fast) {
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return fast; // entry of cycle
            }
        }
        return nullptr;
    }
};

int main() {
    // Create nodes
    ListNode* node1 = new ListNode(3);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(0);
    ListNode* node4 = new ListNode(-4);

    // Link them: 3 -> 2 -> 0 -> -4
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    // Make a cycle: -4 -> 2
    node4->next = node2;

    Solution sol;
    ListNode* entry = sol.detectCycle(node1);

    if (entry != nullptr)
        cout << "Cycle starts at node with value: " << entry->val << endl;
    else
        cout << "No cycle in the list" << endl;

    // Break the cycle to safely delete (optional):
    node4->next = nullptr;
    delete node1;
    delete node2;
    delete node3;
    delete node4;

    return 0;
}
