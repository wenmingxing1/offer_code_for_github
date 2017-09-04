#include<iostream>
#include<string>
#include<cstring>
//#include<>

using namespace std;

//No.1_��ֵ���������
//����Ϊ����CMySting����������Ϊ��������Ӹ�ֵ�����������
class CMyString
{
public:
    CMyString(char* pData = NULL);  //���캯��
    CMyString(const CMyString& str);    //���캯��
    ~CMyString(void);   //��������

    CMyString& operator=(const CMyString& str);

    void Print();   //Ϊ���Դ���׼��

private:
    char* m_pData;
};

//=================================================

//���캯��
CMyString::CMyString(char *pData)
{
    if (pData == NULL)
    {
        m_pData = new char[1];
        m_pData[0] = '\0';
    }
    else
    {
        int length = strlen(pData);
        m_pData = new char[length + 1];
        strcpy(m_pData, pData);
    }
}

//���캯��2
CMyString::CMyString(const CMyString &str)
{
    int length = strlen(str.m_pData);
    m_pData = new char[length + 1];
    strcpy(m_pData, str.m_pData);
}

//��������
CMyString::~CMyString()
{
    delete []m_pData;
}

//==========================��Ŀ��============================

/*
//��������Ա
//�ж��Ը�ֵ-->��������Ը�ֵ���ͷ�*this���ڴ�-->���ٿռ���и�ֵ-->����*this
CMyString& CMyString::operator=(const CMyString &str)   //��ֵ�����Ӧ���й��캯���������������ֹ���
{
    if (this == &str)   //�Ը�ֵ
        return *this;
    //����delete�ͷ��ڴ棬Ȼ������newΪ�µ����ݿ��ٿռ䣬��new char�ڴ治�㣬���޷��������ٿռ�
    //��ʱ��ԭʼ��m_pDataû���ˣ�Ҳ�޷������µ����ݣ������쳣�������CMyString�޷�������Ч״̬��Υ�����쳣��ȫ��ԭ��
    delete []m_pData;
    m_pData = NULL;
    m_pData = new char[strlen(str.m_pData) + 1];
    strcpy(m_pData, str.m_pData);

    return *this;
}
*/

//�߼�����Ա
//�ȴ���һ����ʱʵ�Σ��ٽ�����ʱʵ�κ�ԭ����ʵ��
CMyString& CMyString::operator=(const CMyString &str)
{
    if (this != &str)   //��������Ը�ֵ
    {
        CMyString strTemp(str);     //������ʱʵ��strTemp

        //���ֲ�������m_pDataָ��ĵ�ַ����Ҫʵ��m_pDataָ��ĵ�ַ����
        //���ַ������ڣ�
        //�ȴ���һ����ʱʵ���������ɹ����׳��쳣����Ӱ��ԭ�����Լ�
        //���ɹ���str_Temp�Ǿֲ���������������if�У�����if�ͻ��Զ�������������
        //�����ǰ�str_Temp.m_pData��ԭ���Լ���m_pData�����ˣ���ʱ�������ľ���ԭ���Լ��Ŀռ�
        char* pTemp = strTemp.m_pData;
        strTemp.m_pData = m_pData;
        m_pData = pTemp;

    }
    return *this;
}


//====================���Դ���=========================
void CMyString::Print()
{
    cout << m_pData << endl;
}

//���Դ���1
void Test1()
{
    cout << "Test1 begin: " << endl;
    char *text = "Hello World";
    CMyString str1(text);
    CMyString str2;
    str2 = str1;

    cout << "The expected result is : " << text << endl;
    cout << "The actual result is : ";
    str2.Print();
    cout << endl;
}

//���Դ���2--�Ը�ֵ
void Test2()
{
    cout << "Text2 begin: " << endl;
    char *text = "Hello World";
    CMyString str1(text);
    CMyString str2;
    str1 = str1;

    cout << "The expected result is : " << text << endl;
    cout << "The actual result is : ";
    str1.Print();
    cout << endl;
}

//���Դ���3--������ֵ
void Text3()
{
    cout << "Text3 begin: " << endl;
    char *text = "Hello World";
    CMyString str1(text);
    CMyString str2, str3;
    str2 = str3 = str1;

    cout << "The expected result is : " << text << endl;
    cout << "The actual result is : ";
    str2.Print();
    cout << endl;
}


int main()
{
    Test1();
    Test1();
    Test1();

    return 0;
}


















