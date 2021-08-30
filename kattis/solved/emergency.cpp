#include <bits/stdc++.h>
using namespace std;
//Credit to geeksforgeeks.org for the original implementations of the graph.
# define INF 0x3f3f3f3f 

//Typedefs
typedef pair<unsigned long long, unsigned long long> pif;

//Directed graph w/ adj list representation
class Graph {
    private:
        //no. of vertices
        unsigned long long V;
        //adj list
        list<pif> *adj;
    public: 
        //constructor
        Graph(unsigned long long V);
        // function to add an edge to graph 
        void addEdge(unsigned long long u, unsigned long long v, unsigned long long w); 
        // finds shortest path from s and saves it in dist
        void shortestPath(unsigned long long s); 
        vector<unsigned long long> dist;

}; 
  
// Allocates memory for adjacency list 
Graph::Graph(unsigned long long V) 
{ 
    this -> V = V; 
    adj = new list<pif> [V]; 
    dist.assign(V,INF);
} 

void Graph::addEdge(unsigned long long u, unsigned long long v, unsigned long long w) 
{ 
    adj[u].push_back(make_pair(v, w)); 
    adj[u].push_back(make_pair(w, v)); 
} 
  
// Prunsigned long longs shortest paths from src to all other vertices 
void Graph::shortestPath(unsigned long long src) 
{ 
    // Create a priority queue to store vertices that 
    // are being preprocessed. This is weird syntax in C++. 
    // Refer below link for details of this syntax 
    // https://www.geeksforgeeks.org/implement-min-heap-using-stl/ 
    priority_queue<pif, vector <pif> , greater<pif>> pq; 

    // Insert source itself in priority queue and initialize 
    // its distance as 0. 
    pq.push(make_pair(unsigned long long(0), src)); 
    dist[src] = unsigned long long(0); 

    /* Looping till priority queue becomes empty (or all 
      distances are not finalized) */
    while (!pq.empty()) 
    { 
        // The first vertex in pair is the minimum distance 
        // vertex, extract it from priority queue. 
        // vertex label is stored in second of pair (it 
        // has to be done this way to keep the vertices 
        // sorted distance (distance must be first item 
        // in pair) 
        unsigned long long u = pq.top().second; 
        pq.pop(); 
  
        // 'i' is used to get all adjacent vertices of a vertex 
        list<pif>::iterator i; 
        for (i = adj[u].begin(); i != adj[u].end(); ++i) 
        { 
            // Get vertex label and weight of current adjacent 
            // of u. 
            unsigned long long v = (*i).first; 
            unsigned long long weight = (*i).second; 
  
            //  If there is shorted path to v through u. 
            if (dist[v] > dist[u] + weight) 
            { 
                // Updating distance of v 
                dist[v] = dist[u] + weight; 
                pq.push(make_pair(dist[v], v)); 
            } 
        } 
    } 
  
    /* Prunsigned long long shortest distances stored in dist[] 
    prunsigned long longf("Vertex   Distance from Source\n"); 
    for (unsigned long long i = 0; i < V; ++i) 
        prunsigned long longf("%d \t\t %d\n", i, dist[i]);
    */
} 

unsigned long long main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    unsigned long long n, k;
    cin >> n >> k;
    Graph forest;
    for(unsigned long long i=0; i<n-1; i++){
        forest.addEdge(i,i+1,1);
    }
    for(unsigned long long i = k; i<n-1-k;){
        for(unsigned long long j = i; j<n-1-k;){
            forest.addEdge(i,i+k,1);
            j+=k;
        }
        i+=k;
    }
    return 0;
}