class Solution {
public:
    bool dfs(unordered_map<char, unordered_set<char>>& graph, unordered_map<char,bool> & visited,stringstream& s, char c ){
        if (visited.contains(c)) return !visited[c];
        visited[c]=true;
        
        for (char next: graph[c]){
            if (!dfs(graph,visited,s,next)) return false;
        }
        visited[c]=false;
        s<<c;
        return true;
    }
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, unordered_set<char>> graph;
        unordered_map<char,bool> visited;
        unordered_set<char> chars;
        for (auto word:words){
            for (char c: word) chars.insert(c);
        }
        for (int i=0;i<words.size()-1;i++){
            string word1=words[i];
            string word2 = words[i+1];
            int minlen= min(word1.size(),word2.size());
            if (string_view(word1).substr(0,minlen)==string_view(word2).substr(0,minlen)&&word2.size()<word1.size()){
                return "";
            }
            for (int i=0;i<minlen;i++){
                if (word1[i]!=word2[i]){
                    graph[word1[i]].insert(word2[i]);
                    break;
                }
            }
            
            
        }
        for (auto &[k,v]:graph){
            cout << k<<":";
            for (auto val:v) cout<<val<<" ";
            cout <<endl;
        }
        //Now graph is ready
        stringstream s;
        //for (auto &[c,v]:graph){
        for (char c : chars){
            cout <<"ADDING" <<c<<endl;
            if (!visited.contains(c)){
                if (!dfs(graph,visited,s,c)) return "";
            }
        }
        string ss = s.str();
        reverse(ss.begin(),ss.end());
        return ss;


    }
};
