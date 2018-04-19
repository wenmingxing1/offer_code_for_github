#include<iostream>

using namespace std;

/*方法一：将构造函数设为private
 * 通过将构造函数和析构函数都定义为私有函数，
 * 当一个类试图继承它时，调用构造函数失败，
 * 从而导致编译错误。
 * 但是这个类由于通过new来创建实例，
 * 只能得到堆上的实例，无法得到栈上的实例。
*/
class SealedClass1 {
public:
    //需要通过static来创建和释放类的实例
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


/*方法二：利用虚拟继承
 * 将T设为友元类，使得下面的SealedClass2可以访问MakeSealed的构造函数
*/
template <typename T> class MakeSealed {
    friend T;

private:
    MakeSealed() {}
    ~MakeSealed() {}
};

/*将SealedClass2虚继承自MakeSealed<SealedClass2>
*/
class SealedClass2 : virtual public MakeSealed<SealedClass2> {
public:
    SealedClass2();
    ~SealedClass2();
};

/*在试图为SealedClass2派生类时，由于是采用的虚继承，
* 所以Try会直接调用模板类的构造函数，而Try不是模板类的友元，
* 所以无法调用，编译错误。
*/
class Try():public SealedClass2 {
public:
    Try() {}
    ~Try() {}
};
