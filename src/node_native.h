#ifndef TNEF_NODE_NATIVE_H
#define TNEF_NODE_NATIVE_H

#if HAVE_CONFIG_H
#  include "config.h"
#endif /* HAVE_CONFIG_H */

#include "common.h"
#include "tnef.h"

enum Error_Code {
    INPUT_FILE_INCORRECT = 0x01,
    OUTPUT_DIR_ERROR = 0x02,
};

int extract_files(const char* file_name, const char* output_dir, File_List* const file_list);
//extern int get_files_info(const char* file_name, File_Info* fileInfo );

#endif //TNEF_NODE_NATIVE_H
