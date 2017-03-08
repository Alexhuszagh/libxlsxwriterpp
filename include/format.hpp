//  :copyright: (c) 2017 Alex Huszagh.
//  :license: FreeBSD, see LICENSE.md for more details.
/**
 *  C++ bindings for libxlsxwriter formatting.
 */

#pragma once

#include <cstdio>
#include <string>
#include <xlsxwriter/format.h>


namespace xlsxwriter
{
// OBJECTS
// -------

typedef uint32_t Color;


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
    //void set_underline();
    void set_font_strikeout();
// TODO: add methods
//    format_set_font_script
//    format_set_num_format
//    format_set_num_format_index
//    format_set_unlocked
//    format_set_hidden
//    format_set_align
//    format_set_text_wrap
//    format_set_rotation
//    format_set_indent
//    format_set_shrink
//    format_set_pattern
//    format_set_bg_color
//    format_set_fg_color
//    format_set_border
//    format_set_bottom
//    format_set_top
//    format_set_left
//    format_set_right
//    format_set_border_color
//    format_set_bottom_color
//    format_set_top_color
//    format_set_left_color
//    format_set_right_color
//    format_set_diag_type
//    format_set_diag_color
//    format_set_diag_border
//    format_set_font_outline
//    format_set_font_shadow
//    format_set_font_family
//    format_set_font_charset
//    format_set_font_scheme
//    format_set_font_condense
//    format_set_font_extend
//    format_set_reading_order
//    format_set_theme
};

}   /* xlsxwriter */
