/* config.h.  Generated from config.h.in by configure.  */
/* config.h.in.  Generated from configure.ac by autoheader.  */

/* Enable optimizer debugging */
/* #undef BDEBUG */

/* define if you have a cloning BPF device */
/* #undef HAVE_CLONING_BPF */

/* define if you have the DAG API */
/* #undef HAVE_DAG_API */

/* define if you have dag_get_erf_types() */
/* #undef HAVE_DAG_GET_ERF_TYPES */

/* define if you have dag_get_stream_erf_types() */
/* #undef HAVE_DAG_GET_STREAM_ERF_TYPES */

/* define if you have streams capable DAG API */
/* #undef HAVE_DAG_STREAMS_API */

/* define if you have vdag_set_device_info() */
/* #undef HAVE_DAG_VDAG */

/* Define to 1 if you have the declaration of `ether_hostton', and to 0 if you
   don't. */
#define HAVE_DECL_ETHER_HOSTTON 1

/* define if you have a /dev/dlpi */
/* #undef HAVE_DEV_DLPI */

/* if passive_req_t primitive exists */
/* #undef HAVE_DLPI_PASSIVE */

/* Define to 1 if you have the `ether_hostton' function. */
#define HAVE_ETHER_HOSTTON 1

/* Define to 1 if fseeko (and presumably ftello) exists and is declared. */
#define HAVE_FSEEKO 1

/* on HP-UX 10.20 or later */
/* #undef HAVE_HPUX10_20_OR_LATER */

/* on HP-UX 9.x */
/* #undef HAVE_HPUX9 */

/* if ppa_info_t_dl_module_id exists */
/* #undef HAVE_HP_PPA_INFO_T_DL_MODULE_ID_1 */

/* Define to 1 if you have the <inttypes.h> header file. */
#define HAVE_INTTYPES_H 1

/* if libdlpi exists */
/* #undef HAVE_LIBDLPI */

/* if libnl exists */
/* #undef HAVE_LIBNL */

/* if libnl exists and is version 2.x */
/* #undef HAVE_LIBNL_2_x */

/* if libnl exists and is version 3.x */
/* #undef HAVE_LIBNL_3_x */

/* libnl has NLE_FAILURE */
/* #undef HAVE_LIBNL_NLE */

/* libnl has new-style socket api */
/* #undef HAVE_LIBNL_SOCKETS */

/* Define to 1 if you have the <limits.h> header file. */
#define HAVE_LIMITS_H 1

/* Define to 1 if you have the <linux/compiler.h> header file. */
/* #undef HAVE_LINUX_COMPILER_H */

/* Define to 1 if you have the <linux/ethtool.h> header file. */
#define HAVE_LINUX_ETHTOOL_H 1

/* Define to 1 if you have the <linux/if_bonding.h> header file. */
#define HAVE_LINUX_IF_BONDING_H 1

/* Define to 1 if you have the <linux/if_packet.h> header file. */
#define HAVE_LINUX_IF_PACKET_H 1

/* Define to 1 if you have the <linux/net_tstamp.h> header file. */
#define HAVE_LINUX_NET_TSTAMP_H 1

/* Define to 1 if you have the <linux/sockios.h> header file. */
#define HAVE_LINUX_SOCKIOS_H 1

/* if tp_vlan_tci exists */
#define HAVE_LINUX_TPACKET_AUXDATA_TP_VLAN_TCI 1

/* Define to 1 if you have the <linux/types.h> header file. */
#define HAVE_LINUX_TYPES_H 1

/* Define to 1 if you have the <linux/usbdevice_fs.h> header file. */
#define HAVE_LINUX_USBDEVICE_FS_H 1

/* Define to 1 if you have the <linux/wireless.h> header file. */
#define HAVE_LINUX_WIRELESS_H 1

/* Define to 1 if you have the <memory.h> header file. */
#define HAVE_MEMORY_H 1

