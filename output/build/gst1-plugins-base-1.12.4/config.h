/* config.h.  Generated from config.h.in by configure.  */
/* config.h.in.  Generated from configure.ac by autoheader.  */

/* Define if building universal (internal helper macro) */
/* #undef AC_APPLE_UNIVERSAL_BUILD */

/* The implementation that should be used for integer audio resampling witll
   be benchmarked at runtime */
#define AUDIORESAMPLE_FORMAT_AUTO 1

/* The float implementation should be used for integer audio resampling */
/* #undef AUDIORESAMPLE_FORMAT_FLOAT */

/* The int implementation should be used for integer audio resampling */
/* #undef AUDIORESAMPLE_FORMAT_INT */

/* defined if cdda headers are in a cdda/ directory */
/* #undef CDPARANOIA_HEADERS_IN_DIR */

/* Default audio sink */
#define DEFAULT_AUDIOSINK "autoaudiosink"

/* Default audio source */
#define DEFAULT_AUDIOSRC "alsasrc"

/* Default video sink */
#define DEFAULT_VIDEOSINK "autovideosink"

/* Default video source */
#define DEFAULT_VIDEOSRC "v4l2src"

/* Default visualizer */
#define DEFAULT_VISUALIZER "goom"

/* Disable Orc */
#define DISABLE_ORC 1

/* Define to 1 if translation of program messages to the user's native
   language is requested. */
/* #undef ENABLE_NLS */

/* gettext package name */
#define GETTEXT_PACKAGE "NULL"

/* The GIO library directory. */
#define GIO_LIBDIR "/media/panpan/tools/buildroot-2018.02.8/output/host/bin/../arm-buildroot-linux-gnueabihf/sysroot/usr/lib"

/* The GIO modules directory. */
#define GIO_MODULE_DIR "/usr/lib/gio/modules"

/* The GIO install prefix. */
#define GIO_PREFIX "/usr"

/* major/minor version */
#define GST_API_VERSION "1.0"

/* system wide data directory */
#define GST_DATADIR "/usr/share"

/* Define if extra runtime checks should be enabled */
/* #undef GST_ENABLE_EXTRA_CHECKS */

/* Extra platform specific plugin suffix */
/* #undef GST_EXTRA_MODULE_SUFFIX */

/* macro to use to show function name */
#define GST_FUNCTION __PRETTY_FUNCTION__

/* Defined if gcov is enabled to force a rebuild due to config.h changing */
/* #undef GST_GCOV_ENABLED */

/* Defined when registry scanning through fork is unsafe */
/* #undef GST_HAVE_UNSAFE_FORK */

/* plugin install helper script */
#define GST_INSTALL_PLUGINS_HELPER "/usr/libexec/gst-install-plugins-helper"

/* Default errorlevel to use */
#define GST_LEVEL_DEFAULT GST_LEVEL_NONE

/* GStreamer license */
#define GST_LICENSE "LGPL"

/* package name in plugins */
#define GST_PACKAGE_NAME "GStreamer Base Plug-ins source release"

/* package origin */
#define GST_PACKAGE_ORIGIN "Unknown package origin"

/* GStreamer package release date/time for plugins as YYYY-MM-DD */
#define GST_PACKAGE_RELEASE_DATETIME "2017-12-07"

/* Define if static plugins should be built */
/* #undef GST_PLUGIN_BUILD_STATIC */

/* Define to enable ALSA (used by alsa). */
/* #undef HAVE_ALSA */

/* ARM NEON support is enabled */
#define HAVE_ARM_NEON /**/

/* Define to enable CDParanoia (used by cdparanoia). */
/* #undef HAVE_CDPARANOIA */

/* Define to 1 if you have the MacOS X function CFLocaleCopyCurrent in the
   CoreFoundation framework. */
/* #undef HAVE_CFLOCALECOPYCURRENT */

/* Define to 1 if you have the MacOS X function CFPreferencesCopyAppValue in
   the CoreFoundation framework. */
/* #undef HAVE_CFPREFERENCESCOPYAPPVALUE */

/* Define if the target CPU is AARCH64 */
/* #undef HAVE_CPU_AARCH64 */

/* Define if the target CPU is an Alpha */
/* #undef HAVE_CPU_ALPHA */

/* Define if the target CPU is an ARC */
/* #undef HAVE_CPU_ARC */

/* Define if the target CPU is an ARM */
#define HAVE_CPU_ARM 1

/* Define if the target CPU is a CRIS */
/* #undef HAVE_CPU_CRIS */

/* Define if the target CPU is a CRISv32 */
/* #undef HAVE_CPU_CRISV32 */

/* Define if the target CPU is a HPPA */
/* #undef HAVE_CPU_HPPA */

/* Define if the target CPU is an x86 */
/* #undef HAVE_CPU_I386 */

/* Define if the target CPU is a IA64 */
/* #undef HAVE_CPU_IA64 */

