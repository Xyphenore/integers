#include <optional>
#include <string>

#include "../../../include/integers/exceptions/common.hpp"
#include "../../../include/integers/exceptions/exceptions.hpp"
#include "../../../include/integers/tools/common.hpp"

namespace strong_glfw::exceptions::common {
    Context::Context( std::string context ) {}

    std::string Context::to_string() const noexcept {
        return context_;
    }

    Information::Information( OptionalContext context, OptionalReason reason,
                              OptionalSolution solution, OptionalNote note )
    : context_(std::move(context)), reason_(std::move(reason)),
    solution_(std::move(solution)), note_(std::move(note)) {
        if ( context_.has_value() ) {
            if ( strong_glfw::utils::common::trim(context_.value()).empty() ) {
                throw BlankContextError();
            }
        }

        if ( reason_.has_value() ) {
            if ( strong_glfw::utils::common::trim(reason_.value()).empty() ) {
                throw BlankReasonError();
            }
        }

        if ( solution_.has_value() ) {
            if ( strong_glfw::utils::common::trim(solution_.value()).empty() ) {
                throw BlankSolutionError();
            }
        }

        if ( note_.has_value() ) {
            if ( strong_glfw::utils::common::trim(note_.value()).empty() ) {
                throw BlankNoteError();
            }
        }
    }

    OptionalContext Information::getContext() const noexcept {
        return context_;
    }

    OptionalReason Information::getReason() const noexcept {
        return reason_;
    }

    OptionalSolution Information::getSolution() const noexcept {
        return solution_;
    }

    OptionalNote Information::getNote() const noexcept {
        return note_;
    }



    File::File( OptionalFunctionName functionName, OptionalFileName fileName,
                OptionalLine line, OptionalColumn column )
    : function_name_(std::move(functionName)), file_name_(std::move(fileName)),
    line_(line), column_(column) {
        if ( function_name_.has_value() ) {
            if ( strong_glfw::utils::common::trim(function_name_.value()).empty() ) {
                throw BlankFunctionNameError();
            }
        }

        if ( file_name_.has_value() ) {
            if ( strong_glfw::utils::common:trim(file_name_.value()).empty() ) {
                throw BlankFileNameError();
            }
        }
    }

    OptionalFunctionName File::getFunctionName() const noexcept {
        return function_name_;
    }

    OptionalFileName File::getFileName() const noexcept {
        return file_name_;
    }

    OptionalLine File::getLine() const noexcept {
        return line_;
    }

    OptionalColumn File::getColumn() const noexcept {
        return column_;
    }

} // namespace strong_glfw::exceptions::common
