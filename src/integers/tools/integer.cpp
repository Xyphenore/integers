#include <string>
#include <cstdint>
#include <string_view>

#include "../../include/utils/integer.hpp"
#include "../../include/utils/common.hpp"

namespace strong_glfw::utils {

    const std::string Integer::CLASS = "Integer";

    Integer::Integer( std::string_view number )
    : value_( stol(number) ) {}

    int32_t Integer::to_integer() const noexcept {
        return value_;
    }
} // namespace strong_glfw::utils


size_t std::hash<strong_glfw::utils::Integer>::operator()( const strong_glfw::utils::Integer& lhs ) const noexcept {
    return std::hash<int32_t>()( lhs.to_integer() );
}

std::string std::to_string( strong_glfw::utils::Integer number ) noexcept {
    return std::to_string( number.to_integer() );
}
