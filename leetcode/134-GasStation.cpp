class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int surplus = 0, total_surplus = 0, start = 0;
        for (int i = 0; i < gas.size(); ++i){
            total_surplus += gas[i] - cost[i];
            surplus += gas[i] - cost[i];
            if (surplus < 0){
                surplus = 0;
                start = i + 1;
            }
        }
        return total_surplus < 0 ? -1: start;
    }
};