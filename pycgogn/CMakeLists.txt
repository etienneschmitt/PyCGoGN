cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

find_package(cgogn_core REQUIRED)
find_package(cgogn_geometry REQUIRED)
find_package(cgogn_io REQUIRED)

set(HEADER_FILES
	dll.h
	bindings/binding.h
	bindings/binding_dart.h
	bindings/binding_cell.h
	bindings/binding_attribute.h
	bindings/binding_map_base_data.h
	bindings/binding_map_base.h
	bindings/binding_cmaps.h
	bindings/binding_cell_marker.h
	bindings/binding_dart_marker.h
	bindings/binding_io.h
)

set(SOURCE_FILES
	bindings/binding_dart.cpp
	bindings/binding_cell.cpp
	bindings/binding_attribute.cpp
	bindings/binding_map_base_data.cpp
	bindings/binding_map_base.cpp
	bindings/binding_cmaps.cpp
	bindings/binding_cell_marker.cpp
	bindings/binding_dart_marker.cpp
	bindings/binding_io.cpp
	bindings/pycgogn_module.cpp
)

add_library(${PROJECT_NAME} SHARED ${HEADER_FILES} ${SOURCE_FILES})

set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "")
set_target_properties(${PROJECT_NAME} PROPERTIES DEBUG_POSTFIX "")
target_compile_definitions(${PROJECT_NAME} PRIVATE "-DPYCGOGN_DLL_EXPORT")

target_include_directories(${PROJECT_NAME} PUBLIC
	$<BUILD_INTERFACE:${CGOGN_SOURCE_DIR}>
	$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}>
	$<INSTALL_INTERFACE:include>
)

target_link_libraries(${PROJECT_NAME} PUBLIC cgogn_core cgogn_geometry cgogn_io)
target_link_libraries(${PROJECT_NAME} PRIVATE pybind11::module)
set_target_properties(${PROJECT_NAME} PROPERTIES
	PREFIX "${PYTHON_MODULE_PREFIX}"
	SUFFIX "${PYTHON_MODULE_EXTENSION}")
