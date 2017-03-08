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

}   /* xlsxwriter */
