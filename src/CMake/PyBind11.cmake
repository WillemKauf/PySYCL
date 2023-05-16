#######################################################################
#######################################################################
##                  src/CMake/PyBind11.cmake for PySYCL
#######################################################################
#######################################################################
## This file is part of the PySYCL software for SYCL development in
## Python.  It is licensed under the MIT licence.  A copy of
## this license, in a file named LICENSE.md, should have been
## distributed with this file.  A copy of this license is also
## currently available at "http://opensource.org/licenses/MIT".
##
## Unless explicitly stated, all contributions intentionally submitted
## to this project shall also be under the terms and conditions of this
## license, without any additional terms or conditions.
#######################################################################
#######################################################################

set(PYTHON_MODULE_NAME "PySYCL")

#######################################################################
## Setup PyBind11
#######################################################################
find_package(Python3 COMPONENTS Interpreter Development REQUIRED)
find_package(pybind11 REQUIRED)

#######################################################################
## Setting up the PySYCL python module
#######################################################################
set(PYSYCL_MODULE_INIT_PY "${CMAKE_CURRENT_BINARY_DIR}/${PYTHON_MODULE_NAME}/pysycl.py")

set(PYSYCL_MODULE_INIT_PY_PERMISSIONS OWNER_EXECUTE OWNER_WRITE OWNER_READ
                                      GROUP_EXECUTE GROUP_READ
                                      WORLD_EXECUTE WORLD_READ)

file(WRITE  ${PYSYCL_MODULE_INIT_PY} "################################################\n")
file(APPEND ${PYSYCL_MODULE_INIT_PY} "# PySYCL Python Module\n")
file(APPEND ${PYSYCL_MODULE_INIT_PY} "################################################\n")

#######################################################################
## Include MPI if needed
#######################################################################
if(PYSYCL_USE_MPI)
  file(APPEND ${PYSYCL_MODULE_INIT_PY} "\n")
  file(APPEND ${PYSYCL_MODULE_INIT_PY} "################################################\n")
  file(APPEND ${PYSYCL_MODULE_INIT_PY} "## Using MPI: Should be importe from mpi4py\n")
  file(APPEND ${PYSYCL_MODULE_INIT_PY} "################################################\n")
  file(APPEND ${PYSYCL_MODULE_INIT_PY} "from mpi4py import MPI\n")
endif()

#######################################################################
## Module registration
#######################################################################
function(PySYCL_add_pybind11_module name file)
  pybind11_add_module(${name} ${file})

  set_property(TARGET ${name}
               PROPERTY LIBRARY_OUTPUT_DIRECTORY
               ${CMAKE_BINARY_DIR}/${PYTHON_MODULE_NAME})

  target_link_libraries(${name} PRIVATE pysycl_project_dependencies)

  target_compile_definitions(${name} PRIVATE PYSYCL_PYTHON_MODULE)

  file(APPEND ${PYSYCL_MODULE_INIT_PY} "\n")
  file(APPEND ${PYSYCL_MODULE_INIT_PY} "################################################\n")
  file(APPEND ${PYSYCL_MODULE_INIT_PY} "## Import Sub-Module: ${name}\n")
  file(APPEND ${PYSYCL_MODULE_INIT_PY} "################################################\n")
  file(APPEND ${PYSYCL_MODULE_INIT_PY} "import ${name}\n")

endfunction()