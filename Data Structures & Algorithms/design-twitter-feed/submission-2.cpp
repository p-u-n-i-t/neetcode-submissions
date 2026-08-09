class Twitter {
    private:
    int count;
    map<int,set<pair<int,int>>>id;
    map<int,set<int>>follower_id;
public:

    Twitter() {
        count=1;
    }
    
    void postTweet(int userId, int tweetId) {
            id[userId].insert({count,tweetId});
            count++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>news_feed;
       
       for(auto &it:id[userId]){
         news_feed.push(it);
         if(news_feed.size()>10) news_feed.pop();
       }
       for(auto &it:follower_id[userId]){
            for(auto &it2:id[it]){
                news_feed.push(it2);
         if(news_feed.size()>10) news_feed.pop();
            }
       }
       
       vector<int>dashboard_news;
       int n=news_feed.size();
       int index=0;
       while(news_feed.size()>0){
            auto x=news_feed.top();
            dashboard_news.push_back(x.second);
            news_feed.pop();
       }
       reverse(dashboard_news.begin(),dashboard_news.end());
       return dashboard_news;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId!=followeeId)              follower_id[followerId].insert({followeeId});
        
    }
    
    void unfollow(int followerId, int followeeId) {
          follower_id[followerId].erase(followeeId);
    }
};
