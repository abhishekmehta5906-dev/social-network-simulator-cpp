#ifndef AVL_HPP
#define AVL_HPP

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Post {
    string content;
    long long timestamp;

    Post() : content(""), timestamp(0) {}
    Post(const string &text, long long ts) : content(text), timestamp(ts) {}
};

struct AVLNode {
    Post data;
    AVLNode* left;
    AVLNode* right;
    int height;

    AVLNode(const Post &p) {
        data=p;
        left=nullptr;
        right=nullptr;
        height=1;
    }
};

class AVLTree {
private:
    AVLNode* root;

    AVLNode* insert(AVLNode* node, const Post &post);
    AVLNode* rotateRight(AVLNode* y);
    AVLNode* rotateLeft(AVLNode* x);
    int height(AVLNode* n);
    int getBalance(AVLNode* n);
    void collectReverse(AVLNode* n, vector<Post> &out, int &remaining);
    void freeNodes(AVLNode* n);

public:
    AVLTree();
    ~AVLTree();

    void addPost(const string &text, long long ts);
    vector<Post> getRecentPosts(int count = -1);
};

#endif
