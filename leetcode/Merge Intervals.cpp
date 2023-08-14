// makring e array with start point 
// chck the array if start point exist then take the max end
//if no start point exist then chck the point is not end or not
// if end then take the Interval



class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& a) {
        
        int n = a.size();
        int N = 1e4+5;
        int ar[N];
        memset(ar, 0, sizeof ar);
        map<int,int>mp;
        vector<vector<int>>ans;
        int start = -1, end = -1;
        int ok = -1;
        for(int i = 0; i < n; i++){ 
            // marking the start position 
            ar[a[i][0]] = 1;
            // if there is same start position then take the max end
            // map key is the start and value will be the end point
            mp[a[i][0]] = max(mp[a[i][0]], a[i][1]); 
        }
        
        for(int i = 0; i < N; i++){

            if(ar[i]){
                // no start and end value
                if(ok == -1){
                    start = i;
                    end = mp[i];
                    ok = 1;
                }
                else{
                    // take the max end
                    end = max(end,mp[i]);
                }
            }
             if(start == -1 and end == -1) continue;
             if(i == end){

                ans.push_back({start,end});
                start = end = ok = -1;

            }
        }
        return ans;
    }
};