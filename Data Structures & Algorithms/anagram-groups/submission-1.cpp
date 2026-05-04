class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // A map where the Key is the sorted string, and Value is the group of anagrams
        unordered_map<string, vector<string>> groups;
        
        for (string s : strs) {
            string key = s;
            sort(key.begin(), key.end()); // Anagrams will have the same sorted string
            groups[key].push_back(s);     // O(1) average lookup and push
        }
        
        vector<vector<string>> result;
        for (auto& pair : groups) {
            result.push_back(pair.second); // Move the groups into the final answer
        }
        
        return result;
    }
};
