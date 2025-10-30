#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node() {
        this->data = 0;
        this->next = NULL;
    }
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node *next) {
        this->data = data;
        this->next = next;
    }
};

// Function declarations
int addHelper(Node* temp);
Node* addOne(Node* head);

// Function definitions
int addHelper(Node* temp) {
    if (temp == nullptr) {
        return 1;
    }
    int carry = addHelper(temp->next);
    temp->data += carry;
    if (temp->data < 10) return 0;
    temp->data = 0;
    return 1;
}

Node* addOne(Node* head) {
    int carry = addHelper(head);
    if (carry == 1) {
        Node* newNode = new Node(1);
        newNode->next = head;
        head = newNode;
    }
    return head;
}

// Helper function to print linked list
void printList(Node* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Main function
int main() {
    // Example: number 999 represented as linked list 9 -> 9 -> 9
    Node* head = new Node(9);
    head->next = new Node(9);
    head->next->next = new Node(9);

    cout << "Original list: ";
    printList(head);

    head = addOne(head);

    cout << "After adding one: ";
    printList(head);

    return 0;
}
