class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;

        int n = s.size();
        int wordLen = words[0].size();
        int totalWords = words.size();
        int totalLen = wordLen * totalWords;

        if (n < totalLen) return ans;

        unordered_map<string, int> mp;

        for (string word : words) {
            mp[word]++;
        }

        // Try each possible offset
        for (int offset = 0; offset < wordLen; offset++) {

            int left = offset;
            int right = offset;
            int count = 0;

            unordered_map<string, int> window;

            while (right + wordLen <= n) {

                string word = s.substr(right, wordLen);
                right += wordLen;

                // Word is not present in words
                if (mp.find(word) == mp.end()) {
                    window.clear();
                    count = 0;
                    left = right;
                }
                else {
                    window[word]++;
                    count++;

                    // Too many occurrences of this word
                    while (window[word] > mp[word]) {
                        string leftWord = s.substr(left, wordLen);
                        window[leftWord]--;
                        left += wordLen;
                        count--;
                    }

                    // Found valid concatenation
                    if (count == totalWords) {
                        ans.push_back(left);

                        // Move window forward
                        string leftWord = s.substr(left, wordLen);
                        window[leftWord]--;
                        left += wordLen;
                        count--;
                    }
                }
            }
        }

        return ans;
    }
};