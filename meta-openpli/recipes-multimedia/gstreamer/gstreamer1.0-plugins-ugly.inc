require gstreamer1.0-plugins.inc

LICENSE = "GPLv2+ & LGPLv2.1+ & LGPLv2+"
LICENSE_FLAGS = "commercial"

DEPENDS += "gstreamer1.0-plugins-base libid3tag libmad"

inherit gettext


PACKAGECONFIG ??= " \
    orc a52dec lame mad mpeg2dec \
    cdio dvdread amrnb amrwb mad \
    "

PACKAGECONFIG[a52dec]   = "--enable-a52dec,--disable-a52dec,liba52"
PACKAGECONFIG[cdio]     = "--enable-cdio,--disable-cdio,libcdio"
PACKAGECONFIG[dvdread]  = "--enable-dvdread,--disable-dvdread,libdvdread"
PACKAGECONFIG[lame]     = "--enable-lame,--disable-lame,lame"
PACKAGECONFIG[mad]      = "--enable-mad,--disable-mad,libmad"
PACKAGECONFIG[mpeg2dec] = "--enable-mpeg2dec,--disable-mpeg2dec,mpeg2dec"
PACKAGECONFIG[x264]     = "--enable-x264,--disable-x264,x264"
PACKAGECONFIG[amrnb]    = "--enable-amrnb,--disable-amrnb,opencore-amr"
PACKAGECONFIG[amrwb]    = "--enable-amrwb,--disable-amrwb,opencore-amr"

EXTRA_OECONF += " \
    --disable-sidplay \
    --disable-twolame \
    "

FILES_${PN}-x264 += "${datadir}/gstreamer-1.0/presets/GstX264Enc.prs"
FILES_${PN}-amrnb += "${datadir}/gstreamer-1.0/presets/GstAmrnbEnc.prs"
