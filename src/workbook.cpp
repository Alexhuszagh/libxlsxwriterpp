//  :copyright: (c) 2017 Alex Huszagh.
//  :license: FreeBSD, see LICENSE.md for more details.
/**
 *  C++ bindings for libxlsxwriter workbooks.
 */

#pragma once

#include "workbook.hpp"


namespace xlsxwriter
{
// OBJECTS
// -------


Options::Options(Options &&other):
    ptr(other.ptr)
{
    other.ptr = nullptr;
}


Options & Options::operator=(Options &&other)
{
    ptr = other.ptr;
    other.ptr = nullptr;
}


Options::~Options()
{
    if (ptr) {
        free(ptr->filename);
        delete ptr;
    }
}


Options::Options(const bool constant_memory):
    ptr(new lxw_workbook_options)
{
    ptr->constant_memory = constant_memory;
    ptr->tmpdir = nullptr;
}


Options::Options(const std::string &tmpdir):
    ptr(new lxw_workbook_options)
{
    ptr->constant_memory = 0;
    ptr->tmpdir = lxw_strdup(tmpdir.data());
}


Options::Options(const bool const_memory,
        const std::string &tmpdir):
    ptr(new lxw_workbook_options)
{
    ptr->constant_memory = const_memory;
    ptr->tmpdir = lxw_strdup(tmpdir.data());
}


Workbook::Workbook(Workbook &&other):
    ptr(other.ptr)
{
    other.ptr = nullptr;
}


Workbook & Workbook::operator=(Workbook &&other)
{
    ptr = other.ptr;
    other.ptr = nullptr;
}


Workbook::~Workbook()
{
    if (ptr) {
        workbook_close(ptr);
    }
}


Workbook::Workbook(const std::string &filename,
    const Options &options)
{
    ptr = workbook_new_opt(filename.data(), options.ptr);
}

}   /* xlsxwriter */
