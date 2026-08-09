class TimeMap {
    private: 
    unordered_map<string, vector<pair<int, string>>> store;
public:
      
    
    TimeMap() {
      
    }
    
    void set(string key, string value, int timestamp) {
        store[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        int left=0;
        int right=store[key].size()-1;
        while(left<=right){
            int middle=left+(right-left)/2;

            if(store[key][middle].first>timestamp) right=middle-1;
            else if(store[key][middle].first==timestamp) return store[key][middle].second;
            else left=middle+1;
        }
        if (right < 0) {
            return "";
        }

        return store[key][right].second;
    }
};
