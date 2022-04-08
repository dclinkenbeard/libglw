//
// Created by Garrett on 9/19/21.
//

#include "exception.hpp"

namespace glw {

    // Exception for out of bounds
out_of_bounds_ex::out_of_bounds_ex(const std::string& msg)
{
    this->msg = msg;
}

//destructor for out of bounds exception
out_of_bounds_ex::~out_of_bounds_ex()
        = default;

//exception for trying to divide by 0
div_by_zero_ex::div_by_zero_ex(const std::string& msg)
{
    this->msg = msg;
}

//destructor for exception above
div_by_zero_ex::~div_by_zero_ex()
        = default;

//exception for failure in viewport
viewport_ex::viewport_ex(const std::string& msg)
{
    this->msg = msg;
}

//destructor for exception above
viewport_ex::~viewport_ex()
        = default;

//loading exception
gl_load_ex::gl_load_ex(const std::string &msg)
{
    this->msg = msg;
}

//destructor for loading exception
gl_load_ex::~gl_load_ex()
        = default;

//exception for app
app_ex::app_ex(const std::string &msg)
{
    this->msg = msg;
}

//destructor for app exception
app_ex::~app_ex()
        = default;

};
