AC_INIT([libu2d], [0.1.0], [soroush-r@users.sf.net], [libu2d], [http://sourceforge.net/p/u2d-base/])
AC_PREREQ([2.59])
AM_INIT_AUTOMAKE([1.10 -Wall no-define])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_HEADERS([config.h])
AC_LANG([C++])
AC_PROG_CPP
AC_PROG_CXX
AX_CXX_COMPILE_STDCXX_11()
AC_TYPE_SIZE_T
AC_HEADER_STDBOOL
LT_INIT([shared static])
AC_SUBST([U2D_SO_VERSION], [0:1:0])
AC_SUBST([U2D_API_VERSION], [0.1.0])
AC_CONFIG_FILES([Makefile src/Makefile
                 libu2d.pc:libu2d.pc.in])
AC_OUTPUT
