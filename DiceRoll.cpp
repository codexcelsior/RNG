#include <iostream>
#include <random> //for std::mt19937 and std::uniform_int_distribution



int main()
{
    std::mt19937 mt{};

    //Create a reusable RNG that generates uniform numbers btween 1 and 6
    std::uniform_int_distribution<> die6{ 1, 6 };

    for (int count {1}; count <= 40; count++)
    {
        std::cout << die6(mt) << '\t'; //generate a roll dice

        if (count % 10 == 0)
            std::cout << "\n";

        return 0;
    }
}
