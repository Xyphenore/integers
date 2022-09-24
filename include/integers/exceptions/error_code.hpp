#ifndef STRONG_GLFW_ERROR_CODE_HPP
#define STRONG_GLFW_ERROR_CODE_HPP

#include <cstdint>
#include <string>

// TODO Remplacer par l'inclusion via le CMake
#include "../tools/name.hpp"
#include "../tools/integer.hpp"
#include "../tools/common.hpp"

namespace strong_glfw::exceptions {
    namespace utils = strong_glfw::utils;

    using Integer = utils::Integer;
    using Name = utils::Name;

    /**
     * @brief An error code that contains the Code_t value and the name of error.
     *
     * @since 1.0
     * @version 1.0
     * @author Axel DAVID
     *
     * @see strong_glfw::ErrorCodes
     */
    class ErrorCode final {
    public:
        /**
         * The name of class.
         */
        static const std::string CLASS;

        ErrorCode() noexcept = delete;

        /**
         * @brief Build an object strong_glfw::ErrorCode with a code and the name.
         *
         * @param [in]code The ErrorCode like a strong_glfw::utils::Integer.
         * @param [in]name The name like a strong_glfw::utils::Name.
         *
         * @pre Another error code must not yet use the name.
         * @pre Another error code must not yet use the code.
         *
         * @throws strong_glfw::exception::AlreadyUsedErrorName Throws if another error code must yet use the name.
         * @throws strong_glfw::exception::AlreadyUsedErrorCode Throws if another error code must yet use the code.
         *
         * @post The method Name::code() returns the given code.
         * @post The method Name::name() returns the given name.
         *
         * @exceptsafe STRONG.
         *
         * @since 1.0
         * @author Axel DAVID
         */
        ErrorCode( Integer code, Name name );

        /**
         * @brief Return the error code.
         *
         * @return Return the value like a Code_t of the error code.
         *
         * @exceptsafe NO-THROWS.
         *
         * @since 1.0
         * @author Axel DAVID
         */
        [[nodiscard]]
        Code_t code() const noexcept;

        /**
         * @brief Return the name of the error code.
         *
         * @return Return the name of the error code like a std::string.
         *
         * @exceptsafe NO-THROWS.
         *
         * @since 1.0
         * @author Axel DAVID
         */
        [[nodiscard]]
        std::string name() const noexcept;

    private:
        Integer code_;

        Name name_;
    };

} // namespace strong_glfw::exceptions

//namespace std {
//    template <>
//    struct hash<strong_glfw::ErrorCode> {
//        size_t operator()( const strong_glfw::ErrorCode & lhs ) const noexcept;
//    };
//
//    std::string to_string( const strong_glfw::ErrorCode& number ) noexcept;
//} // namespace std

#endif // STRONG_GLFW_ERROR_CODE_HPP
