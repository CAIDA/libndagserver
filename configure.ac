# Super primitive configure script

AC_INIT(libndagserver, 0.1.0, salcock@wand.net.nz)

LIBNDAGSERVER_MAJOR_VERSION=0
LIBNDAGSERVER_MID_VERSION=1
LIBNDAGSERVER_MINOR_VERSION=0

AC_DEFINE_UNQUOTED([LIBNDAGSERVER_MAJOR_VERSION],$LIBNDAGSERVER_MAJOR_VERSION,
	[libndagserver major version])
AC_DEFINE_UNQUOTED([LIBNDAGSERVER_MID_VERSION],$LIBNDAGSERVER_MID_VERSION,
	[libndagserver mid version])
AC_DEFINE_UNQUOTED([LIBNDAGSERVER_MINOR_VERSION],$LIBNDAGSERVER_MINOR_VERSION,
	[libndagserver minor version])

LT_INIT

AM_INIT_AUTOMAKE([foreign subdir-objects])
AC_CONFIG_SRCDIR(ndagmulticaster.c)
AM_CONFIG_HEADER(config.h)
AC_CONFIG_MACRO_DIR([m4])

m4_ifdef([AM_SILENT_RULES],[AM_SILENT_RULES([yes])])

AC_PREFIX_DEFAULT(/usr/local/)

AC_PROG_CC
AC_PROG_INSTALL

AC_PROG_LIBTOOL

gcc_PACKED

AC_CHECK_LIB([trace], [trace_get_payload_length],,
  [AC_MSG_ERROR(Required library libtrace not found)]
)
AC_CHECK_LIB([wandio], [wandio_create],,
  [AC_MSG_ERROR(Required library libwandio not found)]
)
AC_CHECK_LIB([pthread], [pthread_create],,
  [AC_MSG_ERROR(Required library libpthread not found)]
)

AC_CHECK_FUNCS([recvmmsg sendmmsg],,
  [AC_MSG_ERROR(Required functions (recvmmsg, sendmmsg) not found.)]
)

AC_SUBST([LIBNDAGSERVER_MAJOR_VERSION])
AC_SUBST([LIBNDAGSERVER_MID_VERSION])
AC_SUBST([LIBNDAGSERVER_MINOR_VERSION])

AC_CONFIG_FILES([Makefile])

AC_OUTPUT
