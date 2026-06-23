// #include <iostream>
// #include <sstream>
// #include <string>
// #include <algorithm>
// #include <cctype>
// #include "graph.hpp"
// using namespace std;

// static string toLower(const string &s) {
//     string r = s;
//     transform(r.begin(), r.end(), r.begin(), ::tolower);
//     return r;
// }

// int main() {
//     Graph social;
//     string line;

//     while (getline(cin,line)) {
//         if(line.size() == 0) continue;
//         stringstream ss(line);

//         string first;
//         ss >> first;
//         if(first == "ADD") {
//             string second;
//             ss >> second;
//             if(second == "USER") {
//                 string username;
//                 ss >> username;
//                 social.addFriend(toLower(username), (username));
//             }
//             else if(second == "FRIEND") {
//                 string user1, user2;
//                 ss >> user1 >> user2;
//                 social.addFriend(toLower(user1), toLower(user2));
//             }
//             else if(second == "POST") {
//                 string username;
//                 ss >> username;
                
//                 string content;
//                 size_t firstquote = line.find('"');
//                 if(firstquote != string::npos) {
//                     size_t secondquote = line.find('"', firstquote + 1);
//                     if(secondquote != string::npos && secondquote > firstquote) {
//                     content = line.substr(firstquote + 1, secondquote-firstquote-1);
//                     }
//                 }
//                 social.addPost(toLower(username), content);
//             }
//         }
//         else if(first == "LIST") {
//             string second;
//             ss >> second;
//             if(second == "FRIENDS") {
//                 string username;
//                 ss >> username;
//                 social.listFriends(toLower(username));
//             }
//         }
//         else if(first == "SUGGEST") {
//             string second;
//             ss >> second;
//             if(second == "FRIENDS") {
//                 string username;
//                 int N;
//                 ss >> username >> N;
//                 social.suggestFriends(toLower(username), N);
//             }
//         }
//         else if(first == "DEGREES") {
//             string of, separation, user1, user2;
//             ss >> of >> separation >> user1 >> user2;
//             social.degreeofSeparation(toLower(user1), toLower(user2));
//         }
//         else if(first == "OUTPUT") {
//             string second;
//             ss >> second;
//             if(second == "POSTS") {
//                 string username;
//                 int N;
//                 ss >> username >> N;
//                 social.outputPosts(toLower(username), N);
//             }
//         }
//     }

//     return 0;
// }


#include <iostream>
#include <string>
#include "graph.hpp"
using namespace std;

int main() {
    cout << "Welcome to the Social Network!" << endl;
    Graph social; // changed SocialNet -> Graph
    string command;

    while (true) {
        if (!(cin >> command)) break;

        else if (command == "ADD_USER") {
            string username; 
            cin >> username;
            social.addUser(username);
        }

        else if (command == "ADD_FRIEND") {
            string u, v; 
            cin >> u >> v;
            social.addFriend(u, v);
        }

        else if (command == "ADD_POST") {
            string username; 
            cin >> username;
            string content;
            getline(cin, content);

            size_t first = content.find('"');
            size_t last = content.rfind('"');
            if (first != string::npos && last != string::npos && last > first)
                content = content.substr(first + 1, last - first - 1);
            else
                content = "";

            social.addPost(username, content);
        }

        else if (command == "LIST_FRIENDS") {
            string username; 
            cin >> username;
            social.listFriends(username);
        }

        else if (command == "SUGGEST_FRIENDS") {
            string username; 
            int N;
            cin >> username >> N;
            social.suggestFriends(username, N);
        }

        else if (command == "DEGREES_OF_SEPARATION") {
            string u1, u2;
            cin >> u1 >> u2;
            social.degreeofSeparation(u1, u2);
        }

        else if (command == "OUTPUT_POSTS") {
            string username; 
            int N;
            cin >> username >> N;
            social.outputPosts(username, N);
        }

        else if (command == "EXIT") {
            cout << "Exiting Social Network..." << endl;
            break;
        }
    }

    return 0;
}
