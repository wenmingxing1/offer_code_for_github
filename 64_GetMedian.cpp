class Solution {
public:
    //保证最大堆的数都比最小堆中的数小
    void Insert(int num)
    {
        if (((min.size() + max.size()) & 1) == 0){		//为第偶数，放入最小堆
            if (max.size() > 0 && num < max[0]){	//如果数比最大堆的最大数小,以下操作的目的都是为了平衡两个堆，并保证两个堆的大小关系
                max.push_back(num);		//先放入最大堆
                push_heap(max.begin(), max.end(), less<int>());	//调整最大堆

                num = max[0];	//取出最大堆中的最大数，之后放入最小堆

                pop_heap(max.begin(), max.end(), less<int>());	//弹出最大堆的最大值
                max.pop_back();		//在容器中删除
            }
            min.push_back(num);		//比最大堆中的最大数还大，则直接压入最小堆
            push_heap(min.begin(), min.end(), greater<int>());		//调整最小堆
        }
        else{		//为第奇个数，放入最大堆
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
        if ((size&1) == 1)	//如果为奇数，因为如果是奇数则最小堆中的元素个数比最大堆多一个
            median = min[0];	//直接返回最小堆中的最小值
        else		//如果为偶数
            median = ((double)min[0] + max[0]) / 2;		//先把其中一个int强制转化为double，才能保证除法得到double

        return median;
    }

private:
    vector<int> min;
    vector<int> max;

};
