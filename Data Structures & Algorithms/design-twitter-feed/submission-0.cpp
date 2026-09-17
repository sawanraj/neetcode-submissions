class Twitter {
    int timestamp;
    struct Tweet{
        int id;
        int time;
        Tweet(int id, int time):id(id),time(time){}
    };
    unordered_map<int,unordered_set<int>>followee;
    unordered_map<int,vector<Tweet>>tweets;
public:
    Twitter() {
        timestamp=0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].emplace_back(tweetId,timestamp++);
    }
    
    vector<int> getNewsFeed(int userId) {
        auto comp=[](const Tweet& a, const Tweet& b){return a.time >b.time;};

        priority_queue<Tweet,vector<Tweet>,decltype(comp)>minheap(comp);
        unordered_set<int>userstoFetch=followee[userId];
        userstoFetch.insert(userId);
        for(int user:userstoFetch){
            const auto& userTweets=tweets[user];
            int count=0;
            for(auto it=userTweets.rbegin(); it != userTweets.rend() && count<10;++it,++count){
               minheap.push(*it);
               if(minheap.size() >10){
                    minheap.pop();
               } 
            }
        }
        vector<int>feed;
        while(!minheap.empty()){
            feed.push_back(minheap.top().id);
            minheap.pop();
        }
        reverse(feed.begin(),feed.end());
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId!=followeeId){
            followee[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId!=followeeId){
            followee[followerId].erase(followeeId);
        }
    }
};
