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


void ChartSeries::set_trendline(const TrendlineType type,
    const uint8_t value)
{
    assert(ptr && "Chart cannot be null.");
    chart_series_set_trendline(ptr, FROM_ENUM(type), value);
}


void ChartSeries::set_trendline_forecast(const double forward,
    const double backward)
{
    assert(ptr && "Chart cannot be null.");
    chart_series_set_trendline_forecast(ptr, forward, backward);
}


void ChartSeries::set_trendline_equation()
{
    assert(ptr && "Chart cannot be null.");
    chart_series_set_trendline_equation(ptr);
}


void ChartSeries::set_trendline_r_squared()
{
    assert(ptr && "Chart cannot be null.");
    chart_series_set_trendline_r_squared(ptr);
}


void ChartSeries::set_trendline_intercept(const double intercept)
{
    assert(ptr && "Chart cannot be null.");
    chart_series_set_trendline_intercept(ptr, intercept);
}


void ChartSeries::set_trendline_name(const std::string &name)
{
    assert(ptr && "Chart cannot be null.");
    chart_series_set_trendline_name(ptr, name.data());
}


ErrorBars::ErrorBars(lxw_series_error_bars *ptr):
    ptr(ptr)
{}


void ErrorBars::set_error_bars(const ErrorBarType type,
    const double value)
{
    assert(ptr && "Chart cannot be null.");
    chart_series_set_error_bars(ptr, FROM_ENUM(type), value);
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


void Chart::set_name(const std::string &name)
{
    assert(ptr && "Chart cannot be null.");
    chart_title_set_name(ptr, name.data());
}


void Chart::set_name_range(const std::string &name,
    const Row row,
    const Column col)
{
    assert(ptr && "Chart cannot be null.");
    chart_title_set_name_range(ptr, name.data(), row, col);
}


void Chart::title_off()
{
    assert(ptr && "Chart cannot be null.");
    chart_title_off(ptr);
}


void Chart::set_legend_position(const LegendPosition position)
{
    assert(ptr && "Chart cannot be null.");
    chart_legend_set_position(ptr, FROM_ENUM(position));
}


void Chart::set_style(const uint8_t style)
{
    assert(ptr && "Chart cannot be null.");
    chart_set_style(ptr, FROM_ENUM(position));
}


void Chart::set_table()
{
    assert(ptr && "Chart cannot be null.");
    chart_set_table(ptr);
}


void Chart::set_table_grid(const bool horizontal,
    const bool vertical,
    const bool outline,
    const bool legend_keys)
{
    assert(ptr && "Chart cannot be null.");
    chart_set_table_grid(ptr, horizontal, vertical, outline, legend_keys);
}


void Chart::set_up_down_bars()
{
    assert(ptr && "Chart cannot be null.");
    chart_set_up_down_bars(ptr);
}

}   /* xlsxwriter */
