#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int data1) : val(data1), next(NULL) {}
    ListNode(int data1, ListNode *next1) : val(data1), next(next1) {}
};

class Solution {
public:
    int lengthOfLoop(ListNode* slow, ListNode* fast) {
        fast = fast->next;
        int count = 1;
        while (slow != fast) {
            count++;
            fast = fast->next;
        }
        return count;
    }

    int findLengthOfLoop(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        // corrected condition
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                return lengthOfLoop(slow, fast); // added ;
            }
        }
        return 0; // no loop
    }
};

int main() {
    // create nodes
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // create a loop: node5->next = node3
    head->next->next->next->next->next = head->next->next;

    Solution sol;
    int loopLen = sol.findLengthOfLoop(head);
    if(loopLen)
        cout << "Length of loop = " << loopLen << endl;
    else
        cout << "No loop detected" << endl;

    return 0;
}
