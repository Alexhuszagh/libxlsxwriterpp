//  :copyright: (c) 2017 Alex Huszagh.
//  :license: FreeBSD, see LICENSE.md for more details.
/**
 *  C++ bindings for libxlsxwriter worksheets.
 */

#pragma once

#include <cstdio>
#include <deque>
#include <xlsxwriter/worksheet.h>


namespace xlsxwriter
{
// OBJECTS
// -------


class Worksheet
{
protected:
    lxw_worksheet *ptr = nullptr;

    friend class Workbook;

    Worksheet(lxw_worksheet *ptr);

public:
    Worksheet() = delete;
    Worksheet(const Worksheet&) = delete;
    Worksheet & operator=(const Worksheet&) = delete;
    Worksheet(Worksheet &&other);
    Worksheet & operator=(Worksheet &&other);

    //
};

typedef std::deque<Worksheet> Worksheets;

}   /* xlsxwriter */
