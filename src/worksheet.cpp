//  :copyright: (c) 2017 Alex Huszagh.
//  :license: FreeBSD, see LICENSE.md for more details.
/**
 *  C++ bindings for libxlsxwriter worksheets.
 */

#include "utility.hpp"
#include "worksheet.hpp"

#include <cassert>


namespace xlsxwriter
{
// OBJECTS
// -------


Worksheet::Worksheet(lxw_worksheet *ptr):
    ptr(ptr)
{}


void Worksheet::write(const Row row,
    const Column col,
    const double number,
    const Format &format)
{
    write_number(row, col, number, format);
}


void Worksheet::write_number(const Row row,
    const Column col,
    const double number,
    const Format &format)
{
    assert(ptr && "Worksheet cannot be null.");
    LXW_CHECK(worksheet_write_number(ptr, row, col, number, format.ptr))
}


void Worksheet::write(const Row row,
    const Column col,
    const std::nullptr_t nullp,
    const Format &format)
{
    write_blank(row, col, nullp, format);
}


void Worksheet::write_blank(const Row row,
    const Column col,
    const std::nullptr_t nullp,
    const Format &format)
{
    assert(ptr && "Worksheet cannot be null.");
    LXW_CHECK(worksheet_write_blank(ptr, row, col, format.ptr));
}


void Worksheet::write(const Row row,
    const Column col,
    const std::string &string,
    const Format &format)
{
    write_string(row, col, string, format);
}


void Worksheet::write_string(const Row row,
    const Column col,
    const std::string &string,
    const Format &format)
{
    assert(ptr && "Worksheet cannot be null.");
    LXW_CHECK(worksheet_write_string(ptr, row, col, string.data(), format.ptr))
}


void Worksheet::write(const Row row,
    const Column col,
    const bool value,
    const Format &format)
{
    write_boolean(row, col, value, format);
}


void Worksheet::write_boolean(const Row row,
    const Column col,
    const bool value,
    const Format &format)
{
    assert(ptr && "Worksheet cannot be null.");
    LXW_CHECK(worksheet_write_boolean(ptr, row, col, value, format.ptr))
}


void Worksheet::write(const Row row,
    const Column col,
    const Datetime &date,
    const Format &format)
{
    write_datetime(row, col, date, format);
}


void Worksheet::write_datetime(const Row row,
    const Column col,
    const Datetime &date,
    const Format &format)
{
    assert(ptr && "Worksheet cannot be null.");
    LXW_CHECK(worksheet_write_datetime(ptr, row, col, const_cast<Datetime*>(&date), format.ptr))
}


void Worksheet::write_url(const Row row,
    const Column col,
    const std::string &url,
    const Format &format,
    const std::string &string,
    const std::string &tooltip)
{
    assert(ptr && "Worksheet cannot be null.");
    if (string.empty() && tooltip.empty()) {
        LXW_CHECK(worksheet_write_url(ptr, row, col, url.data(), format.ptr));
    } else {
        LXW_CHECK(worksheet_write_url_opt(ptr, row, col, url.data(), format.ptr, string.data(), tooltip.data()));
    }
}


void Worksheet::write_formula(const Row row,
    const Column col,
    const std::string &formula,
    const Format &format,
    const double result)
{
    assert(ptr && "Worksheet cannot be null.");
    LXW_CHECK(worksheet_write_formula_num(ptr, row, col, formula.data(), format.ptr, result))
}


void Worksheet::write_array_formula(const Row first_row,
    const Column first_col,
    const Row last_row,
    const Column last_col,
    const std::string &formula,
    const Format &format,
    const double result)
{
    assert(ptr && "Worksheet cannot be null.");
    LXW_CHECK(worksheet_write_array_formula_num(ptr, first_row, first_col, last_row, last_col, formula.data(), format.ptr, result));
}


void Worksheet::set_row(const Row row,
    const double height,
    const Format &format,
    const RowColOptions &options)
{
    assert(ptr && "Worksheet cannot be null.");
    LXW_CHECK(worksheet_set_row_opt(ptr, row, height, format.ptr, const_cast<RowColOptions*>(&options)));
}


void Worksheet::set_column(const Column first_col,
    const Column last_col,
    const double width,
    const Format &format,
    const RowColOptions &options)
{
    assert(ptr && "Worksheet cannot be null.");
    LXW_CHECK(worksheet_set_column_opt(ptr, first_col, last_col, width, format.ptr, const_cast<RowColOptions*>(&options)));
}


void Worksheet::merge_range(const Row first_row,
    const Column first_col,
    const Row last_row,
    const Column last_col,
    const std::string &string,
    const Format &format)
{
    assert(ptr && "Worksheet cannot be null.");
}


void Worksheet::insert_chart(const Row row,
    const Column col,
    const Chart &chart,
    const ImageOptions &options)
{
    assert(ptr && "Worksheet cannot be null.");
    LXW_CHECK(worksheet_insert_chart_opt(ptr, row, col, chart.ptr, const_cast<ImageOptions*>(&options)));
}


void Worksheet::insert_image(const Row row,
    const Column col,
    const std::string &filename,
    const ImageOptions &options)
{
    assert(ptr && "Worksheet cannot be null.");
    LXW_CHECK(worksheet_insert_image_opt(ptr, row, col, filename.data(), const_cast<ImageOptions*>(&options)));
}


void Worksheet::autofilter(const Row first_row,
    const Column first_col,
    const Row last_row,
    const Column last_col)
{
    assert(ptr && "Worksheet cannot be null.");
    worksheet_autofilter(ptr, first_row, first_col, last_row, last_col);
}


void Worksheet::activate()
{
    assert(ptr && "Worksheet cannot be null.");
    worksheet_activate(ptr);
}


void Worksheet::select()
{
    assert(ptr && "Worksheet cannot be null.");
    worksheet_select(ptr);
}


void Worksheet::hide()
{
    assert(ptr && "Worksheet cannot be null.");
    worksheet_hide(ptr);
}


void Worksheet::set_first_sheet()
{
    worksheet_set_first_sheet(ptr);
}


void Worksheet::freeze_panes(const Row row,
    const Column col)
{
    freeze_panes(row, col, row, col);
}


void Worksheet::freeze_panes(const Row first_row,
    const Column first_col,
    const Row top_row,
    const Column top_col)
{
    assert(ptr && "Worksheet cannot be null.");
    worksheet_freeze_panes_opt(ptr, first_row, first_col, top_row, top_col, 0);
}


void Worksheet::split_panes(const Row row,
    const Column col)
{
    split_panes(row, col, row, col);
}


void Worksheet::split_panes(const Row first_row,
    const Column first_col,
    const Row top_row,
    const Column top_col)
{
    assert(ptr && "Worksheet cannot be null.");
    worksheet_split_panes_opt(ptr, first_row, first_col, top_row, top_col);
}


void Worksheet::set_selection(const Row first_row,
    const Column first_col,
    const Row last_row,
    const Column last_col)
{
    assert(ptr && "Worksheet cannot be null.");
    worksheet_set_selection(ptr, first_row, first_col, last_row, last_col);
}


void Worksheet::set_landscape()
{
    assert(ptr && "Worksheet cannot be null.");
    worksheet_set_landscape(ptr);
}


void Worksheet::set_portrait()
{
    assert(ptr && "Worksheet cannot be null.");
    worksheet_set_portrait(ptr);
}


void Worksheet::set_page_view()
{
    assert(ptr && "Worksheet cannot be null.");
    worksheet_set_page_view(ptr);
}


void Worksheet::set_paper(const PaperType type)
{
    assert(ptr && "Worksheet cannot be null.");
    worksheet_set_paper(ptr, FROM_ENUM(type));
}


void Worksheet::set_margins(const double left,
    const double right,
    const double top,
    const double bottom)
{
    assert(ptr && "Worksheet cannot be null.");
    worksheet_set_margins(ptr, left, right, top, bottom);
}


void Worksheet::set_header(const std::string &string,
    const double margin)
{
    assert(ptr && "Worksheet cannot be null.");
    lxw_header_footer_options options = {margin};
    worksheet_set_header_opt(ptr, string.data(), &options);
}


void Worksheet::set_footer(const std::string &string,
    const double margin)
{
    assert(ptr && "Worksheet cannot be null.");
    lxw_header_footer_options options = {margin};
    worksheet_set_footer_opt(ptr, string.data(), &options);
}


void Worksheet::set_h_pagebreaks(Rows &rows)
{
    assert(ptr && "Worksheet cannot be null.");
    if (rows.empty() || rows.back() != 0) {
        rows.emplace_back(0);
    }
    LXW_CHECK(worksheet_set_h_pagebreaks(ptr, rows.data()));
}


void Worksheet::set_h_pagebreaks(Rows &&rows)
{
    set_h_pagebreaks(rows);
}


void Worksheet::set_v_pagebreaks(Columns &columns)
{
    assert(ptr && "Worksheet cannot be null.");
    if (columns.empty() || columns.back() != 0) {
        columns.emplace_back(0);
    }
    LXW_CHECK(worksheet_set_v_pagebreaks(ptr, columns.data()));
}


void Worksheet::set_v_pagebreaks(Columns &&columns)
{
    set_v_pagebreaks(columns);
}


void Worksheet::print_across()
{
    assert(ptr && "Worksheet cannot be null.");
    worksheet_print_across(ptr);
}


void Worksheet::set_zoom(const uint16_t scale)
{
    assert(ptr && "Worksheet cannot be null.");
    worksheet_set_zoom(ptr, scale);
}


void Worksheet::gridlines(const Gridlines options)
{
    assert(ptr && "Worksheet cannot be null.");
    worksheet_gridlines(ptr, FROM_ENUM(options));
}


void Worksheet::center_horizontally()
{
    assert(ptr && "Worksheet cannot be null.");
    worksheet_center_horizontally(ptr);
}


void Worksheet::center_vertically()
{
    assert(ptr && "Worksheet cannot be null.");
    worksheet_center_vertically(ptr);
}


void Worksheet::print_row_col_headers()
{
    assert(ptr && "Worksheet cannot be null.");
    worksheet_print_row_col_headers(ptr);
}


void Worksheet::repeat_rows(const Row first_row,
    const Row last_row)
{
    assert(ptr && "Worksheet cannot be null.");
    LXW_CHECK(worksheet_repeat_rows(ptr, first_row, last_row));
}


void Worksheet::repeat_columns(const Column first_col,
    const Column last_col)
{
    assert(ptr && "Worksheet cannot be null.");
    LXW_CHECK(worksheet_repeat_columns(ptr, first_col, last_col));
}


void Worksheet::print_area(const Row first_row,
    const Column first_col,
    const Row last_row,
    const Column last_col)
{
    assert(ptr && "Worksheet cannot be null.");
    LXW_CHECK(worksheet_print_area(ptr, first_row, first_col, last_row, last_col));
}


void Worksheet::fit_to_pages(const uint16_t width,
    const uint16_t height)
{
    assert(ptr && "Worksheet cannot be null.");
    worksheet_fit_to_pages(ptr, width, height);
}


void Worksheet::set_start_page(const uint16_t start_page)
{
    assert(ptr && "Worksheet cannot be null.");
    worksheet_set_start_page(ptr, start_page);
}


void Worksheet::set_print_scale(const uint16_t scale)
{
    assert(ptr && "Worksheet cannot be null.");
    worksheet_set_print_scale(ptr, scale);
}


void Worksheet::right_to_left()
{
    assert(ptr && "Worksheet cannot be null.");
    worksheet_right_to_left(ptr);
}


void Worksheet::hide_zero()
{
    assert(ptr && "Worksheet cannot be null.");
    worksheet_hide_zero(ptr);
}


void Worksheet::set_tab_color(const Color color)
{
    assert(ptr && "Worksheet cannot be null.");
    worksheet_set_tab_color(ptr, color);
}


void Worksheet::protect(const std::string &password,
    const Protection &options)
{
    assert(ptr && "Worksheet cannot be null.");
    worksheet_protect(ptr, password.data(), const_cast<Protection*>(&options));
}


void Worksheet::set_default_row(const double height,
    const bool hide_unused_rows)
{
    assert(ptr && "Worksheet cannot be null.");
    worksheet_set_default_row(ptr, height, hide_unused_rows);
}

}   /* xlsxwriter */
