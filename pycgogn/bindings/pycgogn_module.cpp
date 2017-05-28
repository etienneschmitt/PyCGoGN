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

#include <pycgogn/bindings/binding.h>
#include <pycgogn/bindings/binding_dart.h>
#include <pycgogn/bindings/binding_cell.h>
#include <pycgogn/bindings/binding_attribute.h>
#include <pycgogn/bindings/binding_map_base_data.h>
#include <pycgogn/bindings/binding_map_base.h>
#include <pycgogn/bindings/binding_cmaps.h>
#include <pycgogn/bindings/binding_io.h>

namespace py = pybind11;

PYBIND11_PLUGIN(pycgogn)
{
	py::module m("pycgogn", "pycgogn DOC : TODO");

	pycgogn::gen_bindings_class_dart(m);
	pycgogn::gen_bindings_class_cell(m);
	pycgogn::gen_bindings_class_attribute_gen(m);
	pycgogn::gen_bindings_class_attribute_t(m);
	pycgogn::gen_bindings_class_attribute(m);
	pycgogn::gen_bindings_class_map_base_data(m);
	pycgogn::gen_bindings_class_map_base(m);
	pycgogn::gen_bindings_class_cmaps(m);
	pycgogn::gen_binding_io(m);

	return m.ptr();
}
