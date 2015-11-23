MACHINE_FEATURES_BACKFILL_CONSIDERED = "rtc"


MACHINE_ESSENTIAL_EXTRA_RDEPENDS = " \
	entwopia-dvb-modules-${MACHINE} \
	"


MACHINE_EXTRA_RRECOMMENDS = " \
	gstreamer1.0-plugin-dvbmediasink \
	"

KERNEL_MODULE_AUTOLOAD += "xfs"


EXTRA_IMAGEDEPENDS += "\
	"

TARGET_ARCH = "mipsel"
DEFAULTTUNE = "mips32el"

GLIBC_EXTRA_OECONF = "--with-tls --with-__thread"
DVBMEDIASINK_CONFIG = "--with-wma --with-wmv --with-pcm --with-dts --with-eac3"


PREFERRED_VERSION_linux-enfinity = "3.14.2"
PREFERRED_VERSION_linux-libc-headers = "3.13"

KV = "linux-kernel-3.14.2"

PREFERRED_PROVIDER_virtual/kernel = "linux-enfinity"

IMAGE_FSTYPES ?= "ubi"

UBI_VOLNAME = "rootfs"
MKUBIFS_ARGS = "-m 2048 -e 126976 -c 4096"
UBINIZE_ARGS = "-m 2048 -p 128KiB"

IMAGEDIR ?= "${MACHINE}"


IMAGE_CMD_ubi_prepend = " \
	rm -Rf ${IMAGE_ROOTFS}/tmp/*; \
	"

IMAGE_CMD_ubi_append = " \
	mkdir -p ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}; \
	cp ${DEPLOY_DIR_IMAGE}/${IMAGE_NAME}.rootfs.ubi ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/rootfs.bin; \
	gzip -c ${DEPLOY_DIR_IMAGE}/vmlinux-${MACHINE}.bin > ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/kernel.bin; \
	echo ${DISTRO_NAME}-${DISTRO_VERSION}-${DATE} > ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/imageversion; \
	echo "rename this file to 'force' to force an update without confirmation" > ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/noforce; \
	cd ${DEPLOY_DIR_IMAGE}; \
	zip ${DISTRO_NAME}-${DISTRO_VERSION}-${MACHINE}-${DATE}_usb.zip ${IMAGEDIR}/*; \
	rm -Rf ${IMAGEDIR}; \
	"





MACHINE_FEATURES += "3dtv alsa hdmicec ci switchoff bootsplash osdposition"

require conf/machine/include/tune-mips32.inc
