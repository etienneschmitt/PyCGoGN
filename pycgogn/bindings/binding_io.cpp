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

#include <pycgogn/bindings/binding_io.h>
#include <cgogn/core/cmap/cmap2_tri.h>
#include <cgogn/core/cmap/cmap2_quad.h>
#include <cgogn/core/cmap/cmap3_tetra.h>
#include <cgogn/core/cmap/cmap3_hexa.h>

PYCGOGN_API void pycgogn::gen_binding_io(pybind11::module& m)
{
	m.def("import_surface", cgogn::io::import_surface<Eigen::Vector3d, cgogn::CMap2>);
	m.def("import_surface_tri", cgogn::io::import_surface<Eigen::Vector3d, cgogn::CMap2Tri>);
	m.def("import_surface_quad", cgogn::io::import_surface<Eigen::Vector3d, cgogn::CMap2Quad>);
	m.def("import_volume", cgogn::io::import_volume<Eigen::Vector3d, cgogn::CMap3>);
	m.def("import_volume_tetra", cgogn::io::import_volume<Eigen::Vector3d, cgogn::CMap3Tetra>);
	m.def("import_volume_hexa", cgogn::io::import_volume<Eigen::Vector3d, cgogn::CMap3Hexa>);
}
