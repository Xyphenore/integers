#include <string>
#include <functional>
#include <memory>
#include <deque>

#include "../../include/utils/common.hpp"
#include "../../include/utils/prototype.hpp"
#include "../../include/exception/error_code.hpp"
#include "../../include/exception/exceptions.hpp"
#include "../../include/exception/common.hpp"

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
