/*
 * (C) Copyright 2008
 * MediaTek <www.mediatek.com>
 * Jauping Chen <jauping.chen@mediatek.com>
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#ifndef __MT65XX_META_H
#define __MT65XX_META_H

#include <common.h>
#include <asm/arch/mt65xx_typedefs.h>

#define META_BOOTARGS  " init=sbin/meta_init rdinit=sbin/meta_init"
#define ADV_META_BOOTARGS  " init=sbin/advanced_meta_init rdinit=sbin/advanced_meta_init"
#define CONFIG_META_BAUDRATE	 115200

extern BOOL meta_detection(void);

#endif /* __MT65XX_META_H */

