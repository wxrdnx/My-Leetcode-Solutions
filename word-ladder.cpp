class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> q;
        unordered_set<string> words(wordList.begin(), wordList.end());
        q.push(beginWord);
        int length = 2;
        while (q.size()) {
            int qsize = q.size();
            while (qsize--) {
                string curr = q.front();
                q.pop();
                for (int i = 0; i < curr.length(); i++) {
                    char tmp = curr[i];
                    for (char c = 'a'; c <= 'z'; c++) {
                        curr[i] = c;
                        if (words.find(curr) != words.end()) {
                            if (curr == endWord) {
                                return length;
                            }
                            q.push(curr);
                            words.erase(curr);
                        }
                    }
                    curr[i] = tmp;
                }
            }
            length++;
        }
        return 0;
    }
};

// Time: O(m^2 * n), m = word length, n = word list length
// Space: O(m * n)