/* Define to 1 if you have the <netinet/ether.h> header file. */
#define HAVE_NETINET_ETHER_H 1

/* Define to 1 if you have the <netinet/if_ether.h> header file. */
#define HAVE_NETINET_IF_ETHER_H 1

/* Define to 1 if you have the <netpacket/if_packet.h> header file. */
/* #undef HAVE_NETPACKET_IF_PACKET_H */

/* Define to 1 if you have the <netpacket/packet.h> header file. */
#define HAVE_NETPACKET_PACKET_H 1

/* Define to 1 if you have the <net/if_media.h> header file. */
/* #undef HAVE_NET_IF_MEDIA_H */

/* Define to 1 if you have the <net/pfvar.h> header file. */
/* #undef HAVE_NET_PFVAR_H */

/* if there's an os_proto.h for this platform, to use additional prototypes */
/* #undef HAVE_OS_PROTO_H */

/* define if net/pfvar.h defines PF_NAT through PF_NORDR */
/* #undef HAVE_PF_NAT_THROUGH_PF_NORDR */

/* define if you have the Septel API */
/* #undef HAVE_SEPTEL_API */

/* define if you have the Myricom SNF API */
/* #undef HAVE_SNF_API */

/* Define to 1 if you have the `snprintf' function. */
#define HAVE_SNPRINTF 1

/* if struct sockaddr has the sa_len member */
/* #undef HAVE_SOCKADDR_SA_LEN */

/* if struct sockaddr_storage exists */
#define HAVE_SOCKADDR_STORAGE 1

/* define if socklen_t is defined */
#define HAVE_SOCKLEN_T 1

/* On solaris */
/* #undef HAVE_SOLARIS */

/* Define to 1 if you have the <stdint.h> header file. */
#define HAVE_STDINT_H 1

/* Define to 1 if you have the <stdlib.h> header file. */
#define HAVE_STDLIB_H 1

/* Define to 1 if you have the `strerror' function. */
#define HAVE_STRERROR 1

/* Define to 1 if you have the <strings.h> header file. */
#define HAVE_STRINGS_H 1

/* Define to 1 if you have the <string.h> header file. */
#define HAVE_STRING_H 1

/* Define to 1 if you have the `strlcpy' function. */
/* #undef HAVE_STRLCPY */

/* Define to 1 if you have the `strtok_r' function. */
#define HAVE_STRTOK_R 1

/* Define to 1 if the system has the type `struct BPF_TIMEVAL'. */
/* #undef HAVE_STRUCT_BPF_TIMEVAL */

/* Define to 1 if the system has the type `struct ether_addr'. */
/* #undef HAVE_STRUCT_ETHER_ADDR */

/* Define to 1 if you have the <sys/bitypes.h> header file. */
#define HAVE_SYS_BITYPES_H 1

/* Define to 1 if you have the <sys/bufmod.h> header file. */
/* #undef HAVE_SYS_BUFMOD_H */

/* Define to 1 if you have the <sys/dlpi_ext.h> header file. */
/* #undef HAVE_SYS_DLPI_EXT_H */

/* Define to 1 if you have the <sys/ioccom.h> header file. */
/* #undef HAVE_SYS_IOCCOM_H */

/* Define to 1 if you have the <sys/select.h> header file. */
#define HAVE_SYS_SELECT_H 1

/* Define to 1 if you have the <sys/sockio.h> header file. */
/* #undef HAVE_SYS_SOCKIO_H */

/* Define to 1 if you have the <sys/stat.h> header file. */
#define HAVE_SYS_STAT_H 1

/* Define to 1 if you have the <sys/types.h> header file. */
#define HAVE_SYS_TYPES_H 1

/* define if you have the TurboCap API */
/* #undef HAVE_TC_API */

/* if if_packet.h has tpacket_stats defined */
#define HAVE_TPACKET_STATS 1

