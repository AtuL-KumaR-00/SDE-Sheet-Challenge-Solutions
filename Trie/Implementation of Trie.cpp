/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */
struct Node{
    Node *arr[26];
    bool flag=false;
    
    bool containsKey(char c){
        return (arr[c-'a']!=NULL);
    }
    void put(char c, Node* node){
        arr[c-'a']=node;
    }
    Node* get(char c){
        return arr[c-'a'];
    }
    
};

class Trie {

public:
    Node* root;
    /** Initialize your data structure here. */
    Trie() {
        root= new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* curr=root;
        for(int i=0;i<word.size();i++){
            if(!curr->containsKey(word[i])){
                curr->put(word[i],new Node);
            }
            curr=curr->get(word[i]);
        }
        curr->flag=true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* curr=root;
        for(int i=0;i<word.size();i++){
            if(!curr->containsKey(word[i]))    
                return false;
            curr=curr->get(word[i]);
        }
        //if(curr->flag==true)    return true;
        return curr->flag;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* curr=root;
        for(int i=0;i<prefix.size();i++){
            if(!curr->containsKey(prefix[i]))    
                return false;
            curr=curr->get(prefix[i]);
        }
        return true;
    }
};