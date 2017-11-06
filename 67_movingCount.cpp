#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int movingCount(int threshold, int rows, int cols)
    {
        bool* visited = new bool[rows*cols];
        for (int i = 0; i < rows*cols; ++i){
            visited[i] = false;
        }
        if (rows <= 0 || cols <= 0 || threshold <= 0)
            return 0;
        int count = movingCountCore(threshold, rows, cols, 0, 0, visited);
        delete[] visited;
        return count;
    }
private:
    int movingCountCore(int threshold, int rows, int cols, int row, int col, bool* visited){
        int count = 0;
        if (check(threshold, rows, cols, row, col, visited)){
            visited[row*cols+col]=true;
            count = 1+movingCountCore(threshold, rows, cols, row-1, col, visited)
                + movingCountCore(threshold, rows, cols, row, col-1, visited)
                + movingCountCore(threshold, rows, cols, row+1, col, visited)
                + movingCountCore(threshold, rows, cols, row, col+1, visited);
        }
        return count;
    }

    //得到一个数的各个位之和
    int getDisigitSum(int num){
        int sum = 0;
        while (num > 0){
            sum += num%10;
            num /=10;
        }
        return sum;
    }

    //判断是否满足条件
    bool check(int threshold, int rows, int cols, int row, int col, bool* visited){
        bool res = false;
        if (row >= 0 && row < rows && col >= 0 && col < cols
            && (getDisigitSum(row)+getDisigitSum(col) <= threshold)
            && !visited[row*cols+col])
            res = true;
        return res;
    }
};

int main()
{
    Solution solu;
    cout << solu.movingCount(5,3,3) << endl;

    return 0;
}
