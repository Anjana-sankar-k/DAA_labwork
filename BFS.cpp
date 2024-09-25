#include <iostream>
#include <queue>

using namespace std;

class Graph {
    int V; // Number of vertices
    int** adj; // Pointer to a 2D array containing adjacency lists
public:
    Graph(int V); // Constructor
    ~Graph(); // Destructor
    void addEdge(int v, int w); // Function to add an edge to graph
    void BFS(int s); // Function to perform BFS traversal from a given source s
};

Graph::Graph(int V) {
    this->V = V;
    adj = new int*[V];
    for(int i = 0; i < V; ++i) {
        adj[i] = new int[V](); // Initialize all adjacency lists as empty
    }
}

Graph::~Graph() {
    for(int i = 0; i < V; ++i) {
        delete[] adj[i];
    }
    delete[] adj;
}

void Graph::addEdge(int v, int w) {
    adj[v][w] = 1; // Add w to v’s list by setting the value to 1
}

void Graph::BFS(int s) {
    bool* visited = new bool[V]; // Create an array to keep track of visited nodes
    for(int i = 0; i < V; ++i) {
        visited[i] = false;
    }

    queue<int> queue; // Create a queue for BFS

    visited[s] = true; // Mark the current node as visited and enqueue it
    queue.push(s);

    while(!queue.empty()) {
        s = queue.front();
        cout << s << " "; // Print the current node
        queue.pop();

        // Get all adjacent vertices of the dequeued vertex s
        // If an adjacent has not been visited, then mark it visited and enqueue it
        for(int i = 0; i < V; ++i) {
            if(adj[s][i] && !visited[i]) {
                visited[i] = true;
                queue.push(i);
            }
        }
    }

    delete[] visited; // Free the dynamically allocated memory
}

int main() {
    int n;
    cout<<"Enter no. of vertices : \n";
    cin>>n;

    Graph g(n);
    g.addEdge(0,1);
    

    int s;
    cout<<"Enter starting vertex: \n";
    cin>>s;
    cout<<"Breadth First Traversal:\n";
    g.BFS(s);

    return 0;
}
