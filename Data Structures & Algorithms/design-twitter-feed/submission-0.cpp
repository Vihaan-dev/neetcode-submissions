class Twitter {
    unordered_map<int,unordered_set<int>> f;//id:followeres
    vector<pair<int,int>> tweets; //userid,tweetid
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets.push_back(pair<int,int>(userId,tweetId));
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        int count = 0;
        for (int i=tweets.size()-1;i>=0&&count<10;i--){
            if (f[userId].contains(tweets[i].first)||tweets[i].first==userId) {ans.push_back(tweets[i].second);count ++;}

        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        f[followerId].insert(followeeId);
        
    }
    
    void unfollow(int followerId, int followeeId) {
        f[followerId].erase(followeeId);
    }
};
