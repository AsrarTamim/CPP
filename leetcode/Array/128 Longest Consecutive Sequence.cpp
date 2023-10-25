class Solution {
public:
    int longestConsecutive(vector<int>& v) {
        int n = v.size();

        // Create a hash set to store all the unique numbers in the array.
        unordered_set<int> st;
        for(auto x : v){
            st.insert(x);
        }

        int ans = 0; // This variable will store the result for the longest consecutive sequence.

        // Loop through the set
        for(auto x : st){
            int val = x;

            // Check if the current number is the starting number of a sequence.
            // We do this by checking if there's no (val - 1) in the set.
            if(st.find(val - 1) == st.end()){
                int cnt = 1; // Initialize a counter to 1 as we've found a number (starting of a sequence)

                // Keep checking for the next consecutive numbers in the sequence.
                while(st.find(val + 1) != st.end()){
                    val++;
                    cnt++; // Increase the count for each consecutive number found.
                }

                // Update the answer with the maximum value.
                ans = max(ans,cnt);
            }
        }

        // Return the result
        return ans;
    }
};
