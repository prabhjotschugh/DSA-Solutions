class Solution {
public:
    bool canEatAll(vector<int>& piles, int hour, int speed){
        int timeTaken = 0;
        int n = piles.size();
        for(int i=0;i<n;i++){
            int time = ( (piles[i]-1) / speed ) + 1;
            timeTaken += time;
            
            if(timeTaken > hour){
                return false;
            }
        }
        return true;
    }
    
    int minEatingSpeed(vector<int>& piles, int hour) {
        int maxi = *max_element(piles.begin(), piles.end());
        
        int l = 1;
        int r = maxi;
        int ans = 0;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(canEatAll(piles, hour, mid) == true){
                ans = mid;
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        return ans;
    }
};