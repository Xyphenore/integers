#ifndef STRONG_GLFW_EXCEPTIONS_ABSTRACT_EXCEPTION_HPP
#define STRONG_GLFW_EXCEPTIONS_ABSTRACT_EXCEPTION_HPP

#include <string>

#include "../tools/common.hpp"
#include "../tools/prototype.hpp"
#include "common.hpp"
#include "exception.hpp"

namespace strong_glfw::exceptions {

    using Parameters = common::Parameters;

    /**
     * Abstract class for exceptions. It inherits the interface strong_glfw::exceptions::Exception.
     *
     * @since 1.0
     * @version 1.0
     * @author Axel DAVID
     *
     * @see strong_glfw::exceptions::Exception
     */
    class AbstractException : public Exception {
    public:
        /**
         * The name of the class.
         */
        static const std::string CLASS;

        AbstractException() noexcept = delete;

        ~AbstractException() noexcept override;

    protected:
        explicit AbstractException( Parameters parameters ) noexcept;

        AbstractException( const AbstractException& ) noexcept;

        AbstractException( AbstractException&& ) noexcept;

        AbstractException& operator=( const AbstractException& ) noexcept;

        AbstractException& operator=( AbstractException&& ) noexcept;

    private:
        Information information_;

        File file_;

        StackTrace stack_trace_;

        mutable std::optional<std::string> what_message_ = std::nullopt;


        [[nodiscard]]
        virtual Information how_impl() const noexcept override;

        [[nodiscard]]
        virtual File where_impl() const noexcept override;

        [[nodiscard]]
        virtual StackTrace stackTrace_impl() const noexcept override;

        virtual void addInStackTrace_impl( Exception&& exception ) noexcept override;

        [[nodiscard]]
        virtual czstring what_impl() const noexcept override;

        void generateWhatMessage() const noexcept;

        UniqueException clone_impl() const noexcept override;
    };
}

#endif // STRONG_GLFW_EXCEPTIONS_ABSTRACT_EXCEPTION_HPP
