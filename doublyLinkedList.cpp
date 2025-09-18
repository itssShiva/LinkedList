#include<iostream>
#include<vector>
using namespace std;
struct Node{
    int data;
    Node *next;
    Node *back;
};

//Converting array to linked list
Node* convert2DDL(vector<int>&nums){
    Node* head=nullptr;
    Node*temp=nullptr;
    for(int i=0;i<nums.size();i++){
        Node* newnode=new Node();
        newnode->data=nums[i];
        newnode->next=nullptr;
        newnode->back=nullptr;
        if(head==nullptr){
        head=newnode;
        temp=head;
    }
    else{
        temp->next=newnode;
        newnode->back=temp;
        temp=temp->next;
    }
    }
    return head;
    
}


//Traversing linked list
void trav(Node* head){
    Node*temp=head;
    while(temp->next!=nullptr){
        cout<<temp->data<<endl;
        temp=temp->next;
    }
    cout<<temp->data<<endl;
}

//Insertion at beginning
Node* insertionAtHead(Node* head){
    int x;
    cout<<"Enter the value of node you want insert at head:  ";
    cin>>x;
    Node* newnode=new Node();
    newnode->back=nullptr;
    newnode->next=nullptr;
    newnode->data=x;

    if(head==nullptr){
        head=newnode;
    }
    else{
        head->back=newnode;
        newnode->next=head;
        head=newnode;
    }
    return head;
}


//Insertion at tail
Node* insertionAtTail(Node* head){
    int x;
    cout<<"Enter the value of node you want insert at tail:  ";
    cin>>x;
    Node* newnode=new Node();
    newnode->back=nullptr;
    newnode->next=nullptr;
    newnode->data=x;

     if(head==nullptr){
        head=newnode;
    }

    else{
        Node* temp=head;
        while(temp->next!=nullptr){
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->back=temp;
    }
    return head;

}

//Insertion at kth position
Node* insertionAtK(Node* head,int k){
  
    int x;
    cout<<"Enter the value of node you want insert at kth position:  ";
    cin>>x;
    Node* newnode=new Node();
    newnode->back=nullptr;
    newnode->next=nullptr;
    newnode->data=x;

     if(k==1){
        head=newnode;
    }
    else{
          int cnt=1;
        Node*temp=head;
        Node* prev=head;
        while(temp!=nullptr){
            
            if(cnt==k)break;
            prev=temp;
            temp=temp->next;
            cnt++;
        }
       prev->next=newnode;
       newnode->back=prev;
       newnode->next=temp;
       temp->back=newnode;
    }
    return head;
}




int main(){
    vector<int>nums={4,6,2,3};
     Node *head=convert2DDL(nums);
    // head= insertionAtHead(head);
    // head= insertionAtTail(head);
    trav(head);
    head=insertionAtK(head,2);
     trav(head);

}