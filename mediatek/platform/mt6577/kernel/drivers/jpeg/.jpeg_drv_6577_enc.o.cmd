cmd_mediatek/platform/mt6577/kernel/drivers/jpeg/jpeg_drv_6577_enc.o := arm-linux-androideabi-gcc -Wp,-MD,mediatek/platform/mt6577/kernel/drivers/jpeg/.jpeg_drv_6577_enc.o.d  -nostdinc -isystem /home/xiuyongtang/OrderTinno/A_GPL/A_GPL/arm-linux-androideabi-4.4.x/bin/../lib/gcc/arm-linux-androideabi/4.4.3/include -I/home/xiuyongtang/OrderTinno/A_GPL/A_GPL/kernel/arch/arm/include -Iarch/arm/include/generated -Iinclude  -include include/generated/autoconf.h -I./mediatek/custom//s8073/common -I../mediatek/platform/mt6577/kernel/core/include/ -I../mediatek/source/kernel/include/ -I../mediatek/custom/out/s8073/kernel/magnetometer/ -I../mediatek/custom/out/s8073/kernel/headset/ -I../mediatek/custom/out/s8073/kernel/kpd/ -I../mediatek/custom/out/s8073/kernel/accelerometer/ -I../mediatek/custom/out/s8073/kernel/touchpanel/ -I../mediatek/custom/out/s8073/kernel/rtc/ -I../mediatek/custom/out/s8073/kernel/core/ -I../mediatek/custom/out/s8073/kernel/leds/ -I../mediatek/custom/out/s8073/kernel/battery/ -I../mediatek/custom/out/s8073/kernel/camera/ -I../mediatek/custom/out/s8073/kernel/alsps/ -I../mediatek/custom/out/s8073/kernel/vibrator/ -I../mediatek/custom/out/s8073/kernel/dct/ -I../mediatek/custom/out/s8073/kernel/usb/ -I../mediatek/custom/out/s8073/kernel/magnetometer/inc/ -I../mediatek/custom/out/s8073/kernel/gyroscope/inc/ -I../mediatek/custom/out/s8073/kernel/sound/inc/ -I../mediatek/custom/out/s8073/kernel/sound/ -I../mediatek/custom/out/s8073/kernel/lens/inc/ -I../mediatek/custom/out/s8073/kernel/lens/ -I../mediatek/custom/out/s8073/kernel/accelerometer/inc/ -I../mediatek/custom/out/s8073/kernel/eeprom/inc/ -I../mediatek/custom/out/s8073/kernel/eeprom/ -I../mediatek/custom/out/s8073/kernel/hdmi/inc/ -I../mediatek/custom/out/s8073/kernel/jogball/inc/ -I../mediatek/custom/out/s8073/kernel/leds/inc/ -I../mediatek/custom/out/s8073/kernel/barometer/inc/ -I../mediatek/custom/out/s8073/kernel/./ -I../mediatek/custom/out/s8073/kernel/lcm/inc/ -I../mediatek/custom/out/s8073/kernel/lcm/ -I../mediatek/custom/out/s8073/kernel/alsps/inc/ -I../mediatek/custom/out/s8073/kernel/imgsensor/inc/ -I../mediatek/custom/out/s8073/kernel/imgsensor/ -I../mediatek/custom/out/s8073/kernel/flashlight/inc/ -I../mediatek/custom/out/s8073/kernel/flashlight/ -I../mediatek/custom/out/s8073/kernel/ccci/ -I../mediatek/custom/out/s8073/hal/sensors/ -I../mediatek/custom/out/s8073/hal/camera/ -I../mediatek/custom/out/s8073/hal/audioflinger/ -I../mediatek/custom/out/s8073/hal/combo/ -I../mediatek/custom/out/s8073/hal/inc/ -I../mediatek/custom/out/s8073/hal/ant/ -I../mediatek/custom/out/s8073/hal/fmradio/ -I../mediatek/custom/out/s8073/hal/lens/ -I../mediatek/custom/out/s8073/hal/eeprom/ -I../mediatek/custom/out/s8073/hal/vt/ -I../mediatek/custom/out/s8073/hal/bluetooth/ -I../mediatek/custom/out/s8073/hal/imgsensor/ -I../mediatek/custom/out/s8073/hal/flashlight/ -I../mediatek/custom/out/s8073/hal/matv/ -I../mediatek/custom/out/s8073/common -D__KERNEL__ -mlittle-endian -DMODEM_3G -Imediatek/platform/mt6577/kernel/core/include -Wall -Wundef -Wstrict-prototypes -Wno-trigraphs -fno-strict-aliasing -fno-common -Werror-implicit-function-declaration -Wno-format-security -fno-delete-null-pointer-checks -O2 -fno-pic -marm -fno-dwarf2-cfi-asm -fno-omit-frame-pointer -mapcs -mno-sched-prolog -mabi=aapcs-linux -mno-thumb-interwork -D__LINUX_ARM_ARCH__=7 -march=armv7-a -msoft-float -Uarm -DHAVE_XLOG_FEATURE -DMTK_WB_SPEECH_SUPPORT -DMTK_AUTORAMA_SUPPORT -DMTK_MULTI_STORAGE_SUPPORT -DCUSTOM_KERNEL_ALSPS -DMTK_EAP_SIM_AKA -DMTK_TVOUT_SUPPORT -DCUSTOM_KERNEL_ACCELEROMETER -DMTK_FD_SUPPORT -DHAVE_AACENCODE_FEATURE -DMTK_IPV6_SUPPORT -DMTK_MASS_STORAGE -DMTK_FACEBEAUTY_SUPPORT -DMTK_MAV_SUPPORT -DMTK_CAMERA_BSP_SUPPORT -DCUSTOM_KERNEL_MAGNETOMETER -DMTK_VT3G324M_SUPPORT -DHAVE_AWBENCODE_FEATURE -DMTK_CAMERA_APP_3DHW_SUPPORT -DMTK_SENSOR_SUPPORT -DMTK_M4U_SUPPORT -DMTK_HDR_SUPPORT -DMTK_EMMC_SUPPORT -DMTK_AUTO_DETECT_ACCELEROMETER -DMTK_USES_HD_VIDEO -DMTK_SD_REINIT_SUPPORT -DBCM_GPS_SUPPORT -DBCM_BT_SUPPORT -DBCM_WLAN_SUPPORT -DBCM_FM_SUPPORT -DMTK_2SDCARD_SWAP -DMTK_SWAP_STATIC_MODE -DMT6577 -DFM50AF -DDUMMY_LENS -DLT4015W_DSI -DR61408 -DNT35510_DSI -DMODEM_3G -DOV5647_MIPI_RAW -DBCM4330 -DCONSTANT_FLASHLIGHT -DHI704_YUV -DDUMMY_LENS -DOV5647_MIPI_RAW -DHI704_YUV -DFM_ANALOG_INPUT -DFM50AF -DFM_ANALOG_OUTPUT -DBCM4330_FM -DMTK_LCM_PHYSICAL_ROTATION=\"0\" -DLCM_WIDTH=\"480\" -DMTK_SHARE_MODEM_SUPPORT=\"2\" -DMTK_NEON_SUPPORT=\"yes\" -DMTK_SHARE_MODEM_CURRENT=\"2\" -DLCM_HEIGHT=\"800\" -DCUSTOM_BUILD_VERNO=\"S8073B_PP_F4_B1B8_2.09_V12\" -Wframe-larger-than=1024 -fno-stack-protector -fno-omit-frame-pointer -fno-optimize-sibling-calls -g -Wdeclaration-after-statement -Wno-pointer-sign -fno-strict-overflow -fconserve-stack    -D"KBUILD_STR(s)=\#s" -D"KBUILD_BASENAME=KBUILD_STR(jpeg_drv_6577_enc)"  -D"KBUILD_MODNAME=KBUILD_STR(jpeg_driver)" -c -o mediatek/platform/mt6577/kernel/drivers/jpeg/jpeg_drv_6577_enc.o mediatek/platform/mt6577/kernel/drivers/jpeg/jpeg_drv_6577_enc.c

