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

#ifndef PYCGOGN_BINDINGS_CELL_MARKER_H_
#define PYCGOGN_BINDINGS_CELL_MARKER_H_

#include <pycgogn/bindings/binding.h>
#include <cgogn/core/basic/cell_marker.h>

namespace pycgogn
{

namespace internal
{

template<typename MAP, cgogn::Orbit ORBIT>
void gen_bindings_class_cell_marker__helper_tmpl(py::module& m, const std::string& map_suffix, const std::string& orbit_name)
{
	using CellMarker_T = cgogn::CellMarker_T<MAP, ORBIT>;
	using CellMarker = typename MAP::template CellMarker<ORBIT>;
	using CellMarkerStore = typename MAP::template CellMarkerStore<ORBIT>;

	const std::string marker_t =  orbit_name + std::string ("Marker") + std::to_string(MAP::DIMENSION) + map_suffix + "_T";
	py::class_<CellMarker_T>(m, marker_t.c_str())
		.def(py::init<const MAP&>())
		.def("mark", &CellMarker_T::mark)
		.def("unmark", &CellMarker_T::unmark)
		.def("is_marked", &CellMarker_T::is_marked)
		.def("is_valid",&CellMarker_T::is_valid)
		;

	const std::string marker =  orbit_name + std::string ("Marker") + std::to_string(MAP::DIMENSION) + map_suffix;
	py::class_<CellMarker, CellMarker_T>(m, marker.c_str())
	.def(py::init<const MAP&>())
	;

	const std::string markerstore =  orbit_name + "MarkerStore" + std::to_string(MAP::DIMENSION) + map_suffix;
	py::class_<CellMarkerStore, CellMarker_T>(m, markerstore.c_str())
		.def(py::init<const MAP&>())
		.def("mark", &CellMarkerStore::mark)
		.def("unmark", &CellMarkerStore::unmark)
		.def("marked_cells",&CellMarkerStore::marked_cells, py::return_value_policy::reference)
		;
}

template<typename MAP>
void gen_bindings_class_cell_marker_helper(py::module& m, const std::string& map_suffix = "")
{
	gen_bindings_class_cell_marker__helper_tmpl<MAP, MAP::Vertex::ORBIT>(m, map_suffix,"Vertex");
	gen_bindings_class_cell_marker__helper_tmpl<MAP, MAP::Edge::ORBIT>(m, map_suffix,"Edge");
	gen_bindings_class_cell_marker__helper_tmpl<MAP, MAP::Face::ORBIT>(m, map_suffix,"Face");
	gen_bindings_class_cell_marker__helper_tmpl<MAP, MAP::Volume::ORBIT>(m, map_suffix,"Volume");
}

} // namespace internal

void gen_bindings_class_cell_marker(py::module& m);

} // namespace pycgogn

#endif // PYCGOGN_BINDINGS_CELL_MARKER_H_
