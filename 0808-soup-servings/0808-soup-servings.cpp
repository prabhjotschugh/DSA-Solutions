class Solution {
public:
    vector<vector<int>> operations{{100,0},{75,25},{50,50},{25,75}};   
    double solve(int a, int b, vector<vector<double>> &memo){
        if(a==0){
            if(b==0) 
                return 0.5; 
            
            return 1; 
        }
        if(b==0) 
            return 0;
        
        if(memo[a][b] != -1) 
            return memo[a][b];
        
        double ans=0;
        for(int k=0;k<4;k++){
            int sub_a=operations[k][0], sub_b=operations[k][1];
            ans += 0.25*solve(max(0,a-sub_a), max(0,b-sub_b), memo);
        }
        return memo[a][b]=ans;
    }
    
    double soupServings(int n) {
        if(n>=4800) 
            return 1;
        
        vector<vector<double>> memo(n+1,vector<double>(n+1,-1));
        return solve(n,n,memo);
    }
};