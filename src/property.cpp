//  :copyright: (c) 2017 Alex Huszagh.
//  :license: FreeBSD, see LICENSE.md for more details.
/**
 *  C++ bindings for libxlsxwriter properties.
 */

#include "property.hpp"


namespace xlsxwriter
{
// OBJECTS
// -------


Properties::Properties(lxw_doc_properties *ptr):
    ptr(ptr)
{}


Properties::Properties(Properties &&other):
    ptr(other.ptr)
{
    other.ptr = nullptr;
}


Properties & Properties::operator=(Properties &&other)
{
    ptr = other.ptr;
    other.ptr = nullptr;
}

}   /* xlsxwriter */
