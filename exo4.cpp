#include <iostream>
#include <array>

class DummyClass
{
public:
    DummyClass() : x(0), y(0), inc(0)
    {
    }

    int GetX() const
    {
        return (x);
    }
    int GetY() const
    {
        return (y);
    }
    int GetIncrementator() const
    {
        return (inc);
    }
    void Increment(int value)
    {
        inc += value;
    }

    std::array<int, 2> GetCoordinate()
    {
        return (std::array<int, 2>{x, y});
    }
private:
    int x;
    int y;
    int inc;
};


template<typename T>
void CallTheRightReference(T &value)
{
    std::cout << "lvalue detected\n";
    value.Increment(100);
}

template<typename T>
void CallTheRightReference(T &&value)
{
    std::cout << "rvalue \n";
    value.Increment(-50);
}

template <typename T>
void CalculateCoordinate(T &&value)
{
    auto array = value.GetCoordinate();

    array[0] -= 1;
    array[1] += 2;
    CallTheRightReference(std::forward<T>(value));
}

int main()
{
    DummyClass Dummy;

    CalculateCoordinate(Dummy);
    CalculateCoordinate(std::move(Dummy));

    if (Dummy.GetIncrementator() == 50) {
        std::cout << "You won !" << std::endl;
    } else {
        std::cout << "Maybe next time ?" << Dummy.GetIncrementator() << std::endl;
    }
    return 0;
}
