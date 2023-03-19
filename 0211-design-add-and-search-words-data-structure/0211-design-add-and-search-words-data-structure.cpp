class WordDictionary {
public:
    WordDictionary(){
        
    }
    
    struct TrieNode{
        bool end;
        TrieNode* child[26];       
        TrieNode(){
            end = false;
            for(int i = 0; i < 26; i++){
                child[i] = NULL;
            }
        }
    };
    
    TrieNode* root = new TrieNode();
    void addWord(string word){
        int n = word.size();
        TrieNode* curr = root;
        for(int i = 0; i < n; i++){
            int idx = word[i] - 'a';
            if(curr -> child[idx] == NULL){
                curr -> child[idx] = new TrieNode();
            }
            curr = curr -> child[idx];
        }
        curr -> end = true;
    }
    
    bool rec_search(string &str, int i, int n, TrieNode* curr){
        if(i == n){
            return curr -> end;
        }
        if(str[i] != '.'){
            int idx = str[i] - 'a';
            if(curr -> child[idx] == NULL){
                return false;
            }
            return rec_search(str, i + 1, n, curr -> child[idx]);
        }else{   
            for(int j = 0; j < 26; j++){
                if(curr -> child[j] != NULL){
                    if(rec_search(str, i + 1, n, curr -> child[j]))
                        return true;
                }
            }
        }
        return false;
    }
    
    bool search(string word){
        int n = word.size();
        return rec_search(word, 0, n, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */