class Solution {
public:
    int countNodes(vector<int> &l,vector<int> &r,int root)   {
        if(root==-1)
            return 0;
        return 1+countNodes(l,r,l[root])+countNodes(l,r,r[root]);
    }
    
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild){
        vector<int> inDegree(n,0);
        int root=-1;
        for(int i=0;i<leftChild.size();i++){
            if(leftChild[i]!=-1&&inDegree[leftChild[i]]++==1)  
                return false;
            else if(rightChild[i]!=-1&&inDegree[rightChild[i]]++==1)  
                return false;
        }
        
        for(int i=0;i<leftChild.size();i++){
            if(inDegree[i]==0){
                if(root==-1) 
                    root=i;
                else   
                    return false;
            }
        }
        if(root==-1)
            return false;
        
        return countNodes(leftChild,rightChild,root)==n;
    }
};