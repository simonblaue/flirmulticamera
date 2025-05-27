#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/numpy.h>
#include "flirmulticamera/fcambindings.h"

#include <opencv2/core.hpp>

using namespace flirmulticamera;

namespace py = pybind11;

/** Helper to convert cv::Mat to numpy */
py::array mat_to_numpy(const cv::Mat& mat) {
    py::dtype dtype = py::dtype::of<uint8_t>();

    std::vector<std::size_t> shape = {
        static_cast<size_t>(mat.rows),
        static_cast<size_t>(mat.cols),
        static_cast<size_t>(mat.channels())
    };

    std::vector<std::size_t> strides = {
        static_cast<size_t>(mat.step[0]),
        static_cast<size_t>(mat.step[1]),
        static_cast<size_t>(mat.elemSize1())
    };

    return py::array(dtype, shape, strides, mat.data, py::none());
}

PYBIND11_MODULE(pyflircam, m) {
    py::class_<FlirCameraWrapper>(m, "FlirMultiCameraHandler")
        .def(py::init<const std::string&>())
        .def("start", &FlirCameraWrapper::start)
        .def("stop", &FlirCameraWrapper::stop)
        .def("get_images", [](FlirCameraWrapper& self) {
            auto images = self.get_images();
            py::list pyimgs;
            for (const auto& img : images) {
                pyimgs.append(mat_to_numpy(img));
            }
            return pyimgs;
        });
}
