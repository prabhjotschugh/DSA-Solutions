class Solution {
public:
    vector<int> par, size;
    int findParent(int u) {
        if (par[u] == u)
            return u;

        return par[u] = findParent(par[u]);
    }
    void Union(int u, int v) {
        int up = findParent(u);
        int vp = findParent(v);

        if (up == vp)
            return;
        if (size[up] > size[vp]) {
            size[up] += size[vp];
            par[vp] = up;
        } else {
            size[vp] += size[up];
            par[up] = vp;
        }
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        par.resize(26, 0);
        for (int i = 0; i < 26; i++)
            par[i] = i;
        size.resize(26, 0);
        for (int i = 0; i < s1.size(); i++) {
            int c1 = s1[i] - 'a';
            int c2 = s2[i] - 'a';

            Union(c1, c2);
        }

        // for(int i=0; i<par.size(); i++) cout<<size[i]<< " ";

        map<int, int> mp;
        for (int i = 0; i < par.size(); i++) {
            int p = findParent(i);
            if (mp.find(p) == mp.end())
                mp[p] = i;
            else
                mp[p] = min(mp[p], i);
        }

        string ans;
        for (auto c : baseStr) {
            int x = findParent(c - 'a');
            ans.push_back(mp[x] + 'a');
        }
        return ans;
    }
};