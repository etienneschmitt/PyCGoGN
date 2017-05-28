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

#include <pycgogn/bindings/binding_map_base_data.h>
#include <cgogn/core/cmap/map_base_data.h>

PYCGOGN_API void pycgogn::gen_bindings_class_map_base_data(py::module& m)
{
	using MapBaseData = cgogn::MapBaseData;

	py::class_<MapBaseData>(m,"MapBaseData")
			.def(py::init<>())
			.def("is_embedded", static_cast<bool (MapBaseData::*)(cgogn::Orbit) const>(&MapBaseData::is_embedded))
			.def("embedding", static_cast<cgogn::uint32 (MapBaseData::*)(cgogn::Dart, cgogn::Orbit) const>(&MapBaseData::embedding))
			;
}





