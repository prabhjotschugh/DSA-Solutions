//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

//Function to return a tree created from postorder and inoreder traversals.
int findPosition(int in[], int inStart, int inEnd, int ele){
        for(int i=inStart;i<=inEnd;i++){
            if(in[i] == ele){
                return i;
            }
        }
        return -1;
    }
    
    Node* solve(int post[], int in[], int& index, int inStart, int inEnd, int n){
        if(index < 0 || inStart > inEnd){
            return NULL;
        }
        
        int ele = post[index--];
        Node* root = new Node(ele);
        
        int position = findPosition(in, inStart, inEnd, ele);
        
        root->right = solve(post, in, index, position+1, inEnd, n);
        root->left = solve(post, in, index, inStart, position-1, n);
        
        return root;
    }
    
    Node* buildTree(int in[], int post[], int n) {

        int postIndex = n-1;
        Node* head = solve(post, in, postIndex, 0, n-1, n);
        return head;
    }
