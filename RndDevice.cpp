#include <iostream>
#include <random>

int main()
{
    std::mt19937 mt {std::random_device{}()}; //seed the first Mersenne Twist
    std::uniform_int_distribution<> die6(1 , 6); // generate uniform numbers from a range 

    for (int count {1}; count <= 40; count++ )
    {
        std::cout << die6(mt) << "\t"; //print out seeded die 6 value after seeding die6 with the first seed

        if (count % 10 == 0) //Jump to new line after 10 numbers
        {
            std::cout << "\n";
        } 
    }
        return 0;
}