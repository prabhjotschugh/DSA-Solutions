//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};
// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
          
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}

// Function for Inorder Traversal
void printInorder(Node* root)
{
    if(!root)
        return;
        
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}


// } Driver Code Ends
class Solution
{
    public:
    void width(Node* root, int level, vector<int> &maxMin){
        if(root == NULL){
            return;
        }

        maxMin[0] = max(maxMin[0], level);
        maxMin[1] = min(maxMin[1], level);

        width(root -> left, level-1, maxMin);
        width(root -> right, level+1, maxMin);
    }

    vector<int> verticalOrder(Node* root) {

        vector<int> maxMin(2, 0);
        width(root, 0, maxMin);

        int width = maxMin[0] - maxMin[1];
        vector<vector<int>> ans(width+1);

        queue<pair<Node*,int>> q;
        q.push({root, -maxMin[1]});

        while(!q.empty()){
            pair<Node*, int> curr = q.front();
            ans[curr.second].push_back(curr.first -> data);
            q.pop();

            if(curr.first -> left) {
                q.push({curr.first -> left, curr.second-1});
            }
            if(curr.first -> right) {
                q.push({curr.first -> right, curr.second+1});
            }
        }
        vector<int> v;
        for(auto i : ans){
            for(auto j : i){
                v.push_back(j);
            } 
        }
        return v;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    string  tc;
    getline(cin,tc);
    t=stoi(tc);
    while(t--)
    {
        string s;
        getline(cin,s);
        // string c;
        // getline(cin,c);
        Solution obj;
    	Node* root = buildTree(s);
    	
    	vector <int> res = obj.verticalOrder(root);
    	for (int i : res) cout << i << " ";
        cout << endl;
    }
	return 0;
}



// } Driver Code Ends