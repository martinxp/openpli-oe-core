MACHINE_FEATURES_BACKFILL_CONSIDERED = "rtc"


MACHINE_ESSENTIAL_EXTRA_RDEPENDS = " \
	dags-dvb-modules-${MACHINE} \
	dags-shutdown \
	ntfs-3g \
	"


MACHINE_EXTRA_RRECOMMENDS = " \
	gstreamer1.0-plugin-dvbmediasink \
	splash-bootlogo \
	"

KERNEL_MODULE_AUTOLOAD += "xfs"


EXTRA_IMAGEDEPENDS += "\
	"

TARGET_ARCH = "mipsel"
DEFAULTTUNE = "mips32el"

GLIBC_EXTRA_OECONF = "--with-tls"
DVBMEDIASINK_CONFIG = "--with-dags --with-pcm --with-eac3 --with-amr --with-wmv"



PREFERRED_VERSION_linux-${MACHINE} = "4.2.1"
PREFERRED_VERSION_linux-libc-headers = "4.2.1"

KV = "linux-kernel-4.2.1"

PREFERRED_PROVIDER_virtual/kernel = "linux-${MACHINE}"

IMAGE_FSTYPES ?= "ubi"

UBI_VOLNAME = "rootfs"
MKUBIFS_ARGS = "-m 2048 -e 126976 -c 4096 -F"
UBINIZE_ARGS = "-m 2048 -p 128KiB"

IMAGEDIR ?= "${MACHINE}"
EXTRA_IMAGECMD_COMPAT = " --eraseblock=0x20000 -n -l --pagesize=0x800 "

IMAGE_CMD_ubi_prepend = " \
        mkfs.jffs2 --root=${IMAGE_ROOTFS}/boot --faketime \
        --disable-compressor=lzo --compression-mode=size \
        --output=${DEPLOY_DIR_IMAGE}/${IMAGE_NAME}.boot.jffs2 \
        ${EXTRA_IMAGECMD_COMPAT}; rm -rf ${IMAGE_ROOTFS}/boot/*; \
        "

IMAGE_CMD_ubi_append = " \
        mkdir -p ${DEPLOY_DIR_IMAGE}/update/${MACHINE}/cfe/; \
        cp ${DEPLOY_DIR_IMAGE}/${IMAGE_NAME}.rootfs.ubi ${DEPLOY_DIR_IMAGE}/update/${MACHINE}/cfe/oe_rootfs.bin; \
        cp ${DEPLOY_DIR_IMAGE}/${MACHINE}_splash.bmp ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/splash.bmp; \
        cp ${DEPLOY_DIR_IMAGE}/${MACHINE}_splash1.bmp ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/splash1.bmp; \
        cp ${DEPLOY_DIR_IMAGE}/${MACHINE}_splash2.bmp ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/splash2.bmp; \
        cp ${DEPLOY_DIR_IMAGE}/${MACHINE}_splash3.bmp ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/splash3.bmp; \
        gzip -f -9c ${DEPLOY_DIR_IMAGE}/vmlinux-${MACHINE}.bin > ${DEPLOY_DIR_IMAGE}/update/${MACHINE}/cfe/oe_kernel.bin; \
        cd ${DEPLOY_DIR_IMAGE}; \
        zip ${DISTRO_NAME}-${DISTRO_VERSION}-${MACHINE}-${DATE}_usb.zip update/${MACHINE}/cfe/*; \
	rm -rf update; \
	rm -rf ${DEPLOY_DIR_IMAGE}/enigma2_2.7*; \
	cp ${DEPLOY_DIR_IPK}/${MACHINE}/enigma2_2.7* ${DEPLOY_DIR_IMAGE}; \
	gzip -f -c ${DEPLOY_DIR_IMAGE}/vmlinux-*.bin > ${DEPLOY_DIR_IMAGE}/vmlinux-${MACHINE}.bin.gz; \
	cp ${DEPLOY_DIR_IMAGE}/vmlinux-${MACHINE}.bin.gz ${DEPLOY_DIR_IMAGE}/oe_kernel.bin; \
        "



MACHINE_FEATURES += "dvb-c alsa usbhost dvbusb usbhost kernelwifi wlan 3dtv switchoff osdposition hdmicec"

require conf/machine/include/tune-mips32.inc
