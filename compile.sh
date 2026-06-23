g++ -std=c++17 main.cpp graph.cpp user.cpp avl.cpp -o socialnet

if [$? -eq 0]; then
    echo "Compilation successfully. Run with: ./socialnet"

else
    echo "Compilation failed."

fi