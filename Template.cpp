//完成模板-
/*1.非类型模板参数
2.类模板的特化
3.类模板特化的应用之类型萃取
4.模板的分离编译
*/


//非类型模板参数     1.非类型模板参数必须在编译期就能确认结果    2.浮点数，类对象以及字符串是不允许作为非类型模板参数的
namespace bite
{
	template<class T,size_t N = 10>
	class array
	{
	public:
		T& operator[](size_t index)
		{
			return _array[index];
		}
		size_t size()const
		{
			return _size;
		}
		bool enpty()const
		{
			return 0 == _size;
		}
	private:
		T _array[N];
		size_t _size;
	};
	//模板的特化
	template<class T>//这个部分看起来是没有什么问题的，但是看我们比较函数，由于支持得比较模式（比如数字之间的比较，字母之间的比较，字符串之间的比较，抽象对象之间的比较等等都不一样）
	bool IsEqual(T& left, T& right)
	{
		return left == right;
	}
	template<>
	bool IsEqual<char*>(char* left, char* right)
	{
		if (strcmp(left, right) > 0)
			return true;
		return false;
	}
	void Test()
	{
		char* p1 = "hello";
		char* p2 = "world";

		if (IsEqual(p1, p2))
		{
			cout << p1 << endl;
		}
else
		cout << p2 << endl;
	}
}
//这了我们考虑到不同数据类型可能比较比较麻烦，所以这里如果可以将模板中的IsEqual函数特化，见上述注释部分
//特化这部分完全可以写Wi为一个单独的函数，作为代替，因为模板如果出错错误原因难以发现

//类模板的特化
template<class T1,class T2>
class Data
{
public:
	Data()
	{
		cout << "data<T1,T2>" << endl;
	}
private:
	T1 _d1;
	T2 _d2;
};

template<>
class Data<int, char>
{
public:
	Data()
	{
		cout << "Data<int,cahr>" << endl;
	}
private:
	T1 _d1;
	T2 _d2;
};
void TestVector()
{
	Data<int, int> d1;
	Data<int, char> d2;
}

//偏特化
//1.部分特化：将模板参数中的一部分参数特化
template<class T>
class Data<T, int>
{
	Data()
	{
		cout << "Data<T,int>" << endl;
	}
private:
	T _d1;
	int _d2;
};
//特化后对参数进行了多一步的限制
//偏特化并不仅仅是指特化部分参数，而是针对模板参数更近一步的条件限制所设计出来的一个特化版本

template <typename T1,typename T2>
class Data<T1*, T2*>
{
public:
	Data()
	{
		cout << "Data<T1*,T2*>" << endl;
	}

private:
	T1 _d1;
	T2 _d2;
};

template<typename T1,typename T2>
class Data<T1&, T2&>
{
public:
	Data(const T1& d1, const T2& d2)
		:_d1(d1)
		, _d2(d2)
private:
	const T1& _d1;
	const T2& _d2;
};

void test2()
{
	Data<double, int> d1;
	Data<int, double>d2;
	Data<int*, int*> d3;
	Data<int&, int&> d4(1, 2);
}
//明天先关注一下分离编译的概念
