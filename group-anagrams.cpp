class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagrams;
        vector<vector<string>> result;
        for (auto &str : strs) {
            string sorted{str};
            sort(sorted.begin(), sorted.end());
            anagrams[sorted].push_back(str);
        }
        for (auto &[_, anagram] : anagrams) {
            result.push_back(anagram);
        }
        return result;
    }
};

// Time: O(nklog(k))
// Space: O(nk)

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagrams;
        vector<vector<string>> result;
        vector<int> count(256);
        for (auto &str : strs) {
            fill(count.begin(), count.end(), 0);
            for (auto &c : str) {
                count[c]++;
            }
            string count_str;
            for (auto c = 'a'; c <= 'z'; c++) {
                if (count[c] > 0) {
                    count_str += c;
                    count_str += to_string(count[c]);
                }
            }
            anagrams[count_str].push_back(str);
        }
        for (auto &[_, anagram] : anagrams) {
            result.push_back(anagram);
        }
        return result;
    }
};

// Time: O(nk)
// Space: O(nk)
