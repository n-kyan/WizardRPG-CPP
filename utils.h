#ifndef UTILS_H
#define UTILS_H

#include <string>

template<typename T>
T inputValid_uint(const std::string& prompt, T minValue, T maxValue) {
    static_assert(std::is_integral_v<T>, "T must be an integral type");
    static_assert(std::is_unsigned_v<T>, "T must be unsigned for this use case");

    const size_t min = static_cast<size_t>(minValue);
    const size_t max = static_cast<size_t>(maxValue);

    size_t input;
    while (true) {
        std::cout << prompt << "\n: ";
        std::cin >> input;
        
        if (std::cin.fail() || input < min || input > max) {
            std::cout << "Invalid input. Please enter a number between " 
            << min << " and " << max << "\n: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            system("clear");
            return static_cast<T>(input);
        }
    }
}

#endif