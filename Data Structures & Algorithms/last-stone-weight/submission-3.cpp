class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        priority_queue<int>stone_weights;
        
        for(int i=0;i<stones.size();i++) stone_weights.push(stones[i]);
        while(stone_weights.size()>1){
            int x=stone_weights.top();
            stone_weights.pop();
            int y=stone_weights.top();
            stone_weights.pop();
            cout<<"x-->"<<x<<"   y-->"<<y<<"   x-y--->"<<x-y<<endl;
            if(x-y==0) continue;
            stone_weights.push(x-y);

        }

        if(stone_weights.size()==0) return 0;
        else return stone_weights.top();

    }
};
