#include <iostream>
#include <string>
#include <string_view>

#include "implicit_sharing.hpp"

namespace self_studies {

    struct data{
        std::uint32_t value1{0};
        std::string value2{"value2"};
        
        // data() = default;
        // data(const data&) = default;
        // data& operator=(const data&) = default;
    };

    class example : public implicit_sharing<data>{
        public:
        std::string_view get_class_name() override;

    };
}