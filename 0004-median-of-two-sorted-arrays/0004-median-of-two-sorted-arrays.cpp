#include<algorithm>
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double arr[2000];
        int m = nums1.size();
        int n = nums2.size();
        for(int i=0;i<m;i++){
            arr[i]=nums1[i];
        }
        for(int i=m,j=0 ; i<m+n,j<n ; i++,j++){
            arr[i]=nums2[j];
        }
        int len=m+n;
        sort(arr, arr+len);
        if(len%2==0){
            double a = arr[((len)/2)-1];
            double b = arr[(len)/2];
            return (a+b)/2;
                
        }
        else{
            return arr[(len)/2];
        }
    }
};