class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
		int length = sequence.size();
        if (length == 0)
            return false;

        return result(sequence, 0, length - 1);
    }

private:
    bool result(vector<int> sequence, int start, int end){
        if (start >= end)
            return true;	//�ݹ��������

        int root = sequence[end];
        int i = start;
        while (sequence[i] < root){
            ++i;
        }

        //�ж�������
        int j = i;
        while (j < end){
            if (sequence[j] < root){
                return false;
            }
            ++j;
        }

        return result(sequence, start, i-1) && result(sequence, i, end-1);
    }
};
