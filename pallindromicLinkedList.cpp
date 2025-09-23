#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverse(ListNode*head){
        if(head==nullptr||head->next==nullptr) return head;
        ListNode* temp=head;
        ListNode* prev=nullptr;
        while(temp!=nullptr){
            ListNode* front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true; // 0 or 1 node is palindrome
        ListNode* slow=head;
        ListNode* fast=head;
        // find middle
        while(fast->next!=nullptr && fast->next->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        // reverse second half
        ListNode* newhead=reverse(slow->next);
        fast=head;
        ListNode* second=newhead;
        // compare first half and reversed second half
        while(second!=nullptr){
            if(fast->val!=second->val){
                reverse(newhead); // restore list
                return false;
            }
            fast=fast->next;
            second=second->next;
        }
        // restore list
        reverse(newhead);
        return true;
    }
};

int main() {
    // Example 1: Palindrome list: 1 -> 2 -> 3 -> 2 -> 1
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(1);

    Solution sol;
    bool result = sol.isPalindrome(head);

    if(result)
        cout << "The linked list is a palindrome" << endl;
    else
        cout << "The linked list is NOT a palindrome" << endl;

    // Example 2: Non-palindrome list: 1 -> 2 -> 3
    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(2);
    head2->next->next = new ListNode(3);

    bool result2 = sol.isPalindrome(head2);

    if(result2)
        cout << "The second linked list is a palindrome" << endl;
    else
        cout << "The second linked list is NOT a palindrome" << endl;

    return 0;
}
