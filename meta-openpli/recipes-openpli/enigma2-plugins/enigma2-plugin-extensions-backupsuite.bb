DESCRIPTION = "Backup Suite"
LICENSE = "GPLv2"

LIC_FILES_CHKSUM = "file://usr/lib/enigma2/python/Plugins/Extensions/BackupSuite/GNU_LICENSE.txt;md5=8aab2037d6ccded90e5a3a3849bc60dc"

SRC_URI = "git://github.com/martinxp/enigma2-plugin-extensions-backupsuite.git"

SRCREV = "${AUTOREV}"

inherit gitpkgv

S = "${WORKDIR}/git"
SRC = "${S}/usr/lib/enigma2/python/Plugins/Extensions/BackupSuite"
DEST = "${D}/usr/lib/enigma2/python/Plugins/Extensions/BackupSuite"

PV = "21+git${SRCPV}"
PKGV = "21+git${GITPKGV}"
PR = "r0"

RDEPENDS_${PN} = "mtd-utils mtd-utils-ubifs ofgwrite"

FILES_${PN} = "/usr/lib/enigma2/python/Plugins/Extensions/BackupSuite"

do_install_append() {
	install -d ${DEST}
	cp -rp ${SRC}/* ${DEST}
	# remove the files we do not want in our package
	find ${DEST} -name '*.pyo' -exec rm {} \;
	find ${DEST} -name '*.po' -exec rm {} \;
}
