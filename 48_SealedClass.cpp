#include<iostream>

using namespace std;

/*����һ�������캯����Ϊprivate
 * ͨ�������캯������������������Ϊ˽�к�����
 * ��һ������ͼ�̳���ʱ�����ù��캯��ʧ�ܣ�
 * �Ӷ����±������
 * �������������ͨ��new������ʵ����
 * ֻ�ܵõ����ϵ�ʵ�����޷��õ�ջ�ϵ�ʵ����
*/
class SealedClass1 {
public:
    //��Ҫͨ��static���������ͷ����ʵ��
    static SealedClass1* GetInstance() {
        return new SealedClass1();
    }
    static void DeleteInstance(SealedClass1* instance) {
        delete instance;
    }

private:
    SealedClass1() {}
    ~SealedClass1() {}
};


/*����������������̳�
 * ��T��Ϊ��Ԫ�࣬ʹ�������SealedClass2���Է���MakeSealed�Ĺ��캯��
*/
template <typename T> class MakeSealed {
    friend T;

private:
    MakeSealed() {}
    ~MakeSealed() {}
};

/*��SealedClass2��̳���MakeSealed<SealedClass2>
*/
class SealedClass2 : virtual public MakeSealed<SealedClass2> {
public:
    SealedClass2();
    ~SealedClass2();
};

/*����ͼΪSealedClass2������ʱ�������ǲ��õ���̳У�
* ����Try��ֱ�ӵ���ģ����Ĺ��캯������Try����ģ�������Ԫ��
* �����޷����ã��������
*/
class Try():public SealedClass2 {
public:
    Try() {}
    ~Try() {}
};
