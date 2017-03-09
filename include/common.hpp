//  :copyright: (c) 2017 Alex Huszagh.
//  :license: FreeBSD, see LICENSE.md for more details.
/**
 *  C++ bindings for common libxlsxwriter functions.
 */

#pragma once

#include <cstdint>
#include <vector>
#include <xlsxwriter/common.h>


namespace xlsxwriter
{
// OBJECTS
// -------

typedef lxw_row_t Row;
typedef lxw_col_t Column;
typedef lxw_datetime Datetime;

typedef std::vector<Row> Rows;
typedef std::vector<Column> Columns;

}   /* xlsxwriter */
