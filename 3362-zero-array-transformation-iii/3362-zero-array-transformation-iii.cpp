class Solution {
public:
    vector<int>segTree,lazy;
    vector<int>nonZeroes;
    void buildTree(vector<int>& nums, int l, int r, int i){
        if(l==r){
            segTree[i] = nums[l];
            return;
        }
        int mid = l+(r-l)/2;
        buildTree(nums,l,mid,2*i+1);
        buildTree(nums,mid+1,r,2*i+2);
        segTree[i] = max(segTree[2*i+1],segTree[2*i+2]);
        return;
    }
    int find(int start, int end, int l, int r, int i){
        if(lazy[i]!=0){
            segTree[i] -= lazy[i];
            if(l!=r){
                // propagate the lazy values....
                lazy[2*i+1] += lazy[i];
                lazy[2*i+2] += lazy[i];
            }
            lazy[i] = 0;
        }
        if(l>end || r<start) return INT_MIN;
        if(l>=start && r<=end){
            return segTree[i];
        }
        int mid = l+(r-l)/2;
        return max(find(start, end, l,mid,2*i+1),find(start,end,mid+1,r,2*i+2));
    }
    void updateRange(int start, int end, int l, int r, int i){
        if(lazy[i]!=0){
            segTree[i] -= lazy[i];
            if(l!=r){
                lazy[2*i+1] += lazy[i];
                lazy[2*i+2] += lazy[i];
            }
            lazy[i] = 0;
        }
        if(l>end || r<start) return;
        if(l>=start && r<=end){
            segTree[i]-=1;
            if(l!=r){
                lazy[2*i+1] += 1;
                lazy[2*i+2] += 1;
            }
            return;
        }
        int mid = l+(r-l)/2;
        updateRange(start,end,l,mid,2*i+1);
        updateRange(start,end,mid+1,r,2*i+2);
        segTree[i] = max(segTree[2*i+1],segTree[2*i+2]);
        return;
    }
    
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        // POINTS THAT I CAN THINK OF IS THAT WE SHOULD BE HAVING BIG INTERVALS IN THE BEGINNING AND SMALL AT THE END....
        // WHICH MEANS SORTING ON CUSTOM BASIS....
        
        // now that we have sorted queries we can begin our "karyakaram"..
        // now after writing and running the code i got to know that this alone wont work as we need to think that small intervals can have more non zero elements...
        // sort it in such a way that the queries with more number of nonZero elements come at top...
        // nahi ho raha yaar accept....
        int n = nums.size();
        // nonZeroes.resize(n,0);
        // if(nums[0]!=0) nonZeroes[0] = nums[0];
        // for(int i=1;i<n;i++){
        //     if(nums[i]!=0) nonZeroes[i] = nonZeroes[i-1]+nums[i];
        //     else nonZeroes[i] = nonZeroes[i-1];
        // }
        sort(queries.begin(),queries.end());
        segTree.resize(4*n);
        lazy.resize(4*n,0);
        buildTree(nums,0,n-1,0);
        int i=0,count=queries.size();
        int j=0;
        priority_queue<int>pq;
        while(i<n){
            while(j<queries.size() && queries[j][0]<=i){
                pq.push(queries[j][1]);
                j++;
            }
            while(find(i,i,0,n-1,0)>0){
                if(pq.empty()) return -1;
                int r = pq.top();
                pq.pop();
                updateRange(i,r,0,n-1,0);
                count--;
            }
            i++;
        }
        return count;
    }
};