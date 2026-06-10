class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<vector<int>> q; //[count,lastcalled,char(int)]
        unordered_map<int,int> counts;
        for (char c:tasks){
            counts[c]++;
        }
        for (auto [k,v]:counts){
            q.push(vector<int>({v,-n,k-'A'}));

        }
        int tot=0;
        while (!q.empty()){
            vector<int> el = q.top();
            vector<vector<int>> readd;
            while (tot-el[1]<=n ){
                readd.push_back(el);
                q.pop();
                if (!q.empty()){
                    el = q.top();
                } else break;
            }
            if (!q.empty()){
                el=q.top();
                cout <<(char)(el[2]+'A')<<' '<<tot;
                q.pop();
                el[0]--;
                el[1]=tot;
                if (el[0]>0) q.push(el);
            }
            cout <<endl;
            for (auto el:readd) q.push(el);
            tot++;
        }
        return tot-1;



    }
};
