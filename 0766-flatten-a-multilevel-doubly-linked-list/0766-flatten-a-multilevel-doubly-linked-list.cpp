/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node*temp=head;
        while(temp!=NULL){
            if(temp->child!=NULL){
                Node*temp2=temp->child;
                Node*front=temp->next;
                temp->next=temp2;
                temp->child=NULL;
                temp2->prev=temp;
                while(temp2->next!=NULL){
                    temp2=temp2->next;
                }
                if(front!=NULL){
                front->prev=temp2;
                temp2->next=front;
                }

                temp=temp->next;

            }
            else{
                temp=temp->next;
            }
        }
        return head;
    }
};