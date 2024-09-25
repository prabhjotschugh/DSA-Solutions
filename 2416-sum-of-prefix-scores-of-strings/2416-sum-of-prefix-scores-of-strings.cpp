class TrieNode {
    public:
    int count;
    TrieNode* children[26];
    TrieNode() : count(0), children{NULL} {}
};
class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        auto *root = new TrieNode();

        for(auto w : words){
            auto *node = root;
            for(auto ch : w){
                int assci = ch - 'a';
                if(not node->children[assci])
                    node->children[assci] = new TrieNode();
                node = node->children[assci];
                node->count += 1;
            }
        }
        vector<int>ans;
        for(auto w : words){
            auto sum  = 0;
            auto *node = root;
            for(auto ch : w){
                int assci = ch - 'a';
                node = node->children[assci];
                sum += node->count;
            }
            ans.push_back(sum);
        }
        return ans;
    }
};