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

#ifndef PYCGOGN_BINDINGS_MAP_BASE_H_
#define PYCGOGN_BINDINGS_MAP_BASE_H_

#include <pycgogn/bindings/binding.h>
#include <cgogn/core/cmap/map_base.h>


namespace pycgogn
{

namespace internal
{
template<typename MAP_TYPE, typename ATT_TYPE>
void add_attribute_helper(py::class_<cgogn::MapBase<MAP_TYPE>, cgogn::MapBaseData>& c, const std::string& attribute_t)
{
	using MapBase = cgogn::MapBase<MAP_TYPE>;
	using ConcreteMap = typename MapBase::ConcreteMap;
	using Vertex = typename ConcreteMap::Vertex;
	using Edge = typename ConcreteMap::Edge;
	using Face = typename ConcreteMap::Face;
	using Volume = typename ConcreteMap::Volume;

	c.def(("add_vertex_attribute_" +attribute_t).c_str(), [](MapBase& mb, const std::string& att_name) { return mb.template add_attribute<ATT_TYPE, Vertex>(att_name); })
	.def(("add_edge_attribute_" +attribute_t).c_str(), [](MapBase& mb, const std::string& att_name) { return mb.template add_attribute<ATT_TYPE, Edge>(att_name); })
	.def(("add_face_attribute_" +attribute_t).c_str(), [](MapBase& mb, const std::string& att_name) { return mb.template add_attribute<ATT_TYPE, Face>(att_name); })
	.def(("add_volume_attribute_" +attribute_t).c_str(), [](MapBase& mb, const std::string& att_name) { return mb.template add_attribute<ATT_TYPE, Volume>(att_name); })
	;
}

template<typename MAP_TYPE>
void helper_gen_bindings_class_map_base(py::module& m, const std::string& classname)
{
	using MapBase = cgogn::MapBase<MAP_TYPE>;
	using ConcreteMap = typename MapBase::ConcreteMap;
	using Vertex = typename ConcreteMap::Vertex;
	using Edge = typename ConcreteMap::Edge;
	using Face = typename ConcreteMap::Face;
	using Volume = typename ConcreteMap::Volume;

	auto c = py::class_<MapBase, cgogn::MapBaseData>(m, classname.c_str())
		.def(py::init<>())
		.def("nb_vertices", &MapBase::template nb_cells<Vertex::ORBIT>)
		.def("nb_edges", &MapBase::template nb_cells<Edge::ORBIT>)
		.def("nb_faces", &MapBase::template nb_cells<Face::ORBIT>)
		.def("nb_volumes", &MapBase::template nb_cells<Volume::ORBIT>)

		.def("foreach_vertex", [](const MapBase& mb, const std::function<void(Vertex)>& func) { mb.foreach_cell(func);} )
		.def("foreach_edge", [](const MapBase& mb, const std::function<void(Edge)>& func) { mb.foreach_cell(func);} )
		.def("foreach_face", [](const MapBase& mb, const std::function<void(Face)>& func) { mb.foreach_cell(func);} )
		.def("foreach_volume", [](const MapBase& mb, const std::function<void(Volume)>& func) { mb.foreach_cell(func);} )

		.def("foreach_vertex_until", [](const MapBase& mb, const std::function<bool(Vertex)>& func) { mb.foreach_cell([&](Vertex v) -> bool { return func(v); } ); })
		.def("foreach_edge_until", [](const MapBase& mb, const std::function<bool(Edge)>& func) { mb.foreach_cell([&](Edge e) -> bool { return func(e); } ); })
		.def("foreach_face_until", [](const MapBase& mb, const std::function<bool(Face)>& func) { mb.foreach_cell([&](Face f) -> bool { return func(f); } ); })
		.def("foreach_volume_until", [](const MapBase& mb, const std::function<bool(Volume)>& func) { mb.foreach_cell([&](Volume w) -> bool { return func(w); } ); })

	;

	add_attribute_helper<MAP_TYPE,int>(c, "int");
	add_attribute_helper<MAP_TYPE,cgogn::float64>(c, "double");
	add_attribute_helper<MAP_TYPE,Eigen::Vector3d>(c, "vec3d");
	add_attribute_helper<MAP_TYPE,Eigen::Vector4d>(c, "vec4d");
	add_attribute_helper<MAP_TYPE,Eigen::VectorXd>(c, "vec");
	add_attribute_helper<MAP_TYPE,Eigen::Matrix3d>(c, "mat3d");
	add_attribute_helper<MAP_TYPE,Eigen::Matrix4d>(c, "mat4d");
	add_attribute_helper<MAP_TYPE,Eigen::MatrixXd>(c, "mat");
}



} // namespace internal

PYCGOGN_API void gen_bindings_class_map_base(py::module& m);

} // namespace pycgogn

#endif // PYCGOGN_BINDINGS_MAP_BASE_H_
