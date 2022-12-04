#define ll long long int

class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n=nums.size();
        int min = INT_MAX;
        ll right_sum=0;
        for(int i=0;i<n;i++)
            right_sum += nums[i];
        
        ll left_sum=0;
        int index=0;
        
        for(int i=0;i<n;i++){
            left_sum += nums[i];
            right_sum -= nums[i];
            
            ll first = (left_sum/(i+1));
            ll last = i<(n-1) ? (right_sum/(n-i-1)) : 0;
            
            ll diff = abs(first-last);
            if(diff<min){
                min = diff;
                index = i;
            }
        }
        return index;
    }
};