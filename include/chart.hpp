//  :copyright: (c) 2017 Alex Huszagh.
//  :license: FreeBSD, see LICENSE.md for more details.
/**
 *  C++ bindings for libxlsxwriter charts.
 */

#pragma once

#include "common.hpp"

#include <string>
#include <xlsxwriter/chart.h>


namespace xlsxwriter
{
// ENUMS
// -----


enum class ChartType: int
{
    LXW_CHART_NONE = 0,
    LXW_CHART_AREA,
    LXW_CHART_AREA_STACKED,
    LXW_CHART_AREA_STACKED_PERCENT,
    LXW_CHART_BAR,
    LXW_CHART_BAR_STACKED,
    LXW_CHART_BAR_STACKED_PERCENT,
    LXW_CHART_COLUMN,
    LXW_CHART_COLUMN_STACKED,
    LXW_CHART_COLUMN_STACKED_PERCENT,
    LXW_CHART_DOUGHNUT,
    LXW_CHART_LINE,
    LXW_CHART_PIE,
    LXW_CHART_SCATTER,
    LXW_CHART_SCATTER_STRAIGHT,
    LXW_CHART_SCATTER_STRAIGHT_WITH_MARKERS,
    LXW_CHART_SCATTER_SMOOTH,
    LXW_CHART_SCATTER_SMOOTH_WITH_MARKERS,
    LXW_CHART_RADAR,
    LXW_CHART_RADAR_WITH_MARKERS,
    LXW_CHART_RADAR_FILLED
};

// OBJECTS
// -------


class ChartSeries
{
protected:
    lxw_chart_series *ptr = nullptr;

    friend class Chart;

    ChartSeries(lxw_chart_series *ptr);

public:
    ChartSeries() = default;
    ChartSeries(const ChartSeries&) = default;
    ChartSeries & operator=(const ChartSeries&) = default;
    ChartSeries(ChartSeries &&other) = default;
    ChartSeries & operator=(ChartSeries &&other) = default;

    // DATA
    void set_categories(const std::string &sheetname,
        const Row first_row,
        const Column first_col,
        const Row last_row,
        const Column last_col);
    void set_values(const std::string &sheetname,
        const Row first_row,
        const Column first_col,
        const Row last_row,
        const Column last_col);
    void set_name(const std::string &name);

// TODO: add methods
//chart_series_set_name_range
//chart_series_set_line
//chart_series_set_fill
//chart_series_set_invert_if_negative
//chart_series_set_pattern
//chart_series_set_marker_type
//chart_series_set_marker_size
//chart_series_set_marker_line
//chart_series_set_marker_fill
//chart_series_set_marker_pattern
//chart_series_set_points
//chart_series_set_smooth
//chart_series_set_labels
//chart_series_set_labels_options
//chart_series_set_labels_separator
//chart_series_set_labels_position
//chart_series_set_labels_leader_line
//chart_series_set_labels_legend
//chart_series_set_labels_percentage
//chart_series_set_labels_num_format
//chart_series_set_labels_font
//chart_series_set_trendline
//chart_series_set_trendline_forecast
//chart_series_set_trendline_equation
//chart_series_set_trendline_r_squared
//chart_series_set_trendline_intercept
//chart_series_set_trendline_name
//chart_series_set_trendline_line
//chart_series_set_error_bars
//chart_series_set_error_bars_direction
//chart_series_set_error_bars_endcap
//chart_series_set_error_bars_line
};


// TODO: add chart axis
//chart_axis_set_name
//chart_axis_set_name_range
//chart_axis_set_name_font
//chart_axis_set_num_font
//chart_axis_set_num_format
//chart_axis_set_line
//chart_axis_set_fill
//chart_axis_set_pattern
//chart_axis_set_reverse
//chart_axis_set_crossing
//chart_axis_set_crossing_max
//chart_axis_off
//chart_axis_set_position
//chart_axis_set_label_position
//chart_axis_set_min
//chart_axis_set_max
//chart_axis_set_log_base
//chart_axis_set_major_tick_mark
//chart_axis_set_minor_tick_mark
//chart_axis_set_interval_unit
//chart_axis_set_interval_tick
//chart_axis_set_major_unit
//chart_axis_set_minor_unit
//chart_axis_set_display_units
//chart_axis_set_display_units_visible
//chart_axis_major_gridlines_set_visible
//chart_axis_minor_gridlines_set_visible
//chart_axis_major_gridlines_set_line
//chart_axis_minor_gridlines_set_line


class Chart
{
protected:
    lxw_chart *ptr = nullptr;
    friend class Workbook;

    Chart(lxw_chart *ptr);

public:
    Chart() = default;
    Chart(const Chart&) = default;
    Chart & operator=(const Chart&) = default;
    Chart(Chart &&other) = default;
    Chart & operator=(Chart &&other) = default;

    // DATA
    ChartSeries add_series(const std::string &categories,
        const std::string &values);
// TODO: add methods
// chart_title_set_name
// chart_title_set_name_range
// chart_title_set_name_font
// chart_title_off
// chart_legend_set_position
// chart_legend_set_font
// chart_legend_delete_series
// chart_chartarea_set_line
// chart_chartarea_set_fill
// chart_chartarea_set_pattern
// chart_plotarea_set_line
// chart_plotarea_set_fill
// chart_plotarea_set_pattern
// chart_set_style
// chart_set_table
// chart_set_table_grid
// chart_set_table_font
// chart_set_up_down_bars
// chart_set_up_down_bars_format
// chart_set_drop_lines
// chart_set_high_low_lines
// chart_set_series_overlap
// chart_set_series_gap
// chart_show_blanks_as
// chart_show_hidden_data
// chart_set_rotation
// chart_set_hole_size
};

}   /* xlsxwriter */
