class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int c=0,i=0,j=0;
        
        while (i < n && j < m){
            if (nums1[i] > nums2[j])
                i++;
            else{
                c = max(c, j - i);
                j++;
            }
        }
        return c;
    }
};