include gstreamer1.0-plugins-good.inc

LIC_FILES_CHKSUM = "file://COPYING;md5=a6f89e2100d9b6cdffcea4f398e37343 \
                    file://common/coverage/coverage-report.pl;beginline=2;endline=17;md5=a4e1830fce078028c8f0974161272607 \
                    file://gst/replaygain/rganalysis.c;beginline=1;endline=23;md5=b60ebefd5b2f5a8e0cab6bfee391a5fe"

SRC_URI += "file://0001-gstrtpmp4gpay-set-dafault-value-for-MPEG4-without-co.patch \
"

SRC_URI[md5sum] = "a930f5ff133f17baf39d2876628b7890"
SRC_URI[sha256sum] = "86d4b814099f7b7b16be19d4b94fa41002ac01fdf1525b07c5764d54c0605935"

S = "${WORKDIR}/gst-plugins-good-${PV}"
