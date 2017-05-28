/*******************************************************************************
* PyCGoGN: A Python Binding for CGoGN_2                                        *
* Copyright (C) 2017, Etienne Schmitt                                          *
*                                                                              *
* This library is free software; you can redistribute it and/or modify it      *
* under the terms of the GNU Lesser General Public License as published by the *
* Free Software Foundation; either version 2.1 of the License, or (at your     *
* option) any later version.                                                   *
*                                                                              *
* This library is distributed in the hope that it will be useful, but WITHOUT  *
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or        *
* FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License  *
* for more details.                                                            *
*                                                                              *
* You should have received a copy of the GNU Lesser General Public License     *
* along with this library; if not, write to the Free Software Foundation,      *
* Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301 USA.           *
*                                                                              *
* Web site: http://cgogn.unistra.fr/                                           *
* Contact information: cgogn@unistra.fr                                        *
*                                                                              *
*******************************************************************************/

#ifndef PYCGOGN_BINDINGS_ATTRIBUTE_H_
#define PYCGOGN_BINDINGS_ATTRIBUTE_H_

#include <pycgogn/bindings/binding.h>
#include <cgogn/core/cmap/attribute.h>
#include <cgogn/core/utils/name_types.h>

namespace pycgogn
{

namespace internal
{
template<typename T>
void helper_class_attribute_t(py::module& m)
{
	using Attribute_T = cgogn::Attribute_T<T>;

	py::class_<Attribute_T, cgogn::AttributeGen>(m, ("Attribute_T_" + cgogn::name_of_type(T())).c_str())
		.def(py::init<>())
		.def(py::init<const Attribute_T&>())
		.def("set_all_values", &Attribute_T::set_all_values)
		.def("__getitem__", static_cast<const T& (Attribute_T::*)(cgogn::Dart) const>(&Attribute_T::operator[]), py::return_value_policy::reference)
		.def("__setitem__", [&](Attribute_T att, cgogn::Dart d, const T& val) { att[d] = val; })
		.def("at_index", static_cast<T& (Attribute_T::*)(cgogn::uint32)>(&Attribute_T::operator[]), py::return_value_policy::reference)
			;
}

template<typename T, cgogn::Orbit ORBIT>
void helper_class_attribute(py::module& m)
{
	using Attribute = cgogn::Attribute<T, ORBIT>;

	py::class_<Attribute, cgogn::Attribute_T<T>>(m, ("Attribute_"+ cgogn::orbit_name(ORBIT) + "_|_" + cgogn::name_of_type(T())).c_str())
		.def(py::init<>())
		.def(py::init<const Attribute&>())
		.def("__getitem__", static_cast<const T& (Attribute::*)(cgogn::Cell<ORBIT>) const>(&Attribute::operator[]), py::return_value_policy::reference)
		.def("__setitem__", [&](Attribute att, cgogn::Cell<ORBIT> c, const T& val) { att[c] = val; })
		.def("orbit", &Attribute::orbit)
		.def("size", &Attribute::size)
			;
}

template<typename T>
void helper_class_attribute_2(py::module& m)
{
	helper_class_attribute<T, cgogn::Orbit::DART>(m);
	helper_class_attribute<T, cgogn::Orbit::PHI1>(m);
	helper_class_attribute<T, cgogn::Orbit::PHI2>(m);
	helper_class_attribute<T, cgogn::Orbit::PHI21>(m);
	helper_class_attribute<T, cgogn::Orbit::PHI1_PHI2>(m);
	helper_class_attribute<T, cgogn::Orbit::PHI1_PHI3>(m);
	helper_class_attribute<T, cgogn::Orbit::PHI2_PHI3>(m);
	helper_class_attribute<T, cgogn::Orbit::PHI21_PHI31>(m);
	helper_class_attribute<T, cgogn::Orbit::PHI1_PHI2_PHI3>(m);
}

} // namespace internal


PYCGOGN_API void gen_bindings_class_attribute_gen(py::module& m);
PYCGOGN_API void gen_bindings_class_attribute_t(py::module& m);
PYCGOGN_API void gen_bindings_class_attribute(py::module& m);

} // namespace pycgogn

#endif // PYCGOGN_BINDINGS_ATTRIBUTE_H_
