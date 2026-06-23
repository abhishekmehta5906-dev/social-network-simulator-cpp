#include "graph.hpp"
#include <queue>
#include <algorithm>
using namespace std;

Graph::Graph() {}

Graph::~Graph() {
    for(auto u : users) delete u;
}

int Graph::findUserIndex(const string & name) {
    for(int i=0; i<users.size(); i++) {
        if(users[i]->name == name) return i;
    }
    return -1;
}

bool Graph::areFriends(int i, int j) {
    for(int f : adj[i])
        if(f == j) return true;
    return false;
}

void Graph::addUser(const string &username) {
    if(findUserIndex(username) != -1) return;
    users.push_back(new User(username));
    adj.push_back(vector<int>());
}
void Graph::addFriend(const string &user1, const string &user2) {
    int i = findUserIndex(user1), j = findUserIndex(user2);
    if(i == -1 || j == -1 || i == j) return;

    if(!areFriends(i, j)) {
        adj[i].push_back(j);
        adj[j].push_back(i);
    }
}

void Graph::listFriends(const string &username) {
    int i = findUserIndex(username);
    if(i == -1) return;

    vector<string> friends;
    for(int f : adj[i]) friends.push_back(users[f]->name);
    sort(friends.begin(), friends.end());

    for(auto &n : friends) cout << n << endl;
}

bool comparePairs(pair<string, int> &a, pair<string, int> &b) {
    if (a.second != b.second)
        return a.second > b.second;
    return a.first < b.first;
}

void Graph::suggestFriends(const string &username, int N) {
    int u = findUserIndex(username);
    if(u == -1 || N == 0) return;

    vector<int> mutual(users.size(), 0);
    for(int f : adj[u]) {
        for(int fof : adj[f]) {
            if(fof == u) continue;
            if(areFriends(u, fof)) continue;
            mutual[fof]++;
        }
    }

    vector<pair<string, int>> candidates;
    for (int i = 0; i < (int)users.size(); i++)
        if (i != u && mutual[i] > 0)
            candidates.push_back({users[i]->name, mutual[i]});

    sort(candidates.begin(), candidates.end(), comparePairs);

    for (int i = 0; i < (int)candidates.size() && i < N; ++i)
        cout << candidates[i].first << endl;
}

void Graph::outputPosts(const string &username, int N) {
    int  i = findUserIndex(username);
    if(i == -1) return;

    auto posts = users[i]->posts.getRecentPosts(N);
    for(auto &p : posts) cout << p.content << endl;
}

void Graph::degreeofSeparation(const string &user1, const string &user2) {
    int s = findUserIndex(user1);
    int t = findUserIndex(user2);
    if (s == -1 || t == -1) {
        cout << -1 << endl;
        return;
    }

    vector<int> dist(users.size(), -1);
    queue<int> q;
    dist[s] = 0;
    q.push(s);

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int i : adj[v]) {
            if (dist[i] == -1) {
                dist[i] = dist[v] + 1;
                if (i == t) {
                    cout << dist[i] << endl;
                    return;
                }
                q.push(i);
            }
        }
    }
    cout << -1 << endl;
}

void Graph::addPost(const string &username, const string &content) {
    int i = findUserIndex(username);
    if(i == -1) return;
    users[i]->posts.addPost(content, timestamp++);
}
