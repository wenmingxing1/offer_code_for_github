#include<iostream>
#include<string>
#include<map>
#include<vector>

using namespace std;

/*=============用map构造hash=================*/
class Solution
{
public:
    int FirstNotRepeatingChar(string str)
    {
        map<char, int> hashtable;
        for (int i = 0; i < str.size(); ++i)
        {
            hashtable[str[i]]++;
        }
        for (int i = 0; i < str.size(); ++i)
        {
            if (hashtable[str[i]] == 1)
                return i;
        }
        return -1;
    }
};

/*======================用vector构造hash=======================*/
class Solution2
{
public:
    int FirstNotRepeatingChar(string str)
    {
        vector<int> hashtable(256, 0);
        for (int i = 0; i < str.size(); ++i)
        {
            hashtable[str[i]]++;
        }
        for (int i = 0; i < str.size(); ++i)
        {
            if (hashtable[str[i]] == 1)
                return i;
        }

        return -1;
    }
};

int main()
{
    string str1 = "aabaccdeff";
    string str2 = "aaaaaaabffabccdlllz";
    Solution solu1;
    Solution2 solu2;
    cout << solu1.FirstNotRepeatingChar(str1) << endl;

    cout << solu2.FirstNotRepeatingChar(str2) << endl;

    return 0;
}
