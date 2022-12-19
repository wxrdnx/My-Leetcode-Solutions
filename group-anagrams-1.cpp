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

// Time: O(nk log(k))
// Space: O(nk)
