# Author: Alexander Rykovanov 2013
#
# Distributed under the GNU LGPL License
# (See accompanying file LICENSE or copy at 
# http://www.gnu.org/licenses/lgpl.html)
#

AC_INIT([opcua-wsdl], [0.1.3], [rykovanov.as@gmail.com])
AC_CONFIG_AUX_DIR([.])
AC_CONFIG_SRCDIR([src/soap_module.cpp])
AM_INIT_AUTOMAKE([-Wall -Werror])

CXXFLAGS="-O0 -g -Wall -std=c++0x"

AC_PROG_CXX
AM_PROG_AR
AC_PROG_LIBTOOL

AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_HEADER([config.h])

#check headers
AC_CHECK_HEADERS([unistd.h])

PKG_CHECK_MODULES([GSOAP], ["gsoapssl++"])

AC_ARG_WITH([gtest], 
            [AS_HELP_STRING([--with-gtest=DIR], [defines path to gtest root directory])],
            [ 
              AC_SUBST([GTEST_LIB], [-Wl,--whole-archive,$with_gtest/lib/.libs/libgtest.a,--no-whole-archive])
              AC_SUBST([GTEST_MAIN_LIB], [-Wl,--whole-archive,$with_gtest/lib/.libs/libgtest_main.a,--no-whole-archive])
              AC_SUBST([GTEST_INCLUDES], [-I$with_gtest/include])
              AC_MSG_NOTICE([Gtest path: $GTEST_INCLUDES]) 
            ], 
            [ 
              AC_SUBST([GTEST_LIB], [-lgtest])
              AC_SUBST([GTEST_MAIN_LIB], [-lgtest_main])
           ])

AC_ARG_WITH([gmock], 
            [AS_HELP_STRING([--with-gmock=DIR], [defines path to gmock root directory])],
            [ 
              AC_SUBST([GMOCK_LIB], [-Wl,--whole-archive,$with_gmock/lib/.libs/libgmock.a,--no-whole-archive])
              AC_SUBST([GMOCK_INCLUDES], [-I$with_gmock/include])
              AC_MSG_NOTICE([gmock path: $GMOCK_INCLUDES]) 
            ], 
            [ 
              AC_SUBST([GMOCK_LIB], [-lgmock])
           ])


AC_ARG_WITH([opcuaserver],
            [AS_HELP_STRING([--with-opcuaserver=DIR], [defines path to the root directory where opcua-server installed.])],
            [
              AC_SUBST([OPCUA_INCLUDES], ["-I$with_opcuaserver/include -I/usr/include/libxml2"])
              AC_SUBST([OPCUA_LIBS], ["-L$with_opcuaserver/lib -lopcuacore -lxml2 -lopc_tcp_client -lopcuabinary"])
    
              AC_MSG_NOTICE([opcuaserver installation path: $with_opcuaserver])
            ],
            [
              AC_SUBST([OPCUA_INCLUDES], ["-I/usr/include/libxml2"])
              AC_SUBST([OPCUA_LIBS], ["-lopcuacore -lxml2 -lopc_tcp_client -lopcuabinary"])
            ])


AC_SUBST([RELEASE_DATE], [$(date -R)])

#################################################################
AC_CONFIG_FILES([debian/changelog Makefile])

AC_OUTPUT

