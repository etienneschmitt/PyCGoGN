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

#ifndef PYCGOGN_BINDINGS_DART_MARKER_H_
#define PYCGOGN_BINDINGS_DART_MARKER_H_

#include <pycgogn/bindings/binding.h>
#include <cgogn/core/basic/dart_marker.h>

namespace pycgogn
{

namespace internal
{

template<typename MAP>
void gen_bindings_class_dart_marker_helper(py::module& m, const char* map_suffix = "")
{
	using DartMarker_T = cgogn::DartMarker_T<MAP>;
	using DartMarker = cgogn::DartMarker<MAP>;
	using DartMarkerStore = cgogn::DartMarkerStore<MAP>;
	using DartMarkerNoUnmark = cgogn::DartMarkerNoUnmark<MAP>;
	using Vertex = typename MAP::Vertex;
	using Edge = typename MAP::Edge;
	using Face = typename MAP::Face;
	using Volume = typename MAP::Volume;

	const std::string dartmarker_t =  std::string ("DartMarker") + std::to_string(MAP::DIMENSION) + map_suffix + std::string("_T");
	py::class_<DartMarker_T>(m, dartmarker_t.c_str())
	.def(py::init<const MAP&>())
	.def("mark", &DartMarker_T::mark)
	.def("unmark", &DartMarker_T::unmark)
	.def("is_marked", &DartMarker_T::is_marked)
	.def("is_valid",&DartMarker_T::is_valid)
	.def("mark_vertex",&DartMarker_T::template mark_orbit<Vertex::ORBIT>)
	.def("unmark_vertex",&DartMarker_T::template unmark_orbit<Vertex::ORBIT>)
	.def("mark_edge",&DartMarker_T::template mark_orbit<Edge::ORBIT>)
	.def("unmark_edge",&DartMarker_T::template unmark_orbit<Edge::ORBIT>)
	.def("mark_face",&DartMarker_T::template mark_orbit<Face::ORBIT>)
	.def("unmark_face",&DartMarker_T::template unmark_orbit<Face::ORBIT>)
	.def("mark_volume",&DartMarker_T::template mark_orbit<Volume::ORBIT>)
	.def("unmark_volume",&DartMarker_T::template unmark_orbit<Volume::ORBIT>)
			;

	const std::string dartmarker =  std::string ("DartMarker") + std::to_string(MAP::DIMENSION) + map_suffix;

	py::class_<DartMarker, DartMarker_T>(m,dartmarker.c_str())
	.def(py::init<const MAP&>())
			;

	const std::string dartmarkerstore =  std::string ("DartMarkerStore") + std::to_string(MAP::DIMENSION) + map_suffix;
	py::class_<DartMarkerStore, DartMarker_T>(m,dartmarkerstore.c_str())
	.def(py::init<const MAP&>())
	.def("mark", &DartMarkerStore::mark)
	.def("unmark", &DartMarkerStore::unmark)
	.def("unmark_all", &DartMarkerStore::unmark_all)
	.def("mark_vertex",&DartMarkerStore::template mark_orbit<Vertex::ORBIT>)
	.def("unmark_vertex",&DartMarkerStore::template unmark_orbit<Vertex::ORBIT>)
	.def("mark_edge",&DartMarkerStore::template mark_orbit<Edge::ORBIT>)
	.def("unmark_edge",&DartMarkerStore::template unmark_orbit<Edge::ORBIT>)
	.def("mark_face",&DartMarkerStore::template mark_orbit<Face::ORBIT>)
	.def("unmark_face",&DartMarkerStore::template unmark_orbit<Face::ORBIT>)
	.def("mark_volume",&DartMarkerStore::template mark_orbit<Volume::ORBIT>)
	.def("unmark_volume",&DartMarkerStore::template unmark_orbit<Volume::ORBIT>)
	.def("marked_darts",&DartMarkerStore::marked_darts, py::return_value_policy::reference)
			;
}

} // namespace internal

PYCGOGN_API void gen_bindings_class_dart_marker(py::module& m);

} // namespace pycgogn

#endif // PYCGOGN_BINDINGS_DART_MARKER_H_
