#include <iostream>
#include <random> //for std::mt19937
#include <chrono> // for std::chrono

int main()
{
    //Seed our Mersenne Twister using the
    std::mt19937 mt{ static_cast<uint>
    (std::chrono::steady_clock::now().time_since_epoch().count())};

    //Create a reusable random number generator that generates uniform btwn 1 and 6
    std::uniform_int_distribution<> die6 {1, 6};

    //Print out a bunch of random numbers

    for (int count{1}; count <= 40; count++)
    {
        std::cout << die6(mt) << '\t';
        
        if (count % 10 == 0)
        {
            std::cout << "\n";
        }
    }

    return 0;
}