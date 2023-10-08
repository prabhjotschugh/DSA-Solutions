class Solution {
public:
    bool strongPasswordCheckerII(string password) {
        if(size(password) < 8) 
            return false;
        bool low = false , upper = false ,digit = false ,special = false;
        for(auto c : password){
            if(c>='a' and c<='z') 
                low = true;
            else if(c>='A' and c <='Z') 
                upper = true;
            else if(isdigit(c)) 
                digit = true;
            else 
                special = true;
        }
        for(int i=0;i+1<size(password);i++) 
            if(password[i] == password[i+1]) 
                return false;
        
        if(low and upper and digit and special) 
            return true;
        
        return false;   
    }
};