//  :copyright: (c) 2017 Alex Huszagh.
//  :license: FreeBSD, see LICENSE.md for more details.
/**
 *  C++ bindings for libxlsxwriter charts.
 */

#include "chart.hpp"


namespace xlsxwriter
{
// OBJECTS
// -------


Chart::Chart(lxw_chart *ptr):
    ptr(ptr)
{}


Chart::Chart(Chart &&other):
    ptr(other.ptr)
{
    other.ptr = nullptr;
}


Chart & Chart::operator=(Chart &&other)
{
    ptr = other.ptr;
    other.ptr = nullptr;
}

}   /* xlsxwriter */
