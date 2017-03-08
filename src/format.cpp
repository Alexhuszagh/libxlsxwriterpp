//  :copyright: (c) 2017 Alex Huszagh.
//  :license: FreeBSD, see LICENSE.md for more details.
/**
 *  C++ bindings for libxlsxwriter formatting.
 */

#include "format.hpp"

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


void Format::set_font_strikeout()
{
    assert(ptr && "Format cannot be null.");
    format_set_font_strikeout(ptr);
}

}   /* xlsxwriter */
