//  :copyright: (c) 2017 Alex Huszagh.
//  :license: FreeBSD, see LICENSE.md for more details.
/**
 *  C++ bindings for libxlsxwriter formatting.
 */

#include "format.hpp"


namespace xlsxwriter
{
// OBJECTS
// -------


Format::Format(lxw_format *ptr):
    ptr(ptr)
{}

}   /* xlsxwriter */