source_mediatek/platform/mt6577/kernel/drivers/jpeg/jpeg_drv_6577_enc.o := mediatek/platform/mt6577/kernel/drivers/jpeg/jpeg_drv_6577_enc.c

deps_mediatek/platform/mt6577/kernel/drivers/jpeg/jpeg_drv_6577_enc.o := \
  ../mediatek/platform/mt6577/kernel/core/include/mach/mt6577_typedefs.h \
  include/linux/bug.h \
    $(wildcard include/config/generic/bug.h) \
  /home/xiuyongtang/OrderTinno/A_GPL/A_GPL/kernel/arch/arm/include/asm/bug.h \
    $(wildcard include/config/bug.h) \
    $(wildcard include/config/debug/bugverbose.h) \
  include/asm-generic/bug.h \
    $(wildcard include/config/generic/bug/relative/pointers.h) \
    $(wildcard include/config/smp.h) \
  include/linux/compiler.h \
    $(wildcard include/config/sparse/rcu/pointer.h) \
    $(wildcard include/config/trace/branch/profiling.h) \
    $(wildcard include/config/profile/all/branches.h) \
    $(wildcard include/config/enable/must/check.h) \
    $(wildcard include/config/enable/warn/deprecated.h) \
  include/linux/compiler-gcc.h \
    $(wildcard include/config/arch/supports/optimized/inlining.h) \
    $(wildcard include/config/optimize/inlining.h) \
  include/linux/compiler-gcc4.h \
  mediatek/platform/mt6577/kernel/drivers/jpeg/jpeg_drv_6577_reg.h \
  ../mediatek/platform/mt6577/kernel/core/include/mach/mt6577_reg_base.h \
    $(wildcard include/config/base.h) \

mediatek/platform/mt6577/kernel/drivers/jpeg/jpeg_drv_6577_enc.o: $(deps_mediatek/platform/mt6577/kernel/drivers/jpeg/jpeg_drv_6577_enc.o)

$(deps_mediatek/platform/mt6577/kernel/drivers/jpeg/jpeg_drv_6577_enc.o):
