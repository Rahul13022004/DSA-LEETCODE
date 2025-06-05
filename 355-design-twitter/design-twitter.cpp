class Twitter {
private:
    int time;
    unordered_map<int, unordered_set<int>> following;
    unordered_map<int, vector<pair<int, int>>> tweets;

public:
    Twitter() {
        time = 0;
    }

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> pq; // max-heap: {timestamp, tweetId}
        unordered_set<int> users = following[userId];
        users.insert(userId); // include self

        for (int uid : users) {
            for (auto &tweet : tweets[uid]) {
                pq.push(tweet);
                if (pq.size() > 50) pq.pop(); // optional optimization
            }
        }

        vector<int> res;
        while (!pq.empty() && res.size() < 10) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }

    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            following[followerId].insert(followeeId);
        }
    }

    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};
