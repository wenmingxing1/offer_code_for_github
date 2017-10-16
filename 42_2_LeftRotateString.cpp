#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    string LeftRotateString(string &str, int n) {
        if (n > str.size())
            return str;

        Reverse(str, 0, str.size() - 1);

        Reverse(str, 0, str.size() - n - 1);

        Reverse(str, str.size() - n, str.size() - 1);

        return str;

    }
private:
    string Reverse(string& str, int start, int end){
        while (start < end){
            char temp = str[start];
            str[start] = str[end];
            str[end] = temp;
            start++;
            end--;
        }
        return str;
    }
};

int main()
{
    string str = "abcXYZdef";
    Solution solu;
    solu.LeftRotateString(str, 9);

    cout << str << endl;

    return 0;
}
