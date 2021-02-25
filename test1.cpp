//构造

class Date//赋初值
{
public:
	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
private:
	int _year;
	int _month;
	int _day;

};

class A
{
public: 
	A(int a)
		:_a(a);
	{}
private:
	int _a;
};

class B
{
public:
	B(int a, int ref)
		:_aobj(a)
		, _ref(ref)
		, _n(10)
	{}
private:
	A _aobj;
	int& _ref;
	const int _n;
};

class Time
{
public:
	Time(int hour = 0)
		:_hour(hour)
	{
		cout << "time" << endl;
	}

private:
	int hour;
};

//static成员

class A
{

public:
	A()
	{
		++_scount;
	}
	A(const A& t)
	{
		++_scount;
	}
private:
	static int _scount;
};
int A::_count = 0;

void TestA()
{
	cout << A::GetACount() << endl;
	A a1, a2;
	A a3(a1);
	cout << A::GetACount() << endl;
}
//静态成员变量为所有类对象共享，不属于某个具体的实例
//静态成员变量必须在类外定义，定义的时候不添加static关键字
//类静态成员即可用类名：：静态成员或者对象，静态成员来访问
//静态成员函数没有隐藏的的this指针，不能访问任何非静态成员
//静态成员和类的普通成员一样，也有public，protected，private3种访问级别，也可以有返回值
