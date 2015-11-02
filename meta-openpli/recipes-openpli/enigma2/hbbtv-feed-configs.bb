DESCRIPTION = "Configuration files for 3rd-party feeds"
DISTRO_FEED_PREFIX="http://openpli.ido.cz/openpli-4/"
PR = "r1"

require conf/license/openpli-gplv2.inc

# Use the PLi download server, regardless of where we are. Even for "private" feeds,
# the 3rd party plugins originate here.
DISTRO_HOST = "openpli.ido.cz/openpli-4"
FEEDS = "hbbtv"


do_compile() {
[ ! -d ${S}/${sysconfdir}/opkg ] && mkdir -p ${S}/${sysconfdir}/opkg
for feed in ${FEEDS}; do
echo "src/gz openpli-${feed} ${DISTRO_FEED_PREFIX}${feed}" > ${S}/${sysconfdir}/opkg/${feed}-feed.conf
done
}
do_install () {
        install -d ${D}${sysconfdir}/opkg
        install -m 0644 ${S}/${sysconfdir}/opkg/* ${D}${sysconfdir}/opkg/
}

PACKAGE_ARCH = "${MACHINE_ARCH}"

CONFFILES_${PN} += '${@ " ".join( [ ( "${sysconfdir}/opkg/%s-feed.conf" % feed ) for feed in "${FEEDS}".split() ] ) }'
