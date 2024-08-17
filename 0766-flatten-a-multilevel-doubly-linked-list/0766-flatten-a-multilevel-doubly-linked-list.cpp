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
        stack<Node*>st;
        Node* h=head;
        while(head)
        {
           
           if(head->child)
           {
            if(head->next)
           st.push(head->next);
           head->next=head->child;
           head->next->prev=head;
           head->child=nullptr;
        //    head=head->next;
           }
           else if(head->next)
           {
            //  head=head->next;
           }
           else 
           {
             if(!st.empty()){
             head->next=st.top();
             head->next->prev=head;
             st.pop();
            //  head=head->next;
             }
           }
           head=head->next;
           
        }
        return h;
    }
};