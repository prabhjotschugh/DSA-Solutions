//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/


class Solution
{
    public:
    //Function to rotate a linked list.
    int listLength(Node* head){
        int len = 0;
        while(head){
            head = head->next;
            len++;
        }
        return len;
    }
    Node* rotate(Node* head, int k)
    {
        // Your code here
        if(head == NULL)    return head;
        int n = listLength(head);
        k = k%n;
        
        if(k==0)    return head;
        
        Node*  temp = head;
        Node* prev = NULL;
        int shift = k;
        while(shift--){
            prev = temp;
            temp = temp->next;
        }
        Node* newHead = temp;
        
        while(temp->next){
            temp = temp->next;
        }
        temp->next = head;
        prev->next = NULL;
        
        return newHead;
    }
};
    


//{ Driver Code Starts.

void printList(Node *n)
{
    while (n != NULL)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, val, k;
        cin>>n;
        
        cin>> val;
        Node *head = new Node(val);
        Node *tail = head;
        
        for(int i=0; i<n-1; i++)
        {
            cin>> val;
            tail->next = new Node(val);
            tail = tail->next;
        }
        
        cin>> k;
        
        Solution ob;
        head = ob.rotate(head,k);
        printList(head);
    }
    return 1;
}

// } Driver Code Ends