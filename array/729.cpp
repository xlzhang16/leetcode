class MyCalendar {
    map<int, int> cal;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        if(cal.size() == 0 || cal.begin()->first >= end){
            cal[start] = end;
            return true;
        }
        
        for(auto it = cal.begin(); it != cal.end(); it++){
            if(start >= it->second){
                auto tmp = it;
                tmp++;
                if(tmp == cal.end() || end <= (tmp)->first){
                    cal[start] = end;
                    return true;
                }
            }
        }
        return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * bool param_1 = obj.book(start,end);
 */
