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
    assert(ptr && "Chart series cannot be null.");
    chart_series_set_categories(ptr, sheetname.data(), first_row, first_col, last_row, last_col);
}


void ChartSeries::set_values(const std::string &sheetname,
    const Row first_row,
    const Column first_col,
    const Row last_row,
    const Column last_col)
{
    assert(ptr && "Chart series cannot be null.");
    chart_series_set_values(ptr, sheetname.data(), first_row, first_col, last_row, last_col);
}


void ChartSeries::set_name(const std::string &name)
{
    assert(ptr && "Chart series cannot be null.");
    chart_series_set_name(ptr, name.data());
}


void ChartSeries::set_name_range(const std::string &name,
    const Row row,
    const Column col)
{
    assert(ptr && "Chart series cannot be null.");
    chart_series_set_name_range(ptr, name.data(), row, col);
}


void ChartSeries::set_line(const ChartLine &line)
{
    assert(ptr && "Chart series cannot be null.");
    chart_series_set_line(ptr, const_cast<ChartLine*>(&line));
}


void ChartSeries::set_fill(const ChartFill &fill)
{
    assert(ptr && "Chart series cannot be null.");
    chart_series_set_fill(ptr, const_cast<ChartFill*>(&fill));
}


void ChartSeries::invert_if_negative()
{
    assert(ptr && "Chart series cannot be null.");
    chart_series_set_invert_if_negative(ptr);
}


void ChartSeries::set_pattern(const ChartPattern &pattern)
{
    assert(ptr && "Chart series cannot be null.");
    chart_series_set_pattern(ptr, const_cast<ChartPattern*>(&pattern));
}


void ChartSeries::set_marker_type(const MarkerType type)
{
    assert(ptr && "Chart series cannot be null.");
    chart_series_set_marker_type(ptr, FROM_ENUM(type));
}


void ChartSeries::set_marker_size(const uint8_t size)
{
    assert(ptr && "Chart series cannot be null.");
    chart_series_set_marker_size(ptr, size);
}


void ChartSeries::set_marker_line(const ChartLine &line)
{
    assert(ptr && "Chart series cannot be null.");
    chart_series_set_marker_line(ptr, const_cast<ChartLine*>(&line));
}


void ChartSeries::set_marker_fill(const ChartFill &fill)
{
    assert(ptr && "Chart series cannot be null.");
    chart_series_set_marker_fill(ptr, const_cast<ChartFill*>(&fill));
}


void ChartSeries::set_marker_pattern(const ChartPattern &pattern)
{
    assert(ptr && "Chart series cannot be null.");
    chart_series_set_marker_pattern(ptr, const_cast<ChartPattern*>(&pattern));
}


void ChartSeries::set_points(const ChartPoints &points)
{
    assert(ptr && "Chart series cannot be null.");
    auto **buffer = new ChartPoint*[points.size()+1];
    for (size_t i = 0; i < points.size(); ++i) {
        buffer[i] = const_cast<ChartPoint*>(&points[i]);
    }
    buffer[points.size()] = nullptr;
    LXW_CHECK(chart_series_set_points(ptr, buffer));

    delete[] buffer;
}


void ChartSeries::set_smooth(const bool smooth)
{
    assert(ptr && "Chart series cannot be null.");
    chart_series_set_smooth(ptr, smooth);
}


void ChartSeries::set_labels()
{
    assert(ptr && "Chart series cannot be null.");
    chart_series_set_labels(ptr);
}


void ChartSeries::set_labels_options(const bool show_name,
    const bool show_category,
    const bool show_value)
{
    assert(ptr && "Chart series cannot be null.");
    chart_series_set_labels_options(ptr, show_name, show_category, show_value);
}


void ChartSeries::set_labels_separator(const LabelSeparators separator)
{
    assert(ptr && "Chart series cannot be null.");
    chart_series_set_labels_separator(ptr, FROM_ENUM(separator));
}


void ChartSeries::set_labels_position(const ChartLabelPosition position)
{
    assert(ptr && "Chart series cannot be null.");
    chart_series_set_labels_position(ptr, FROM_ENUM(position));
}


void ChartSeries::set_labels_leader_line()
{
    assert(ptr && "Chart series cannot be null.");
    chart_series_set_labels_leader_line(ptr);
}


void ChartSeries::set_labels_legend()
{
    assert(ptr && "Chart series cannot be null.");
    chart_series_set_labels_legend(ptr);
}


