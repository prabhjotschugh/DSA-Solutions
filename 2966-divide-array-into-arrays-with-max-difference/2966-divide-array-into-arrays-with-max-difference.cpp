class Solution {
public:
    static vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n=nums.size();
        int freq[100001]={0};
        int xMax=0;
        for(int x: nums){
            freq[x]++;
            xMax=max(x, xMax);
        }
        vector<vector<int>> ans(n/3);
        vector<int> vec3(3);
        int count=0, vec_m, i=0;
        for(int x=1; x<=xMax; x++){
            for( ; freq[x]>0; freq[x]--, count++){
                if (count%3==0)
                    vec_m=x;
                if (x>vec_m+k ) return {};
                vec3[count]=x;
                if (count%3==2){
                    ans[i++]=vec3;
                    count=-1;
                }
            }
        }
        return ans;
    }
};