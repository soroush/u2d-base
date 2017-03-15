AC_PREREQ([2.69])
AC_INIT([libu2d], [1.0.0], [https://github.com/soroush/u2d-base])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_MACRO_DIR([m4])

# Checks for programs.
AC_PROG_CXX
AC_PROG_AWK
AC_PROG_CC
AC_PROG_CPP
AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_MAKE_SET
AC_PROG_RANLIB

# Check for C++11 compiler
AX_CXX_COMPILE_STDCXX_11([noext],[mandatory])

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([arpa/inet.h])
AC_CHECK_HEADERS([netinet/in.h])
AC_CHECK_HEADERS([stdint.h])
AC_CHECK_HEADERS([string.h])
AC_CHECK_HEADERS([sys/socket.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL
AC_C_INLINE
AC_TYPE_SIZE_T
AC_TYPE_SSIZE_T
AC_TYPE_UINT16_T
AC_TYPE_UINT32_T
AC_TYPE_UINT8_T

# Checks for library functions.
AC_FUNC_ERROR_AT_LINE
AC_CHECK_FUNCS([socket])
AC_CHECK_FUNCS([strerror])

AC_CONFIG_FILES([Makefile
                 src/Makefile
                 src/network/Makefile
                 src/geometry/Makefile
                 src/perception/Makefile
                 src/parser/Makefile
                 test/Makefile
                 libu2d.pc])

AC_SUBST([U2D_SO_VERSION], [1:0:0])
AC_SUBST([U2D_API_VERSION], [1.0.0])

# Configure automake
AM_INIT_AUTOMAKE
AM_SILENT_RULES([yes])

LT_INIT([static shared pic-only])

AC_OUTPUT
