/* lazy Singleton */

class Singleton
{
public:
    /* �ṩstatic��Instance()��������Ϊȫ�ַ��ʵ㣻
     * ������ֳɵ�ʵ������ֱ�ӷ��أ�
     *���û�У��������ɵ�ʵ�����浽˽�е�static������
    */
     /* Instance()���ص���ʵ�������ö�����ָ�룬�����ָ���б��ⲿ������delete�ķ��ա�
      * ֱ��Instance()���������ʣ��Ż�����ʵ�����������Ա���Ϊ�ӳٳ�ʼ����Lazy Singleton��
     */
    /* �������ַ�ʽ�����̰߳�ȫ�ģ��������߳�A��B
     * ��ͨ����instance==nullptr�жϣ��������̻߳���䴴����ʵ������������ģʽ�ͱ������ˡ�
    */
    static Singleton& Instance() {
        if (instance == nullptr)
            instance = new Singleton;
        return *instance;
    }

private:
    //���캯���뿽�����캯����������ֵ�����������Ϊ˽�з����������ž����ⲿ�����µ�ʵ��
    Singleton();
    ~Singleton();
    Singleton(const Singleton&);
    Singleton& operator=(const Singleton&);

private:
    static Singleton* instance;
};
//ʵ���ļ���
Singleton* Singleton::instance = 0;


/* Eager Singleton */
/* ����ģʽ�ڳ���ʼ�������ʵ���Ĵ�������Lazy�෴��
 * ��Ϊ��main����֮ǰ��ʼ��������û���̰߳�ȫ�����⣻
 * ����Ǳ�ڵ���������no-local static���󣨺������static����
 * �ڲ�ͬ���뵥Ԫ�еĳ�ʼ��˳����δ����ġ�
 * ����ڳ�ʼ�����֮ǰ������Instance()�����ͻ᷵��һ��δ�����ʵ����
 * Ҳ����˵���ܱ�֤����ɳ�ʼ����
*/
class Singleton
{
public:
    static Singleton& Instance() {
        return instance;
    }
private:
    Singleton();
    ~Singleton();
    Singleton(const Singleton&);
    Singleton& operator=(const Singleton&);

private:
    static Singleton instance;
};


/* Meyers Singleton*/
/* ������effective C++�������һ��ģʽ��ʹ��local static����
 * ʵ���˵���һ�η���Instance()����ʱ�Ŵ���ʵ����
*/
class Singleton
{
public:
    static Singleton& Instance() {
        static Singleton instance;
        return instance;
    }
private:
    Singleton();
    ~Singleton();
    Singleton(const Singleton&);
    Singleton& operator=(const Singleton&);

};
