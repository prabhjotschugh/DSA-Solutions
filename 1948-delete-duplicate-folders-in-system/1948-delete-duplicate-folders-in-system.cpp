struct Trie {
    std::string folderName;
    std::unordered_map<std::string, Trie*> children;
};

class Solution {
public:
    void build(Trie *node, std::unordered_map<std::string, int> &hashmap) {
        if (node->children.empty()) return;
        std::vector<std::string> v;
        for (const auto& [folder, child] : node->children) {
            build(child, hashmap);
            v.push_back(folder + "(" + child->folderName + ")");
        }
        sort(v.begin(), v.end());
        for (std::string &s : v) node->folderName += move(s);
        ++hashmap[node->folderName];
    };

    void traverse(Trie *node, std::unordered_map<std::string, int> &hashmap, std::vector<std::vector<std::string>> &output, std::vector<std::string> &path) {
        if (hashmap[node->folderName] > 1) return;
        if (!path.empty()) output.push_back(path);
        for (const auto& [folder, child] : node->children) {
            path.push_back(folder);
            traverse(child, hashmap, output, path);
            path.pop_back();
        }
    };

    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        Trie* root = new Trie();
        for (const std::vector<std::string> &path : paths) {
            Trie* cur = root;
            for (const std::string &dir : path) {
                if (!cur->children.count(dir)) {
                    cur->children[dir] = new Trie();
                }
                cur = cur->children[dir];
            }
        }
        std::unordered_map<std::string, int> hashmap; 
        build(root, hashmap);
        std::vector<std::vector<std::string>> output;
        std::vector<std::string> path;
        traverse(root, hashmap, output, path);
        return output;
    }
};