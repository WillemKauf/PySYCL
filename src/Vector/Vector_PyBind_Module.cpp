#ifndef VECTOR_PYBIND_MODULE_H
#define VECTOR_PYBIND_MODULE_H

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
/// \brief Python module for vector in PySYCL.
///////////////////////////////////////////////////////////////////////

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "Vector_Operations.h"
#include "Vector_Object.h"

namespace py = pybind11;

PYBIND11_MODULE(vector, m){
  m.doc() = R"delim(
    Vector module for PySYCL
      This module contains classes and functions that perform simple vector operations.
  )delim";

  m.def("vector_addition", &pysycl::Vector_Addition, R"delim(
    Description
      Performs a vector addition on two python lists and returns the sum.

    Parameters
      vector_a : list[float]
        The first vector to be added.

      vector_b : list[float]
        The second vector to be added.

      device : device_object
        The device to target in the vector addition.

    Returns
      list[float]
        The sum of the two input vectors.

    Examples
      Copy
      ----
      >>> from pysycl import device
      >>> from pysycl import vector
      >>> gpu_queue = device.device_select(0, 0)
      >>> vector_a = [1.0, 2.0, 3.0]
      >>> vector_b = [4.0, 5.0, 6.0]
      >>> vector.vector_addition(a, b, gpu_queue)
      [5.0, 7.0, 9.0]
  )delim",
  py::arg("vector_a"),
  py::arg("vector_b"),
  py::arg("device_object"));

  m.def("vector_subtraction", &pysycl::Vector_Subtraction, R"delim(
    Description
      Performs a vector subtraction on two python lists and returns the difference.

    Parameters
      vector_a : list[float]
        The first minuend vector.

      vector_b : list[float]
        The second subtrahend vector.

      device : device_object
        The device to target in the vector subtraction.

    Returns
      list[float]
        The difference of the two input vectors.

    Examples
      Copy
      ----
      >>> from pysycl import device
      >>> from pysycl import vector
      >>> gpu_queue = device.device_select(0, 0)
      >>> vector_a = [1.0, 2.0, 3.0]
      >>> vector_b = [4.0, 5.0, 6.0]
      >>> vector.vector_subtraction(a, b, gpu_queue)
      [-3.0, -3.0, -3.0]
  )delim",
  py::arg("vector_a"),
  py::arg("vector_b"),
  py::arg("device_object"));

  m.def("vector_element_multiplication", &pysycl::Vector_Element_Multiplication, R"delim(
    Description
      Performs a vector element-wise multiplication on two python lists and returns the product.

    Parameters
      vector_a : list[float]
        The first vector to be multiplied (element-wise).

      vector_b : list[float]
        The second vector to be multiplied (element-wise).

      device : device_object
        The device to target in the vector element multiplication.

    Returns
      list[float]
        The vector product.

    Examples
      Copy
      ----
      >>> from pysycl import device
      >>> from pysycl import vector
      >>> gpu_queue = device.device_select(0, 0)
      >>> vector_a = [1.0, 2.0, 3.0]
      >>> vector_b = [4.0, 5.0, 6.0]
      >>> vector.vector_element_multiplication(a, b, gpu_queue)
      [4.0, 10.0, 18.0]
  )delim",
  py::arg("vector_a"),
  py::arg("vector_b"),
  py::arg("device_object"));

  m.def("vector_element_division", &pysycl::Vector_Element_Division, R"delim(
    Description
      Performs a vector element-wise division on two python lists and returns the product.

    Parameters
      vector_a : list[float]
        The first vector for element-wise division (numerator).

      vector_b : list[float]
        The first vector for element-wise division (denominator).

      device : device_object
        The device to target in the vector element multiplication.

    Returns
      list[float]
          The vector quotient.

    Examples
      Copy
      ----
      >>> from pysycl import device
      >>> from pysycl import vector
      >>> gpu_queue = device.device_select(0, 0)
      >>> vector_a = [1.0, 2.0, 3.0]
      >>> vector_b = [4.0, 5.0, 6.0]
      >>> vector.vector_element_division(a, b, gpu_queue)
      [0.25, 0.4, 0.5]
  )delim",
  py::arg("vector_a"),
  py::arg("vector_b"),
  py::arg("device_object"));

  m.def("vector_sum_reduction", &pysycl::Vector_Sum_Reduction, R"delim(
    Description
      Performs a sum reduction on an input vector and returns the total.

    Parameters
      vector_a : list[float]
        The input vector for sum reduction.

      device : device_object
        The device to target in the vector element multiplication.

    Returns
      float
        The sum of every element in the input vector.

    Examples
      Copy
      ----
      >>> from pysycl import device
      >>> from pysycl import vector
      >>> gpu_queue = device.device_select(0, 0)
      >>> vector_a = [1.0, 2.0, 3.0]
      >>> vector.vector_sum_reduction(a, gpu_queue)
      6.0
  )delim",
  py::arg("vector_a"),
  py::arg("device_object"));

  m.def("vector_min_reduction", &pysycl::Vector_Min_Reduction, R"delim(
    Description
      Performs a minimum reduction on an input vector and returns the minimum value.

    Parameters
      vector_a : list[float]
        The input vector minimum reduction.

      device : device_object
        The device to target in the vector element multiplication.

    Returns
      float
        The minimum element value in the input vector.

    Examples
      Copy
      ----
      >>> from pysycl import device
      >>> from pysycl import vector
      >>> gpu_queue = device.device_select(0, 0)
      >>> vector_a = [1.0, 2.0, 3.0]
      >>> vector.vector_min_reduction(a, gpu_queue)
      1.0
  )delim",
  py::arg("vector_a"),
  py::arg("device_object"));

  m.def("vector_max_reduction", &pysycl::Vector_Max_Reduction, R"delim(
    Description
      Performs a maximum reduction on an input vector and returns the minimum value.

    Parameters
      vector_a : list[float]
        The input vector for maximum reduction.

      device : device_object
        The device to target in the vector element multiplication.

    Returns
      float
        The maximum element value in the input vector.

    Examples
      Copy
      ----
      >>> from pysycl import device
      >>> from pysycl import vector
      >>> gpu_queue = device.device_select(0, 0)
      >>> vector_a = [1.0, 2.0, 3.0]
      >>> vector.vector_max_reduction(a, gpu_queue)
      3.0
  )delim",
  py::arg("vector_a"),
  py::arg("device_object"));

  m.def("vector_dot_product", &pysycl::Vector_Dot_Product, R"delim(
    Description
      Performs a vector dot product on two python lists and returns the sum.

    Parameters
      vector_a : list[float]
        The first vector for dot product.

      vector_b : list[float]
        The second vector for dot product.

      device : device_object
        The device to target in the vector element multiplication.

    Returns
      float
        The vector dot product.

    Examples
      Copy
      ----
      >>> from pysycl import device
      >>> from pysycl import vector
      >>> gpu_queue = device.device_select(0, 0)
      >>> vector_a = [1.0, 2.0, 3.0]
      >>> vector_b = [4.0, 5.0, 6.0]
      >>> vector.vector_dot_product(a, b, gpu_queue)
      32.0
  )delim",
  py::arg("vector_a"),
  py::arg("vector_b"),
  py::arg("device_object"));

  /////////////////////////////////////////////////////////////////////

  py::class_<pysycl::Vector_Object>(m, "vector_object", R"delim(
    Description
      This is a class for creating and manipulating vectors in PySYCL.
    )delim")
    .def(py::init<int, pysycl::Device_Object>(), R"delim(
      Default Constructor
        Constuctor that creates a PySYCL vector object.

      Constructor Parameters
        N: int
          The length of the vector.
        Device_Object: device_object
          The device to target when manipulating the vector object.

      Example
        Copy
        ----
        >>> from pysycl import vector_object
        >>> vector = vector_object.vector_object(3000, 0, 0)
      )delim",
      py::arg("N"),
      py::arg("device_object"))
    .def("set_data", &pysycl::Vector_Object::set_data, R"delim(
      Description
        This function sets the data of the vector.

      Parameters
        data_in: list[float]
          The data to be set to the vector.

      Example
        Copy
        ----
        >>> from pysycl import vector_object
        >>> vector = vector_object.vector_object(3000, 0, 0)
        >>> vector.set_data([1.0, 2.0, 3.0])
      )delim")
    .def("reset_data", &pysycl::Vector_Object::reset_data, R"delim(
      Description
        This function resets the data of the vector to zero.

      Example
        >>> from pysycl import vector_object
        >>> vector = vector_object.vector_object(3000, 0, 0)
        >>> vector.set_data([1.0, 2.0, 3.0])
        >>> vector.reset_data()
        >>> vector.get_data()
        [0.0, 0.0, 0.0]
      )delim")
    .def("get_data", &pysycl::Vector_Object::get_data, R"delim(
      Description
        This function gets the data of the vector.

      Returns
        list[float]
          The data of the vector.

      Example
        Copy
        ----
        >>> from pysycl import vector_object
        >>> vector = vector_object.vector_object(3000, 0, 0)
        >>> vector.set_data([1.0, 2.0, 3.0])
        >>> vector.get_data()
        [1.0, 2.0, 3.0]
      )delim")
    .def("add_vector", &pysycl::Vector_Object::add_vector, R"delim(
      Description
        This function adds two vectors together.

      Parameters
        vector_b: list[float]
          The vector to be added to the vector object calling the function.

      Example
        Copy
        ----
        >>> from pysycl import vector_object
        >>> vector_a = vector_object.vector_object(3000, 0, 0)
        >>> vector_a.set_data([1.0, 2.0, 3.0])
        >>> vector_b = [4.0, 5.0, 6.0]
        >>> vector_a.add_vector(vector_b)
        >>> vector_a.get_data()
        [5.0, 7.0, 9.0]
      )delim")
    .def("add_constant", &pysycl::Vector_Object::add_constant, R"delim(
      Description
        This function adds two vectors together.

      Parameters
        C: double
          The constant to be added to the vector object calling the function.

      Example
        Copy
        ----
        >>> from pysycl import vector_object
        >>> vector_a = vector_object.vector_object(3000, 0, 0)
        >>> vector_a.set_data([1.0, 2.0, 3.0])
        >>> C = 4.0
        >>> vector_a.add_constant(C)
        >>> vector_a.get_data()
        [5.0, 6.0, 7.0]
      )delim")
    .def("subtract_vector", &pysycl::Vector_Object::subtract_vector, R"delim(
      Description
        This function subtracts two vectors.

      Parameters
        vector_b: list[float]
          The vector to be subtracted from the vector object calling the function.

      Example
        Copy
        ----
        >>> from pysycl import vector_object
        >>> vector_a = vector_object.vector_object(3000, 0, 0)
        >>> vector_a.set_data([1.0, 2.0, 3.0])
        >>> vector_b = [4.0, 5.0, 6.0]
        >>> vector_a.subtract_vector(vector_b)
        >>> vector_a.get_data()
        [-3.0, -3.0, -3.0]
      )delim")
    .def("subtract_constant", &pysycl::Vector_Object::subtract_constant, R"delim(
      Description
        This function subtracts a constant from a vector.

      Parameters
        C: double
          The constant to be subtracted from the vector object calling the function.

      Example
        Copy
        ----
        >>> from pysycl import vector_object
        >>> vector_a = vector_object.vector_object(3000, 0, 0)
        >>> vector_a.set_data([1.0, 2.0, 3.0])
        >>> C = 4.0
        >>> vector_a.subtract_constant(C)
        >>> vector_a.get_data()
        [-3.0, -2.0, -1.0]
      )delim")
    .def("multiply_vector", &pysycl::Vector_Object::multiply_vector, R"delim(
      Description
        This function multiplies two vectors together.

      Parameters
        vector_b: list[float]
          The vector to be multiplied with the vector object calling the function.

      Example
        Copy
        ----
        >>> from pysycl import vector_object
        >>> vector_a = vector_object.vector_object(3000, 0, 0)
        >>> vector_a.set_data([1.0, 2.0, 3.0])
        >>> vector_b = [4.0, 5.0, 6.0]
        >>> vector_a.multiply_vector(vector_b)
        >>> vector_a.get_data()
        [4.0, 10.0, 18.0]
      )delim")
    .def("multiply_constant", &pysycl::Vector_Object::multiply_constant, R"delim(
      Description
        This function multiplies a vector by a constant.

      Parameters
        C: double
          The constant to be multiplied with the vector object calling the function.

      Example
        Copy
        ----
        >>> from pysycl import vector_object
        >>> vector_a = vector_object.vector_object(3000, 0, 0)
        >>> vector_a.set_data([1.0, 2.0, 3.0])
        >>> C = 4.0
        >>> vector_a.multiply_constant(C)
        >>> vector_a.get_data()
        [4.0, 8.0, 12.0]
      )delim")
    .def("divide_vector", &pysycl::Vector_Object::divide_vector, R"delim(
      Description
        This function divides two vectors.

      Parameters
        vector_b: list[float]
          The vector to be divided from the vector object calling the function.

      Example
        Copy
        ----
        >>> from pysycl import vector_object
        >>> vector_a = vector_object.vector_object(3000, 0, 0)
        >>> vector_a.set_data([1.0, 2.0, 3.0])
        >>> vector_b = [4.0, 5.0, 6.0]
        >>> vector_a.divide_vector(vector_b)
        >>> vector_a.get_data()
        [0.25, 0.4, 0.5]
      )delim")
    .def("divide_constant", &pysycl::Vector_Object::divide_constant, R"delim(
      Description
        This function divides a vector by a constant.

      Parameters
        C: double
          The constant to be divided from the vector object calling the function.

      Example
        Copy
        ----
        >>> from pysycl import vector_object
        >>> vector_a = vector_object.vector_object(3000, 0, 0)
        >>> vector_a.set_data([1.0, 2.0, 3.0])
        >>> C = 4.0
        >>> vector_a.divide_constant(C)
        >>> vector_a.get_data()
        [0.25, 0.5, 0.75]
      )delim");
}

#endif // #ifndef VECTOR_PYBIND_MODULE_H
