/* lazy Singleton */

class Singleton
{
public:
    /* 提供static的Instance()方法，作为全局访问点；
     * 如果有现成的实例，则直接返回；
     *如果没有，则将新生成的实例保存到私有的static属性中
    */
     /* Instance()返回的是实例的引用而不是指针，如果是指针有被外部调用者delete的风险。
      * 直到Instance()方法被访问，才会生成实例，这种特性被称为延迟初始化（Lazy Singleton）
     */
    /* 但是这种方式不是线程安全的，比如有线程A和B
     * 都通过了instance==nullptr判断，则两个线程会分配创建新实例，这样单例模式就被打破了。
    */
    static Singleton& Instance() {
        if (instance == nullptr)
            instance = new Singleton;
        return *instance;
    }

private:
    //构造函数与拷贝构造函数，拷贝赋值运算符都声明为私有方法，这样杜绝从外部生成新的实例
    Singleton();
    ~Singleton();
    Singleton(const Singleton&);
    Singleton& operator=(const Singleton&);

private:
    static Singleton* instance;
};
//实现文件中
Singleton* Singleton::instance = 0;


/* Eager Singleton */
/* 这种模式在程序开始就完成了实例的创建。与Lazy相反；
 * 因为在main函数之前初始化，所以没有线程安全的问题；
 * 但是潜在的问题在于no-local static对象（函数外的static对象）
 * 在不同编译单元中的初始化顺序是未定义的。
 * 如果在初始化完成之前调用了Instance()方法就会返回一个未定义的实例。
 * 也就是说不能保证先完成初始化。
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
/* 下面是effective C++中提出的一种模式，使用local static对象
 * 实现了当第一次访问Instance()方法时才创建实例。
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
