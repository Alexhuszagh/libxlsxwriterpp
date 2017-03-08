//  :copyright: (c) 2017 Alex Huszagh.
//  :license: FreeBSD, see LICENSE.md for more details.
/**
 *  C++ bindings for libxlsxwriter charts.
 */

#pragma once

#include <cstdio>
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

    // TODO: add methods
};

}   /* xlsxwriter */