/* Define if the target CPU is a M68K */
/* #undef HAVE_CPU_M68K */

/* Define if the target CPU is a MIPS */
/* #undef HAVE_CPU_MIPS */

/* Define if the target CPU is a PowerPC */
/* #undef HAVE_CPU_PPC */

/* Define if the target CPU is a 64 bit PowerPC */
/* #undef HAVE_CPU_PPC64 */

/* Define if the target CPU is a S390 */
/* #undef HAVE_CPU_S390 */

/* Define if the target CPU is a SPARC */
/* #undef HAVE_CPU_SPARC */

/* Define if the target CPU is a x86_64 */
/* #undef HAVE_CPU_X86_64 */

/* Define if the GNU dcgettext() function is already present or preinstalled.
   */
/* #undef HAVE_DCGETTEXT */

/* Define to 1 if you have the declaration of `__i386__', and to 0 if you
   don't. */
#define HAVE_DECL___I386__ 0

/* Define to 1 if you have the declaration of `__x86_64__', and to 0 if you
   don't. */
#define HAVE_DECL___X86_64__ 0

/* Define to 1 if you have the <dlfcn.h> header file. */
#define HAVE_DLFCN_H 1

/* Define to 1 if you have the <emmintrin.h> header file. */
/* #undef HAVE_EMMINTRIN_H */

/* Define to enable building of experimental plug-ins. */
/* #undef HAVE_EXPERIMENTAL */

/* Define to enable building of plug-ins with external deps. */
#define HAVE_EXTERNAL /**/

/* Define to 1 if fseeko (and presumably ftello) exists and is declared. */
#define HAVE_FSEEKO 1

/* defined if the compiler implements __func__ */
#define HAVE_FUNC 1

/* defined if the compiler implements __FUNCTION__ */
#define HAVE_FUNCTION 1

/* Define if the GNU gettext() function is already present or preinstalled. */
/* #undef HAVE_GETTEXT */

/* Define to 1 if you have the `gmtime_r' function. */
#define HAVE_GMTIME_R 1

/* Define if you have the iconv() function and it works. */
/* #undef HAVE_ICONV */

/* Define to 1 if you have the <inttypes.h> header file. */
#define HAVE_INTTYPES_H 1

/* make use of iso-codes for ISO-639 */
/* #undef HAVE_ISO_CODES */

/* Define to enable integer vorbis plug-in (used by ivorbisdec). */
/* #undef HAVE_IVORBIS */

/* Define to 1 if you have the `asound' library (-lasound). */
/* #undef HAVE_LIBASOUND */

/* Define to enable libvisual visualization library (used by libvisual). */
/* #undef HAVE_LIBVISUAL */

/* Define to 1 if you have the `localtime_r' function. */
#define HAVE_LOCALTIME_R 1

/* Define to 1 if you have the `log2' function. */
#define HAVE_LOG2 1

/* Define if you have C99's lrint function. */
#define HAVE_LRINT 1

/* Define if you have C99's lrintf function. */
#define HAVE_LRINTF 1

/* Define to 1 if you have the <memory.h> header file. */
#define HAVE_MEMORY_H 1

/* Defined if mmap is supported */
#define HAVE_MMAP 1

/* Define to enable Xiph Ogg library (used by ogg). */
/* #undef HAVE_OGG */

/* Define to enable opus (used by opus). */
/* #undef HAVE_OPUS */

/* Use Orc */
/* #undef HAVE_ORC */

/* Defined if compiling for OSX */
/* #undef HAVE_OSX */

/* Define to enable Pango font rendering (used by pango). */
/* #undef HAVE_PANGO */

/* defined if the compiler implements __PRETTY_FUNCTION__ */
#define HAVE_PRETTY_FUNCTION 1

/* Define to 1 if you have the <process.h> header file. */
/* #undef HAVE_PROCESS_H */

/* Define if you have POSIX threads libraries and header files. */
#define HAVE_PTHREAD 1

/* Have PTHREAD_PRIO_INHERIT. */
#define HAVE_PTHREAD_PRIO_INHERIT 1

/* Define if RDTSC is available */
/* #undef HAVE_RDTSC */

/* Define to 1 if you have the <smmintrin.h> header file. */
/* #undef HAVE_SMMINTRIN_H */

/* SSE support is enabled */
#define HAVE_SSE 0

/* SSE2 support is enabled */
#define HAVE_SSE2 0

/* SSE4.1 support is enabled */
#define HAVE_SSE41 0

/* Define to 1 if you have the <stdint.h> header file. */
#define HAVE_STDINT_H 1

/* Define to 1 if you have the <stdlib.h> header file. */
#define HAVE_STDLIB_H 1

/* Define to 1 if you have the <strings.h> header file. */
#define HAVE_STRINGS_H 1

/* Define to 1 if you have the <string.h> header file. */
#define HAVE_STRING_H 1

/* Define to 1 if you have the <sys/socket.h> header file. */
#define HAVE_SYS_SOCKET_H 1

