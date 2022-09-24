#include <algorithm>
#include <charconv>
#include <cstdlib>
#include <string>
#include <string_view>
#include <system_error>

#include "../../include/exception/exceptions.hpp"
#include "../../include/utils/common.hpp"

namespace {
    using std::operator""sv;

    /**
     * All characters, which are spaces in C locale.
     */
    constexpr auto WHITE_SPACE = " \t\n\r\v\f"sv;

    /**
     * DEFAULT BASE of number.
     */
    constexpr int32_t DEFAULT_BASE = 10;

    /**
     * Get the position of the first of last of searched characters, from the view.
     *
     * @param [in]view std::string_view
     * @param [in]searched Characters searched in the view, contains in a std::string_view.
     *
     * @exceptsafe NO-THROWS.
     *
     * @return Return the position of first of last of searched characters, like a size_t.
     *
     * @since 1.0
     * @version 1.0
     */
    [[nodiscard("You call the function to have a position.")]]
    constexpr
    size_t findFirstOfLastOf_( const std::string_view view, const std::string_view searched ) noexcept {
        if ( const auto pos = view.find_last_not_of(searched);
             pos != std::string_view::npos ) {
            return pos + 1;
        }

        return 0;
    }

    /**
     * Internal function, which trimmed the given view.
     *
     * @param [in/out]view std::string_view
     *
     * @exceptsafe NO-THROWS.
     *
     * @return Return a reference of the trimmed view.
     *
     * @since 1.0
     * @version 1.0
     */
    constexpr
    std::string_view& trim_( std::string_view& view ) noexcept {
        view.remove_prefix( std::min(view.find_first_not_of(WHITE_SPACE), view.size()) );

        const auto pos = findFirstOfLastOf_(view, WHITE_SPACE);

        view.remove_suffix( view.size() - pos );

        return view;
    }

    /**
     * Internal function, which trimmed the given string.
     *
     * @param [in/out]str std::string
     *
     * @exceptsafe NO-THROWS.
     *
     * @return Return a reference of the trimmed string.
     *
     * @since 1.0
     * @version 1.0
     */
    constexpr
    std::string& trim_( std::string& str ) noexcept {
        str.erase( findFirstOfLastOf_(str, WHITE_SPACE) )
           .erase( 0, str.find_first_not_of( WHITE_SPACE ) );

        return str;
    }
} // namespace

namespace strong_glfw::utils::common {

    constexpr std::string_view& trim( std::string_view& view ) noexcept {
        return ::trim_( view );
    }

    constexpr std::string_view trim( std::string_view view ) noexcept {
        ::trim_( view );

        return view;
    }

    constexpr std::string& trim( std::string& str ) noexcept {
        return ::trim_( str );
    }

    std::string trim( std::string str ) noexcept {
        ::trim_( str );

        return str;
    }


    int32_t stol( std::string_view str, const int32_t base ) {
        ::trim_( str );

        int32_t integer = 0;

        const auto result = std::from_chars( str.cbegin(), str.cend(), integer, base );

        if ( result.ptr == str.cbegin() ) {
            throw strong_glfw::exceptions::PatternMismatchError();
        }

        if ( result.ec == std::errc::result_out_of_range ) {
            throw strong_glfw::exceptions::OutOfRangeError();
        }

        if ( result.ptr != str.cend() ) {
            throw strong_glfw::exceptions::InvalidNumberError( "The number in the string must contain only digits." );
        }

        return integer;
    }

    int32_t stol( const std::string_view str ) {
        return stol( str, DEFAULT_BASE );
    }
} // namespace strong_glfw::utils::common
