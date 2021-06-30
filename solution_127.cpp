#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution{
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList){
        int size = wordList.size();
        int begin_i = -1;
        int end_i = -1;
        int w_size = beginWord.size();
        bool relation[size][size];
        for(int i = 0; i < size; ++i){
            if(begin_i == -1 && wordList[i] == beginWord){
                begin_i = i;
            }
            if(end_i == -1 && wordList[i] == endWord){
                end_i = i;
            }
            if(begin_i != -1 && end_i != -1){
                break;
            }
        }
        if (end_i == -1){
            return 0;
        }
        if (begin_i == -1){
            wordList.push_back(beginWord);
            begin_i = wordList.size() - 1;
            ++size;
        }


        for(int i = 0; i < size; ++i){
            for(int j = 0; j < size; ++j){
                int diff = 0;
                for(int k = 0; k < w_size; ++k){
                    if(wordList[i][k] != wordList[j][k]){
                        ++diff;
                        if (diff > 1){
                            break;
                        }
                    }
                }
                relation[i][j] = diff == 1;
            }
        }

        unordered_set<int> history{begin_i};
        unordered_set<int> next_node{begin_i};
        unordered_set<int> new_next_node{};
        int m_step = 0;
        while(true){
            ++m_step;
            new_next_node.clear();
            for(auto& i : next_node){
                if(i == end_i){
                    return m_step;
                }
                for(int j = 0; j < size; j++){
                    if(relation[i][j] && history.find(j) == history.end()){
                        new_next_node.insert(j);
                        history.insert(j);
                    }
                }
            }
            if (new_next_node.size() == 0){
                return 0;
            }
            next_node.swap(new_next_node);
        }
    }
};

int main(int argc, char const *argv[])
{
    string beginWord = "hit";
    string endWord = "cog";
    vector<string>  wordList{"hot","dot","dog","lot","log", "cog"};
    int step = Solution().ladderLength(beginWord, endWord, wordList);
    cout << step << endl;
    return 0;

}