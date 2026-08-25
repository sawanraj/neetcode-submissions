class TimeMap {
private:
    unordered_map<string,vector<pair<int,string>>>store;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        store[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if(store.find(key) ==store.end())
            return "";

        const auto& history=store[key];

        int l=0;
        int n=history.size();
        int h=n-1;

        string res="";

        while(l<=h){
            int m=l+(h-l)/2;

            if(history[m].first<=timestamp){
                res=history[m].second;
                l=m+1;
            }
            else{
                h=m-1;
            }
        }
    return res;
    }
};
