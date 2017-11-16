class Solution
{
public:
    int index;
    int occurence[256];
    Solution() : index(0){	//���ù��캯����ʼ��index��occurence
        for (int i = 0; i < 256; ++i)
            occurence[i] = -1;
    }
  //Insert one char from stringstream
    void Insert(char ch)
    {
        if (occurence[ch] == -1)	//���֮ǰû�г��ֹ�
             occurence[ch] = index;
        else if (occurence[ch] >= 0)	//���ֹ���ε���Ϊ-2
            occurence[ch] = -2;
        index++;	//�仯index��Ϊ��ȷ���ĸ��ǵ�һ��
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        char ch = '#';
        int minIndex = INT_MAX;
        for (int i = 0; i < 256; ++i){
            if (occurence[i] >= 0 && occurence[i] < minIndex){		//�ҵ�index��С�ģ���Ϊ��һ��
                ch = (char)(i);
                minIndex = occurence[i];
            }
        }
        return ch;
    }
};
