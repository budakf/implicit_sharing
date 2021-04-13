#include <iostream>
#include <concepts>
#include <string_view>

namespace self_studies{

    template<typename type>
    concept not_pointer = !std::is_pointer_v<type>;

    template<typename type>
    concept movable = std::is_move_constructible_v<type>;

    template<typename type>
    concept copyable = ( std::is_copy_constructible_v<type> 
                        && std::is_copy_assignable_v<type> );

    template<typename data>
    requires ( not_pointer<data> && 
               movable<data> && copyable<data> ) 
    class implicit_sharing{
        
        using ref_count_t = std::uint64_t*;

        protected:
        data* private_data;
        ref_count_t ref_count;

        public:
        data* get_data(){
            return private_data;
        }

        std::uint64_t get_ref_count(){
            return *ref_count;
        }

        virtual std::string_view get_class_name(){
            return "implicit_sharing";
        }

        implicit_sharing<data>(){
            ref_count = new std::uint64_t{1};
            private_data = new data{};
        }

        implicit_sharing<data>(const implicit_sharing<data>& is){
            shallow_copy(is);
        }

        implicit_sharing<data>& operator=(const implicit_sharing<data>& is){
            shallow_copy(is);
            return *this;
        }

        implicit_sharing<data>(implicit_sharing<data>&&) = default;
        implicit_sharing<data>& operator=(implicit_sharing<data>&&) = default;

        virtual ~implicit_sharing<data>(){
            --(*ref_count);
            if(*ref_count == 0){
                delete ref_count;
                delete private_data;
            }
        }

        void deep_copy_on_write(){
            ref_count = new std::uint64_t{1};
            data* new_data = new data{*private_data};
            private_data = new_data;
        }

        void shallow_copy(const implicit_sharing<data>& is){
            ref_count = is.ref_count;
            private_data = is.private_data;
            ++(*ref_count);
        }

        void set_attributes(){
            if( *ref_count > 1 ){
                deep_copy_on_write();
            }
        }

    };


}