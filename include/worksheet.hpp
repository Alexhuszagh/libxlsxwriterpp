//  :copyright: (c) 2017 Alex Huszagh.
//  :license: FreeBSD, see LICENSE.md for more details.
/**
 *  C++ bindings for libxlsxwriter worksheets.
 */

#pragma once

#include "common.hpp"
#include "format.hpp"

#include <deque>
#include <string>
#include <xlsxwriter/worksheet.h>


namespace xlsxwriter
{
// OBJECTS
// -------

typedef lxw_row_t Row;
typedef lxw_col_t Column;


class Worksheet
{
protected:
    lxw_worksheet *ptr = nullptr;

    friend class Workbook;

    Worksheet(lxw_worksheet *ptr);

public:
    Worksheet() = default;
    Worksheet(const Worksheet&) = default;
    Worksheet & operator=(const Worksheet&) = default;
    Worksheet(Worksheet &&other) = default;
    Worksheet & operator=(Worksheet &&other) = default;

    // WRITE

    // NUMBER
    void write(const Row row,
        const Column col,
        const double number,
        const Format &format = Format());
    void write_number(const Row row,
        const Column col,
        const double number,
        const Format &format = Format());

    // BLANK
    void write(const Row row,
        const Column col,
        const std::nullptr_t nullp,
        const Format &format = Format());
    void write_blank(const Row row,
        const Column col,
        const std::nullptr_t nullp,
        const Format &format = Format());

    // STRING
    void write(const Row row,
        const Column col,
        const std::string &string,
        const Format &format = Format());
    void write_string(const Row row,
        const Column col,
        const std::string &string,
        const Format &format = Format());

    // BOOLEAN
    void write(const Row row,
        const Column col,
        const bool value,
        const Format &format = Format());
    void write_boolean(const Row row,
        const Column col,
        const bool value,
        const Format &format = Format());

    // DATETIME
    void write(const Row row,
        const Column col,
        const Datetime &date,
        const Format &format = Format());
    void write_datetime(const Row row,
        const Column col,
        const Datetime &date,
        const Format &format = Format());

    // URL
    void write(const Row row,
        const Column col,
        const std::string &url,
        const Format &format = Format(),
        const std::string &string = "",
        const std::string &tooltip = "");
    void write_url(const Row row,
        const Column col,
        const std::string &url,
        const Format &format = Format(),
        const std::string &string = "",
        const std::string &tooltip = "");

    // FORMULA
    void write(const Row row,
        const Column col,
        const std::string &formula,
        const Format &format = Format(),
        const double result = 0);
    void write_formula(const Row row,
        const Column col,
        const std::string &formula,
        const Format &format = Format(),
        const double result = 0);

//    worksheet_set_row
//    worksheet_set_column
//    worksheet_write_url
//    write_formula();
//    worksheet_write_array_formula

//    worksheet_merge_range
//    worksheet_merge_range
//    worksheet_insert_chart
//    worksheet_insert_image
//    worksheet_autofilter
//    worksheet_activate
//    worksheet_select
//    worksheet_hide
//    worksheet_set_first_sheet
//    worksheet_freeze_panes
//    worksheet_split_panes
//    worksheet_set_selection
//    worksheet_set_landscape
//    worksheet_set_portrait
//    worksheet_set_page_view
//    worksheet_set_paper
//    worksheet_set_margins
//    worksheet_set_header
//    worksheet_set_footer
//    worksheet_set_h_pagebreaks
//    worksheet_set_v_pagebreaks
//    worksheet_print_across
//    worksheet_set_zoom
//    worksheet_gridlines
//    worksheet_center_horizontally
//    worksheet_center_vertically
//    worksheet_print_row_col_headers
//    worksheet_repeat_rows
//    worksheet_repeat_columns
//    worksheet_print_area
//    worksheet_fit_to_pages
//    worksheet_set_start_page
//    worksheet_set_print_scale
//    worksheet_right_to_left
//    worksheet_hide_zero
//    worksheet_set_tab_color
//    worksheet_protect
//    worksheet_set_default_row
};

typedef std::deque<Worksheet> Worksheets;

}   /* xlsxwriter */
