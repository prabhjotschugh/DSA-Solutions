class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int>count(25);
        for(auto bill:bills){
            if(bill == 5) 
                count[5]++;
            else if(bill == 10){
                if(count[5]) 
                    count[5]--;
                else 
                    return false;
                
                count[10]++;
            }
            else {
                if(count[5] and count[10]) count[5]--, count[10]--;
                else if(count[5] > 2) count[5] -= 3;
                else return false;
            }
        }
        return true;
    }
};