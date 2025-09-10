#include<iostream>
#include<vector>
using namespace std;

struct Node{
    int data;
    Node *next;
};

Node* convert2LL(vector<int>&nums){
    Node* head=nullptr;
    Node *temp=nullptr;
   for(int i=0;i<nums.size();i++){
    
        Node* newnode=new Node;
        newnode->data=nums[i];
        newnode->next=nullptr;
    if(head==nullptr){
        head=newnode;
        temp=head;
    }
    else{
        temp->next=newnode;
        temp=temp->next;
    }
   }
   return head;
    
}

Node* inserthead(Node *head,int val){
    Node* newnode=new Node;
    newnode->data=val;
    newnode->next=head;
    head=newnode;
    return head;
}

void insertail(Node *head,int val){
    Node* newnode=new Node;
    Node *temp=head;
    newnode->data=val;
    newnode->next=nullptr;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    temp->next=newnode;
}

void trav(Node *head){
    Node* temp=head;
    while(temp->next!=nullptr){
        cout<<temp->data<<endl;
        temp=temp->next;
    }
     cout<<temp->data<<endl;
}

void insertposval(Node*head,int val){
    int info;
    cout<<"Enter the value after which you want to insert: "<<endl;
    cin>>info;
    Node* temp=head;
    Node* newnode=new Node;
    newnode->data=val;
    newnode->next=nullptr;
    while(temp->data!=info){
        temp=temp->next;
    }
    newnode->next=temp->next;
    temp->next=newnode;
}
Node* insertpos(Node* head, int val){
    int pos;
    cout << "Enter the position after which you want to insert: " << endl;
    cin >> pos;

    if(pos < 0){
        cout << "Invalid position!" << endl;
        return head;
    }

    Node* newnode = new Node;
    newnode->data = val;
    newnode->next = nullptr;

    // Insert at beginning if pos == 0
    if(pos == 0){
        newnode->next = head;
        return newnode;
    }

    Node* temp = head;
    int cnt = 1;

    while(temp != nullptr && cnt < pos){
        temp = temp->next;
        cnt++;
    }

    if(temp == nullptr){
        cout << "Position out of bounds!" << endl;
        delete newnode;
        return head;
    }

    // Insert in middle or end
    newnode->next = temp->next;
    temp->next = newnode;

    return head;
}

int main(){
    vector<int>nums={4,6,2,3};
    Node* head=convert2LL(nums);
    head=inserthead(head,90);
    insertail(head,46);
     trav(head);
    insertpos(head,22);
    trav(head);
   
    
}