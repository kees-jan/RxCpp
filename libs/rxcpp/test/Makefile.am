AM_CPPFLAGS = -I $(top_srcdir)/inc

if BOOST_UNITTESTS

check_PROGRAMS = tests

tests_SOURCES = \
	receiving-events-from-containers.cc \
	main.cc

tests_LDADD = ../../boost-test-helper/src/libsboosttesthelper.la

TESTS = tests

endif BOOST_UNITTESTS
