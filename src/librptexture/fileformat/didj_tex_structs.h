/****************************************************************************
 * ROM Properties Page shell extension. (librptexture)                      *
 * didj_tex_structs.h: Leapster Didj .tex format data structures.           *
 *                                                                          *
 * Copyright (c) 2019 by David Korth.                                       *
 * SPDX-License-Identifier: GPL-2.0-or-later                                *
 ****************************************************************************/

#ifndef __ROMPROPERTIES_LIBRPTEXTURE_FILEFORMAT_DIDJ_TEX_STRUCTS_H__
#define __ROMPROPERTIES_LIBRPTEXTURE_FILEFORMAT_DIDJ_TEX_STRUCTS_H__

#include "librpbase/common.h"
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#pragma pack(1)

/**
 * Leapster Didj .tex: File header.
 * Reverse-engineered from Didj .tex files.
 *
 * NOTE: The actual image size is usually a power of two.
 * It should be rescaled to the display size when rendering.
 * rom-properties will use the actual size.
 *
 * All fields are in little-endian.
 */
#define DIDJ_TEX_HEADER_MAGIC 3
typedef struct PACKED _Didj_Tex_Header {
	uint32_t magic;		// [0x000] Magic number? (always 3)
	uint32_t width_disp;	// [0x004] Width [display size]
	uint32_t height_disp;	// [0x008] Height [display size]
	uint32_t width;		// [0x00C] Width [actual size]
	uint32_t height;	// [0x010] Height [actual size]
	uint32_t uncompr_size;	// [0x014] Uncompressed data size, including palette
	uint32_t px_format;	// [0x018] Pixel format (see Didj_Pixel_Format_e)
	uint32_t num_images;	// [0x01C] Number of images? (always 1)
	uint32_t compr_size;	// [0x020] Compressed size (zlib)
} Didj_Tex_Header;
ASSERT_STRUCT(Didj_Tex_Header, 36);

/**
 * Pixel format.
 */
typedef enum {
	DIDJ_PIXEL_FORMAT_RGB565	= 1,	// RGB565
	DIDJ_PIXEL_FORMAT_UNK16		= 3,	// Unknown 16-bit format

	DIDJ_PIXEL_FORMAT_8BPP_RGB565	= 4,	// 8bpp; palette is RGB565
	DIDJ_PIXEL_FORMAT_8BPP_UNK16	= 6,	// 8bpp; palette is unknown 16-bit [TODO: Transparency?]

	DIDJ_PIXEL_FORMAT_4BPP_RGB565	= 7,	// 4bpp; palette is RGB565
	DIDJ_PIXEL_FORMAT_4BPP_UNK16	= 9,	// 4bpp; palette is unknown 16-bit [TODO: Transparency?]
} Didj_Pixel_Format_e;

#pragma pack()

#ifdef __cplusplus
}
#endif

#endif /* __ROMPROPERTIES_LIBRPTEXTURE_FILEFORMAT_DIDJ_TEX_STRUCTS_H__ */