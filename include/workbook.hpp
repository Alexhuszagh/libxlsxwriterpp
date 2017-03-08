//  :copyright: (c) 2017 Alex Huszagh.
//  :license: FreeBSD, see LICENSE.md for more details.
/**
 *  C++ bindings for libxlsxwriter workbooks.
 */

#pragma once

#include "xlsxwriter/workbook.h"

#include <string>


namespace xlsxwriter
{
// OBJECTS
// -------


class Options
{
protected:
    lxw_workbook_options *ptr = nullptr;
    friend class Workbook;

public:
    Options() = default;
    Options(const Options&) = default;
    Options & operator=(const Options&) = default;
    Options(Options &&other);
    Options & operator=(Options &&other);

    ~Options();
    Options(const bool constant_memory);
    Options(const std::string &tmpdir);
    Options(const bool constant_memory,
        const std::string &tmpdir);
};


class Workbook
{
protected:
    lxw_workbook *ptr = nullptr;

public:
    Workbook() = delete;
    Workbook(const Workbook&) = delete;
    Workbook & operator=(const Workbook&) = delete;
    Workbook(Workbook &&other);
    Workbook & operator=(Workbook &&other);

    ~Workbook();
    Workbook(const std::string &filename,
        const Options &options = Options());
};

}   /* xlsxwriter */
