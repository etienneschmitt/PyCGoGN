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

#include <pycgogn/bindings/binding_dart.h>
#include <cgogn/core/basic/dart.h>

PYCGOGN_API void pycgogn::gen_bindings_class_dart(py::module& m)
{
	using Dart = cgogn::Dart;

	py::class_<Dart>(m,"Dart")
		.def(py::init<>())
		.def(py::init<cgogn::uint32>())
		.def(py::init<const Dart&>())
		.def("is_nil", &Dart::is_nil)
		.def_readwrite("index", &Dart::index)
		.def(py::self == py::self)
		.def(py::self != py::self)
		.def("__repr__", [](const Dart d) -> std::string
	{
		return "<pycgogn.cgogn::Dart with index " + std::to_string(d.index) + '>';
	});
			;
}





