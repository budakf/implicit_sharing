#include "gtest/gtest.h"
#include "implicit_sharing.hpp"

using namespace self_studies;

struct data{
    std::uint32_t value1{0};
    std::string value2{"value2"};
    data() = default;
    data(const data&) = default;
    data& operator=(const data&) = default;
};


TEST(EXAMPLE_TEST, CLASS_NAME){
    implicit_sharing<data> is;
    ASSERT_STREQ(is.get_class_name().data(), "implicit_sharing");
}

TEST(EXAMPLE_TEST, Copy_Constructor){
    implicit_sharing<data> is;
    implicit_sharing<data> is2 = is;

    ASSERT_EQ(is.get_data(), is2.get_data());
}

TEST(EXAMPLE_TEST, Copy_Constructor_2){
    implicit_sharing<data> is;
    implicit_sharing<data> is2 = is;

    is2.set_attributes();
    ASSERT_NE(is.get_data(), is2.get_data());
}

TEST(EXAMPLE_TEST, Copy_Assignment_Operator){
    implicit_sharing<data> is;
    implicit_sharing<data> is2;
    is2 = is;

    ASSERT_EQ(is.get_data(), is2.get_data());
}

TEST(EXAMPLE_TEST, Copy_Assignment_Operator_2){
    implicit_sharing<data> is;
    implicit_sharing<data> is2;
    is2 = is;

    is2.set_attributes();
    ASSERT_NE(is.get_data(), is2.get_data());
}

TEST(EXAMPLE_TEST, Destructor){
    implicit_sharing<data> is;
    {
        implicit_sharing<data> is2 = is;
    }

    ASSERT_NE(is.get_data(), nullptr);
}

TEST(EXAMPLE_TEST, Ref_Counter){
    implicit_sharing<data> is;
    ASSERT_EQ(is.get_ref_count(), 1);

    {
        implicit_sharing<data> is2 = is;
        ASSERT_EQ(is.get_ref_count(), 2);
        ASSERT_EQ(is2.get_ref_count(), 2);
    }

    ASSERT_EQ(is.get_ref_count(), 1);
}