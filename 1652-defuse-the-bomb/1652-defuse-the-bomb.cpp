class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        if(k==0) return vector<int>(n, 0);

        int i, j;
        if(k < 0) i = (n+k)%n, j = n-1;
        else i = 1, j = k;

        int sum = accumulate(code.begin()+i, code.begin()+j+1, 0);

        vector<int> ans(n);
        for(int ind=0; ind<n; ind++){
            ans[ind] = sum;
            sum -= code[i];
            i = (i+1)%n;
            j = (j+1)%n;
            sum += code[j];
        }

        return ans;
    }
};