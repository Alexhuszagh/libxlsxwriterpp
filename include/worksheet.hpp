//  :copyright: (c) 2017 Alex Huszagh.
//  :license: FreeBSD, see LICENSE.md for more details.
/**
 *  C++ bindings for libxlsxwriter worksheets.
 */

#pragma once

#include "chart.hpp"
#include "common.hpp"
#include "format.hpp"

#include <deque>
#include <xlsxwriter/worksheet.h>


namespace xlsxwriter
{
// ENUMS
// -----

enum class PaperType: uint8_t
{
    DEFAULT = 0,
    LETTER,
    LETTER_SMALL,
    TABLOID,
    LEDGER,
    LEGAL,
    STATEMENT,
    EXECUTIVE,
    A3,
    A4,
    A4_SMALL,
    A5,
    B5,
    FOLIO,
    QUARTO,
    NOTE = 18,
    ENVELOPE_9,
    ENVELOPE_10,
    ENVELOPE_11,
    ENVELOPE_12,
    ENVELOPE_14,
    C_SIZE_SHEET,
    D_SIZE_SHEET,
    E_SIZE_SHEET,
    ENVELOPE_DL,
    ENVELOPE_C3,
    ENVELOPE_C4,
    ENVELOPE_C5,
    ENVELOPE_C6,
    ENVELOPE_C65,
    ENVELOPE_B4,
    ENVELOPE_B5,
    ENVELOPE_B6,
    ENVELOPE,
    MONARCH,
    FANFOLD,
    GERMAN_STD_FANFOLD,
    GERMAN_LEGAL_FANFOLD,
};


enum class Gridlines: uint8_t
{
    HIDE_ALL = 0,
    SHOW_SCREEN,
    SHOW_PRINT,
    SHOW_ALL,
};

// OBJECTS
// -------

typedef lxw_row_col_options RowColOptions;
typedef lxw_col_options ColumnOptions;
typedef lxw_image_options ImageOptions;
typedef lxw_protection Protection;


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
    void write_url(const Row row,
        const Column col,
        const std::string &url,
        const Format &format = Format(),
        const std::string &string = "",
        const std::string &tooltip = "");

    // FORMULA
    void write_formula(const Row row,
        const Column col,
        const std::string &formula,
        const Format &format = Format(),
        const double result = 0);
    void write_array_formula(const Row first_row,
        const Column first_col,
        const Row last_row,
        const Column last_col,
        const std::string &formula,
        const Format &format = Format(),
        const double result = 0);

    // FORMAT
    void set_row(const Row row,
        const double height,
        const Format &format = Format(),
        const RowColOptions &options = RowColOptions {0});
    void set_column(const Column first_col,
        const Column last_col,
        const double width,
        const Format &format = Format(),
        const RowColOptions &options = RowColOptions {0});
    void merge_range(const Row first_row,
        const Column first_col,
        const Row last_row,
        const Column last_col,
        const std::string &string,
        const Format &format = Format());
    void insert_chart(const Row row,
        const Column col,
        const Chart &chart,
        const ImageOptions &options = ImageOptions {0});
    void insert_image(const Row row,
        const Column col,
        const std::string &filename,
        const ImageOptions &options = ImageOptions {0});
    void autofilter(const Row first_row,
        const Column first_col,
        const Row last_row,
        const Column last_col);
    void activate();
    void select();
    void hide();
    void set_first_sheet();
    void freeze_panes(const Row row,
        const Column col);
    void freeze_panes(const Row first_row,
        const Column first_col,
        const Row top_row,
        const Column top_col);
    void split_panes(const Row row,
        const Column col);
    void split_panes(const Row first_row,
        const Column first_col,
        const Row top_row,
        const Column top_col);
    void set_selection(const Row first_row,
        const Column first_col,
        const Row last_row,
        const Column last_col);
    void set_landscape();
    void set_portrait();
    void set_page_view();
    void set_paper(const PaperType type);
    void set_margins(const double left,
        const double right,
        const double top,
        const double bottom);
    void set_header(const std::string &string,
        const double margin = 0.3);
    void set_footer(const std::string &string,
        const double margin = 0.3);
    void set_h_pagebreaks(Rows &rows);
    void set_h_pagebreaks(Rows &&rows);
    void set_v_pagebreaks(Columns &columns);
    void set_v_pagebreaks(Columns &&columns);
    void print_across();
    void set_zoom(const uint16_t scale);
    void gridlines(const Gridlines options);
    void center_horizontally();
    void center_vertically();
    void print_row_col_headers();
    void repeat_rows(const Row first_row,
        const Row last_row);
    void repeat_columns(const Column first_col,
        const Column last_col);
    void print_area(const Row first_row,
        const Column first_col,
        const Row last_row,
        const Column last_col);
    void fit_to_pages(const uint16_t width,
        const uint16_t height);
    void set_start_page(const uint16_t start_page);
    void set_print_scale(const uint16_t scale);
    void right_to_left();
    void hide_zero();
    void set_tab_color(const Color color);
    void protect(const std::string &password,
        const Protection &options);
    void set_default_row(const double height,
        const bool hide_unused_rows);
};

typedef std::deque<Worksheet> Worksheets;

}   /* xlsxwriter */
