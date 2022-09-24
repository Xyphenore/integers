#include <string>

#include "../../../include/integers/tools/common.hpp"
#include "../../../include/integers/tools/prototype.hpp"
#include "../../../include/integers/exceptions/error_code.hpp"
#include "../../../include/integers/exceptions/abstract_exception.hpp"
#include "../../../include/integers/exceptions/common.hpp"

namespace strong_glfw::exceptions {
    AbstractException::~AbstractException() noexcept = default;

    AbstractException::AbstractException( const AbstractException& ) noexcept = default;

    AbstractException::AbstractException( AbstractException&& ) noexcept = default;

    AbstractException& AbstractException::operator=( const AbstractException& ) noexcept = default;

    AbstractException& AbstractException::operator=( AbstractException&& ) noexcept = default;

    AbstractException::AbstractException( Parameters parameters ) noexcept
    : information_( std::move( parameters.information ) ), file_( std::move( parameters.file ) ),
      stack_trace_( std::move( parameters.stack_trace ) ) {}


    const std::string AbstractException::CLASS = "AbstractException";

    Information AbstractException::how_impl() const noexcept {
        return information_;
    }

    File AbstractException::where_impl() const noexcept {
        return file_;
    }

    StackTrace AbstractException::stackTrace_impl() const noexcept {
        return stack_trace_;
    }

    void addEndLine( std::string& message ) {
        message += "\n";
    }

    void addErrorCode( std::string& message, const ErrorCode& error_code ) {
        message += "Error " + std::to_string( error_code.code() ) + " : " + error_code.name();
    }

    void addFunction( std::string& message, const Function& function ) {
        message += " in the function : " + function;
    }

    void addFile( std::string& message, const File& file ) {
        if ( const auto& file_name = file.file_name;
                file_name.has_value() ) {

            if ( const auto& line = file.line;
                    line.has_value() ) {

                message += " at " + file_name.value() + ":" + std::to_string( line.value() );

                if ( const auto& column = file.column;
                        column.has_value() ) {

                    message += ":" + std::to_string( column.value() );
                }
            }
            else {
                message += " in the file : " + file_name.value();
            }
        }

        if ( file.function_name.has_value() ) {
            addFunction( message, file.function_name.value() );
        }
    }

    void addContext( std::string& message, const Context& context ) {
        message += "Context : " + context;
        addEndLine( message );
    }

    void addSolution( std::string& message, const Solution& solution ) {
        message += "Solution : " + solution;
        addEndLine( message );
    }

    void addInformation( std::string& message, const Information& information ) {
        if ( const auto& context = information.context;
                context.has_value() ) {
            addContext( message, context.value() );
        }

        if ( const auto& solution = information.solution;
                solution.has_value() ) {
            addSolution( message, solution.value() );
        }
    }

    void addStackTrace( std::string& message, const std::optional<StackTrace>& trace ) {
        if ( trace.has_value() && !trace.value().empty() ) {
            message += "Cause : \n";

            std::for_each( trace->begin(), trace->end(), [&]( const auto& exception ) {
                message += "\t" + std::string( exception.get().what() );
            } );
        }
    }

    void AbstractException::generateWhatMessage() const noexcept {
        what_message_ = {};
        std::string& what_message = what_message_.value();

        addErrorCode( what_message, how().error_code() );

        addFile( what_message, where() );

        addEndLine( what_message );

        addInformation( what_message, how() );

        addStackTrace( what_message, stackTrace() );
    }

    czstring AbstractException::what_impl() const noexcept {
        if ( !what_message_.has_value() || isBlank( what_message_.value() ) ) {
            generateWhatMessage();
        }

        return what_message_->c_str();
    }

    void AbstractException::addInStackTrace_impl( Exception&& exception ) noexcept {
        if ( !stack_trace_.has_value() ) {
            stack_trace_ = {};
        }

        stack_trace_->emplace_back( std::forward<Exception&>( exception ) );
    }

    // TODO Peut etre supprimer le cloner pour abstract exceptions
    UniqueException AbstractException::clone_impl() const noexcept {
        class MineAbstractException final
                : public AbstractException {
        public:
            explicit MineAbstractException( const AbstractException& other ) noexcept
                    : AbstractException( other ) {}
        };

        return std::make_unique<MineAbstractException>( *this );
    }
} // namespace strong_glfw::exceptions