void ChartSeries::set_labels_percentage()
{
    assert(ptr && "Chart series cannot be null.");
    chart_series_set_labels_percentage(ptr);
}


void ChartSeries::set_labels_num_format(const std::string &num_format)
{
    assert(ptr && "Chart series cannot be null.");
    chart_series_set_labels_num_format(ptr, num_format.data());
}


void ChartSeries::set_trendline(const TrendlineType type,
    const uint8_t value)
{
    assert(ptr && "Chart series cannot be null.");
    chart_series_set_trendline(ptr, FROM_ENUM(type), value);
}


void ChartSeries::set_labels_font(const ChartFont &font)
{
    assert(ptr && "Chart series cannot be null.");
    chart_series_set_labels_font(ptr, const_cast<ChartFont*>(&font));
}


void ChartSeries::set_trendline_forecast(const double forward,
    const double backward)
{
    assert(ptr && "Chart series cannot be null.");
    chart_series_set_trendline_forecast(ptr, forward, backward);
}


void ChartSeries::set_trendline_equation()
{
    assert(ptr && "Chart series cannot be null.");
    chart_series_set_trendline_equation(ptr);
}


void ChartSeries::set_trendline_r_squared()
{
    assert(ptr && "Chart series cannot be null.");
    chart_series_set_trendline_r_squared(ptr);
}


void ChartSeries::set_trendline_intercept(const double intercept)
{
    assert(ptr && "Chart series cannot be null.");
    chart_series_set_trendline_intercept(ptr, intercept);
}


void ChartSeries::set_trendline_name(const std::string &name)
{
    assert(ptr && "Chart series cannot be null.");
    chart_series_set_trendline_name(ptr, name.data());
}


void ChartSeries::set_trendline_line(const ChartLine &line)
{
    assert(ptr && "Chart series cannot be null.");
    chart_series_set_trendline_line(ptr, const_cast<ChartLine*>(&line));
}


ErrorBars::ErrorBars(lxw_series_error_bars *ptr):
    ptr(ptr)
{}


void ErrorBars::set_error_bars(const ErrorBarType type,
    const double value)
{
    assert(ptr && "Errorbars cannot be null.");
    chart_series_set_error_bars(ptr, FROM_ENUM(type), value);
}


void ErrorBars::set_error_bars_direction(const ErrorBarDirection direction)
{
    assert(ptr && "Errorbars cannot be null.");
    chart_series_set_error_bars_direction(ptr, FROM_ENUM(direction));
}


void ErrorBars::set_error_bars_endcap(const ErrorBarCap endcap)
{
    assert(ptr && "Errorbars cannot be null.");
    chart_series_set_error_bars_endcap(ptr, FROM_ENUM(endcap));
}


void ErrorBars::set_error_bars_line(const ChartLine &line)
{
    assert(ptr && "Errorbars cannot be null.");
    chart_series_set_error_bars_line(ptr, const_cast<ChartLine*>(&line));
}


ChartAxis::ChartAxis(lxw_chart_axis *ptr):
    ptr(ptr)
{}


void ChartAxis::set_name(const std::string &name)
{
    assert(ptr && "ChartAxis cannot be null.");
    chart_axis_set_name(ptr, name.data());
}


void ChartAxis::set_name_range(const std::string &name,
    const Row row,
    const Column col)
{
    assert(ptr && "ChartAxis cannot be null.");
    chart_axis_set_name_range(ptr, name.data(), row, col);
}


void ChartAxis::set_name_font(const ChartFont &font)
{
    assert(ptr && "ChartAxis cannot be null.");
    chart_axis_set_name_font(ptr, const_cast<ChartFont*>(&font));
}


void ChartAxis::set_num_font(const ChartFont &font)
{
    assert(ptr && "ChartAxis cannot be null.");
    chart_axis_set_num_font(ptr, const_cast<ChartFont*>(&font));
}


void ChartAxis::set_num_format(const std::string &num_format)
{
    assert(ptr && "ChartAxis cannot be null.");
    chart_axis_set_num_format(ptr, num_format.data());
}


void ChartAxis::set_line(const ChartLine &line)
{
    assert(ptr && "ChartAxis cannot be null.");
    chart_axis_set_line(ptr, const_cast<ChartLine*>(&line));
}


void ChartAxis::set_fill(const ChartFill &fill)
{
    assert(ptr && "ChartAxis cannot be null.");
    chart_axis_set_fill(ptr, const_cast<ChartFill*>(&fill));
}


