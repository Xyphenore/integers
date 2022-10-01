/*******************************************************************************
 * Integers - Safe conversion from a string to integer.
 * Copyright (C) 2022 Xyphenore
 *
 * This program is free software. You can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 ******************************************************************************/

#ifndef INTEGERS_CONCEPTS_SIGNED_INTEGER_HPP
#define INTEGERS_CONCEPTS_SIGNED_INTEGER_HPP

#include <concepts>

namespace integers {
/**
 * All concepts of the library @c integers.
 *
 * @version 1.0.0
 * @since 1.0.0
 * @authors Xyphenore
 *
 * @see integers::Integer
 * @see integers::concepts::SignedInteger
 */
namespace concepts {

/**
 * A signed type concept.
 *
 * @tparam T Any signed type.
 *
 * @version 1.0.0
 * @since 1.0.0
 *
 * @see integers::concepts::SignedInteger
 */
template <typename T>
concept SignedType = std::is_signed_v<T>;

/**
 * An integral type concept.
 *
 * @tparam T Any integral type.
 *
 * @version 1.0.0
 * @since 1.0.0
 *
 * @see integers::concepts::SignedInteger
 */
template <typename T>
concept IntegralType = std::is_integral_v<T>;

/**
 * A signed integral type concept.
 *
 * @tparam T Any signed integral type.
 *
 * @version 1.0.0
 * @since 1.0.0
 *
 * @see integers::Integer
 */
template <typename IntegerType>
concept SignedInteger = IntegralType<IntegerType> && SignedType<IntegerType>;

}  // namespace concepts
}  // namespace integers

#endif  // INTEGERS_CONCEPTS_SIGNED_INTEGER_HPP
