//  :copyright: (c) 2017 Alex Huszagh.
//  :license: FreeBSD, see LICENSE.md for more details.
/**
 *  C++ bindings for libxlsxwriter formatting.
 */

#pragma once

#include "common.hpp"

#include <string>
#include <xlsxwriter/format.h>


namespace xlsxwriter
{
// ENUMS
// -----


enum class Underlines: uint8_t
{
    SINGLE = 1,
    DOUBLE,
    SINGLE_ACCOUNTING,
    DOUBLE_ACCOUNTING,
};


enum class FontScripts: uint8_t
{
    SUPERSCRIPT = 1,
    SUBSCRIPT,
};


enum class Aligments: uint8_t
{
    NONE = 0,
    LEFT,
    CENTER,
    RIGHT,
    FILL,
    JUSTIFY,
    CENTER_ACROSS,
    DISTRIBUTED,
    VERTICAL_TOP,
    VERTICAL_BOTTOM,
    VERTICAL_CENTER,
    VERTICAL_JUSTIFY,
    VERTICAL_DISTRIBUTED,
};


enum class Patterns: uint8_t
{
    NONE = 0,
    SOLID,
    MEDIUM_GRAY,
    DARK_GRAY,
    LIGHT_GRAY,
    DARK_HORIZONTAL,
    DARK_VERTICAL,
    DARK_DOWN,
    DARK_UP,
    DARK_GRID,
    DARK_TRELLIS,
    LIGHT_HORIZONTAL,
    LIGHT_VERTICAL,
    LIGHT_DOWN,
    LIGHT_UP,
    LIGHT_GRID,
    LIGHT_TRELLIS,
    GRAY_125,
    GRAY_0625,
};


enum class Borders: uint8_t
{
    NONE = 0,
    THIN,
    MEDIUM,
    DASHED,
    DOTTED,
    THICK,
    DOUBLE,
    HAIR,
    MEDIUM_DASHED,
    DASH_DOT,
    MEDIUM_DASH_DOT,
    DASH_DOT_DOT,
    MEDIUM_DASH_DOT_DOT,
    SLANT_DASH_DOT,
};


enum class Diagonals: uint8_t
{
    BORDER_UP = 1,
    BORDER_DOWN,
    BORDER_UP_DOWN,
};

// OBJECTS
// -------

typedef lxw_color_t Color;


class Format
{
protected:
    lxw_format *ptr = nullptr;

    friend class Workbook;
    friend class Worksheet;

    Format(lxw_format *ptr);

public:
    Format() = default;
    Format(const Format&) = default;
    Format & operator=(const Format&) = default;
    Format(Format&&) = default;
    Format & operator=(Format&&) = default;

    void set_font_name(const std::string &name);
    void set_font_size(const uint16_t size);
    void set_font_color(const Color color);
    void set_bold();
    void set_italic();
    void set_underline(const Underlines style = Underlines::SINGLE);
    void set_font_strikeout();
    void set_font_script(const FontScripts script);
    void set_num_format(const std::string &format);
    void set_num_format_index(const uint8_t index);
    void set_unlocked();
    void set_hidden();
    void set_align(const Aligments aligment);
    void set_text_wrap();
    void set_rotation(const int16_t angle);
    void set_indent(const int8_t level);
    void set_shrink();
    void set_pattern(const Patterns pattern);
    void set_bg_color(const Color color);
    void set_fg_color(const Color color);
    void set_border(const Borders style);
    void set_bottom(const Borders style);
    void set_top(const Borders style);
    void set_left(const Borders style);
    void set_right(const Borders style);
    void set_border_color(const Color color);
    void set_bottom_color(const Color color);
    void set_top_color(const Color color);
    void set_left_color(const Color color);
    void set_right_color(const Color color);
    void set_diag_type(const Diagonals type);
    void set_diag_color(const Color color);
    void set_diag_border(const Borders style);
    void set_font_outline();
    void set_font_shadow();
    void set_font_condense();
    void set_font_extend();
};

}   /* xlsxwriter */
