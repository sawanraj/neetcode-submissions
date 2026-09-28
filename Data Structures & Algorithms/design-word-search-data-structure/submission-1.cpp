class Node{
    public:
    char data;
    unordered_map<char,Node*>mp;
    bool isterminal;
    Node(char d){
        data=d;
        isterminal=false;
    }
};
class WordDictionary {
    Node* root;
public:
    WordDictionary() {
        root=new Node('\0');
    }
    
    void addWord(string word) {
        Node* temp=root;
        for(char ch:word){
            if(temp->mp.count(ch)==0){
                Node *n=new Node(ch);
                temp->mp[ch]=n;
            }
            temp=temp->mp[ch];
        }
        temp->isterminal=true;
    }
    
    bool search(string word) {
        Node* temp=root;
    return searchhelper(word,0,root);
    }
    bool searchhelper(string &word, int idx, Node* curr){
        if(curr == nullptr)
            return false;
        if(idx == word.length())
            return curr->isterminal;

        char ch=word[idx];
        if(ch == '.'){
            for(auto& pair:curr->mp){
                if(searchhelper(word,idx+1,pair.second)){
                    return true;
                }
            }
            return false;
        }
        else {
            if(curr->mp.count(ch)==0){
                return false;
            }
            return searchhelper(word,idx+1,curr->mp[ch]);
        }
    }
};
