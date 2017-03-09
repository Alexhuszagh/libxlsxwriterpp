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


enum class ChartType: uint8_t
{
    NONE = 0,
    AREA,
    AREA_STACKED,
    AREA_STACKED_PERCENT,
    BAR,
    BAR_STACKED,
    BAR_STACKED_PERCENT,
    COLUMN,
    COLUMN_STACKED,
    COLUMN_STACKED_PERCENT,
    DOUGHNUT,
    LINE,
    PIE,
    SCATTER,
    SCATTER_STRAIGHT,
    SCATTER_STRAIGHT_WITH_MARKERS,
    SCATTER_SMOOTH,
    SCATTER_SMOOTH_WITH_MARKERS,
    RADAR,
    RADAR_WITH_MARKERS,
    RADAR_FILLED,
};


enum class MarkerType: uint8_t
{
    AUTOMATIC = 0,
    NONE,
    SQUARE,
    DIAMOND,
    TRIANGLE,
    X,
    STAR,
    SHORT_DASH,
    LONG_DASH,
    CIRCLE,
    PLUS,
};


enum class LabelSeparators: uint8_t
{
    COMMA = 0,
    SEMICOLON,
    PERIOD,
    NEWLINE,
    SPACE,
};


enum class ChartLabelPosition: uint8_t
{
    DEFAULT = 0,
    CENTER,
    RIGHT,
    LEFT,
    ABOVE,
    BELOW,
    INSIDE_BASE,
    INSIDE_END,
    OUTSIDE_END,
    BEST_FIT,
};

// OBJECTS
// -------


class ChartLine
{};


class ChartFill
{};


class ChartPattern
{};


class ChartPoint
{};


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
    void set_name_range(const std::string &name,
        const Row row,
        const Column col);

// TODO: add methods
//chart_series_set_line
//chart_series_set_fill

    void invert_if_negative();

//chart_series_set_pattern

    void set_marker_type(const MarkerType type);
    void set_marker_size(const uint8_t size);
//chart_series_set_marker_line
//chart_series_set_marker_fill
//chart_series_set_marker_pattern

//chart_series_set_points
    void set_smooth(const bool smooth);
    void set_labels();
    void set_labels_options(const bool show_name,
        const bool show_category,
        const bool show_value);
    void set_labels_separator(const LabelSeparators separator);
    void set_labels_position(const ChartLabelPosition position);
    void set_labels_leader_line();
    void set_labels_legend();
    void set_labels_percentage();
    void set_labels_num_format(const std::string &num_format);

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
