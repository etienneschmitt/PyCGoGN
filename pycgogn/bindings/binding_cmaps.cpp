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

#include <pycgogn/bindings/binding_cmaps.h>
#include <cgogn/core/cmap/cmap3.h>
#include <cgogn/core/cmap/cmap2_tri.h>
#include <cgogn/core/cmap/cmap2_quad.h>
#include <cgogn/core/cmap/cmap3_tetra.h>
#include <cgogn/core/cmap/cmap3_hexa.h>



PYCGOGN_API void pycgogn::gen_bindings_class_cmaps(py::module& m)
{
	internal::gen_bindings_class_cmap0(m);
	internal::gen_bindings_class_cmap1(m);
	internal::gen_bindings_class_cmap2(m);
	internal::gen_bindings_class_cmap2_tri(m);
	internal::gen_bindings_class_cmap2_quad(m);
	internal::gen_bindings_class_cmap3_tetra(m);
	internal::gen_bindings_class_cmap3_hexa(m);
	internal::gen_bindings_class_cmap3(m);
}

void pycgogn::internal::gen_bindings_class_cmap0(py::module& m)
{
	using CMap0 = cgogn::CMap0;
	using MapBase = cgogn::MapBase<CMap0::MapType>;

	py::class_<CMap0, MapBase>(m, "CMap0")
			.def(py::init<>())
			;
}

void pycgogn::internal::gen_bindings_class_cmap1(py::module& m)
{
	using CMap1 = cgogn::CMap1;
	using CMap0 = CMap1::Inherit;
	using MapBase = CMap0::Inherit;

	py::class_<CMap0, MapBase>(m, "CMap0_1")
			.def(py::init<>());

	py::class_<CMap1, CMap0>(m, "CMap1")
			.def(py::init<>());
}

void pycgogn::internal::gen_bindings_class_cmap2(py::module& m)
{
	using CMap2 = cgogn::CMap2;
	using CMap1 = CMap2::Inherit;
	using CMap0 = CMap1::Inherit;
	using MapBase = CMap0::Inherit;

	using Vertex = CMap2::Vertex;
	using Edge = CMap2::Edge;
	using Face = CMap2::Face;
	using Volume = CMap2::Volume;

	py::class_<CMap0, MapBase>(m, "CMap0_2")
			.def(py::init<>());
	py::class_<CMap1, CMap0>(m, "CMap1_2")
			.def(py::init<>());


	py::class_<CMap2, CMap1>(m, "CMap2")
		.def(py::init<>())
		.def("foreach_incident_edge", [](const CMap2& map2, Vertex v, const std::function<void(Edge)>& func) { map2.foreach_incident_edge(v, func);} )
		.def("foreach_incident_face", [](const CMap2& map2, Vertex v, const std::function<void(Face)>& func) { map2.foreach_incident_face(v, func);} )
		.def("foreach_incident_volume", [](const CMap2& map2, Vertex v, const std::function<void(Volume)>& func) { map2.foreach_incident_volume(v, func);} )

		.def("foreach_incident_vertex", [](const CMap2& map2, Edge e, const std::function<void(Vertex)>& func) { map2.foreach_incident_vertex(e, func);} )
		.def("foreach_incident_face", [](const CMap2& map2, Edge e, const std::function<void(Face)>& func) { map2.foreach_incident_face(e, func);} )
		.def("foreach_incident_volume", [](const CMap2& map2, Edge e, const std::function<void(Volume)>& func) { map2.foreach_incident_volume(e, func);} )

		.def("foreach_incident_vertex", [](const CMap2& map2, Face f, const std::function<void(Vertex)>& func) { map2.foreach_incident_vertex(f, func);} )
		.def("foreach_incident_edge", [](const CMap2& map2, Face f, const std::function<void(Edge)>& func) { map2.foreach_incident_edge(f, func);} )
		.def("foreach_incident_volume", [](const CMap2& map2, Face f, const std::function<void(Volume)>& func) { map2.foreach_incident_volume(f, func);} )

		.def("foreach_incident_vertex", [](const CMap2& map2, Volume w, const std::function<void(Vertex)>& func) { map2.foreach_incident_vertex(w, func);} )
		.def("foreach_incident_edge", [](const CMap2& map2, Volume w, const std::function<void(Edge)>& func) { map2.foreach_incident_edge(w, func);} )
		.def("foreach_incident_face", [](const CMap2& map2, Volume w, const std::function<void(Face)>& func) { map2.foreach_incident_face(w, func);} )
		;
}

void pycgogn::internal::gen_bindings_class_cmap2_tri(py::module& m)
{
	using CMap2 = cgogn::CMap2Tri;
	using MapBase = CMap2::Inherit;

	py::class_<CMap2, MapBase>(m, "CMap2Tri")
			.def(py::init<>())
			;
}

void pycgogn::internal::gen_bindings_class_cmap2_quad(py::module& m)
{
	using CMap2 = cgogn::CMap2Quad;
	using MapBase = CMap2::Inherit;

	py::class_<CMap2, MapBase>(m, "CMap2Quad")
			.def(py::init<>())
			;
}

void pycgogn::internal::gen_bindings_class_cmap3(py::module& m)
{
	using CMap3 = cgogn::CMap3;
	using CMap2 = typename CMap3::Inherit;
	using CMap1 = typename CMap2::Inherit;
	using CMap0 = typename CMap1::Inherit;
	using MapBase = typename CMap0::Inherit;

	py::class_<CMap0, MapBase>(m, "CMap0_3")
			.def(py::init<>());
	py::class_<CMap1, CMap0>(m, "CMap1_3")
			.def(py::init<>());

	py::class_<CMap2, CMap1>(m, "CMap2_3")
			.def(py::init<>())
			;

	py::class_<CMap3, CMap2>(m, "CMap3")
			.def(py::init<>())
			;
}

void pycgogn::internal::gen_bindings_class_cmap3_tetra(py::module& m)
{
	using CMap3 = cgogn::CMap3Tetra;
	using MapBase = CMap3::Inherit;

	py::class_<CMap3, MapBase>(m, "CMap3Tetra")
			.def(py::init<>())
			;
}

void pycgogn::internal::gen_bindings_class_cmap3_hexa(py::module& m)
{
	using CMap3 = cgogn::CMap3Hexa;
	using MapBase = CMap3::Inherit;

	py::class_<CMap3, MapBase>(m, "CMap3Hexa")
			.def(py::init<>())
			;
}
