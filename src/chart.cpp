//  :copyright: (c) 2017 Alex Huszagh.
//  :license: FreeBSD, see LICENSE.md for more details.
/**
 *  C++ bindings for libxlsxwriter charts.
 */

#include "chart.hpp"
#include "utility.hpp"

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


void ChartSeries::set_name_range(const std::string &name,
    const Row row,
    const Column col)
{
    assert(ptr && "Chart cannot be null.");
    chart_series_set_name_range(ptr, name.data(), row, col);
}


void ChartSeries::invert_if_negative()
{
    assert(ptr && "Chart cannot be null.");
    chart_series_set_invert_if_negative(ptr);
}


void ChartSeries::set_marker_type(const MarkerType type)
{
    assert(ptr && "Chart cannot be null.");
    chart_series_set_marker_type(ptr, FROM_ENUM(type));
}


void ChartSeries::set_marker_size(const uint8_t size)
{
    assert(ptr && "Chart cannot be null.");
    chart_series_set_marker_size(ptr, size);
}


void ChartSeries::set_smooth(const bool smooth)
{
    assert(ptr && "Chart cannot be null.");
    chart_series_set_smooth(ptr, smooth);
}


void ChartSeries::set_labels()
{
    assert(ptr && "Chart cannot be null.");
    chart_series_set_labels(ptr);
}


void ChartSeries::set_labels_options(const bool show_name,
    const bool show_category,
    const bool show_value)
{
    assert(ptr && "Chart cannot be null.");
    chart_series_set_labels_options(ptr, show_name, show_category, show_value);
}


void ChartSeries::set_labels_separator(const LabelSeparators separator)
{
    assert(ptr && "Chart cannot be null.");
    chart_series_set_labels_separator(ptr, FROM_ENUM(separator));
}


void ChartSeries::set_labels_position(const ChartLabelPosition position)
{
    assert(ptr && "Chart cannot be null.");
    chart_series_set_labels_position(ptr, FROM_ENUM(position));
}


void ChartSeries::set_labels_leader_line()
{
    assert(ptr && "Chart cannot be null.");
    chart_series_set_labels_leader_line(ptr);
}


void ChartSeries::set_labels_legend()
{
    assert(ptr && "Chart cannot be null.");
    chart_series_set_labels_legend(ptr);
}


void ChartSeries::set_labels_percentage()
{
    assert(ptr && "Chart cannot be null.");
    chart_series_set_labels_percentage(ptr);
}


void ChartSeries::set_labels_num_format(const std::string &num_format)
{
    assert(ptr && "Chart cannot be null.");
    chart_series_set_labels_num_format(ptr, num_format.data());
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
    return ChartSeries(chart_add_series(ptr, categories_, values_));
}

}   /* xlsxwriter */
