#ifndef STRONG_GLFW_UTILS_INTEGER_HPP
#define STRONG_GLFW_UTILS_INTEGER_HPP

#include <string>
#include <cstdint>
#include <string_view>

namespace strong_glfw::utils {

    /**
     * Strong typed object that represents an Integer.
     * An integer must be in the range of integers (32bits).
     *
     * @since 1.0
     * @version 1.0
     * @author Axel DAVID
     */
    class Integer final {
    public:
        /**
         * The class name.
         */
        static const std::string CLASS;

        /**
         * Build an Integer from a std::string_view.
         *
         * @param [in]number std::string_view.
         *
         * @pre The number must contain only digits (+ or - are accepted).
         * @pre The number must be in the range of integers (32bits).
         *
         * @throws strong_glfw::exceptions::PatternMismatchError Throws if the number does not match with a pattern.
         * @throws strong_glfw::exceptions::OutOfRangeError Throws if the number is out of the range of integers (32bits).
         * @throws strong_glfw::exceptions::InvalidNumberError Throws if the number contains other character of digits.
         *
         * @post Create an Integer object in the range of integers (32bits).
         * @post The method 'Integer::to_integer()' return a value equals to the given number.
         *
         * @exceptsafe STRONG.
         *
         * @since 1.0
         * @author Axel DAVID
         */
        Integer( std::string_view number );

        /**
         * @brief Convert the object to an int32_t.
         *
         * @return int32_t.
         *
         * @exceptsafe NO-THROWS.
         *
         * @post The returned integer is in the range of integers (32bits).
         *
         * @since 1.0
         * @author Axel DAVID
         */
        [[nodiscard]]
        int32_t to_integer() const noexcept;

        bool operator<=>(const Integer& other) const noexcept = default;

    private:
        int32_t value_{0};
    };
} // namespace strong_glfw::utils

namespace std {
    template <>
    struct hash<strong_glfw::utils::Integer> {
        size_t operator()( const strong_glfw::utils::Integer & lhs ) const noexcept;
    };

    std::string to_string( strong_glfw::utils::Integer number ) noexcept;
} // namespace std

#endif // STRONG_GLFW_UTILS_INTEGER_HPP
