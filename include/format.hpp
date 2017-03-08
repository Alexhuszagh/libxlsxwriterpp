//  :copyright: (c) 2017 Alex Huszagh.
//  :license: FreeBSD, see LICENSE.md for more details.
/**
 *  C++ bindings for libxlsxwriter formatting.
 */

#pragma once

#include <cstdio>
#include <xlsxwriter/format.h>


namespace xlsxwriter
{
// OBJECTS
// -------


class Format
{
protected:
    lxw_format *ptr = nullptr;

    friend class Workbook;
    friend class Worksheet;

    Format(lxw_format *ptr);

public:
    Format() = default;
    Format(const Format&) = default;
    Format & operator=(const Format&) = default;
    Format(Format &&other);
    Format & operator=(Format &&other);
};

}   /* xlsxwriter */
