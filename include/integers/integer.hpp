#ifndef INTEGERS_INTEGER_HPP
#define INTEGERS_INTEGER_HPP

#include <cstdint>
#include <string>
#include <string_view>

#include "concepts/signed_integer.hpp"
//#include <integers/concepts/signed_integer>

namespace integers {
    /**
     * Strong typed object that represents an Integer.
     * An integer must be in the range of IntegerType.
     *
     * @tparam IntegerType An signed integer between 8bits and 64bits.
     *
     * @since 1.0
     * @version 1.0
     * @author Axel DAVID
     */
    template<concepts::SignedInteger IntegerType>
    class Integer final {
    public:
        /**
         * The class name.
         */
        static const std::string CLASS;

        /**
         * Build an Integer from a std::string_view.
         *
         * @param[in] number An integer in a std::string_view.
         *
         * @pre The number must contain only digits (+ or - are accepted).
         * @pre The number must be in the range of integers.
         *
         * @post The method 'Integer::to_integer()' returns a value equals to the given number.
         *
         * @throws integers::exceptions::PatternMismatchError Throws if the number does not match with a pattern.
         * @throws integers::exceptions::OutOfRangeError Throws if the number is out of the range of integers.
         * @throws integers::exceptions::InvalidNumberError Throws if the number has other character of digits.
         *
         * @exceptsafe STRONG.
         *
         * @version 1.0
         * @since 1.0
         */
        Integer( std::string_view number );

        /**
         * Convert the object to an IntegerType.
         *
         * @returns Return an IntegerType.
         *
         * @post The returned integer is in the range of IntegerType.
         *
         * @exceptsafe NO-THROWS.
         *
         * @version 1.0
         * @since 1.0
         */
        [[nodiscard("You call the function to get the sub integer.")]]
        IntegerType to_integer() const noexcept;

        bool operator<=>(const Integer& other) const noexcept = default;

        explicit operator IntegerType() const noexcept;

    private:
        IntegerType value_{0};
    };

    using Integer8bits = Integer<int8_t>;
    using Integer16bits = Integer<int16_t>;
    using Integer32bits = Integer<int32_t>;
    using Integer64bits = Integer<int64_t>;

    template<concepts::SignedInteger IntegerType>
    std::string to_string( Integer<IntegerType> number ) noexcept;

} // namespace integers

namespace std {
    template<integers::concepts::SignedInteger IntegerType>
    struct hash<integers::Integer<IntegerType>> {
        size_t operator()( integers::Integer<IntegerType> lhs ) const noexcept;
    };

} // namespace std

#endif // INTEGERS_INTEGER_HPP
