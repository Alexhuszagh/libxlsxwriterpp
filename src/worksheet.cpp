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


void Worksheet::write(const Row row,
    const Column col,
    const std::string &url,
    const Format &format,
    const std::string &string,
    const std::string &tooltip)
{
    write_url(row, col, url, format, string, tooltip);
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


void Worksheet::write(const Row row,
    const Column col,
    const std::string &formula,
    const Format &format,
    const double result)
{
    write_formula(row, col, formula, format);
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

}   /* xlsxwriter */
