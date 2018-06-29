class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int max_d = 0;
        int t_d = 0;
        int last_p = -1;
        for(int i = 0; i < seats.size(); i++){
            if(seats[i] == 0){
                t_d++;
                if(last_p < 0)
                    max_d = max(max_d, t_d);
                else
                    max_d = max(max_d, (t_d + 1) / 2);
            }
            else {
                t_d = 0;
                last_p = i;
            }
        }
        return max(max_d, t_d);
    }
};
