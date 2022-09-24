#ifndef STRONG_GLFW_ERROR_CODES_HPP
#define STRONG_GLFW_ERROR_CODES_HPP

#include <string>

#include "error_code.hpp"

namespace strong_glfw::exceptions {
    /**
     * All strong_glfw::ErrorCode.
     * This value is used to throw the good exceptions from the GLFW exceptions callback.
     *
     * @since 1.0
     * @version 1.0
     * @author Axel DAVID
     *
     * @note This class can't be instantiated.
     *
     * @see strong_glfw::ErrorCode
     */
    class ErrorCodes final {
    public:

        /**
         * Used to get the name of the class.
         */
        static const std::string CLASS;

        /**
         * No error has occured.
         */
        static const ErrorCode NO_ERROR;

        /**
         * This occurs if a GLFW function was called that must not be called unless the library is initialized.\n
         *
         * @reason Application programmer error.\n
         *
         * @resolution Initialize GLFW before calling any function that requires initialization.
         */
        static const ErrorCode NOT_INITIALIZED;

        /**
         * This occurs if a GLFW function was called that needs and operates on the current OpenGL or OpenGL ES context
         * but no context is current on the calling thread. One such function is glfwSwapInterval.\n
         *
         * @reason Application programmer error.\n
         *
         * @resolution Ensure a context is current before calling functions that require a current context.
         */
        static const ErrorCode NO_CURRENT_CONTEXT;

        /**
         * One argument given to the function was an invalid enum value.\n
         *
         * @example Requesting GLFW_RED_BITS with glfwGetWindowAttrib.\n
         *
         * @reason Application programmer error.\n
         *
         * @resolution Fix the offending call.
         */
        static const ErrorCode INVALID_ENUM;

        /**
         * One argument given to the function was an invalid value.\n
         *
         * @example Requesting a non-existent OpenGL or OpenGL ES version like 2.7.\n
         *
         * @reason Application programmer error.\n
         *
         * @resolution Fix the offending call.
         */
        static const ErrorCode INVALID_VALUE;

        /**
         * A memory allocation failed.\n
         *
         * @reason A bug in GLFW or the underlying operating system.
         *
         * @resolution Report the bug to our issue tracker.
         */
        static const ErrorCode OUT_OF_MEMORY;

        /**
         * GLFW could not find support for the requested API on the system.\n
         *
         * @reason The installed graphics driver does not support the requested API, or does not support it via the
         * chosen context creation backend.\n
         *
         * @example Some pre-installed Windows graphics drivers do not support OpenGL.\n
         * @example AMD only supports OpenGL ES via EGL.\n
         * @example Nvidia and Intel only support OpenGL ES via a WGL or GLX extension.\n
         * @example macOS does not provide OpenGL ES at all.\n
         * @example The Mesa EGL, OpenGL and OpenGL ES libraries do not interface with the Nvidia binary driver.\n
         * @example Older graphics drivers do not support Vulkan.\n
         *
         * @resolution Update the graphic driver.\n
         */
        static const ErrorCode API_UNAVAILABLE;

        /**
         * The requested OpenGL or OpenGL ES version (including any requested context or frame-buffer hints) is not
         * available on this machine.\n
         *
         * @reason The machine does not support your requirements.\n
         *
         * @example Future invalid OpenGL and OpenGL ES versions. For example, OpenGL 4.8 if 5.0 comes out before the
         * 4.x series gets that far, also fail with this error and not GLFW_INVALID_VALUE, because GLFW cannot know what
         * future versions will exist.
         *
         * @resolution If your application is sufficiently flexible, downgrade your requirements and try again.\n
         * @resolution Otherwise, inform the user that their machine does not match your requirements.\n
         */
        static const ErrorCode VERSION_UNAVAILABLE;

        /**
         * A platform-specific error occurred that does not match any of the more specific categories.\n
         *
         * @reason A bug or configuration error in GLFW, the underlying operating system or its drivers, or a lack of
         * required resources.\n
         *
         * @resolution Report the issue to our issue tracker.
         */
        static const ErrorCode PLATFORM;

        /**
         * If emitted during window creation, the requested pixel format is not supported.\n
         * If emitted when querying the clipboard, the contents of the clipboard could not be converted to the requested
         * format.\n
         *
         * @reason If emitted during window creation, one or more hard constraints did not match any of the available
         * pixel formats.\n
         * @resaon If emitted when querying the clipboard, ignore the error or report it to the user, as appropriate.\n
         *
         * @resolution If your application is sufficiently flexible, downgrade your requirements and try again.\n
         * @resolution Otherwise, inform the user that their machine does not match your requirements.
         */
        static const ErrorCode FORMAT_UNAVAILABLE;

        /**
         * A window that does not have an OpenGL or OpenGL ES context was passed to a function that requires it to have
         * one.\n
         *
         * @reason Application programmer error.\n
         *
         * @resolution Fix the offending call.
         */
        static const ErrorCode NO_WINDOW_CONTEXT;

        /**
         * The given error name to the constructor of strong_glfw::ErrorCode, is empty or filled with spaces.\n
         *
         * @reason Application programmer error.\n
         *
         * @resolution Fix the offending call.
         */
        static const ErrorCode BLANK_NAME_ERROR;

        /**
         * The given error name to the constructor of strong_glfw::ErrorCode, is already used from another error code.\n
         *
         * @reason Application programmer error.\n
         *
         * @resolution Fix the offending call.
         */
        static const ErrorCode ALREADY_USED_ERROR_NAME;

        /**
         * The given error code to the constructor of strong_glfw::ErrorCode, is already used from another error code.\n
         *
         * @reason Application programmer error.\n
         *
         * @resolution Fix the offending call.
         */
        static const ErrorCode ALREADY_USED_ERROR_CODE;


        ErrorCodes() = delete;

        ErrorCodes( const ErrorCodes& ) = delete;

        ErrorCodes( ErrorCodes&& ) = delete;

        ErrorCodes& operator=( const ErrorCodes& ) = delete;

        ErrorCodes& operator=( ErrorCodes&& ) = delete;

        ~ErrorCodes() = delete;
    };

} // namespace strong_glfw::exceptions

#endif // STRONG_GLFW_ERROR_CODES_HPP
