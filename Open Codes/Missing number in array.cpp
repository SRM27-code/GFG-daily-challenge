class Solution{
  public:
    int missingNumber(vector<int>& array, int n) {
        // Your code goes here
        int res = 0;
        for(int i=1; i<=n; i++) res ^= i;
        for(int i=0; i<n-1; i++) res ^= array[i];
        return res;
    }
};