void ChartAxis::set_pattern(const ChartPattern &pattern)
{
    assert(ptr && "ChartAxis cannot be null.");
    chart_axis_set_pattern(ptr, const_cast<ChartPattern*>(&pattern));
}


void ChartAxis::set_reverse()
{
    assert(ptr && "ChartAxis cannot be null.");
    chart_axis_set_reverse(ptr);
}


void ChartAxis::set_crossing(const double value)
{
    assert(ptr && "ChartAxis cannot be null.");
    chart_axis_set_crossing(ptr, value);
}


void ChartAxis::set_crossing_max()
{
    assert(ptr && "ChartAxis cannot be null.");
    chart_axis_set_crossing_max(ptr);
}


void ChartAxis::axis_off()
{
    assert(ptr && "ChartAxis cannot be null.");
    chart_axis_off(ptr);
}


void ChartAxis::set_position(const ChartAxisPosition position)
{
    assert(ptr && "ChartAxis cannot be null.");
    chart_axis_set_position(ptr, FROM_ENUM(position));
}


void ChartAxis::set_label_position(const ChartAxisLabelPosition position)
{
    assert(ptr && "ChartAxis cannot be null.");
    chart_axis_set_label_position(ptr, FROM_ENUM(position));
}


void ChartAxis::set_min(const double min)
{
    assert(ptr && "ChartAxis cannot be null.");
    chart_axis_set_min(ptr, min);
}


void ChartAxis::set_max(const double max)
{
    assert(ptr && "ChartAxis cannot be null.");
    chart_axis_set_max(ptr, max);
}


void ChartAxis::set_log_base(const uint16_t log_base)
{
    assert(ptr && "ChartAxis cannot be null.");
    chart_axis_set_log_base(ptr, log_base);
}


void ChartAxis::set_major_tick_mark(const TickMark type)
{
    assert(ptr && "ChartAxis cannot be null.");
    chart_axis_set_major_tick_mark(ptr, FROM_ENUM(type));
}


void ChartAxis::set_minor_tick_mark(const TickMark type)
{
    assert(ptr && "ChartAxis cannot be null.");
    chart_axis_set_minor_tick_mark(ptr, FROM_ENUM(type));
}


void ChartAxis::set_interval_unit(const uint16_t unit)
{
    assert(ptr && "ChartAxis cannot be null.");
    chart_axis_set_interval_unit(ptr, unit);
}


void ChartAxis::set_interval_tick(const uint16_t unit)
{
    assert(ptr && "ChartAxis cannot be null.");
    chart_axis_set_interval_tick(ptr, unit);
}


void ChartAxis::set_major_unit(const double unit)
{
    assert(ptr && "ChartAxis cannot be null.");
    chart_axis_set_major_unit(ptr, unit);
}


void ChartAxis::set_minor_unit(const double unit)
{
    assert(ptr && "ChartAxis cannot be null.");
    chart_axis_set_minor_unit(ptr, unit);
}


void ChartAxis::set_display_units(const DisplayUnits units)
{
    assert(ptr && "ChartAxis cannot be null.");
    chart_axis_set_display_units(ptr, FROM_ENUM(units));
}


void ChartAxis::set_display_units_visible(const bool visible)
{
    assert(ptr && "ChartAxis cannot be null.");
    chart_axis_set_display_units_visible(ptr, visible);
}


void ChartAxis::major_gridlines_set_visible(const bool visible)
{
    assert(ptr && "ChartAxis cannot be null.");
    chart_axis_major_gridlines_set_visible(ptr, visible);
}


void ChartAxis::minor_gridlines_set_visible(const bool visible)
{
    assert(ptr && "ChartAxis cannot be null.");
    chart_axis_minor_gridlines_set_visible(ptr, visible);
}


void ChartAxis::major_gridlines_set_line(const ChartLine &line)
{
    assert(ptr && "ChartAxis cannot be null.");
    chart_axis_major_gridlines_set_line(ptr, const_cast<ChartLine*>(&line));
}


