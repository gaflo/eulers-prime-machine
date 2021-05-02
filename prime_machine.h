#ifndef PRIMEMACHINE_PRIME_MACHINE_H
#define PRIMEMACHINE_PRIME_MACHINE_H


#include <vector>

class prime_machine {
public:

    static std::vector<int> sum_divisors(int n);

    static std::vector<int> generate_primes(int n);

private:
    // constructor is private, as class is entirely static
    prime_machine();

    static std::vector<int> diff_list(int n);

    static std::vector<int> position_numbers(int n);
};


#endif //PRIMEMACHINE_PRIME_MACHINE_H
