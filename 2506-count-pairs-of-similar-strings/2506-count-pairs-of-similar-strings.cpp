class Solution {
public:
    vector<int> mapping(string &words){
        vector<int> ans(26, 0);
        for (int i = 0; i < words.size(); i++){
            ans[words[i] - 'a']++;
        }
        return ans;
    }

    int similarPairs(vector<string>& words) {
        int n=words.size();
        int count = 0;
        for (int i = 0; i < n; i++){
            vector<int> mapping1 = mapping(words[i]);
            for (int j = i + 1; j < n; j++){
                vector<int> mapping2 = mapping(words[j]);
                bool equal = true;
                for (int k = 0; k < 26; k++){
                    if ((mapping1[k] != 0 && mapping2[k] == 0) || mapping1[k] == 0 && mapping2[k] != 0){
                        equal = false;
                        break;
                    }
                }
                if (equal)
                    count++;
            }
        }
        return count;
    }
};