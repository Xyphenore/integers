#include <string>
#include <unordered_set>

// TODO Remplacer par l'inclusion via CMake
#include "../../../include/integers/tools/name.hpp"
#include "../../../include/integers/tools/integer.hpp"
#include "../../../include/integers/exceptions/error_code.hpp"
#include "../../../include/integers/exceptions/exceptions.hpp"

namespace {
    std::unordered_set<strong_glfw::utils::Integer> used_codes_;
    std::unordered_set<strong_glfw::utils::Name> used_names_;
} // namespace

namespace strong_glfw::exceptions {
    const std::string ErrorCode::CLASS = "ErrorCode";

    ErrorCode::ErrorCode( Integer code, Name name )
    : code_( code ), name_( std::move( name ) ) {
        if ( used_names_.contains( name_ ) ) {
            throw AlreadyUsedErrorName();
        }
        used_names_.insert( name_ );

        if ( used_codes_.contains( code_ ) ) {
            throw AlreadyUsedErrorCode();
        }
        used_codes_.insert( code_ );
    }

    Code_t ErrorCode::code() const noexcept {
        return code_.to_integer();
    }

    std::string ErrorCode::name() const noexcept {
        return name_.to_string();
    }
} // namespace strong_glfw::exceptions
