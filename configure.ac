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
AM_PROG_AR

# Check for C++11 compiler
AX_CXX_COMPILE_STDCXX_11([noext],[mandatory])

# Checks for libraries.

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

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
