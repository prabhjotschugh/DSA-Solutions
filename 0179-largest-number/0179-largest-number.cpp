class Solution {
private:
    static bool comparator(int &num1, int &num2){
        string a = to_string(num1);
        string b = to_string(num2);
        return a + b > b + a;
    }
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), comparator);
        string ans = "";
        for(auto &num : nums) ans += to_string(num);
        return ans[0] != '0' ? ans : "0";
    }
};