class Solution {
public:
    vector<int> ans;
    int n;
    void helper(int i){
        if (i>n) return;
        if (i>0) ans.push_back(i);
        for(int j=(i==0)?1:0; j<=9; j++){
            int x=10*i+j;
            if (x>n) break;
            helper(x);
        }
    }
    vector<int> lexicalOrder(int n) {
        this->n=n;
        ans.reserve(n);
        helper(0);
        return ans;
    }
};