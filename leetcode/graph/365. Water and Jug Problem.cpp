class Solution {
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
         // Store the capacities of both jugs in variables x and y.
         int x = jug1Capacity, y = jug2Capacity;
         // Calculate the total capacity of both jugs.
         int z = x + y;
         // Define an array of steps representing possible operations on the jugs.
         int steps[] = {x, -x, -y, y}; 

         // Create a queue to perform a breadth-first search.
         queue<int> q;
         // Create a vector to keep track of visited states.
         vector<int> vis(z + 1, 0); 
         
         // Initialize the queue with the starting state (both jugs empty).
         q.push(0);
         // Mark the starting state as visited.
         vis[0] = 1;

         // Start the breadth-first search.
         while (!q.empty()) {
            // Get the current state from the front of the queue.
            int node = q.front();
            q.pop();
            
            // Check if the current state matches the target capacity.
            if (node == targetCapacity) {
                return true; // If yes, we can measure the target capacity, so return true.
            }

            // Try all possible operations on the jugs.
            for (int i = 0; i < 4; i++) {
                int newNode = node + steps[i]; // Apply the operation to calculate the new state.
                
                // Check if the new state is within bounds and has not been visited before.
                if (newNode >= 0 && newNode <= z && vis[newNode] == 0) {
                    q.push(newNode); // Add the new state to the queue for further exploration.
                    vis[newNode] = 1; // Mark the new state as visited.
                }
            }
        }
        
        // If the loop completes without finding the target capacity, return false.
        return false; 
    }
};
