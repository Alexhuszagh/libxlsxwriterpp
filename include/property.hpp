//  :copyright: (c) 2017 Alex Huszagh.
//  :license: FreeBSD, see LICENSE.md for more details.
/**
 *  C++ bindings for libxlsxwriter properties.
 */

#pragma once

#include <xlsxwriter/workbook.h>


namespace xlsxwriter
{
// OBJECTS
// -------


class Properties
{
protected:
    lxw_doc_properties *ptr = nullptr;
    friend class Workbook;

    Properties(lxw_doc_properties *ptr);

public:
    Properties() = delete;
    Properties(const Properties&) = delete;
    Properties & operator=(const Properties&) = delete;
    Properties(Properties &&other);
    Properties & operator=(Properties &&other);
};

}   /* xlsxwriter */