void ChartAxis::minor_gridlines_set_line(const ChartLine &line)
{
    assert(ptr && "ChartAxis cannot be null.");
    chart_axis_minor_gridlines_set_line(ptr, const_cast<ChartLine*>(&line));
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


ChartAxis Chart::x_axis()
{
    assert(ptr && "Chart cannot be null.");
    return ChartAxis(ptr->x_axis);
}


ChartAxis Chart::y_axis()
{
    assert(ptr && "Chart cannot be null.");
    return ChartAxis(ptr->y_axis);
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


void Chart::set_name_font(const ChartFont &font)
{
    assert(ptr && "Chart cannot be null.");
    chart_title_set_name_font(ptr, const_cast<ChartFont*>(&font));
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


void Chart::set_legend_font(const ChartFont &font)
{
    assert(ptr && "Chart cannot be null.");
    chart_legend_set_font(ptr, const_cast<ChartFont*>(&font));
}


void Chart::delete_legend_series(const Series &series)
{
    assert(ptr && "Chart cannot be null.");
    auto *buffer = new int16_t[series.size()+1];
    for (size_t i = 0; i < series.size(); ++i) {
        buffer[i] = series[i];
    }
    buffer[series.size()] = -1;
    LXW_CHECK(chart_legend_delete_series(ptr, buffer));

    delete[] buffer;
}


void Chart::set_chartarea_line(const ChartLine &line)
{
    assert(ptr && "Chart cannot be null.");
    chart_chartarea_set_line(ptr, const_cast<ChartLine*>(&line));
}


void Chart::set_chartarea_fill(const ChartFill &fill)
{
    assert(ptr && "Chart cannot be null.");
    chart_chartarea_set_fill(ptr, const_cast<ChartFill*>(&fill));
}


void Chart::set_chartarea_pattern(const ChartPattern &pattern)
{
    assert(ptr && "Chart cannot be null.");
    chart_chartarea_set_pattern(ptr, const_cast<ChartPattern*>(&pattern));
}


void Chart::set_plotarea_line(const ChartLine &line)
{
    assert(ptr && "Chart cannot be null.");
    chart_plotarea_set_line(ptr, const_cast<ChartLine*>(&line));
}


void Chart::set_plotarea_fill(const ChartFill &fill)
{
    assert(ptr && "Chart cannot be null.");
    chart_plotarea_set_fill(ptr, const_cast<ChartFill*>(&fill));
}


void Chart::set_plotarea_pattern(const ChartPattern &pattern)
{
    assert(ptr && "Chart cannot be null.");
    chart_plotarea_set_pattern(ptr, const_cast<ChartPattern*>(&pattern));
}


void Chart::set_style(const uint8_t style)
{
    assert(ptr && "Chart cannot be null.");
    chart_set_style(ptr, style);
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


void Chart::set_table_font(const ChartFont &font)
{
    assert(ptr && "Chart cannot be null.");
    chart_set_table_font(ptr, const_cast<ChartFont*>(&font));
}


void Chart::set_up_down_bars()
{
    assert(ptr && "Chart cannot be null.");
    chart_set_up_down_bars(ptr);
}


void Chart::set_up_down_bars_format(const ChartLine &up_bar_line,
    const ChartFill &up_bar_fill,
    const ChartLine &down_bar_line,
    const ChartFill &down_bar_fill)
{
    assert(ptr && "Chart cannot be null.");
    chart_set_up_down_bars_format(ptr, const_cast<ChartLine*>(&up_bar_line), const_cast<ChartFill*>(&up_bar_fill), const_cast<ChartLine*>(&down_bar_line), const_cast<ChartFill*>(&down_bar_fill));
}


void Chart::set_drop_lines(const ChartLine &line)
{
    assert(ptr && "Chart cannot be null.");
    chart_set_drop_lines(ptr, const_cast<ChartLine*>(&line));
}


void Chart::set_high_low_lines(const ChartLine &line)
{
    assert(ptr && "Chart cannot be null.");
    chart_set_high_low_lines(ptr, const_cast<ChartLine*>(&line));
}


void Chart::set_series_overlap(const uint8_t overlap)
{
    assert(ptr && "Chart cannot be null.");
    chart_set_series_overlap(ptr, overlap);
}


void Chart::set_series_gap(const uint16_t gap)
{
    assert(ptr && "Chart cannot be null.");
    chart_set_series_gap(ptr, gap);
}


void Chart::show_blanks_as(const ChartBlank option)
{
    assert(ptr && "Chart cannot be null.");
    chart_show_blanks_as(ptr, FROM_ENUM(option));
}


void Chart::show_hidden_data()
{
    assert(ptr && "Chart cannot be null.");
    chart_show_hidden_data(ptr);
}


void Chart::set_rotation(const uint16_t rotation)
{
    assert(ptr && "Chart cannot be null.");
    chart_set_rotation(ptr, rotation);
}


void Chart::set_hole_size(const uint8_t size)
{
    assert(ptr && "Chart cannot be null.");
    chart_set_hole_size(ptr, size);
}

}   /* xlsxwriter */
