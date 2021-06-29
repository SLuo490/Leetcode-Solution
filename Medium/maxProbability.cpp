class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int src, int dst) {
        //initialize
        vector<double> dis(n,0); //since it is find the maximum path, we initialize all node to 0 and src to 1.0
        dis[src] = 1.0;
        
        //use a priority queue for dijkstra's algorithm
        priority_queue<pair<int,double>> pq;
        
        //build the graph using edge list
        vector<vector<pair<int,double>>> graph(n); //n = size of graph
        const int m = edges.size();
        
        for (int i = 0; i < m; i++) {
            auto u = edges[i][0];
            auto v = edges[i][1];
            auto prob = succProb[i];
            graph[u].emplace_back(v,prob);
            graph[v].emplace_back(u,prob);
        }
        
        //dijkstra's algorithm
        //enqueue srcs with prob of 1.0 to graph
        pq.emplace(src,1.0);
        while (!pq.empty()) {
            auto [node,prob] = pq.top();
            pq.pop();
            
            if (prob < dis[node]) continue;
            
            //traverse the the graph[u]
            for (auto &[v, thisProb]: graph[node]) {
                double newProb = prob * thisProb;
                if (newProb > dis[v]) {
                    dis[v] = newProb;
                    pq.emplace(v, newProb);
                }
            }    
        }
        return dis[dst];
    }
};
