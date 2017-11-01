class Solution {
public:
    //��֤���ѵ���������С���е���С
    void Insert(int num)
    {
        if (((min.size() + max.size()) & 1) == 0){		//Ϊ��ż����������С��
            if (max.size() > 0 && num < max[0]){	//����������ѵ������С,���²�����Ŀ�Ķ���Ϊ��ƽ�������ѣ�����֤�����ѵĴ�С��ϵ
                max.push_back(num);		//�ȷ�������
                push_heap(max.begin(), max.end(), less<int>());	//��������

                num = max[0];	//ȡ�������е��������֮�������С��

                pop_heap(max.begin(), max.end(), less<int>());	//�������ѵ����ֵ
                max.pop_back();		//��������ɾ��
            }
            min.push_back(num);		//�������е������������ֱ��ѹ����С��
            push_heap(min.begin(), min.end(), greater<int>());		//������С��
        }
        else{		//Ϊ�����������������
            if (min.size() > 0 && min[0] < num){
                min.push_back(num);
                push_heap(min.begin(), min.end(), greater<int>());

                num = min[0];

                pop_heap(min.begin(), min.end(), greater<int>());
                min.pop_back();
            }
            max.push_back(num);
            push_heap(max.begin(), max.end(), less<int>());
        }
    }

    double GetMedian()
    {
        int size = min.size() + max.size();
        if (size == 0){
            return 0;
        }
        double median = 0;
        if ((size&1) == 1)	//���Ϊ��������Ϊ�������������С���е�Ԫ�ظ��������Ѷ�һ��
            median = min[0];	//ֱ�ӷ�����С���е���Сֵ
        else		//���Ϊż��
            median = ((double)min[0] + max[0]) / 2;		//�Ȱ�����һ��intǿ��ת��Ϊdouble�����ܱ�֤�����õ�double

        return median;
    }

private:
    vector<int> min;
    vector<int> max;

};
