//  :copyright: (c) 2017 Alex Huszagh.
//  :license: FreeBSD, see LICENSE.md for more details.
/**
 *  Generic utilities.
 */

#pragma once

#include <stdexcept>
#include <string>
#include <type_traits>
#include <xlsxwriter/common.h>


namespace xlsxwriter
{
// OBJECTS
// -------

class LxwError: public std::exception
{
protected:
    const std::string &message;

public:
    LxwError(const lxw_error code);
    virtual const char * what() const throw();
};

// MACROS
// ------

#define LXW_CHECK(EX)                                                   \
    {                                                                   \
        lxw_error code = (EX);                                          \
        if (code != LXW_NO_ERROR) {                                     \
            throw LxwError(code);                                       \
        }                                                               \
    }

// FUNCTIONS
// ---------


/** \brief Convert enum to underlying type.
 */
template <typename Enum>
auto FROM_ENUM(const Enum value)
    -> typename std::underlying_type<Enum>::type
{
    return static_cast<typename std::underlying_type<Enum>::type>(value);
}

}   /* xlsxwriter */
