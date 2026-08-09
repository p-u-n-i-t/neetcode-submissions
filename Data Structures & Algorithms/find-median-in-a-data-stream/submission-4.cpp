class MedianFinder {
    private:
    priority_queue<double,vector<double>,greater<double>>greater_half;
    priority_queue<double>smaller_half;
    int total_size;
public:
    MedianFinder() {
        total_size=0;
    }
    
    void addNum(int num) {
       greater_half.push(num);
       total_size++;
       if(smaller_half.size()>0&&greater_half.top()<smaller_half.top()){
        int x=smaller_half.top(); int y=greater_half.top();
          greater_half.pop();
          smaller_half.pop();

          greater_half.push(x);
          smaller_half.push(y);
       }
       if(greater_half.size()>total_size/2){
         int x=greater_half.top();
         greater_half.pop();
         smaller_half.push(x);
       }
    }
    
    double findMedian() {
       
        if(total_size%2==0)
          
            return (greater_half.top()+smaller_half.top())/2;
        
        else    
            return smaller_half.top();
            
    }
};