/* Define to 1 if you have the <unistd.h> header file. */
#define HAVE_UNISTD_H 1

/* if struct usbdevfs_ctrltransfer has bRequestType */
#define HAVE_USBDEVFS_CTRLTRANSFER_BREQUESTTYPE 1

/* Define to 1 if you have the `vsnprintf' function. */
#define HAVE_VSNPRINTF 1

/* define if the system supports zerocopy BPF */
/* #undef HAVE_ZEROCOPY_BPF */

/* define if your compiler has __attribute__ */
#define HAVE___ATTRIBUTE__ 1

/* IPv6 */
#define INET6 1

/* if unaligned access fails */
#define LBL_ALIGN 1

/* path for device for USB sniffing */
#define LINUX_USB_MON_DEV "/dev/usbmon"

/* Define to 1 if netinet/ether.h declares `ether_hostton' */
#define NETINET_ETHER_H_DECLARES_ETHER_HOSTTON /**/

/* Define to 1 if netinet/if_ether.h declares `ether_hostton' */
/* #undef NETINET_IF_ETHER_H_DECLARES_ETHER_HOSTTON */

/* do not use protochain */
/* #undef NO_PROTOCHAIN */

/* Define to the address where bug reports for this package should be sent. */
#define PACKAGE_BUGREPORT ""

/* Define to the full name of this package. */
#define PACKAGE_NAME ""

/* Define to the full name and version of this package. */
#define PACKAGE_STRING ""

/* Define to the one symbol short name of this package. */
#define PACKAGE_TARNAME ""

/* Define to the home page for this package. */
#define PACKAGE_URL ""

/* Define to the version of this package. */
#define PACKAGE_VERSION ""

/* /dev/dlpi directory */
/* #undef PCAP_DEV_PREFIX */

/* target host supports Bluetooth sniffing */
#define PCAP_SUPPORT_BT 1

/* target host supports Bluetooth Monitor */
#define PCAP_SUPPORT_BT_MONITOR /**/

/* support D-Bus sniffing */
#define PCAP_SUPPORT_DBUS 1

/* target host supports netfilter sniffing */
#define PCAP_SUPPORT_NETFILTER 1

/* use Linux packet ring capture if available */
#define PCAP_SUPPORT_PACKET_RING 1

/* target host supports USB sniffing */
#define PCAP_SUPPORT_USB 1

/* include ACN support */
/* #undef SITA */

/* if struct sockaddr_hci has hci_channel member */
#define SOCKADDR_HCI_HAS_HCI_CHANNEL /**/

/* Define to 1 if you have the ANSI C header files. */
#define STDC_HEADERS 1

/* Enable parser debugging */
/* #undef YYDEBUG */

/* Define to 1 if `lex' declares `yytext' as a `char *' by default, not a
   `char[]'. */
/* #undef YYTEXT_POINTER */

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

/* define on AIX to get certain functions */
/* #undef _SUN */

/* define if your compiler allows __attribute__((format)) without a warning */
#define __ATTRIBUTE___FORMAT_OK 1

/* to handle Ultrix compilers that don't support const in prototypes */
/* #undef const */

/* Define as token for inline if inlining supported */
#define inline inline

/* Define to `short' if int16_t not defined. */
/* #undef int16_t */

/* Define to `int' if int32_t not defined. */
/* #undef int32_t */

/* Define to `long long' if int64_t not defined. */
/* #undef int64_t */

/* Define to `signed char' if int8_t not defined. */
/* #undef int8_t */

/* on sinix */
/* #undef sinix */

/* Define to `unsigned short' if u_int16_t not defined. */
/* #undef u_int16_t */

/* Define to `unsigned int' if u_int32_t not defined. */
/* #undef u_int32_t */

/* Define to `unsigned long long' if u_int64_t not defined. */
/* #undef u_int64_t */

/* Define to `unsigned char' if u_int8_t not defined. */
/* #undef u_int8_t */
