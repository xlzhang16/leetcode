class Solution {
public:
    int myAtoi(string str) {
        int idx = 0;
        while(idx < str.length()){
            if(str[idx] != ' ')
                break;
            idx++;
        }
        int sign = 1;
        if(str[idx] == '-'){
            sign = -1;
            idx++;
        }
        else if(str[idx] == '+')
            idx++;
        else if(str[idx] > '9' || str[idx] < '0')
            return 0;
        int ans = 0;
        while(idx < str.length() && str[idx] >= '0' && str[idx] <= '9'){
            int digit = sign * (str[idx] - '0');
            if(ans * 10 / 10 == ans){
                ans = ans * 10 + digit;
                if(ans > 0 && sign < 0)
                    return INT_MIN;
                else if(ans < 0 && sign > 0)
                    return  INT_MAX;
            }
            else if(sign > 0)
                return INT_MAX;
            else return INT_MIN;
            idx++;
        }
        return ans;
    }
};