/* Define to 1 if you have the <sys/stat.h> header file. */
#define HAVE_SYS_STAT_H 1

/* Define to 1 if you have the <sys/types.h> header file. */
#define HAVE_SYS_TYPES_H 1

/* Define to 1 if you have the <sys/wait.h> header file. */
#define HAVE_SYS_WAIT_H 1

/* Define to enable Xiph Theora video codec (used by theora). */
/* #undef HAVE_THEORA */

/* Define to 1 if you have the <unistd.h> header file. */
#define HAVE_UNISTD_H 1

/* Define if valgrind should be used */
/* #undef HAVE_VALGRIND */

/* Define to enable Xiph Vorbis audio codec (used by vorbis). */
/* #undef HAVE_VORBIS */

/* defined if vorbis_synthesis_restart is present */
/* #undef HAVE_VORBIS_SYNTHESIS_RESTART */

/* Defined if compiling for Windows */
/* #undef HAVE_WIN32 */

/* Define to 1 if you have the <winsock2.h> header file. */
/* #undef HAVE_WINSOCK2_H */

/* Define to enable X libraries and plugins (used by ximagesink). */
#define HAVE_X /**/

/* Define to 1 if you have the <xmmintrin.h> header file. */
/* #undef HAVE_XMMINTRIN_H */

/* Define to enable X Shared Memory extension. */
#define HAVE_XSHM /**/

/* Define to enable X11 XVideo extensions (used by xvimagesink). */
#define HAVE_XVIDEO /**/

/* Define to enable zlib support for ID3 parsing in libgsttag. */
#define HAVE_ZLIB /**/

/* the host CPU */
#define HOST_CPU "arm"

/* prefix */
/* #undef ISO_CODES_PREFIX */

/* */
/* #undef ISO_CODES_VERSION */

/* directory in which the detected libvisual's plugins are located */
/* #undef LIBVISUAL_PLUGINSBASEDIR */

/* gettext locale dir */
#define LOCALEDIR "/usr/share/locale"

/* Define to the sub-directory where libtool stores uninstalled libraries. */
#define LT_OBJDIR ".libs/"

/* Name of package */
#define PACKAGE "gst-plugins-base"

/* Define to the address where bug reports for this package should be sent. */
#define PACKAGE_BUGREPORT "http://bugzilla.gnome.org/enter_bug.cgi?product=GStreamer"

/* Define to the full name of this package. */
#define PACKAGE_NAME "GStreamer Base Plug-ins"

/* Define to the full name and version of this package. */
#define PACKAGE_STRING "GStreamer Base Plug-ins 1.12.4"

/* Define to the one symbol short name of this package. */
#define PACKAGE_TARNAME "gst-plugins-base"

/* Define to the home page for this package. */
#define PACKAGE_URL ""

/* Define to the version of this package. */
#define PACKAGE_VERSION "1.12.4"

/* directory where plugins are located */
#define PLUGINDIR "/usr/lib/gstreamer-1.0"

/* Define to necessary symbol if this constant uses a non-standard name on
   your system. */
/* #undef PTHREAD_CREATE_JOINABLE */

/* The size of `char', as computed by sizeof. */
/* #undef SIZEOF_CHAR */

/* The size of `int', as computed by sizeof. */
/* #undef SIZEOF_INT */

/* The size of `long', as computed by sizeof. */
/* #undef SIZEOF_LONG */

/* The size of `short', as computed by sizeof. */
/* #undef SIZEOF_SHORT */

/* The size of `void*', as computed by sizeof. */
/* #undef SIZEOF_VOIDP */

/* Define to 1 if you have the ANSI C header files. */
#define STDC_HEADERS 1

/* the target CPU */
#define TARGET_CPU "arm"

/* "Define if building for android" */
/* #undef USE_TREMOLO */

/* Version number of package */
#define VERSION "1.12.4"

/* Define WORDS_BIGENDIAN to 1 if your processor stores words with the most
   significant byte first (like Motorola and SPARC, unlike Intel). */
#if defined AC_APPLE_UNIVERSAL_BUILD
# if defined __BIG_ENDIAN__
#  define WORDS_BIGENDIAN 1
# endif
#else
# ifndef WORDS_BIGENDIAN
/* #  undef WORDS_BIGENDIAN */
# endif
#endif

/* Enable large inode numbers on Mac OS X 10.5.  */
#ifndef _DARWIN_USE_64_BIT_INODE
# define _DARWIN_USE_64_BIT_INODE 1
#endif

/* Number of bits in a file offset, on hosts where this is settable. */
/* #undef _FILE_OFFSET_BITS */

/* Define to 1 to make fseeko visible on some hosts (e.g. glibc 2.2). */
/* #undef _LARGEFILE_SOURCE */

/* Define for large files, on AIX-style hosts. */
/* #undef _LARGE_FILES */

/* We need at least WinXP SP2 for __stat64 */
/* #undef __MSVCRT_VERSION__ */
