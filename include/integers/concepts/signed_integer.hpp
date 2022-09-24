#ifndef INTEGERS_CONCEPTS_SIGNED_INTEGER_HPP
#define INTEGERS_CONCEPTS_SIGNED_INTEGER_HPP

#include <concepts>

namespace integers::concepts {
    template<class Object>
    concept SignedObject = std::is_signed_v<Object>;

    template<class Object>
    concept IntegralObject = std::is_integral_v<Object>;

    template<class IntegerType>
    concept SignedInteger = IntegralObject<IntegerType> && SignedObject<IntegerType>;

} // namespace integers::concepts

#endif // INTEGERS_CONCEPTS_SIGNED_INTEGER_HPP
