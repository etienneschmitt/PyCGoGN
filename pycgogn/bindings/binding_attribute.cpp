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

#include <pycgogn/bindings/binding_attribute.h>
#include <cgogn/core/cmap/map_base_data.h>

PYCGOGN_API void pycgogn::gen_bindings_class_attribute_gen(py::module& m)
{
	using AttributeGen = cgogn::AttributeGen;
	py::class_<AttributeGen>(m, "AttributeGen")
		.def("is_valid", &AttributeGen::is_valid)
		.def("name", &AttributeGen::name, py::return_value_policy::reference_internal)
		.def("type_name", &AttributeGen::type_name, py::return_value_policy::reference_internal);
		;
}

PYCGOGN_API void pycgogn::gen_bindings_class_attribute_t(pybind11::module& m)
{
	using namespace cgogn;

	internal::helper_class_attribute_t<int32>(m);
	internal::helper_class_attribute_t<float64>(m);
	internal::helper_class_attribute_t<Eigen::Vector3i>(m);
	internal::helper_class_attribute_t<Eigen::Vector3d>(m);
}

PYCGOGN_API void pycgogn::gen_bindings_class_attribute(pybind11::module& m)
{
	using namespace cgogn;

	internal::helper_class_attribute_2<int32>(m);
	internal::helper_class_attribute_2<float64>(m);
	internal::helper_class_attribute_2<Eigen::Vector3i>(m);
	internal::helper_class_attribute_2<Eigen::Vector3d>(m);
}
