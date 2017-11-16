class Solution
{
public:
    int index;
    int occurence[256];
    Solution() : index(0){	//利用构造函数初始化index和occurence
        for (int i = 0; i < 256; ++i)
            occurence[i] = -1;
    }
  //Insert one char from stringstream
    void Insert(char ch)
    {
        if (occurence[ch] == -1)	//如果之前没有出现过
             occurence[ch] = index;
        else if (occurence[ch] >= 0)	//出现过多次的设为-2
            occurence[ch] = -2;
        index++;	//变化index是为了确保哪个是第一个
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        char ch = '#';
        int minIndex = INT_MAX;
        for (int i = 0; i < 256; ++i){
            if (occurence[i] >= 0 && occurence[i] < minIndex){		//找到index最小的，即为第一个
                ch = (char)(i);
                minIndex = occurence[i];
            }
        }
        return ch;
    }
};
