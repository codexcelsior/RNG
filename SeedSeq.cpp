#include <iostream>
#include <random>

int main()
{
    std::random_device rd;
    //get a set of 8 random values from random device for our seed
    std::seed_seq ss {rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd()};

    std::mt19937 mt{ss};

    //Create a reusable using uniform integer distribution
    std::uniform_int_distribution<> die6(1 , 6);

    for (int count{1}; count <= 40; count++)
    {
        std::cout << die6(mt) << "\t";
        if (count % 10 == 0)
            std::cout << "\n";
    }

    return 0;

}