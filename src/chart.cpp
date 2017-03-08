//  :copyright: (c) 2017 Alex Huszagh.
//  :license: FreeBSD, see LICENSE.md for more details.
/**
 *  C++ bindings for libxlsxwriter charts.
 */

#include "chart.hpp"

#include <cassert>


namespace xlsxwriter
{
// OBJECTS
// -------


ChartSeries::ChartSeries(lxw_chart_series *ptr):
    ptr(ptr)
{}


void ChartSeries::set_categories(const std::string &sheetname,
    const Row first_row,
    const Column first_col,
    const Row last_row,
    const Column last_col)
{
    assert(ptr && "Chart cannot be null.");
    chart_series_set_categories(ptr, sheetname.data(), first_row, first_col, last_row, last_col);
}


void ChartSeries::set_values(const std::string &sheetname,
    const Row first_row,
    const Column first_col,
    const Row last_row,
    const Column last_col)
{
    assert(ptr && "Chart cannot be null.");
    chart_series_set_values(ptr, sheetname.data(), first_row, first_col, last_row, last_col);
}


void ChartSeries::set_name(const std::string &name)
{
    assert(ptr && "Chart cannot be null.");
    chart_series_set_name(ptr, name.data());
}


Chart::Chart(lxw_chart *ptr):
    ptr(ptr)
{}


ChartSeries Chart::add_series(const std::string &categories,
    const std::string &values)
{
    assert(ptr && "Chart cannot be null.");
    const char *categories_ = categories.empty() ? nullptr : categories.data();
    const char *values_ = values.empty() ? nullptr : values.data();
    chart_add_series(ptr, categories_, values_);
}

}   /* xlsxwriter */
