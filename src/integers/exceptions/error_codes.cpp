#include <string>

#include "../../deps/glfw-3.3.7/include/GLFW/glfw3.h"

#include "../../include/utils/integer.hpp"
#include "../../include/utils/name.hpp"
#include "../../include/exception/error_code.hpp"
#include "../../include/exception/error_codes.hpp"

namespace strong_glfw::exceptions {
    const std::string ErrorCodes::CLASS = "ErrorCodes";

    const ErrorCode ErrorCodes::NO_ERROR = ErrorCode(
            Integer( std::to_string( GLFW_NO_ERROR ) ),
            Name( "GLFW_NO_ERROR" )
    );

    const ErrorCode ErrorCodes::NOT_INITIALIZED = ErrorCode(
            Integer( std::to_string( GLFW_NOT_INITIALIZED ) ),
            Name( "GLFW_NOT_INITIALIZED" )
    );

    const ErrorCode ErrorCodes::NO_CURRENT_CONTEXT = ErrorCode(
            Integer( std::to_string( GLFW_NO_CURRENT_CONTEXT ) ),
            Name( "GLFW_NO_CURRENT_CONTEXT" )
    );

    const ErrorCode ErrorCodes::INVALID_ENUM = ErrorCode(
            Integer( std::to_string( GLFW_INVALID_ENUM ) ),
            Name( "GLFW_INVALID_ENUM" )
    );

    const ErrorCode ErrorCodes::INVALID_VALUE = ErrorCode(
            Integer( std::to_string( GLFW_INVALID_VALUE ) ),
            Name( "GLFW_INVALID_VALUE" )
    );

    const ErrorCode ErrorCodes::OUT_OF_MEMORY = ErrorCode(
            Integer( std::to_string( GLFW_OUT_OF_MEMORY ) ),
            Name( "GLFW_OUT_OF_MEMORY" )
    );

    const ErrorCode ErrorCodes::API_UNAVAILABLE = ErrorCode(
            Integer( std::to_string( GLFW_API_UNAVAILABLE ) ),
            Name( "GLFW_API_UNAVAILABLE" )
    );

    const ErrorCode ErrorCodes::VERSION_UNAVAILABLE = ErrorCode(
            Integer( std::to_string( GLFW_VERSION_UNAVAILABLE ) ),
            Name( "GLFW_VERSION_UNAVAILABLE" )
    );

    const ErrorCode ErrorCodes::PLATFORM = ErrorCode(
            Integer( std::to_string( GLFW_PLATFORM_ERROR ) ),
            Name( "GLFW_PLATFORM_ERROR" )
    );

    const ErrorCode ErrorCodes::FORMAT_UNAVAILABLE = ErrorCode(
            Integer( std::to_string( GLFW_FORMAT_UNAVAILABLE ) ),
            Name( "GLFW_FORMAT_UNAVAILABLE" )
    );

    const ErrorCode ErrorCodes::NO_WINDOW_CONTEXT = ErrorCode(
            Integer( std::to_string( GLFW_NO_WINDOW_CONTEXT ) ),
            Name( "GLFW_NO_WINDOW_CONTEXT" )
    );

    const ErrorCode ErrorCodes::BLANK_NAME_ERROR = ErrorCode(
            Integer( std::to_string(1) ),
            Name( "BLANK_NAME_ERROR" )
    );

    const ErrorCode ErrorCodes::ALREADY_USED_ERROR_CODE = ErrorCode(
            Integer( std::to_string(2) ),
            Name( "ALREADY_USED_ERROR_CODE" )
    );

    const ErrorCode ErrorCodes::ALREADY_USED_ERROR_NAME = ErrorCode(
            Integer( std::to_string(3) ),
            Name( "ALREADY_USED_ERROR_NAME" )
    );
}
