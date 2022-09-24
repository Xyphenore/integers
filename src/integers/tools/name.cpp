#include <string>
#include <string_view>

#include "../../include/utils/name.hpp"

#include "../../include/utils/common.hpp"
#include "../../include/exception/exceptions.hpp"

namespace strong_glfw::utils {

    const std::string Name::CLASS = "Name";

    Name::Name( std::string name )
    : name_( std::move( trim( std::move( name ) ) ) ) {
        if ( name_.empty() ) {
            throw strong_glfw::exceptions::BlankNameError();
        }
    }

    std::string Name::to_string() const noexcept {
        return name_;
    }
} // namespace strong_glfw::utils

size_t std::hash<strong_glfw::utils::Name>::operator()( const strong_glfw::utils::Name& lhs ) const noexcept {
    return std::hash<std::string>()( lhs.to_string() );
}

std::string std::to_string( const strong_glfw::utils::Name& name ) noexcept {
    return name.to_string();
}
