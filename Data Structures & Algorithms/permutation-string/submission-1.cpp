class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s2.size()<s1.size()) return false;
        unordered_map<char,int> count1;
        unordered_map<char,int> count2;
        for (char c : s1){
            count1[c]++;
        }
        for (int i=0;i<s1.size();i++){
            count2[s2[i]]++;
        }
        int i=0;
        int j=s1.size()-1;
        for (auto &[k,v]:count1){
            cout <<k<<' '<<v<<endl;
        }
        cout <<"------------------ that was s1"<<endl;
        while (j<s2.size()){
            cout << i<<' '<<j<<endl;
            for (auto &[k,v]:count2){
                cout <<k<<' '<<v<<endl;
            }
            cout <<"------------------ that was count2"<<endl;
            if (count1==count2) return true;
            count2[s2[i]]--;
            if (count2[s2[i]]==0) count2.erase(s2[i]);
            i++;
            j++;
            count2[s2[j]]++;

        }
        return false;
    }
};
