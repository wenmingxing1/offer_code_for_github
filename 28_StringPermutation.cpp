class Solution {
public:
    vector<string> result;
    vector<string> Permutation(string str) {
        if (str.empty())
            return result;
        PermutationRecursion(str, 0);

        sort(result.begin(), result.end()); //字典序排列
        return result;
    }

private:
    bool HasDuplicate(string str, int left, int right) {   //如果两个需要交换的序号之间有等于后面的值就不交换，证明之前已经交换过了
        for (int i = left; i < right; ++i){
            if (str[i] == str[right])	//有重复元素
                return true;
        }
        return false;
    }

    void PermutationRecursion(string str, int begin){
        if (str[begin] == '\0'){	//递归结束条件
            result.push_back(str);
        }
        else{
            for (int i = begin; str[i] != '\0'; i++){
                if (!HasDuplicate(str, begin, i)){		//无重复元素
                    swap(str[i], str[begin]);
                    PermutationRecursion(str, begin+1);
                    swap(str[i], str[begin]);
                }
            }
        }
    }

};
