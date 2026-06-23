#ifndef USER_HPP
#define USER_HPP

#include <string>
#include "avl.hpp"
using namespace std;


class User{
public:
    string name;
    AVLTree posts;

    User(const string &originalName);
    ~User();
};

#endif