class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int currShifts = 0;
        for(int i = s.size()-1; i >= 0; i--){
            currShifts += shifts[i];
            currShifts %= 26;
            if(currShifts > 'z' - s[i])
                s[i] += currShifts - 26;
            else      
                s[i] += currShifts;
        }
        return s;
    }
};