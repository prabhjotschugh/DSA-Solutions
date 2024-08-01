class Solution {
public:
    int countSeniors(vector<string>& v) {
        int count = 0; 
        for(auto &x : v){
            int age = stoi(x.substr(11,2)) ;
            if(age > 60){
                count+=1 ;
            }
        }
        return count ;
    }
};