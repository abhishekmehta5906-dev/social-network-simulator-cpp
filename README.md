# Social Network Simulator

A command-line social network simulator implemented in C++ using Graphs, BFS and AVL Trees.

## Features

- Add and manage users
- Create friendships
- Add and retrieve posts
- Suggest friends based on mutual connections
- Compute degrees of separation using BFS

## Data Structures Used

| Component | Data Structure |
|-----------|----------------|
| Social Network | Graph (Adjacency List) |
| Posts | AVL Tree |
| Friend Recommendation | Mutual Friend Analysis |
| Degrees of Separation | BFS |

## Project Structure

```
src/
├── main.cpp
├── graph.cpp
├── user.cpp
└── avl.cpp

include/
├── graph.hpp
├── user.hpp
└── avl.hpp
```

## Compilation

```bash
g++ -std=c++17 main.cpp graph.cpp user.cpp avl.cpp -o socialnet
```

## Sample Commands

```text
ADD_USER Alice
ADD_USER Bob

ADD_FRIEND Alice Bob

ADD_POST Alice "Hello World!"

LIST_FRIENDS Alice

SUGGEST_FRIENDS Alice 3

DEGREES_OF_SEPARATION Alice Bob

OUTPUT_POSTS Alice -1

EXIT
```

## Algorithms Used

- Breadth First Search (BFS)
- AVL Tree Rotations (LL, RR, LR, RL)
- Mutual Friend Recommendation
