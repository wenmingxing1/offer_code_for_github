class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {

        int local_max = array[0];
        int global_max = array[0];
        for (int i = 1; i < array.size(); ++i){
            local_max = local_max + array[i];
            local_max = max(local_max, array[i]);
            global_max = max(local_max, global_max);
        }
        return global_max;
    }
};
