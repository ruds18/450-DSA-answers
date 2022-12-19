class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
      queue<pair<string, int>>q;
      q.push({startWord, 1});
      unordered_set<string>st(wordList.begin(), wordList.end());
      st.erase(startWord);
      
      while(!q.empty()){
          string word = q.front().first;
          int steps = q.front().second;
          q.pop();
          if(word == targetWord) return steps;
          for(int i=0; i<word.length();i++){
              char letter = word[i];
              for(char j= 'a' ;j<='z'; j++ ){
                  word[i] = j;
                  // It EXISTS
                  if(st.find(word) != st.end()){
                      q.push({word, steps+1});
                      st.erase(word);
                  }
              }
              word[i] = letter;
          }
      }
      return 0;
    }
};