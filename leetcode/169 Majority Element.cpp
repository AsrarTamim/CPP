class Solution {
public:
    int majorityElement(vector<int>& ar) {
        int cnt = 0;
        int ele = 0;
        
        for(int num : ar){
            if(cnt == 0) ele = num;

            if(num == ele) cnt++;
            else cnt--;
        }   
        return ele;
    }
};