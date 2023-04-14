class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s;
        stringstream ss(path);
        string token;

        while (getline(ss, token, '/')) {
            if (token == "..") {
                if (!s.empty()) {
                    s.pop();
                }
            } else if (token != "" && token != "." && token != "..") {
                s.push(token);
            }
        }

        if (s.empty()) {
            return "/";
        }

        vector<string> v;
        while (!s.empty()) {
            v.push_back(s.top());
            s.pop();
        }

        reverse(v.begin(), v.end());

        string res;
        for (string& str : v) {
            res += "/" + str;
        }

        return res;
    }
};
