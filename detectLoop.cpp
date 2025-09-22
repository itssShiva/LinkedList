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
    bool hasCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                return true;
            }
        }
        return false;
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

    // Create a cycle: -4 -> 2
    node4->next = node2;

    // Test the function
    Solution sol;
    if (sol.hasCycle(node1))
        cout << "Cycle detected" << endl;
    else
        cout << "No cycle" << endl;

    // Clean up memory manually if you break the cycle before deleting nodes
    // (for simplicity omitted here)

    return 0;
}
