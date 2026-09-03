struct Node{
    int key;
    int value;
    Node(int k,int v):key(k),value(v){}
};
class LRUCache {
public:
    int capacity;
    list<Node>l;
    unordered_map<int,list<Node>::iterator>mp;
    LRUCache(int capacity) {
        this->capacity=capacity>0?capacity:1;
    }
    
    int get(int key) {
        if(mp.count(key)!=0){
            auto it=mp[key];
            int value=it->value;
            l.push_front(*it);
            l.erase(it);
            mp[key]=l.begin();
            return value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.count(key)!=0){
            auto it=mp[key];
            it->value=value;
            l.erase(it);
            l.push_front(Node(key,value));
            mp[key]=l.begin();
            return;
        }
        else{
            if(l.size()==capacity){
                Node last=l.back();
                mp.erase(last.key);
                l.pop_back();
            }
            l.push_front(Node(key,value));
            mp[key]=l.begin();
        }
    }
};
