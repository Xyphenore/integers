#include <cstdint>
#include <string>
#include <string_view>

//#include <integers/integer.hpp>
#include "../../include/integers/integer.hpp"

namespace integers {
    template<concepts::SignedInteger IntegerType>
    Integer<IntegerType>::Integer( std::string_view number ) {}

    template<concepts::SignedInteger IntegerType>
    IntegerType Integer<IntegerType>::to_integer() const noexcept {
        return value_;
    }

    template<concepts::SignedInteger IntegerType>
    Integer<IntegerType>::operator IntegerType() const noexcept {
        return value_;
    }

    template<concepts::SignedInteger IntegerType>
    std::string to_string( const Integer<IntegerType> number ) noexcept {
        return std::to_string( number );
    }

} // namespace integers

namespace std {
    template<integers::concepts::SignedInteger IntegerType>
    size_t hash<integers::Integer<IntegerType>>::operator()(
            const integers::Integer<IntegerType> lhs
    ) const noexcept {
        return std::hash<IntegerType>( lhs.to_integer() );
    }
} // namespace std
