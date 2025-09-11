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

Node* deleteBeg(Node *head){
    if(head==nullptr){
        cout<<"Linked List is empty nothing to delete";
    }
    else{
        Node*temp=head;
        head=head->next;
        delete(temp);
        return head;
    }
}

Node*deleteTail(Node *head){
    if(head==nullptr){
        cout<<"Linked List is empty nothing to delete";
    }
    else{
        Node*temp=head;
        Node *prev=head;
        while(temp->next!=nullptr){
            prev=temp;
            temp=temp->next;
        }
        prev->next=nullptr;
        delete(temp);
        return head;    
    }
}

Node *deleteAfterValue(Node* head){
     if(head==nullptr){
        cout<<"Linked List is empty nothing to delete";
    }
    else{
        Node*temp=head;
        Node*prev=head;
        int info;
        cout<<"Enter the value you want to delete"<<endl;
        cin>>info;
        while(temp->data!=info){
            prev=temp;
            temp=temp->next;
        }
        prev->next=temp->next;
        delete(temp);
        return head;
    }
}


Node* deleteAfterPos(Node* head){
    if(head==nullptr){
        cout<<"Linked List is empty nothing to delete";
    }
    Node* temp=head;
    Node* prev=head;
    int pos;
    cout<<"Enter the position from where you want to delete"<<endl;
    cin>>pos;
    int cnt=0;
    while(temp->next!=nullptr){
        cnt++;

        if(cnt==pos){
            prev->next=temp->next;
            delete(temp);
            return head;
        }
        prev=temp;
        temp=temp->next;
    }
}

int main(){
    vector<int>nums={4,6,2,3};
    Node* head=convert2LL(nums);
    head=inserthead(head,90);
    insertail(head,46);
    //  trav(head);
    // insertpos(head,22);
    // trav(head);
    trav(head);
//    head= deleteBeg(head);
//    cout<<"Linked list after deletion from beginning"<<endl;

    // head=deleteTail(head);
    // cout<<"Linked List after deletion from end"<<endl;
    //  trav(head);



    // head=deleteAfterValue(head);
    // cout<<"Linked List after deletion "<<endl;
    //  trav(head);


    head=deleteAfterPos(head);
    cout<<"Linked List after deletion "<<endl;
     trav(head);
   
    
}