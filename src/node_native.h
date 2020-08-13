#ifndef TNEF_NODE_NATIVE_H
#define TNEF_NODE_NATIVE_H

#if HAVE_CONFIG_H
#  include "config.h"
#endif /* HAVE_CONFIG_H */

#include "common.h"
enum Error_Code {
    INPUT_FILE_INCORRECT = 0x01,
    OUTPUT_DIR_ERROR = 0x02,
};
typedef struct {
    char* file_name;
    char* path;
    size_t len;
    char* mime_type;
    char* content_id; //cid;
}File_Info;

int extract_files(const char* file_name, const char* output_dir);
//extern int get_files_info(const char* file_name, File_Info* fileInfo );

#endif //TNEF_NODE_NATIVE_H
