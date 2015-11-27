require conf/license/openpli-gplv2.inc
require softcam.inc
inherit cmake

DESCRIPTION = "OScam ${PV} Open Source Softcam"
LICENSE = "GPLv3"
LIC_FILES_CHKSUM = "file://COPYING;md5=d32239bcb673463ab874e80d47fae504"

SRCREV = "11174"
PV = "svn${SRCREV}"
PKGV = "${PV}"
SRC_URI = "svn://www.streamboard.tv/svn/oscam;protocol=http;module=trunk;scmdata=keep"

DEPENDS = "libusb openssl"

S = "${WORKDIR}/trunk"
B = "${S}"
CAMNAME = "oscam"
CAMSTART = "/usr/bin/oscam -c /etc/tuxbox/config/oscam -b -r2 --pidfile /tmp/oscam.pid"
CAMSTOP = "kill \`cat /tmp/oscam.pid\` 2> /dev/null"

SRC_URI += " \
	file://oscam.conf \
	file://oscam.server \
	file://oscam.user"

CONFFILES = "/etc/tuxbox/config/oscam/oscam.conf /etc/tuxbox/config/oscam/oscam.server /etc/tuxbox/config/oscam/oscam.user"

FILES_${PN} = "/usr/bin/oscam /etc/tuxbox/config/oscam/* /etc/init.d/softcam.oscam"

EXTRA_OECMAKE += "\
	-DOSCAM_SYSTEM_NAME=Tuxbox \
	-DWEBIF=1 \
	-DWITH_STAPI=0 \
	-DHAVE_LIBUSB=1 \
	-DSTATIC_LIBUSB=1 \
	-DWITH_SSL=1 \
	-DHAVE_PCSC=0"

do_install() {
	install -d ${D}/etc/tuxbox/config/oscam
	install -m 0644 ${WORKDIR}/oscam.* ${D}/etc/tuxbox/config/oscam/
	install -d ${D}/usr/bin
	install -m 0755 ${B}/oscam ${D}/usr/bin
}
