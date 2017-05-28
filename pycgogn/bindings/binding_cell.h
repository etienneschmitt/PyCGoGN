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

#ifndef PYCGOGN_BINDINGS_CELL_H_
#define PYCGOGN_BINDINGS_CELL_H_

#include <pycgogn/dll.h>
#include <pycgogn/bindings/binding.h>
#include <cgogn/core/basic/cell.h>

namespace pycgogn
{

namespace internal
{
template<cgogn::Orbit ORB>
void helper_gen_bindings_class_cell(py::module& m, const std::string& classname)
{
	using Cell = cgogn::Cell<ORB>;
	py::class_<cgogn::Cell<ORB>>(m,classname.c_str())
	.def(py::init<>())
	.def(py::init<cgogn::Dart>())
	.def(py::init<const Cell&>())
	.def_readwrite("dart", &Cell::dart)
	.def("is_valid",&Cell::is_valid)
	.def("__repr__", [](const Cell c) -> std::string
	{
		return "<pycgogn." + Cell::cgogn_name_of_type() + " with dart index " + std::to_string(c.dart.index) + '>';
	})

			;
}
}

PYCGOGN_API void gen_bindings_class_cell(py::module& m);

} // namespace pycgogn

#endif // PYCGOGN_BINDINGS_CELL_H_
