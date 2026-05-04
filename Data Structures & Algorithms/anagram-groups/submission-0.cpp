class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<unordered_map<char,int>> L;
        for (string s:strs){
            unordered_map<char,int> u;
            for (char c:s){
                if (u.contains(c)) u[c]+=1;
                else u[c]=1;
            }
            L.push_back(u);
        }
        vector<int> indices;
        
        vector<vector<string>> ans;
        while (L.size()>0){
            indices={0};
            vector<string> ans1;
            int i=0;
            for (i=1;i<L.size();i++){
                if (L[i]==L[0]) indices.push_back(i);
            }
            for (int j=0;j<indices.size();j++){
                ans1.push_back(strs[indices[j]-j]);
                L.erase(L.begin()+indices[j]-j);
                strs.erase(strs.begin()+indices[j]-j);

            }
            ans.push_back(ans1);
        }
        return ans;
    }
};
