#ifndef _CPP_LOAD_JPEG_H_
#define _CPP_LOAD_JPEG_H_

#include "../export.h"
#include <dlib/image_io.h>
#include "../shared.h"
#include "../template.h"

using namespace dlib;
using namespace std;

#pragma region template

#define load_jpeg_template(__TYPE__, error, type, ...) \
dlib::load_jpeg(*((array2d<__TYPE__>*)image), file_name);

#pragma endregion template

DLLEXPORT int load_jpeg(array2d_type type, void* image, const char* file_name, std::string** error_message)
{
    int error = ERR_OK;

    try
    {
        array2d_template(type,
                         error,
                         load_jpeg_template,
                         image,
                         file_name);
    }
    catch(dlib::image_load_error& e)
    {
        error = ERR_GENERAL_IMAGE_LOAD;
        *error_message = new std::string(e.what());
    }

    return error;
}

#endif