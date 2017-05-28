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

#include <pycgogn/bindings/binding_map_base.h>
#include <cgogn/core/cmap/cmap3.h>
#include <cgogn/core/cmap/cmap2_tri.h>
#include <cgogn/core/cmap/cmap2_quad.h>
#include <cgogn/core/cmap/cmap3_tetra.h>
#include <cgogn/core/cmap/cmap3_hexa.h>


PYCGOGN_API void pycgogn::gen_bindings_class_map_base(pybind11::module& m)
{
	py::class_<cgogn::MapBase<cgogn::CMap0Type>, cgogn::MapBaseData>(m, "MapBase0")
		.def(py::init<>());
	py::class_<cgogn::MapBase<cgogn::CMap1Type>, cgogn::MapBaseData>(m, "MapBase1")
		.def(py::init<>());

	internal::helper_gen_bindings_class_map_base<cgogn::CMap2Type>(m, "MapBase2");
	internal::helper_gen_bindings_class_map_base<cgogn::CMap2TriType>(m, "MapBase2Tri");
	internal::helper_gen_bindings_class_map_base<cgogn::CMap2QuadType>(m, "MapBase2Quad");
	internal::helper_gen_bindings_class_map_base<cgogn::CMap3Type>(m, "MapBase3");
	internal::helper_gen_bindings_class_map_base<cgogn::CMap3TetraType>(m, "MapBase3Tetra");
	internal::helper_gen_bindings_class_map_base<cgogn::CMap3HexaType>(m, "MapBase3Hexa");
}
