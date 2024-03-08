#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool sameFreq(string s) {
        unordered_map<char, int> freq;

        // Count frequency of each character
        for (char ch : s) {
            freq[ch]++;
        }

        // Find distinct frequencies
        unordered_map<int, int> distinct_freq;
        for (auto& entry : freq) {
            distinct_freq[entry.second]++;
        }

        if (distinct_freq.size() == 1) {
            return true;
        } else if (distinct_freq.size() == 2) {
            // If one frequency occurs only once, return true
            if (distinct_freq.count(1) == 1 && distinct_freq[1] == 1) {
                return true;
            } else {
                int max_freq = max_element(distinct_freq.begin(), distinct_freq.end())->first;
                int min_freq = min_element(distinct_freq.begin(), distinct_freq.end())->first;

                if ((distinct_freq[max_freq] == 1 && max_freq - min_freq == 1) ||
                    (distinct_freq[min_freq] == 1 && min_freq == 1)) {
                    return true;
                } else {
                    return false;
                }
            }
        } else {
            return false;
        }
    }
};
