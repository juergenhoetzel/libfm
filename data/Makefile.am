SUBDIRS=ui

mimedir = $(datadir)/mime/packages
mime_DATA = libfm.xml

libfmconfdir = $(sysconfdir)/xdg/libfm
libfmconf_DATA = libfm.conf

pkglib_SCRIPTS = gnome-terminal
CLEANFILES = $(pkglib_SCRIPTS)

EXTRA_DIST= \
	$(libfmconf_DATA) \
	$(mime_DATA)

