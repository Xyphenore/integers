#ifndef STRONG_GLFW_UTILS_COMMON_HPP
#define STRONG_GLFW_UTILS_COMMON_HPP

#include <algorithm>
#include <cctype>
#include <string>
#include <string_view>

/**
 * An editable character string ended with '\0'.
 */
using zstring = char*;

/**
 * A constant character string ended with '\0'.
 */
using czstring = const zstring;

/**
 * A type that represents a code.
 */
using Code_t = int32_t;

namespace strong_glfw::utils::common {
    using BlankPredicate = bool(*)(const char);

    /**
     * @brief Check if the given character is a space.
     *
     * @param [in]character : char
     *
     * @exceptsafe NO-THROWS.
     *
     * @return Return true if the character is a space.
     *
     * @since 1.0
     * @version 1.0
     * @author Axel DAVID
     *
     * @see isBlank(std::string_view)
     */
    [[nodiscard("You call the function to know if the character is a space.")]]
    constexpr
    bool isBlank( const char character ) noexcept {
        return std::isspace(static_cast<int16_t>(character)) != 0;
    };

    constexpr BlankPredicate BlankCharacter = isBlank;

    /**
 * @brief Check if the given string is filled with spaces.
 *
 * @param [in]str A std::string to check.
 *
 * @exceptsafe NO-THROWS.
 *
 * @return Return true if the given string is filled with spaces.
 *
 * @since 1.0
 * @version 1.0
 * @author Axel DAVID
 *
 * @see isBlank(const char)
 * @see std::string trim(std::string)
 */
    [[nodiscard("You call the function to know if the string is filled with spaces.")]]
    constexpr
    bool isBlank( const std::string_view str ) noexcept {
        return std::ranges::all_of( str, BlankCharacter );
    }

    /**
 * @brief Erase spaces at the start and at the end of the given string.
 *
 * @param [in]str A right reference of a std::string.
 *
 * @exceptsafe NO-THROWS.
 *
 * @return Return the given string without spaces at the start and at the end.
 *
 * @since 1.0
 * @version 1.0
 * @author Axel DAVID
 *
 * @source https://stackoverflow.com/questions/216823/how-to-trim-a-stdstring
 */
    [[nodiscard("You call the function to have the a trimmed string.")]]
    std::string trim( std::string str ) noexcept;

    /**
     * @brief Erase spaces at the start and at the end of the given string.
     *
     * @param [in/out]str A reference of a std::string.
     *
     * @exceptsafe NO-THROWS.
     *
     * @return Return the reference of the string.
     *
     * @since 1.0
     * @version 1.0
     * @author Axel DAVID
     *
     * @source https://stackoverflow.com/questions/216823/how-to-trim-a-stdstring
     */
    constexpr std::string& trim( std::string& str ) noexcept;

    /**
     * @brief Erase spaces at the start and at the end of the given string_view.
     *
     * @param [in/out]view A reference of a std::string_view.
     *
     * @exceptsafe NO-THROWS.
     *
     * @return Return the reference of the string_view.
     *
     * @since 1.0
     * @version 1.0
     * @author Axel DAVID
     *
     * @source https://stackoverflow.com/questions/216823/how-to-trim-a-stdstring
     */
    constexpr std::string_view& trim( std::string_view& view ) noexcept;

    /**
     * @brief Erase spaces at the start and at the end of the given string_view.
     *
     * @param [in]view A right reference of a std::string_view.
     *
     * @exceptsafe NO-THROWS.
     *
     * @return Return the given string_view without spaces at the start and at the end.
     *
     * @since 1.0
     * @version 1.0
     * @author Axel DAVID
     *
     * @source https://stackoverflow.com/questions/216823/how-to-trim-a-stdstring
     */
    [[nodiscard("You call the function to have the a trimmed string_view.")]]
    constexpr std::string_view trim( std::string_view view ) noexcept;

    /**
     * Convert a string to an integer (32 bits).
     *
     * @param [in]str The string containing the integer.
     * @param [in]base The number base of the integer.
     *
     * @throws strong_glfw::exceptions::PatternMismatchError Thrown if a pattern in th string didn't find.
     * @throws strong_glfw::exceptions::OutOfRangeError Thrown if the integer in the string is out of range of integers (32 bits).
     * @throws strong_glfw::exceptions::InvalidNumberError Thrown if all the string didn't converted to an integer.
     *
     * @exceptsafe STRONG.
     *
     * @return Return an integer (32 bits).
     *
     * @since 1.0
     * @version 1.0
     * @author Axel DAVID
     *
     * @source glib_c++ string_conversions template __stoa
     */
    [[nodiscard("You call the function to have an integer from a string.")]]
    int32_t stol( std::string_view str, int32_t base);

    /**
     * @overload stol(std::string_view str, int32_t base) with base 10.
     */
    [[nodiscard("You call the function to have an integer from a string.")]]
    int32_t stol( std::string_view str );
} // namespace strong_glfw::utils::common

#endif // STRONG_GLFW_UTILS_COMMON_HPP
