//  :copyright: (c) 2017 Alex Huszagh.
//  :license: FreeBSD, see LICENSE.md for more details.
/**
 *  C++ bindings for libxlsxwriter worksheets.
 */

#include "worksheet.hpp"


namespace xlsxwriter
{
// OBJECTS
// -------


Worksheet::Worksheet(lxw_worksheet *ptr):
    ptr(ptr)
{}


Worksheet::Worksheet(Worksheet &&other):
    ptr(other.ptr)
{
    other.ptr = nullptr;
}


Worksheet & Worksheet::operator=(Worksheet &&other)
{
    ptr = other.ptr;
    other.ptr = nullptr;
}

}   /* xlsxwriter */
