class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int res=0;
        int n = nums1.size();
        int m = nums2.size();
        int x=0;
        int y=0;
        for (int i=0;i<n;i++)
            x^=nums1[i];
        for (int i=0;i<m;i++)
            y^=nums2[i];
        
        if (n%2==0 && m%2==0 )
            res=0;
        else if (m%2==0 && n%2!=0)
            res=y;
        else if (n%2!=0 && m%2!=0)
            res=x ^ y;
        else if (n%2==0 && m%2!=0)
            res=x;

        return res;
    }
};