#ifndef STRONG_GLFW_EXCEPTIONS_COMMON_HPP
#define STRONG_GLFW_EXCEPTIONS_COMMON_HPP

#include <string>
#include <optional>
#include <deque>

namespace strong_glfw::exceptions {
    class Exception;
}

namespace strong_glfw::exceptions::common {
    class Context final {
    public:
        Context() noexcept = delete;

        explicit Context( std::string context );

        [[nodiscard]]
        std::string to_string() const noexcept;

    private:
        std::string context_;
    };

    template<typename TAG = struct NotBlankStringTAG>
    class NotBlankString {
    public:
        static const std::string CLASS;

        NotBlankString() noexcept = delete;

        explicit NotBlankString(std::string string);

        [[nodiscard]]
        std::string to_string() const noexcept;

    private:
        std::string string_;
    };

    using Solution = std::string;
    using Reason = std::string;
    using Note = std::string;
    using Line = int32_t;
    using Column = int32_t;
    using FunctionName = std::string;
    using FileName = std::string;

    using OptionalContext = std::optional<Context>;
    using OptionalSolution = std::optional<Solution>;
    using OptionalReason = std::optional<Reason>;
    using OptionalNote = std::optional<Note>;
    using OptionalLine = std::optional<Line>;
    using OptionalColumn = std::optional<Column>;
    using OptionalFunctionName = std::optional<FunctionName>;
    using OptionalFileName = std::optional<FileName>;

    using StackTrace = std::deque<std::reference_wrapper<strong_glfw::exceptions::Exception>>;

    /**
     * Concrete class representing information contained in a strong_glfw::exceptions::Exception object.
     *
     * @since 1.0
     * @version 1.0
     * @author Axel DAVID
     *
     * @see strong_glfw::exceptions::Exception
     */
    class Information final {
    public:
        // TODO Documenter
        // TODO Argument variadic
        Information( OptionalContext context, OptionalReason reason,
                     OptionalSolution solution, OptionalNote note );

        /**
         * Return the error code of the Exception.
         *
         * @exceptsafe NO-THROWS.
         *
         * @return Return an glfw::ErrorCode.
         *
         * @since 1.0
         * @version 1.0
         */
        [[nodiscard("You call the function to get the error code of the exceptions.")]]
        ErrorCode error_code() const noexcept;

        /**
         * Return the context.
         *
         * @exceptsafe NO-THROWS.
         *
         * @return Return a strong_glfw::exceptions::common::OptionalContext.
         *
         * @since 1.0
         * @version 1.0
         */
        [[nodiscard("You call the function to get the context.")]]
        OptionalContext getContext() const noexcept;

        /**
         * Return the reason.
         *
         * @exceptsafe NO-THROWS.
         *
         * @return Return a strong_glfw::exceptions::common::OptionalReason.
         *
         * @since 1.0
         * @version 1.0
         */
        [[nodiscard("You call the function to get the reason.")]]
        OptionalReason getReason() const noexcept;

        /**
         * Return the solution.
         *
         * @exceptsafe NO-THROWS.
         *
         * @return Return a strong_glfw::exceptions::common::OptionalSolution.
         *
         * @since 1.0
         * @version 1.0
         */
        [[nodiscard("You call the function to get the solution.")]]
        OptionalSolution getSolution() const noexcept;

        /**
         * Return notes.
         *
         * @exceptsafe NO-THROWS.
         *
         * @return Return a strong_glfw::exceptions::common::OptionalNote.
         *
         * @since 1.0
         * @version 1.0
         */
        [[nodiscard("You call the function to get notes.")]]
        OptionalNote getNote() const noexcept;

    private:
        OptionalContext context_ = std::nullopt;

        OptionalSolution solution_ = std::nullopt;

        OptionalReason reason_ = std::nullopt;

        OptionalNote note_ = std::nullopt;
    };

    // TODO Documenter
    class File final {
    public:
        File( OptionalFunctionName functionName, OptionalFileName fileName,
              OptionalLine line, OptionalColumn column );

        [[nodiscard]]
        OptionalFunctionName getFunctionName() const noexcept;

        [[nodiscard]]
        OptionalFileName getFileName() const noexcept;

        [[nodiscard]]
        OptionalLine getLine() const noexcept;

        [[nodiscard]]
        OptionalColumn getColumn() const noexcept;

    private:
        OptionalFunctionName function_name_ = std::nullopt;

        OptionalFileName file_name_ = std::nullopt;

        OptionalLine line_ = std::nullopt;

        OptionalColumn column_ = std::nullopt;
    };

    class StackTrace final {
    public:
        StackTrace()

    private:
        std::deque<Exception> stack_trace_;
    };

    struct Parameters {
        Information information;
        File file;
        StackTrace stack_trace;
    };

} // namespace strong_glfw::exceptions::common

#endif // STRONG_GLFW_EXCEPTIONS_COMMON_HPP
