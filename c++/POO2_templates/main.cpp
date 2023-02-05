#include <iostream>

template <typename T>
T Minimum (const T & x, const T & y)
{
    return x<y ? x : y;
}


int main() {
    std::cout << int Minimum(4,5) << std::endl;
    return 0;
}
