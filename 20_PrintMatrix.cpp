#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void printMatrix(vector<vector<int> > matrix) {
        int rows = matrix.size();
        int columns = matrix[0].size();
        if (rows <= 0 && columns <= 0)
            return;

        int start = 0;
        while (rows > start * 2 && columns > start * 2){
            PrintACircle(matrix, start, rows, columns);
            start++;
        }
    }
private:
        void PrintACircle(vector<vector<int>> matrix, int start, int rows, int columns){
            int endX = rows - 1 - start;
            int endY = columns - 1 - start;

            for (int i = start; i <= endY; ++i){
                cout << matrix[start][i] << ",";
            }
            if (endX > start){
                for (int i = start + 1; i <= endX; ++i){
                    cout << matrix[i][endY] << ",";
                }
            }
            if (endX > start && endY > start){
                for (int i = endY - 1; i >= start; --i){
                    cout << matrix[endX][i] << ",";
                }
            }
            if (endX > start + 1 && endY > start){
                for (int i = endX - 1; i > start; --i){
                    cout << matrix[i][start] << ",";
                }
            }
        }
};

int main()
{
    vector<vector<int>> nums = { {1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16}};
    Solution solu;
    solu.printMatrix(nums);

    return 0;
}
