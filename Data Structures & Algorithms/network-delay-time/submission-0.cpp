class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
       vector<vector<pair<int,int>>>adj(n+1);

       for(int i=0;i<times.size();i++){
                adj[times[i][0]].push_back({times[i][2],times[i][1]});
       }
        int INF=INT_MAX;
        vector<int>time(n+1,INF);
        time[k]=0;
        time[0] = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        pq.push({time[k],k});

        while(pq.size()){
                int current_time =pq.top().first;
                int u=pq.top().second;
                pq.pop();
                if(current_time>time[u]) continue;

                for(auto neighbour:adj[u]){
                    int v=neighbour.second;
                    int weight=neighbour.first;
                    if(weight+time[u]<time[v]){
                        time[v]=weight+time[u];
                        pq.push({time[v],v});
                    }
                }
        }
       
        for(int i=1;i<=n;i++) if(time[i]==INF) return -1;
        return *max_element(time.begin(),time.end());
        
        

       

    }
};
