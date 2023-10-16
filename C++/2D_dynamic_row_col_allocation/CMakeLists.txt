cmake_minimum_required (VERSION 3.5)

project (2D_dynamic_row_col_allocationE)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror")
set (source_dir "${PROJECT_SOURCE_DIR}/2D_dynamic_row_col_allocation/")

#set(GLOB source_files "${source_dir}/dynamic_row_col.cc")
add_executable (2D_dynamic_row_col_allocationE "${PROJECT_SOURCE_DIR}/2D_dynamic_row_col_allocation/dynamic_row_col.cc")
set_target_properties(2D_dynamic_row_col_allocationE PROPERTIES LINKER_LANGUAGE CXX)
