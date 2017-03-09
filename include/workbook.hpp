//  :copyright: (c) 2017 Alex Huszagh.
//  :license: FreeBSD, see LICENSE.md for more details.
/**
 *  C++ bindings for libxlsxwriter workbooks.
 */

#pragma once

#include "chart.hpp"
#include "format.hpp"
#include "worksheet.hpp"

#include <xlsxwriter/workbook.h>


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
    Options(const Options&) = delete;
    Options & operator=(const Options&) = delete;
    Options(Options &&other);
    Options & operator=(Options &&other);

    ~Options();
    Options(const bool constant_memory);
    Options(const std::string &tmpdir);
    Options(const bool constant_memory,
        const std::string &tmpdir);
};


typedef lxw_doc_properties Properties;


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

    Worksheet add_worksheet(const std::string &sheetname);
    Format add_format();
    Chart add_chart(const ChartType chart_type);
    void close();

    Worksheets worksheets();
    Worksheet get_worksheet_by_name(const std::string &name);
    void set_properties(const Properties &properties);
    void set_custom_property(const std::string &name,
        const std::string &value);
    void set_custom_property(const std::string &name,
        const double value);
    void set_custom_property(const std::string &name,
        const int32_t value);
    void set_custom_property(const std::string &name,
        const bool value);
    // TODO: set_custom_property(datetime)
    // TODO: workbook_define_name
};

}   /* xlsxwriter */
