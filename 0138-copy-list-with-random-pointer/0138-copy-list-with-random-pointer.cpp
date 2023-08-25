/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void insertAtTail(Node* &head, Node* &tail, int d){
        Node* temp = new Node(d);
        if(head == NULL){
            head = temp;
            tail = temp;
            return;
        }
        else{
            tail->next = temp;
            tail = temp;
        }
    }
    
    Node* copyRandomList(Node* head) {
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        
        Node* temp = head;
        while(temp){
            insertAtTail(cloneHead, cloneTail, temp->val);
            temp = temp->next;
        }
        
        Node* originalNode = head;
        Node* cloneNode = cloneHead;
        while(originalNode && cloneNode){
            temp = originalNode->next;
            originalNode->next = cloneNode;
            originalNode = temp;
            
            temp = cloneNode->next;
            cloneNode->next = originalNode;
            cloneNode = temp;
        }
        
        temp = head;
        while(temp){
            if(temp->next && temp->random){
                temp->next->random = temp->random->next;
            }
            temp = temp->next->next;
        }
        
        originalNode = head;
        cloneNode = cloneHead;
        while(originalNode && cloneNode){
            originalNode->next = cloneNode->next;
            originalNode = originalNode->next;
            
            if(originalNode)
                cloneNode->next = originalNode->next;
            cloneNode = cloneNode->next;
        }
        
        return cloneHead;
    }
};