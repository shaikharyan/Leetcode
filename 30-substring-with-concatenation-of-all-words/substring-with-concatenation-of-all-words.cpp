class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
      vector<int> result;

        if (s.empty() || words.empty()) {
            return result;
        }

        int wordSize = words[0].size();
        int totalWords = words.size();
        int totalLength = wordSize * totalWords;

        unordered_map<string, int> wordCount;
        for (const string& word : words) {
            wordCount[word]++;
        }

        for (int i = 0; i < wordSize; ++i) {
            int left = i, right = i, wordsSeen = 0;
            unordered_map<string, int> seenWords;

            while (right + wordSize <= s.size()) {
                string currentWord = s.substr(right, wordSize);
                right += wordSize;

                if (wordCount.find(currentWord) == wordCount.end()) {
                    seenWords.clear();
                    wordsSeen = 0;
                    left = right;
                } else {
                    seenWords[currentWord]++;
                    wordsSeen++;

                    while (seenWords[currentWord] > wordCount[currentWord]) {
                        string leftWord = s.substr(left, wordSize);
                        seenWords[leftWord]--;
                        wordsSeen--;
                        left += wordSize;
                    }

                    if (wordsSeen == totalWords) {
                        result.push_back(left);
                    }
                }
            }
        }

        return result;
    }
    
};