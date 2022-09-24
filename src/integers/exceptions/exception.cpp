#include <string>

#include "../../include/utils/common.hpp"
#include "../../include/exceptions/common.hpp"
#include "../../include/exceptions/exception.hpp"

namespace strong_glfw::exceptions {
    const std::string Exception::CLASS = "Exception";

    Information Exception::how() const noexcept {
        return how_impl();
    }

    File Exception::where() const noexcept {
        return where_impl();
    }

    StackTrace Exception::stackTrace() const noexcept {
        return stackTrace_impl();
    }

    void Exception::addToStackTrace( Exception&& exception ) noexcept {
        return addInStackTrace_impl(std::move(exception));
    }

    czstring Exception::what() const noexcept {
        return what_impl();
    }

} // namespace strong_glfw::exceptions
