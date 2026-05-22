class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> pairs;
        for (int i=0;i<position.size();i++){
            pairs.push_back({position[i],speed[i]});

        }
        sort(pairs.begin(),pairs.end());
        for (int i=0;i<pairs.size();i++){
            position[i]=pairs[i].first;
            speed[i]=pairs[i].second;
        }
        for (int pos : position) cout<<pos<<' ';
        cout <<endl;
        for (int spee : speed) cout<<spee<<' ';
        cout<<endl;
        vector<bool> ans(position.size(),false);
        int count=1;
        int prevspeed=speed[speed.size()-1];
        int prevpos=position[position.size()-1];
        for (int i=position.size()-2;i>=0;i--){
            float timenext=float(target-prevpos)/(prevspeed);
            float time=float(target-position[i])/speed[i];
            if (time>timenext){
                prevspeed=speed[i];
                prevpos=position[i];
                count++;
            }
        }
        return count;
    }
};
