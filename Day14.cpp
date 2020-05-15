class TrieNode{
public:
    TrieNode *chars[26];
    bool isEnd;
    TrieNode()
    {
        for(int i=0;i<26;i++)
            chars[i] = NULL;
        isEnd = false;
    }
};

class Trie {
public:
    /** Initialize your data structure here. */
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *curr = root;
        for(int i=0;i<word.length(); i++)
        {
            if(curr->chars[word[i]-'a'] == NULL)
            {
                curr->chars[word[i]-'a'] = new TrieNode();
            }
            curr = curr->chars[word[i]-'a'];
        }
        curr->isEnd = true;
        
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *curr = root;
        
        for(int i=0;i<word.length(); i++)
        {
            if(curr->chars[word[i]-'a'] == NULL)
                return false;
            curr = curr->chars[word[i]-'a'];
        }
        
        return curr->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
       TrieNode *curr = root;
        
       for(int i=0;i<prefix.length(); i++)
       {
           if(curr->chars[prefix[i] - 'a'] == NULL)
               return false;
           curr = curr->chars[prefix[i] - 'a'];
       }
        
       if(curr->isEnd == true)
           return true;
       
        for(int i=0;i<26;i++)
        {
            if(curr->chars[i] != NULL)
                return true;
        }
        return false;
    }
};
/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
