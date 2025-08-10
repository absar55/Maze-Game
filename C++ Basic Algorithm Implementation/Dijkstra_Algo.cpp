#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <limits>
#include <algorithm>
#include <ctime> // For timing

using namespace std;

// Directions for Up, Down, Left, Right
const vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

// Define a cell structure for the grid
struct Cell
{
    char type;  // 'S', 'E', '#', or empty space
    int weight; // The cost of entering this cell
};

// Priority queue node
struct Node
{
    int dist; // Distance from the start
    int x, y; // Coordinates of the cell
    bool operator<(const Node &other) const
    {
        return dist > other.dist; // Min-heap
    }
};

// Function to find the shortest path using Dijkstra's algorithm
pair<string, int> dijkstra(vector<vector<Cell>> &grid)
{
    int rows = grid.size();
    int cols = grid[0].size();

    // Priority Queue for Dijkstra's algorithm
    priority_queue<Node> pq;

    // Distance and previous node trackers
    vector<vector<int>> dist(rows, vector<int>(cols, numeric_limits<int>::max()));
    vector<vector<pair<int, int>>> prev(rows, vector<pair<int, int>>(cols, {-1, -1}));

    // Find start ('S') and end ('E') points
    int start_x = -1, start_y = -1, end_x = -1, end_y = -1;
    for (int r = 0; r < rows; ++r)
    {
        for (int c = 0; c < cols; ++c)
        {
            if (grid[r][c].type == 'S')
            {
                start_x = c;
                start_y = r;
                dist[start_y][start_x] = 0;     // Starting point has distance 0
                pq.push({0, start_x, start_y}); // Push the start into the priority queue
            }
            if (grid[r][c].type == 'E')
            {
                end_x = c;
                end_y = r;
            }
        }
    }

    // Ensure 'E' was found
    if (end_x == -1 || end_y == -1)
    {
        cout << "End point 'E' not found." << endl;
        return {"", numeric_limits<int>::max()};
    }

    cout << "Starting Dijkstra's Algorithm..." << endl;

    // Dijkstra's algorithm
    while (!pq.empty())
    {
        Node current = pq.top();
        pq.pop();

        int current_dist = current.dist;
        int x = current.x;
        int y = current.y;

        // If we've reached the end, no need to process further
        if (x == end_x && y == end_y)
        {
            break;
        }

        // Explore neighbors
        for (auto [dx, dy] : DIRECTIONS)
        {
            int nx = x + dx, ny = y + dy;
            if (nx >= 0 && nx < cols && ny >= 0 && ny < rows && grid[ny][nx].type != '#')
            {
                int weight = grid[ny][nx].weight; // Weight of the neighbor cell
                int new_dist = current_dist + weight;

                if (new_dist < dist[ny][nx])
                {
                    dist[ny][nx] = new_dist;
                    prev[ny][nx] = {x, y};
                    pq.push({new_dist, nx, ny});
                }
            }
        }
    }

    // Reconstruct path by backtracking from the end
    string path;
    int total_weight = dist[end_y][end_x];

    if (total_weight != numeric_limits<int>::max())
    {
        int cx = end_x, cy = end_y;
        while (prev[cy][cx].first != -1)
        {
            auto [px, py] = prev[cy][cx];
            if (px == cx)
            {
                path += (py < cy ? 'D' : 'U'); // Down or Up
            }
            else if (py == cy)
            {
                path += (px < cx ? 'R' : 'L'); // Right or Left
            }
            cx = px;
            cy = py;
        }
        reverse(path.begin(), path.end());
    }
    else
    {
        path = ""; // No path found
    }

    return {path, total_weight};
}
int main()
{
    // Initialize SDL (replace with SDL or other graphics libraries in C++)
    const int WIDTH = 600;
    const int HEIGHT = 600;

    const int GRID_SIZE = 7; // Fixed grid size
    const int BOX_SIZE = 50;
    const int MARGIN = 5;

    // Define predefined weights (matching the Python example)
    vector<vector<int>> PREDEFINED_WEIGHTS = {
        {1, 1, 1, 2, 1, 3, 1},
        {1, 3, 2, 1, 1, 2, 1},
        {1, 1, 1, 1, 2, 1, 1},
        {3, 2, 1, 1, 1, 1, 3},
        {1, 1, 1, 2, 1, 3, 1},
        {1, 2, 1, 1, 1, 1, 1},
        {1, 1, 3, 2, 1, 1, 1}};

    // Create a 2D grid of cells
    vector<vector<Cell>> grid(GRID_SIZE, vector<Cell>(GRID_SIZE));

    // Populate the grid with cells using predefined weights
    for (int r = 0; r < GRID_SIZE; ++r)
    {
        for (int c = 0; c < GRID_SIZE; ++c)
        {
            grid[r][c] = {' ', PREDEFINED_WEIGHTS[r][c]};
        }
    }

    // Manually set the start ('S') and end ('E') positions
    grid[0][0].type = 'S'; // Start at top-left corner
    grid[0][0].weight = 1;
    grid[6][6].type = 'E'; // End at bottom-right corner
    grid[6][6].weight = 1;

    // Start timing
    std::clock_t start_time = std::clock();

    // Find the shortest path using Dijkstra's algorithm
    auto [path, total_weight] = dijkstra(grid);

    // End timing
    std::clock_t end_time = std::clock();

    // Calculate the execution time in seconds
    double duration = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;

    // Display the results
    if (!path.empty())
    {
        cout << "Shortest Path: " << path << endl;
        cout << "Total Weight: " << total_weight << endl;
    }
    else
    {
        cout << "No path found." << endl;
    }

    // Display the execution time
    cout << "Execution Time: " << duration << " seconds" << endl;

    return 0;
}
