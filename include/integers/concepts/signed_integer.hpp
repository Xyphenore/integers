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

namespace integers::concepts {
template <class Object>
concept SignedObject = std::is_signed_v<Object>;

template <class Object>
concept IntegralObject = std::is_integral_v<Object>;

template <class IntegerType>
concept SignedInteger = IntegralObject<IntegerType> && SignedObject<IntegerType>;

}  // namespace integers::concepts

#endif  // INTEGERS_CONCEPTS_SIGNED_INTEGER_HPP
