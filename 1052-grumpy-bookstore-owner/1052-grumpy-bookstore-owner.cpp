class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int count = 0; 
        for(int i=0; i<customers.size(); i++){
            if(grumpy[i] == 0) 
                count+= customers[i];
        }
        for(int i=0; i<customers.size(); i++){
            customers[i] *= grumpy[i];  
        }  
        int max = 0, temp = 0; 
        for(int i=0; i<minutes; i++){
            temp += customers[i]; 
        }
        if(max < temp) 
            max = temp; 
        for(int i=minutes; i<customers.size(); i++){
            temp -= customers[i - minutes]; 
            temp += customers[i]; 
            if(max < temp) 
               max = temp; 
        }
        return count + max; 
    }
};