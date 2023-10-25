class Solution {
public:
    int maxProduct(vector<int>& ar) {
         int n = ar.size(); 
         int p1 = 1, p2 = 1, mx = INT_MIN;
   
   for(int i = 0; i < n; i++){
      p1 *= ar[i]; 
      mx = max(mx,p1);
      if(p1 == 0) p1 = 1;
      
    }

    for(int i = n-1; i >= 0; i--){
      p2 *= ar[i];
      mx = max(mx,p2);
      if(p2 == 0) p2 = 1;
      
    }
        return mx;
    }
};