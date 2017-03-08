//  :copyright: (c) 2017 Alex Huszagh.
//  :license: FreeBSD, see LICENSE.md for more details.
/**
 *  Generic utilities.
 */

#include "utility.hpp"

#include <vector>


namespace xlsxwriter
{
// CONSTANTS
// ---------

std::vector<std::string> ERROR_MESSAGES = {
    "No error",                                 // LXW_NO_ERROR
    "Malloc failed.",                           // LXW_ERROR_MEMORY_MALLOC_FAILED
    "Error creating Xlsx file.",                // LXW_ERROR_CREATING_XLSX_FILE
    "Error creating temporary file.",           // LXW_ERROR_CREATING_TMPFILE
    "Zlib error while creating Xlsx file.",     // LXW_ERROR_ZIP_FILE_OPERATION
    "Zlib error while adding worksheet.",       // LXW_ERROR_ZIP_FILE_ADD
    "Zlib error while closing file.",           // LXW_ERROR_ZIP_CLOSE
    "Ignored null parameter.",                  // LXW_ERROR_NULL_PARAMETER_IGNORED
    "Error during parameter validation.",       // LXW_ERROR_PARAMETER_VALIDATION
    "Worksheet name exceeds 31 characters.",    // LXW_ERROR_SHEETNAME_LENGTH_EXCEEDED
    "Worksheet name contains '[]:*?/\\'.",      // LXW_ERROR_INVALID_SHEETNAME_CHARACTER
    "Worksheet name already exists.",           // LXW_ERROR_SHEETNAME_ALREADY_USED
    "Parameter exceeds 128 character limit."    // LXW_ERROR_128_STRING_LENGTH_EXCEEDED
    "Parameter exceeds 255 character limit."    // LXW_ERROR_255_STRING_LENGTH_EXCEEDED
    "String exceeds max length limit."          // LXW_ERROR_MAX_STRING_LENGTH_EXCEEDED
    "Error finding internal string index."      // LXW_ERROR_SHARED_STRING_INDEX_NOT_FOUND
    "Worksheet row or column out of range."     // LXW_ERROR_WORKSHEET_INDEX_OUT_OF_RANGE
    "Maximim number of URLs exceeded."          // LXW_ERROR_WORKSHEET_MAX_NUMBER_URLS_EXCEEDED
    "Could not read image dimensions or DPI."   // LXW_ERROR_IMAGE_DIMENSIONS
};


// OBJECTS
// --------


LxwError::LxwError(const lxw_error code):
    message(ERROR_MESSAGES[FROM_ENUM(code)])
{}


const char * LxwError::what() const throw()
{
    return message.data();
}

}   /* xlsxwriter */
