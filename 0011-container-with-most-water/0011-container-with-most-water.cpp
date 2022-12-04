class Solution {
public:
    int maxArea(vector<int>& height) {
        int max = INT_MIN;
        int n = height.size();
        int left=0;
        int right = n-1;
        while(left<right){
            int h = min(height[left], height[right]);
            int area = (right-left)*h;
            
            if(area>max){
                max=area;
            }
            if(height[right]>height[left])
                left++;
            else if(height[left]>height[right])
                right--;
            else{
                left++;
                right--;
            }
        }
        return max;
    }
};