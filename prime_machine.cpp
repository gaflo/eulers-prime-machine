#include "prime_machine.h"

std::vector<int> prime_machine::diff_list(int n) {
    std::vector<int> v;
    for (int i = 1; i < n; ++i) {
        v.push_back(i);
        v.push_back(i * 2 + 1);
        if (i * 3 + 1 >= n) {
            break;
        }
    }
    return v;
}

std::vector<int> prime_machine::generate_primes(int n) {
    std::vector<int> v = sum_divisors(n);
    std::vector<int> primes;

    for (int i = 0; i < v.size(); ++i) {
        if (v[i] == i + 1) primes.push_back(i);
    }
    return primes;
}

std::vector<int> prime_machine::sum_divisors(int n) {
    std::vector<int> numbers;
    int current = 1;
    std::vector<int> positions = position_numbers(n);
    for (int i = 0; i < n; i++) {
        numbers.push_back(current);
        int next_number = 0;
        int op = 0;
        for (int position : positions) {
            if (position > numbers.size()) {
                break;
            }
            if (op++ % 4 < 2) {
                next_number += numbers[numbers.size() - position];
            } else {
                next_number -= numbers[numbers.size() - position];
            }
        }
        current = next_number;
        numbers[0]++;
    }
    return numbers;
}

std::vector<int> prime_machine::position_numbers(int n) {
    std::vector<int> differences = diff_list(n);
    std::vector<int> v;
    int current = 1;
    for (int difference : differences) {
        v.push_back(current);
        current += difference;
    }
    v.push_back(current);
    return v;
}
