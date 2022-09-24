#ifndef STRONG_GLFW_UTILS_PROTOTYPE_HPP
#define STRONG_GLFW_UTILS_PROTOTYPE_HPP

#include <memory>

namespace strong_glfw::utils {
    /**
     * Interface, which allows cloning of concrete objects that implements it.
     *
     * @tparam T Base class or concrete class, which have a static std::string named CLASS.
     *
     * @warning The template parameter needs a static std::string named CLASS, which represents the name of the class.
     *
     * @since 1.0
     * @version 1.0
     * @author Axel DAVID
     *
     * @source https://refactoring.guru/fr/design-patterns/prototype
     */
    template<class T>
    class Prototype {
    public:
        /**
         * Name of interface.
         */
        static const std::string CLASS;

        using pointer = std::unique_ptr<T>;

        /**
         * Clone the concrete object.
         *
         * @exceptsafe NO-THROWS.
         *
         * @return Return an owner pointer. The pointer refers to the cloned object.
         *
         * @since 1.0
         * @version 1.0
         */
        [[nodiscard("You call the function to create a copy of the instance.")]]
        pointer clone() const noexcept;

    private:
        virtual pointer clone_impl() const noexcept = 0;
    };
} // namespace strong_glfw::utils

namespace strong_glfw::utils {
    template<class T>
    inline const std::string Prototype<T>::CLASS = "Prototype<" + T::CLASS + ">";

    template<class T>
    inline typename Prototype<T>::pointer Prototype<T>::clone() const noexcept {
        return clone_impl();
    }
} // namespace strong_glfw::utils


#endif // STRONG_GLFW_UTILS_PROTOTYPE_HPP
