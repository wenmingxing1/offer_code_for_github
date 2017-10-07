class Solution {
public:
    vector<string> result;
    vector<string> Permutation(string str) {
        if (str.empty())
            return result;
        PermutationRecursion(str, 0);

        sort(result.begin(), result.end()); //�ֵ�������
        return result;
    }

private:
    bool HasDuplicate(string str, int left, int right) {   //���������Ҫ���������֮���е��ں����ֵ�Ͳ�������֤��֮ǰ�Ѿ���������
        for (int i = left; i < right; ++i){
            if (str[i] == str[right])	//���ظ�Ԫ��
                return true;
        }
        return false;
    }

    void PermutationRecursion(string str, int begin){
        if (str[begin] == '\0'){	//�ݹ��������
            result.push_back(str);
        }
        else{
            for (int i = begin; str[i] != '\0'; i++){
                if (!HasDuplicate(str, begin, i)){		//���ظ�Ԫ��
                    swap(str[i], str[begin]);
                    PermutationRecursion(str, begin+1);
                    swap(str[i], str[begin]);
                }
            }
        }
    }

};
