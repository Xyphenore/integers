#ifndef STRONG_GLFW_EXCEPTIONS_EXCEPTION_HPP
#define STRONG_GLFW_EXCEPTIONS_EXCEPTION_HPP

#include <exception>
#include <string>

#include "../tools/common.hpp"
#include "../tools/prototype.hpp"
#include "common.hpp"

namespace strong_glfw::exceptions {

    using Prototype = strong_glfw::utils::Prototype<Exception>;
    using UniqueException = Prototype::pointer;

    using Information = common::Information;
    using File = common::File;
    using StackTrace = common::StackTrace;


    /**
     * Interface for exceptions. It inherits the interface strong_glfw::utils::Prototype<Exception>.
     *
     * @since 1.0
     * @version 1.0
     * @author Axel DAVID
     *
     * @see strong_glfw::utils::Prototype<T>
     */
    class Exception : public std::exception, public Prototype {
    public:
        /**
         * Class name.
         */
        static const std::string CLASS;

        /**
         * Return the reason and the solution of the exceptions.
         *
         * @exceptsafe NO-THROWS.
         *
         * @return Return strong_glfw::exceptions::common::Information
         *
         * @since 1.0
         * @version 1.0
         */
        [[nodiscard("You call the function to get informations about the exceptions.")]]
        Information how() const noexcept;

        /**
         * Return the place where the exceptions was thrown.
         *
         * @exceptsafe NO-THROWS.
         *
         * @return Return strong_glfw::exceptions::common::File
         *
         * @since 1.0
         * @version 1.0
         */
        [[nodiscard("You call the function to get the file where the error occurred.")]]
        File where() const noexcept;

        /**
         * Return a C string about all information from the exceptions.
         *
         * @exceptsafe NO-THROWS.
         *
         * @return Return a view to a C string.
         *
         * @since 1.0
         * @version 1.0
         */
        [[nodiscard("You call the function to have all informations from the exceptions.")]]
        czstring what() const noexcept final;

        /**
         * Return the stacktrace of the exceptions.
         *
         * @exceptsafe NO-THROWS.
         *
         * @return Return a strong_glfw::exceptions::common::StackTrace
         *
         * @since 1.0
         * @version 1.0
         */
        [[nodiscard("You call the function to get the stack trace of the exceptions.")]]
        StackTrace stackTrace() const noexcept;

        /**
         * Add the exceptions at the end of stacktrace.
         *
         * @param [in]exception A right reference to a strong_glfw::exceptions::Exception.
         *
         * @exceptsafe NO-THROWS.
         *
         * @since 1.0
         * @version 1.0
         */
        void addToStackTrace( Exception&& exception ) noexcept;

    private:
        [[nodiscard]]
        virtual Information how_impl() const noexcept = 0;

        [[nodiscard]]
        virtual File where_impl() const noexcept = 0;

        [[nodiscard]]
        virtual StackTrace stackTrace_impl() const noexcept = 0;

        virtual void addInStackTrace_impl( Exception&& exception ) noexcept = 0;

        [[nodiscard]]
        virtual czstring what_impl() const noexcept = 0;
    };

} // namespace strong_glfw::exceptions

#endif // STRONG_GLFW_EXCEPTIONS_EXCEPTION_HPP
