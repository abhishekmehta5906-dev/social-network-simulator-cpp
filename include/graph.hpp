#ifndef GRAPH_HPP
#define GRAPH_HPP

#include<vector>
#include <string>
#include<queue>
#include <algorithm>
#include<iostream>
#include "user.hpp"
using namespace std;

class Graph {
private:
    vector<User*> users;
    vector<vector<int>> adj;
    long long timestamp = 1;

    int findUserIndex(const string &name);
    bool areFriends(int i, int j);

public:
    Graph();
    ~Graph();

    void addUser(const string &username);
    void addFriend(const string &user1, const string &user2);
    void listFriends(const string &username);
    void suggestFriends(const string &username, int N);
    void degreeofSeparation(const string & user1, const string &user2);
    void addPost(const string &username, const string &content);
    void outputPosts(const string &username, int N);
};

#endif
