#include <iostream>
#include "implicit_sharing.hpp"
using namespace self_studies;

int main() {
    implicit_sharing<int> is;
    std::cout << is.get_class_name() << '\n';

    return 0;
}

