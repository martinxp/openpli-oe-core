DESCRIPTION = "Hardware drivers for ${MACHINE}"
SECTION = "base"
PRIORITY = "required"
LICENSE = "CLOSED"

KV = "4.2.1"
KV_EXTRA = ""
PV = "${KV}+${SRCDATE}"

SRCDATE = "20151126"

SRC_URI = "http://en3homeftp.net/release/images/oedrivers/bcmlinuxdvb_${CHIP}-${KV}-${SRCDATE}.tar.gz"

S = "${WORKDIR}"

INHIBIT_PACKAGE_STRIP = "1"

inherit module

do_compile() {
}

FILES_${PN} += "${sysconfdir}/modules-load.d/_${MACHINE}.conf"

do_install() {
		install -d ${D}/lib/modules/${KV}/extra
		for f in ${S}/lib/modules/${KV}/extra/*.ko; do
			install -m 0644 $f ${D}/lib/modules/${KV}/extra;
		done
		install -d ${D}/${sysconfdir}/modules-load.d
		for i in `ls ${D}/lib/modules/${KV}/extra | grep \\.ko | sed -e 's/.ko//g'`; do
		    echo $i _hwtype=\$hwtypenum >> ${D}/${sysconfdir}/modules-load.d/_${MACHINE}.conf
		done
}

SRC_URI[md5sum] = "0d17594102821fdf238836d404d2c0cc"
SRC_URI[sha256sum] = "950030e709cc165bcaf0bcbea4896a9587325a1ca7a3d293c281dc8d38aa71c0"
