class Solution {
private:
    string invert(string s){
        string temp;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '0') temp.push_back('1');
            else temp.push_back('0');
        }
        return temp;
    }
public:
    char findKthBit(int n, int k) {
        if(k == 1) return '0';
        vector<string> v;
        string s = "0";
        v.push_back(s);
        for(int i=1; i<n; i++){
            string x = invert(v[i-1]);
            reverse(x.begin(), x.end());
            string str = v[i-1]+"1"+ x;
            v.push_back(str);
        }
        return v[n-1][k-1];
    }
};