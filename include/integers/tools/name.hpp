#ifndef STRONG_GLFW_UTILS_NAME_HPP
#define STRONG_GLFW_UTILS_NAME_HPP

#include <string>

namespace strong_glfw::utils {

    /**
     * Strong typed object that represents a Name.
     * A name must not be blank or filled with spaces.
     *
     * @since 1.0
     * @version 1.0
     * @author Axel DAVID
     */
    class Name final {
    public:
        /**
         * The class name.
         */
        static const std::string CLASS;

        Name() noexcept = delete;

        /**
         * Build a Name. Apply the trim operation on the given name.
         *
         * @param [in]name std::string.
         *
         * @throws strong_glfw::exceptions::EmptyNameError Throws if the name is empty or filled with spaces.
         *
         * @exceptsafe STRONG.
         *
         * @since 1.0
         * @author Axel DAVID
         */
        explicit Name( std::string name );

        /**
         * @brief Convert the name to a std::string.
         *
         * @return std::string.
         *
         * @exceptsafe NO-THROWS.
         *
         * @since 1.0
         * @author Axel DAVID
         */
        [[nodiscard]]
        std::string to_string() const noexcept;

        bool operator<=>(const Name& other) const noexcept = default;

    private:
        std::string name_;
    };
} // namespace strong_glfw::utils

namespace std {
    template <>
    struct hash<strong_glfw::utils::Name> {
        size_t operator()( const strong_glfw::utils::Name & lhs ) const noexcept;
    };

    std::string to_string( const strong_glfw::utils::Name& name ) noexcept;
} // namespace std

#endif // STRONG_GLFW_UTILS_NAME_HPP
