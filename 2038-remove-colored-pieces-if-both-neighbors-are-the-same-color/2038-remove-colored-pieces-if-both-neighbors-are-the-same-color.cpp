class Solution {
public:
    bool winnerOfGame(string colors) {
        int count=0,count1=0;
        for(int i=1; i<colors.length()-1;i++){
            if(colors[i] =='A' && colors[i-1]=='A' && colors[i+1]=='A'){
                count++;
            }else if(colors[i]=='B' && colors[i-1]=='B' && colors[i+1]=='B'){
                count1++;
            }
        }
        return count>count1;
    }
};