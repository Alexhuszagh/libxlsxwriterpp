//  :copyright: (c) 2017 Alex Huszagh.
//  :license: FreeBSD, see LICENSE.md for more details.
/**
 *  C++ bindings for libxlsxwriter formatting.
 */

#include "format.hpp"
#include "utility.hpp"

#include <cassert>


namespace xlsxwriter
{
// OBJECTS
// -------


Format::Format(lxw_format *ptr):
    ptr(ptr)
{}


void Format::set_font_name(const std::string &name)
{
    assert(ptr && "Format cannot be null.");
    format_set_font_name(ptr, name.data());
}


void Format::set_font_size(const uint16_t size)
{
    assert(ptr && "Format cannot be null.");
    format_set_font_size(ptr, size);
}


void Format::set_font_color(const Color color)
{
    assert(ptr && "Format cannot be null.");
    format_set_font_color(ptr, color);
}

void Format::set_bold()
{
    assert(ptr && "Format cannot be null.");
    format_set_bold(ptr);
}


void Format::set_italic()
{
    assert(ptr && "Format cannot be null.");
    format_set_italic(ptr);
}


void Format::set_underline(const Underlines style)
{
    assert(ptr && "Format cannot be null.");
    format_set_underline(ptr, FROM_ENUM(style));
}


void Format::set_font_script(const FontScripts script)
{
    assert(ptr && "Format cannot be null.");
    format_set_font_script(ptr, FROM_ENUM(script));
}


void Format::set_num_format(const std::string &format)
{
    assert(ptr && "Format cannot be null.");
    format_set_num_format(ptr, format.data());
}


void Format::set_num_format_index(const uint8_t index)
{
    assert(ptr && "Format cannot be null.");
    format_set_num_format_index(ptr, index);
}


void Format::set_font_strikeout()
{
    assert(ptr && "Format cannot be null.");
    format_set_font_strikeout(ptr);
}


void Format::set_unlocked()
{
    assert(ptr && "Format cannot be null.");
    format_set_unlocked(ptr);
}


void Format::set_hidden()
{
    assert(ptr && "Format cannot be null.");
    format_set_hidden(ptr);
}


void Format::set_align(const Aligments aligment)
{
    assert(ptr && "Format cannot be null.");
    format_set_align(ptr, FROM_ENUM(aligment));
}


void Format::set_rotation(const int16_t angle)
{
    assert(ptr && "Format cannot be null.");
    format_set_rotation(ptr, angle);
}


void Format::set_indent(const int8_t level)
{
    assert(ptr && "Format cannot be null.");
    format_set_indent(ptr, level);
}


void Format::set_text_wrap()
{
    assert(ptr && "Format cannot be null.");
    format_set_text_wrap(ptr);
}


void Format::set_shrink()
{
    assert(ptr && "Format cannot be null.");
    format_set_shrink(ptr);
}


void Format::set_pattern(const Patterns pattern)
{
    assert(ptr && "Format cannot be null.");
    format_set_pattern(ptr, FROM_ENUM(pattern));
}


void Format::set_bg_color(const Color color)
{
    assert(ptr && "Format cannot be null.");
    format_set_bg_color(ptr, color);
}


void Format::set_fg_color(const Color color)
{
    assert(ptr && "Format cannot be null.");
    format_set_fg_color(ptr, color);
}


void Format::set_border(const Borders style)
{
    assert(ptr && "Format cannot be null.");
    format_set_border(ptr, FROM_ENUM(style));
}


void Format::set_bottom(const Borders style)
{
    assert(ptr && "Format cannot be null.");
    format_set_bottom(ptr, FROM_ENUM(style));
}


void Format::set_top(const Borders style)
{
    assert(ptr && "Format cannot be null.");
    format_set_top(ptr, FROM_ENUM(style));
}


void Format::set_left(const Borders style)
{
    assert(ptr && "Format cannot be null.");
    format_set_left(ptr, FROM_ENUM(style));
}


void Format::set_right(const Borders style)
{
    assert(ptr && "Format cannot be null.");
    format_set_right(ptr, FROM_ENUM(style));
}


void Format::set_border_color(const Color color)
{
    assert(ptr && "Format cannot be null.");
    format_set_border_color(ptr, color);
}


void Format::set_bottom_color(const Color color)
{
    assert(ptr && "Format cannot be null.");
    format_set_bottom_color(ptr, color);
}


void Format::set_top_color(const Color color)
{
    assert(ptr && "Format cannot be null.");
    format_set_top_color(ptr, color);
}


void Format::set_left_color(const Color color)
{
    assert(ptr && "Format cannot be null.");
    format_set_left_color(ptr, color);
}


void Format::set_right_color(const Color color)
{
    assert(ptr && "Format cannot be null.");
    format_set_right_color(ptr, color);
}


void Format::set_diag_type(const Diagonals type)
{
    assert(ptr && "Format cannot be null.");
    format_set_diag_type(ptr, FROM_ENUM(type));
}


void Format::set_diag_color(const Color color)
{
    assert(ptr && "Format cannot be null.");
    format_set_diag_color(ptr, color);
}


void Format::set_diag_border(const Borders style)
{
    assert(ptr && "Format cannot be null.");
    format_set_diag_border(ptr, FROM_ENUM(style));
}


void Format::set_font_outline()
{
    assert(ptr && "Format cannot be null.");
    format_set_font_outline(ptr);
}


void Format::set_font_shadow()
{
    assert(ptr && "Format cannot be null.");
    format_set_font_shadow(ptr);
}


void Format::set_font_condense()
{
    assert(ptr && "Format cannot be null.");
    format_set_font_condense(ptr);
}


void Format::set_font_extend()
{
    assert(ptr && "Format cannot be null.");
    format_set_font_extend(ptr);
}

}   /* xlsxwriter */
