class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folders) {
        sort(folders.begin(), folders.end());
        int n = folders.size();
        vector<string> ans;
        map<string, int> mp;
        for(int i=0; i<n; i++){
            string s = folders[i];
            string temp;
            bool flag = false;
            int incr=1;
            for(int j=0; j<s.size();){
                int k=j;
                if(j == 0){
                    temp.push_back('/');
                    k++;
                }
                while(k<s.size() && s[k]!='/'){
                    temp.push_back(s[k]);
                    k++;
                }
                if(k < s.size() && s[k] == '/'){
                    temp.push_back('/');
                    k++;
                }
                j = k;
                bool x = 0;
                if(temp[temp.size()-1] == '/'){
                    temp.pop_back();
                    x=1;
                }
                if(mp.find(temp)!=mp.end()){
                    flag = true;
                    break;
                }
                if(x)
                    temp.push_back('/');
            }
            if(!flag) {
                mp[s]++;
                ans.push_back(s);
            }
        }
        return ans;
    }

};