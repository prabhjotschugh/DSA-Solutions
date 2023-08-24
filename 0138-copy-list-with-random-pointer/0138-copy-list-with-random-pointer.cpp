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
        
        unordered_map<Node*, Node*> umap;
        Node* originalNode = head;
        Node* cloneNode = cloneHead;
        
        while(originalNode){
            umap[originalNode] = cloneNode;
            cloneNode = cloneNode->next;
            originalNode = originalNode->next;
        }
        
        originalNode = head;
        cloneNode = cloneHead;
        
        while(originalNode){
            cloneNode->random = umap[originalNode->random];
            cloneNode = cloneNode->next;
            originalNode = originalNode->next;
        }
        return cloneHead;
    }
};