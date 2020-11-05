#include <string>
#include <unordered_set>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // 建图、广度优先搜索
		unordered_set<string> word_set(wordList.begin(), wordList.end());
		if (!word_set.count(endWord))
			return 0;
		queue<string> q{ {beginWord} };
		int res = 0;
		while (!q.empty()) {
			for (int k = q.size(); k > 0; --k) {
				string word = q.front();
				q.pop();
				if (word == endWord) {
					return res + 1;
				}
				for (int i = 0; i < word.size(); i++) {
					string new_word = word;
					for (char ch = 'a'; ch <= 'z'; ch++) {
						new_word[i] = ch;
						if (word_set.count(new_word) && new_word!= word) {
							q.push(new_word);
							word_set.erase(new_word);
						}
					}
				}
			}
			++res;
		}
		return 0;
	}
};