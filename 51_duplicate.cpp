#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    //暴力解法
    bool duplicate(vector<int> numbers, int length, int* duplication) {
        if (length <= 0)
            return false;

        bool found = false;
        for (int i = 0; i < length; ++i){
            for (int j = i + 1; j < length; ++j){
                if (numbers[i] == numbers[j]){
                    *duplication = numbers[i];
                    found = true;
                    break;
                }
                if (found == true)
                    break;
            }
        }
        return found;
    }

    //答案解法
        bool duplicate2(vector<int> numbers, int length, int* duplication) {
        if (length <= 0)
            return false;
        for (int i = 0; i < length; ++i){
            if (numbers[i] > length -1 || numbers[i] < 0)
                return false;
        }

        for (int i = 0; i < length; ++i){
            while (numbers[i] != i){
                if (numbers[i] == numbers[numbers[i]]){
                    *duplication = numbers[i];
                    return true;
                }
                Swap(&numbers[i],&numbers[numbers[i]]);
            }
        }
        return false;
    }
    //还可以利用hash，先排序等解法。
private:
    void Swap (int* i, int* j)
    {
        int temp = *i;
        *i = *j;
        *j = temp;
    }

};

int main()
{
    vector<int> numbers = {2,3,1,0,2,5,3};
    Solution solu;
    int duplication1 = 0;
    int duplication2 = 0;

    bool result1 = solu.duplicate(numbers, numbers.size(), &duplication1);
    bool result2 = solu.duplicate2(numbers, numbers.size(), &duplication2);

    cout << result1 << " " << duplication1 << endl;
    cout << result2 << " " << duplication2 << endl;

    return 0;

}
