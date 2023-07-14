//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    int findPosition(int in[], int inStart, int inEnd, int ele){
        for(int i=inStart;i<=inEnd;i++){
            if(in[i] == ele){
                return i;
            }
        }
        return -1;
    }
    
    Node* solve(int pre[], int in[], int &index, int inStart, int inEnd, int n){
        if(index >= n || inStart > inEnd){
            return NULL;
        }
        
        int ele = pre[index++];
        Node* root = new Node(ele);
        
        int position = findPosition(in, inStart, inEnd, ele);
        
        root->left = solve(pre, in, index, inStart, position-1, n);
        root->right = solve(pre, in, index, position+1, inEnd, n);
        
        return root;
    }
     Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        int preIndex = 0;
        Node* head = solve(pre, in, preIndex, 0, n-1, n);
        return head;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends