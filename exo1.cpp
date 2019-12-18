#include <iostream>
#include <thread>
#include <chrono>

class MyBigClass {
public:
	MyBigClass()
	{
		std::cout << "MyBigClass constructed !" << std::endl;
	}

	MyBigClass(const MyBigClass &)
	{
		std::cout << "MyBigClass coping..." << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(1));
		std::cout << "MyBigClass copied !" << std::endl;
	}

	MyBigClass(MyBigClass &&)
	{
		std::cout << "MyBigClass moved !" << std::endl;
	}

	~MyBigClass()
	{
		std::cout << "MyBigClass destroyed !" << std::endl;
	}

	void doSomething()
	{
		std::cout << "Something has been done !" << std::endl;
	}
private:
	std::string m_myBigData = "big data";
};

void doSomethingWithMyBigClass(MyBigClass c)
{
	c.doSomething();
}

int main(int, const char * const [])
{
	MyBigClass c;

	doSomethingWithMyBigClass(std::move(c));
	return 0;
}
