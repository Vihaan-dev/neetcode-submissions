class Solution {
public:
    vector<string> onestar(string s){
        vector<string> ans;
        for (int i=0;i<s.size();i++){
            char c = s[i];
            s[i]='*';
            ans.push_back(s);
            s[i]=c;
        }
        return ans;
    }
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
         unordered_map<string,unordered_set<string>> dict;
         unordered_map<string,vector<string>> parentdict;
         parentdict[beginWord]=onestar(beginWord);
         parentdict[endWord]=onestar(endWord);
         for (string word:wordList){
            vector<string> parents = onestar(word);
            parentdict[word]=parents;
            for (string parent:parents){
                dict[parent].insert(word);
            }
         }
         queue<string> todo;
        unordered_set<string> visited;
        vector<string> endparentsvect = onestar(endWord);
        unordered_set<string> endparents(endparentsvect.begin(),endparentsvect.end());
        visited.insert(beginWord);
        todo.push(beginWord);
        int c=1;
        while (!todo.empty()){
            int s = todo.size();
            for (int i=0;i<s;i++){
                string word = todo.front();
                todo.pop();
                bool flag=false;
                for (string parent:parentdict[word]){
                    for (string next:dict[parent]){

                        if (!visited.contains(next)){
                            flag=true;
                            visited.insert(next);
                            todo.push(next);
                            if (next==endWord) return c+1;
                        } 
                    }
                }
            }
            c++;
        }return 0;


    }
};
