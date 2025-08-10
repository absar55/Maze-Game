#include <iostream>
#include <vector>
#include <queue>
#include <ctime> // For timing
using namespace std;

// Function to check if a path reaches the finish or if a move is valid
bool atFinish(const vector<vector<char>> &maze, const string &path, bool endCheck, bool moveCheck)
{
    int startX = 0, startY = 0;

    // Find the start position ('S')
    for (int row = 0; row < maze.size(); ++row)
    {
        for (int col = 0; col < maze[row].size(); ++col)
        {
            if (maze[row][col] == 'S')
            {
                startX = col;
                startY = row;
                break;
            }
        }
    }

    // Follow the path to determine the current position
    for (char move : path)
    {
        if (move == 'U')
            startY -= 1;
        else if (move == 'D')
            startY += 1;
        else if (move == 'L')
            startX -= 1;
        else if (move == 'R')
            startX += 1;
    }

    // Check if the end position is the maze's end ('E')
    if (endCheck)
    {
        if (maze[startY][startX] == 'E')
            return true;
    }

    // Check if the move is valid
    if (moveCheck)
    {
        if (startX >= 0 && startX < maze[0].size() && startY >= 0 && startY < maze.size())
        {
            if (maze[startY][startX] != '#')
                return true;
        }
    }

    return false;
}

// BFS-based function to find the shortest path in the maze
string findShortestPath(const vector<vector<char>> &maze)
{
    queue<string> pathQueue; // Queue to store paths
    pathQueue.push("");      // Start with an empty path
    string currentPath = "";

    // Keep searching until the shortest path to the end is found
    while (!atFinish(maze, currentPath, true, false))
    {
        currentPath = pathQueue.front();
        pathQueue.pop();

        // Add all possible moves (U, D, L, R) to the current path
        for (char direction : {'U', 'D', 'L', 'R'})
        {
            string newPath = currentPath + direction;
            if (atFinish(maze, newPath, false, true))
            {
                pathQueue.push(newPath);
            }
        }
    }

    return currentPath;
}

int main()
{
    // Define a sample maze
    vector<vector<char>> maze = {
        {'S', ' ', ' ', '#', ' ', ' ', ' '},
        {'#', '#', ' ', '#', ' ', '#', ' '},
        {' ', ' ', ' ', ' ', ' ', '#', ' '},
        {' ', '#', '#', '#', ' ', '#', ' '},
        {' ', ' ', ' ', '#', ' ', ' ', ' '},
        {' ', '#', ' ', ' ', ' ', '#', 'E'},
        {' ', '#', '#', '#', ' ', '#', ' '}};

    // Start timing
    clock_t start_time = clock();

    // Find the shortest path using BFS
    string shortestPath = findShortestPath(maze);

    // End timing
    clock_t end_time = clock();

    // Calculate execution time in seconds
    double duration = double(end_time - start_time) / CLOCKS_PER_SEC;

    // Output results
    cout << "Shortest Path: " << shortestPath << endl;
    cout << "Execution Time: " << duration << " seconds" << endl;

    return 0;
}
