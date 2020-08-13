#ifdef HAVE_CONFIG_H
#  include "config.h"
#endif /* HAVE_CONFIG_H */

#include "common.h"
#include <ctype.h>

#ifndef _
/* This is for other GNU distributions with internationalized messages.
   When compiling libc, the _ macro is predefined.  */
# ifdef HAVE_LIBINTL_H
#  include <libintl.h>
#  define _(msgid)	gettext (msgid)
# else
#  define _(msgid)	(msgid)
# endif
#endif

#if HAVE_GETOPT_LONG
//#  include <getopt.h>
#else
#  include "replace/getopt_long.h"
#endif /* HAVE_GETOPT_LONG */

//#include "alloc.h"
// #include "tnef.h"
#include "options.h"
#include "node_native.h"
#include "alloc.h"

int extract_files(const char* file_name, const char* output_dir, File_List* const file_list){
    FILE* fp = NULL;
    int flags = NONE;
    char* body_file_name = strdup("message");
    char* body_pref = strdup("rht");
    if(file_name){
        fp = fopen(file_name, "rb");
        if(fp == NULL){
            perror(file_name);
            return INPUT_FILE_INCORRECT;
        }
    } else {
        return INPUT_FILE_INCORRECT;
    }
    flags |= OVERWRITE;
    flags |= SAVEBODY;
    flags |= LISTMIME;

    int ret = parse_file(fp, output_dir, body_file_name, body_pref, flags, file_list);

    XFREE(body_file_name);
    XFREE(body_pref);

    fclose(fp);
    return ret;
}