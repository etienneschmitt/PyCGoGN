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

#include <pycgogn/bindings/binding_cell.h>
#include <cgogn/core/basic/cell.h>


PYCGOGN_API void pycgogn::gen_bindings_class_cell(pybind11::module& m)
{
	py::enum_<cgogn::Orbit>(m, "Orbit", py::arithmetic())
		.value("DART", cgogn::Orbit::DART)
		.value("PHI1", cgogn::Orbit::PHI1)
		.value("PHI2", cgogn::Orbit::PHI2)
		.value("PHI21", cgogn::Orbit::PHI21)
		.value("PHI1_PHI2", cgogn::Orbit::PHI1_PHI2)
		.value("PHI1_PHI3", cgogn::Orbit::PHI1_PHI3)
		.value("PHI2_PHI3", cgogn::Orbit::PHI2_PHI3)
		.value("PHI21_PHI31", cgogn::Orbit::PHI21_PHI31)
		.value("PHI1_PHI2_PHI3", cgogn::Orbit::PHI1_PHI2_PHI3)
		.export_values();

	pycgogn::internal::helper_gen_bindings_class_cell<cgogn::Orbit::DART>(m,"CellD");
	pycgogn::internal::helper_gen_bindings_class_cell<cgogn::Orbit::PHI1>(m,"CellP1");
	pycgogn::internal::helper_gen_bindings_class_cell<cgogn::Orbit::PHI2>(m,"CellP2");
	pycgogn::internal::helper_gen_bindings_class_cell<cgogn::Orbit::PHI21>(m,"CellP21");
	pycgogn::internal::helper_gen_bindings_class_cell<cgogn::Orbit::PHI1_PHI2>(m,"CellP1P2");
	pycgogn::internal::helper_gen_bindings_class_cell<cgogn::Orbit::PHI1_PHI3>(m,"CellP1P3");
	pycgogn::internal::helper_gen_bindings_class_cell<cgogn::Orbit::PHI2_PHI3>(m,"CellP2P3");
	pycgogn::internal::helper_gen_bindings_class_cell<cgogn::Orbit::PHI21_PHI31>(m,"CellP21P31");
	pycgogn::internal::helper_gen_bindings_class_cell<cgogn::Orbit::PHI1_PHI2_PHI3>(m,"CellP1P2P3");
}
