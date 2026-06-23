# Social Network Simulator

A command-line social network simulator implemented in **C++** using **Graphs, Breadth First Search (BFS)** and **AVL Trees**.

---

## Overview

This project simulates a miniature social networking platform where users can:

- Create accounts
- Form friendships
- Create posts
- Get friend recommendations
- Find degrees of separation between users
- View recent posts

The project demonstrates the implementation and application of fundamental data structures and algorithms in C++.

---

## Features

### User Management
- Add new users
- Prevent duplicate users

### Friendship Network
- Add friendships between users
- List friends alphabetically

### Friend Recommendations
- Suggest friends based on the number of mutual friends
- Rank suggestions by:
  1. Number of mutual friends
  2. Lexicographical order of usernames

### Degrees of Separation
- Compute the shortest friendship path between two users
- Implemented using **Breadth First Search (BFS)**

### Post Management
- Add posts with timestamps
- Retrieve the most recent posts efficiently

---

## Data Structures Used

| Component | Data Structure |
|-----------|----------------|
| Users | Vector of User objects |
| Friendships | Graph (Adjacency List) |
| Friend Suggestions | Mutual Friend Analysis |
| Shortest Path | Breadth First Search (BFS) |
| Posts | AVL Tree |

---

## Project Structure

```text
social-network-simulator-cpp

├── src
│   ├── main.cpp
│   ├── graph.cpp
│   ├── user.cpp
│   └── avl.cpp
│
├── include
│   ├── graph.hpp
│   ├── user.hpp
│   └── avl.hpp
│
├── compile.sh
└── README.md
```

---

## Algorithms Implemented

### Breadth First Search (BFS)

Used to compute:

- Degrees of separation
- Shortest friendship path

**Time Complexity**

```text
O(V + E)
```

where

- V = Number of users
- E = Number of friendships

---

### AVL Tree

Used for:

- Storing posts
- Maintaining chronological ordering
- Efficient insertion and retrieval

**Time Complexity**

| Operation | Complexity |
|-----------|-----------|
| Insert Post | O(log n) |
| Retrieve Recent Posts | O(log n) + O(k) |

---

## Sample Commands

```text
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
```

---

## Sample Output

```text
Welcome to the Social Network!

Bob

Charlie

2

Hello from Alice!

Exiting Social Network...
```

---

## Future Improvements

- Persistent storage using files
- Graph visualization
- User profiles
- Faster username lookup using hash maps
- Improved recommendation algorithms

---

## Author

**Abhishek Mehta**

B.Tech Electrical Engineering  
Indian Institute of Technology Delhi
