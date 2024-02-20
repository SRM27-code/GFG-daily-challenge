class Solution
{
public:
    int wordBreak(int n, string s, vector<string> &dictionary) {
        //code here
        unordered_set<string> dict(dictionary.begin(), dictionary.end());
        int len = s.length();
        
        vector<bool> dp(len + 1, false);
        dp[0] = true;
        
        for (int i = 1; i <= len; ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        
        return dp[len] ? 1 : 0;
    }
};