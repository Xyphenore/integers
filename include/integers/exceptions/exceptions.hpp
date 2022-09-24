#ifndef STRONG_GLFW_EXCEPTIONS_HPP
#define STRONG_GLFW_EXCEPTIONS_HPP

#include <cstdint>
#include <deque>
#include <exception>
#include <functional>
#include <memory>
#include <optional>
#include <string>

#include "../tools/common.hpp"
#include "../tools/prototype.hpp"
#include "common.hpp"
#include "exception.hpp"
#include "abstract_exception.hpp"

namespace strong_glfw::exceptions {

    using Prototype = strong_glfw::utils::Prototype<Exception>;
    using UniqueException = Prototype::pointer;

    using Parameters = common::Parameters;
    using Information = common::Information;
    using File = common::File;
    using StackTrace = common::StackTrace;


    class InternalError : public Exception {
    };

    class BaseInternalError : public InternalError {};

    class PlatformError final : public BaseInternalError {};

    class UnknownError final : public BaseInternalError {};

    class OutOfMemory final : public BaseInternalError {};


    class LogicError : public Exception {};

    class BaseLogicError : public LogicError {};

    class NotInitializedError final : public BaseLogicError {};

    class NoCurrentContextError final : public BaseLogicError {};

    class NoWindowContextError final : public BaseLogicError {};


    class InvalidArgument : public LogicError {};

    class BaseInvalidArgument : public LogicError {};

    class InvalidValueError final : public BaseInvalidArgument {};

    class InvalidEnumError final : public BaseInvalidArgument {};

    class InvalidTitleError : public BaseInvalidArgument {};

    class InvalidNumberError : public BaseInvalidArgument {};

    class BlankNameError : public BaseInvalidArgument {};

    class BlankContextError : public BaseInvalidArgument {};

    class BlankReasonError : public BaseInvalidArgument {};

    class BlankSolutionError : public BaseInvalidArgument {};

    class BlankNoteError : public BaseInvalidArgument {};

    class BlankFunctionNameError : public BaseInvalidArgument {};

    class BlankFileNameError : public BaseInvalidArgument {};

    class AlreadyUsedErrorName : public BaseInvalidArgument {};

    class AlreadyUsedErrorCode : public BaseInvalidArgument {};

    class OutOfRangeError : public BaseInvalidArgument {};


    class PatternMismatchError : public BaseInvalidArgument {};


    class SystemError : public Exception {};

    class BaseSystemError : public SystemError {};

    class ApiUnavailableError final : public BaseSystemError {};

    class VersionUnavailableError final : public BaseSystemError {};

    class FormatUnavailableError final : public BaseSystemError {};


} // namespace strong_glfw::exceptions

#endif // STRONG_GLFW_EXCEPTIONS_HPP
