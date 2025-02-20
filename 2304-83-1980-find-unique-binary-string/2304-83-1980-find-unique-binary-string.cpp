class Solution {
public:
    string addOne(string &s){
        int carry = 1;
        for(int i = s.length()-1 ; i >= 0 ; i-- ){
            int sum = (s[i]-'0')+carry;
            if(s[i] == '0' && carry > 0){
                s[i] = '1';
                carry = 0;
            }
            else if(carry > 1){
                s[i] = '0';
                carry++;
            }
        }
        return s;
    }
    
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<string>s;
        for(auto it : nums){
            s.insert(it);
        }    
        string temp = "";
        for(int i = 0 ; i < nums.size() ; i++){
            temp.push_back('0');
        }
        if(s.find(temp) == s.end())return temp;
        for(int i = 1 ; i <= nums.size() ; i++){
            temp = addOne(temp);
            if(s.find(temp) == s.end())return temp;    
        }
        return temp;
    }
};