using System;
class MyClass
{
    public MyClass()
    {  //构造函数
        Console.WriteLine("Constructor");
    }
    public MyClass(int value)
    {
        MyField = value;


        Console.WriteLine("Constructor");
    }
    ~MyClass()
    {  //析构函数
        Console.WriteLine("Destructor");
    }
    public const int MyConstant = 12;  //定义常量
    public int MyField = 34;
    public void MyMethod()
    {   //定义了一个方法
        Console.WriteLine("MyClass.MyMethod");
    }
    public int MyProperty
    {  //定义类的属性
        get { return MyField; }
        set { MyField = value; }
    }
    public int this[int index]
    {
        get { return 0; }
        set
        {
            Console.WriteLine("this[{0}] was set to {1}", index, value);
        }
    }
    public event EventHandler MyEvent;

    public static MyClass operator +(MyClass a, MyClass b)
    {
        return new MyClass(a.MyField + b.MyField);
    }
    internal class MyNestedClass { }
}
//下面代码将访问上面定义的MyClass类
class Test
{
    static void Main()
    {
        MyClass a = new MyClass();  //调用构造函数
        MyClass b = new MyClass(123);
        //常量的使用
        Console.WriteLine("MyClass.MyConstant = {0}", MyClass.MyConstant);
        a.MyField++; //域的用法
        Console.WriteLine("a.MyField = {0}", a.MyField);

        a.MyMethod(); //调用方法
        a.MyProperty++;  //属性设置
        Console.WriteLine("a.MyProperty = {0}", a.MyProperty);

        a[3] = a[1] = a[2];   //索引的使用
        Console.WriteLine("a[3] = {0}", a[3]);
        a.MyEvent += new EventHandler(MyHandler);  //调用事件
        // Overloaded operator usage


        MyClass c = a + b;
        Console.ReadKey();
    }
    static void MyHandler(object sender, EventArgs e)
    {
        Console.WriteLine("Test.MyHandler");
    }
    internal class MyNestedClass { }
}
