#ifndef DEVICE_PYBIND_MODULE_H
#define DEVICE_PYBIND_MODULE_H

///////////////////////////////////////////////////////////////////////
// This file is part of the PySYCL software for SYCL development in
// Python.  It is licensed under the MIT licence.  A copy of
// this license, in a file named LICENSE.md, should have been
// distributed with this file.  A copy of this license is also
// currently available at "http://opensource.org/licenses/MIT".
//
// Unless explicitly stated, all contributions intentionally submitted
// to this project shall also be under the terms and conditions of this
// license, without any additional terms or conditions.
///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
/// \file
/// \brief Python module for device in PySYCL.
///////////////////////////////////////////////////////////////////////

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "Device_Object.h"
#include "Device_Inquiry.h"

namespace py = pybind11;

PYBIND11_MODULE(device, m){
  m.doc() = R"delim(
    Device module for PySYCL
      This module provides classes and functions for selecting SYCL devices.
  )delim";

  py::class_<pysycl::Device_Object>(m, "device_object", R"delim(
    Description
      This class creates a PySYCL device object.
    )delim")
    .def(py::init<int, int>(), R"delim(
      Default Constructor
        Constructor that creates a PySYCL device Object

      Parameters
        platform_index: int
          Optional: Index for the sycl platform to select.
        device_index: int
          Optional: Index for the sycl device to select."

      Returns
        device_object
          A PySYCL device object.

      Example
        Copy
        ----
        >>> from pysycl import device_queue
        >>> gpu_queue = device_queue.device_select(0, 0)
      )delim",
      py::arg("platform_index") = 0,
      py::arg("device_index") = 0)
    .def("device_name", &pysycl::Device_Object::device_name, R"delim(
      Description
        This function outputs the selected device name.

      Returns
        str
          The name of the selected device.

      Example
        Copy
        ----
        >>> from pysycl import device_queue
        >>> gpu_queue = device_queue.device_select(0, 0)
        >>> gpu_queue.device_name()
        'Intel(R) Gen9 HD Graphics NEO'
      )delim")
    .def("device_vendor", &pysycl::Device_Object::device_vendor, R"delim(
      Description
        This function outputs the selected device vendor.

      Returns
        str
          The vendor of the selected device.

      Example
        Copy
        ----
        >>> from pysycl import device_queue
        >>> gpu_queue = device_queue.device_select(0, 0)
        >>> gpu_queue.device_vendor()
        'Intel(R) Corporation'
      )delim");

  /////////////////////////////////////////////////////////////////////

  m.def("platform_list", &pysycl::platform_list, R"delim(
    .. figure:: _static/images/platforms.png
      :scale: 50 %
      :alt: Common Platforms

      Common Platforms

    Description
      This function returns a list of available SYCL platforms.

    Returns
      list
        A list of available SYCL platforms.

    Example
      Copy
      ----
      >>> from pysycl import device_inquiry
      >>> device_inquiry.platform_list()
      [NVIDIA CUDA BACKEND, Intel(R) OpenCL, Intel(R) Level-Zero]
  )delim")
  .def("device_list", &pysycl::device_list, R"delim(
    .. figure:: _static/images/gpu.png
      :scale: 50 %
      :alt: Device Selection

      Device Selection(GPU, CPU, FPGA)

    Description
      This function returns a list of available SYCL devices.

    Returns
      list
        A list of available SYCL devices.

    Example
      Copy
      ----
      >>> from pysycl import device_inquiry
      >>> device_inquiry.device_list()
      [Intel(R) Gen9 HD Graphics NEO, Intel(R) Core(TM) i7-8700 CPU @ 3.20GHz]
  )delim"),
  py::arg("platform_index") = 0;
}

#endif // #ifndef DEVICE_PYBIND_MODULE_H
