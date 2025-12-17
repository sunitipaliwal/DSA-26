class MyCalendarTwo {
public:
   map<int,int>mpp;
    MyCalendarTwo() {
        
    }
    
    bool book(int startTime, int endTime) {
        mpp[startTime]++;
        mpp[endTime]--;
            int b=0;
        for(auto &it : mpp){
           b+=it.second;

           if(b>=3){
            mpp[startTime]--;
            mpp[endTime]++;
            if(mpp[startTime]==0) mpp.erase(startTime);
            if(mpp[endTime]==0) mpp.erase(endTime);
            return false;
           }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */