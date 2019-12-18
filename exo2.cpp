#include <iostream>

class MySafeIntArray {
public:
	MySafeIntArray(std::size_t arraySize)
	{
		this->m_size = arraySize;
		this->m_intArray = new int[arraySize];
	}

	MySafeIntArray(const MySafeIntArray &a)
	{
        this->m_size = a.m_size;
        this->m_intArray = new int[a.m_size];
    }

	MySafeIntArray(MySafeIntArray &&a)
	{
		// @HERE: fill this move constructor !!!
	}

	~MySafeIntArray()
	{
		delete[] this->m_intArray;
	}

	void fillWith(int n)
	{
		for (std::size_t i = 0; i < m_size; i++)
			m_intArray[i] = n;
	}

	void display() const
	{
		for (std::size_t i = 0; i < m_size; i++) {
			std::cout << m_intArray[i];
			if (i + 1 != m_size) {
				std::cout << ' ';
			}
		}
		std::cout << std::endl;
	}
private:
	std::size_t m_size = 0;
	int *m_intArray = nullptr;
};

MySafeIntArray makeIntArray(std::size_t size)
{
	MySafeIntArray a(size);
	a.fillWith(42);

	return a;
}

int main(int, const char * const [])
{
	MySafeIntArray intArray(10);
	MySafeIntArray copiedIntArray(intArray);
	MySafeIntArray movedIntArray = makeIntArray(3);

	intArray.fillWith(420);
	copiedIntArray.fillWith(69);

	std::cout << "initial array" << std::endl;
	intArray.display();
	std::cout << "copied array" << std::endl;
	copiedIntArray.display();
	std::cout << "moved array" << std::endl;
	movedIntArray.display();

	return 0;
}
