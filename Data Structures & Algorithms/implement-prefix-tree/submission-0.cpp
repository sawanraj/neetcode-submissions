class Node{
    public:
    char data;
    unordered_map<char,Node*>mp;
    bool isTerminal;
    Node(char d){
        data=d;
        isTerminal=false;
    }
};
class PrefixTree {
    Node* root;
public:
    PrefixTree() {
        root=new Node('\0');

    }
    
    void insert(string word) {
        Node* temp=root;
        for(char ch:word){
            if(temp->mp.count(ch)==0){
                Node* n=new Node(ch);
                temp->mp[ch]=n;
            }
            temp=temp->mp[ch];
        }
        temp->isTerminal=true;
    }
    
    bool search(string word) {
        Node *temp=root;
        for(char ch:word){
            if(temp->mp.count(ch)==0){
                return false;
            }
            temp=temp->mp[ch];
        }
        return temp->isTerminal;
    }
    
    bool startsWith(string prefix) {
        Node* temp=root;
        for(char ch:prefix){
            if(temp->mp.count(ch)==0){
                return false;
            }
            temp=temp->mp[ch];
        }
    return true;
    }
};
