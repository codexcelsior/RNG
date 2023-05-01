# Pseudo-random number generators (PRNGs)

To simulate randomness, programs typically use a pseudo-random number generator. A pseudo-random number generator (PRNG) is an algorithm that generates a sequence of numbers whose properties simulate a sequence of random numbers.

When a PRNG is instantiated, an initial value (or set of values) called a random seed (or seed for short) can be provided to initialize the state of the PRNG. When a PRNG has been initialized with a seed, we say it has been seeded.

Most PRNGs that produce quality results use at least 16 bytes of state, if not significantly more. However, the size of the seed value can be smaller than the size of the state of the PRNG. When this happens, we say the PRNG has been underseeded.

# Mersenne Twister 

1) Generating random numbers in C++ using Mersenne Twister

The Mersenne Twister PRNG, besides having a great name, is probably the most popular PRNG across all programming languages. 
The random library has support for two Mersenne Twister types:

mt19937 is a Mersenne Twister that generates 32-bit unsigned integers
mt19937_64 is a Mersenne Twister that generates 64-bit unsigned integers