#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string ReverseSentence(string& str) {
        int length = str.size() - 1;
        Reverse(str, 0, length);

        int start = 0;
        int end = 0;
        while (str[start] != '\0'){
            if (str[end] == ' ' || str[end] == '\0'){
                Reverse(str, start, end-1);
                start = end + 1;
                end++;
            }
            else
                end++;
        }
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
    string str = "I am a good student";
    cout << str << endl;
    Solution solu;
    solu.ReverseSentence(str);
    cout << str << endl;

    return 0;
}
