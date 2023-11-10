class Solution {
public:
    // This function finds an order in which courses should be taken, given their dependencies.
    // 'n' represents the total number of courses numbered from 0 to n-1.
    // 'v' is a vector of pairs, where each pair represents a prerequisite relationship; 
    // v[i] = [a, b] indicates course a must be taken before course b.
    vector<int> findOrder(int n, vector<vector<int>>& v) {
      // 'g' is an adjacency list representing the graph of courses.
      vector<int> g[n];

      // 'ans' will store the final order of courses.
      vector<int> ans;

      // 'q' is a queue used for BFS traversal.
      queue<int> q;

      // 'indeg' keeps track of the in-degree (number of prerequisites) for each course.
      vector<int> indeg(n+1, 0);

      // Building the graph and updating in-degrees of nodes.
      for(auto& x : v){
        g[x[1]].push_back(x[0]);
        indeg[x[0]]++;
      }

      // Adding courses with no prerequisites to the queue.
      for(int i = 0; i < n; i++){
        if(indeg[i] == 0){
          q.push(i);
        }
      }

      // BFS traversal of the graph.
      while(!q.empty()){
        int temp = q.front();
        q.pop();
        ans.push_back(temp);
        // Decreasing the in-degree of adjacent nodes and adding zero in-degree nodes to the queue.
        for(auto u : g[temp]){
          indeg[u]--;
          if(indeg[u] == 0){
            q.push(u);
          }
        }
      }

      // If all courses are not covered, return an empty array.
      if(ans.size() < n){
        ans.clear();
        return ans;
      }
      else {
        // Return the order of courses to be taken.
        return ans;
      }
    }
};
