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

#include <pycgogn/bindings/binding_cell_marker.h>
#include <cgogn/core/cmap/cmap3.h>
#include <cgogn/core/cmap/cmap3_hexa.h>
#include <cgogn/core/cmap/cmap3_tetra.h>
#include <cgogn/core/cmap/cmap2_tri.h>
#include <cgogn/core/cmap/cmap2_quad.h>

void pycgogn::gen_bindings_class_cell_marker(pybind11::module& m)
{
	internal::gen_bindings_class_cell_marker_helper<cgogn::CMap2>(m);
	internal::gen_bindings_class_cell_marker_helper<cgogn::CMap2Tri>(m,"T");
	internal::gen_bindings_class_cell_marker_helper<cgogn::CMap2Quad>(m, "Q");
	internal::gen_bindings_class_cell_marker_helper<cgogn::CMap3>(m);
	internal::gen_bindings_class_cell_marker_helper<cgogn::CMap3Tetra>(m, "T");
	internal::gen_bindings_class_cell_marker_helper<cgogn::CMap3Hexa>(m, "H");
}
