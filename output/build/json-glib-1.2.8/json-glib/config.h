/* json-glib/config.h.  Generated from config.h.in by configure.  */
/* json-glib/config.h.in.  Generated from configure.ac by autoheader.  */

/* Define to 1 if translation of program messages to the user's native
   language is requested. */
/* #undef ENABLE_NLS */

/* The prefix for our gettext translation domains. */
#define GETTEXT_PACKAGE "json-glib-1.0"

/* Define to 1 if you have the MacOS X function CFLocaleCopyCurrent in the
   CoreFoundation framework. */
/* #undef HAVE_CFLOCALECOPYCURRENT */

/* Define to 1 if you have the MacOS X function CFPreferencesCopyAppValue in
   the CoreFoundation framework. */
/* #undef HAVE_CFPREFERENCESCOPYAPPVALUE */

/* Define if the GNU dcgettext() function is already present or preinstalled.
   */
/* #undef HAVE_DCGETTEXT */

/* Define to 1 if you have the <dlfcn.h> header file. */
#define HAVE_DLFCN_H 1

/* Whether you have gcov */
/* #undef HAVE_GCOV */

/* Define if the GNU gettext() function is already present or preinstalled. */
/* #undef HAVE_GETTEXT */

/* Define if you have the iconv() function and it works. */
/* #undef HAVE_ICONV */

/* Define to 1 if you have the <inttypes.h> header file. */
#define HAVE_INTTYPES_H 1

/* Define to 1 if you have the <memory.h> header file. */
#define HAVE_MEMORY_H 1

/* Define to 1 if you have the <stdint.h> header file. */
#define HAVE_STDINT_H 1

/* Define to 1 if you have the <stdlib.h> header file. */
#define HAVE_STDLIB_H 1

/* Define to 1 if you have the <strings.h> header file. */
#define HAVE_STRINGS_H 1

/* Define to 1 if you have the <string.h> header file. */
#define HAVE_STRING_H 1

/* Define to 1 if you have the <sys/stat.h> header file. */
#define HAVE_SYS_STAT_H 1

/* Define to 1 if you have the <sys/types.h> header file. */
#define HAVE_SYS_TYPES_H 1

/* Define to 1 if you have the <unistd.h> header file. */
#define HAVE_UNISTD_H 1

/* Define to the sub-directory where libtool stores uninstalled libraries. */
#define LT_OBJDIR ".libs/"

/* Define to the address where bug reports for this package should be sent. */
#define PACKAGE_BUGREPORT "http://bugzilla.gnome.org/enter_bug.cgi?product=json-glib"

/* Define to the full name of this package. */
#define PACKAGE_NAME "JSON-GLib"

/* Define to the full name and version of this package. */
#define PACKAGE_STRING "JSON-GLib 1.2.8"

/* Define to the one symbol short name of this package. */
#define PACKAGE_TARNAME "json-glib"

/* Define to the home page for this package. */
#define PACKAGE_URL "http://wiki.gnome.org/Project/JsonGlib"

/* Define to the version of this package. */
#define PACKAGE_VERSION "1.2.8"

/* Define to 1 if you have the ANSI C header files. */
#define STDC_HEADERS 1

/* defines how to decorate public symbols while building */
#define _JSON_EXTERN __attribute__((visibility("default"))) extern
