SocialNet Simulator

# OVERVIEW
This program simulates a basic social network on the command line.
It supports adding users, creating friendships, posting messages,
listing friends, suggesting new friends, viewing degrees of separation,
and displaying user posts.

Data Structures Used:
- Graph (Adjacency List) for managing users and friendships
- AVL Tree for storing and sorting user posts by timestamp

# FILE STRUCTURE
SocialNet/
│
├── main.cpp           → Handles command input and program control
├── graph.hpp / graph.cpp  → Graph class implementation
├── user.hpp / user.cpp    → User class and data storage
├── avl.hpp / avl.cpp      → AVL Tree for post management
├── compile.sh         → Script to compile all source files
└── README.txt         → Documentation file

# COMPILATION

### Using the provided script:
    ./compile.sh

### Or compile manually:
    g++ -std=c++17 main.cpp graph.cpp user.cpp avl.cpp -o socialnet

# RUNNING THE PROGRAM

Run the executable:
    ./socialnet

You will see:
    Welcome to the Social Network!

Enter commands line by line as described below.

# COMMANDS

ADD_USER <username>  
    → Adds a new user to the network.

ADD_FRIEND <user1> <user2>  
    → Creates a friendship between two existing users.

ADD_POST <username> "<post content>"  
    → Adds a post for the given user.

LIST_FRIENDS <username>  
    → Displays all friends of the user in alphabetical order.

SUGGEST_FRIENDS <username> <N>  
    → Suggests up to N new friends ranked by mutual connections.

DEGREES_OF_SEPARATION <user1> <user2>  
    → Prints the shortest friendship path length between two users.

OUTPUT_POSTS <username> <N>  
    → Displays the most recent N posts (or all if N = -1).

EXIT  
    → Ends the simulation.

# SAMPLE INPUT

ADD_USER Alice
ADD_USER Bob
ADD_USER Charlie
ADD_FRIEND Alice Bob
ADD_FRIEND Bob Charlie
ADD_POST Alice "Hello from Alice!"
LIST_FRIENDS Alice
SUGGEST_FRIENDS Alice 2
DEGREES_OF_SEPARATION Alice Charlie
OUTPUT_POSTS Alice -1
EXIT

# SAMPLE OUTPUT

Welcome to the Social Network!
Bob
Charlie
2
Hello from Alice!
Exiting Social Network...

# NOTES
- Usernames are case-sensitive in this version.
- Posts are stored chronologically using an AVL tree.
- Friend suggestions are based on mutual friends count.
- BFS is used to compute degrees of separation.

# END OF FILE
