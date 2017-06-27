#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;

/*
 * Design Twitter
 *
 * Design a simplified version of Twitter where users can post tweets, follow/unfollow another user and is able to see the 10 most recent tweets in the user's news feed. Your design should support the following methods:
 *
 * postTweet(userId, tweetId): Compose a new tweet.
 * getNewsFeed(userId): Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent.
 * follow(followerId, followeeId): Follower follows a followee.
 * unfollow(followerId, followeeId): Follower unfollows a followee.
 * Example:
 *
 * Twitter twitter = new Twitter();
 *
 * // User 1 posts a new tweet (id = 5).
 * twitter.postTweet(1, 5);

 * // User 1's news feed should return a list with 1 tweet id -> [5].
 * twitter.getNewsFeed(1);
 *
 * // User 1 follows user 2.
 * twitter.follow(1, 2);
 *
 * // User 2 posts a new tweet (id = 6).
 * twitter.postTweet(2, 6);
 *
 * // User 1's news feed should return a list with 2 tweet ids -> [6, 5].
 * // Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
 * twitter.getNewsFeed(1);
 *
 * // User 1 unfollows user 2.
 * twitter.unfollow(1, 2);
 *
 * // User 1's news feed should return a list with 1 tweet id -> [5],
 * // since user 1 is no longer following user 2.
 * twitter.getNewsFeed(1);
 *
 *
 */

struct mycomp {
public:
    bool operator() (const pair<int, int>& lhs, const pair<int, int>& rhs) {
        return lhs.first > rhs.first;
    }
};

class Twitter {
private:
    int cnt;    //标记当前时间，越大表示时间越靠后
    map<int, set<pair<int, int>>> feeds;    //记录用户发送的feed
    map<int, set<int>> follows;     //记录用户的关注列表

public:
    Twitter() {
        cnt = 0;
    }

    void postTweet(int userId, int tweetId) {
        if(follows.find(userId) == follows.end())
            follows[userId] = set<int>();
        if(feeds.find(userId) == feeds.end())
            feeds[userId] = set<pair<int, int>>();
        feeds[userId].insert(pair<int, int>(cnt++, tweetId));
    }

    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        if(follows.find(userId) == follows.end())
            return res;
        priority_queue<pair<int, int>, vector<pair<int, int>>, mycomp> news;
        set<int> user_follows = follows[userId];
        if(feeds.find(userId) == feeds.end())
            feeds[userId] = set<pair<int, int>>();
        for(auto feed: feeds[userId]) {
            news.push(feed);
            if(news.size() > 10)
            	news.pop();
        }
        for(auto followee: user_follows) {
            if(followee != userId) {
                for(auto feed: feeds[followee]) {
                    news.push(feed);
                    if(news.size() > 10)
                        news.pop();
                }
            }
        }
        while(!news.empty()) {
            res.push_back(news.top().second);
            news.pop();
        }
        int i = 0, j = res.size() - 1;
        while(i < j) {
        	swap(res[i], res[j]);
        	i++;
        	j--;
        }
        return res;
    }

    void follow(int followerId, int followeeId) {
        if(follows.find(followerId) == follows.end())
            follows[followerId] = set<int>();
        if(feeds.find(followerId) == feeds.end())
            feeds[followerId] = set<pair<int, int>>();
        if(follows.find(followeeId) == follows.end())
            follows[followeeId] = set<int>();
        if(feeds.find(followeeId) == feeds.end())
            feeds[followeeId] = set<pair<int, int>>();
        follows[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        if(follows.find(followerId) == follows.end())
            return;
        follows[followerId].erase(followeeId);
    }
};
