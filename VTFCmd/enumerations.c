/*
 * VTFCmd
 * Copyright (C) 2005-2010 Neil Jedrzejewski & Ryan Gregg
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 */

#include "stdafx.h"

VTFImageFormat StringToImageFormat(const vlChar *cString)
{
	if(stricmp(cString, "RGBA8888") == 0)
	{
		return IMAGE_FORMAT_RGBA8888;
	}
	else if(stricmp(cString, "ABGR8888") == 0)
	{
		return IMAGE_FORMAT_ABGR8888;
	}
	else if(stricmp(cString, "RGB888") == 0)
	{
		return IMAGE_FORMAT_RGB888;
	}
	else if(stricmp(cString, "BGR888") == 0)
	{
		return IMAGE_FORMAT_BGR888;
	}
	else if(stricmp(cString, "RGB565") == 0)
	{
		return IMAGE_FORMAT_RGB565;
	}
	else if(stricmp(cString, "I8") == 0)
	{
		return IMAGE_FORMAT_I8;
	}
	else if(stricmp(cString, "IA88") == 0)
	{
		return IMAGE_FORMAT_IA88;
	}
	else if(stricmp(cString, "A8") == 0)
	{
		return IMAGE_FORMAT_A8;
	}
	else if(stricmp(cString, "RGB888_BLUESCREEN") == 0)
	{
		return IMAGE_FORMAT_RGB888_BLUESCREEN;
	}
	else if(stricmp(cString, "BGR888_BLUESCREEN") == 0)
	{
		return IMAGE_FORMAT_BGR888_BLUESCREEN;
	}
	else if(stricmp(cString, "ARGB8888") == 0)
	{
		return IMAGE_FORMAT_ARGB8888;
	}
	else if(stricmp(cString, "BGRA8888") == 0)
	{
		return IMAGE_FORMAT_BGRA8888;
	}
	else if(stricmp(cString, "DXT1") == 0)
	{
		return IMAGE_FORMAT_DXT1;
	}
	else if(stricmp(cString, "DXT3") == 0)
	{
		return IMAGE_FORMAT_DXT3;
	}
	else if(stricmp(cString, "DXT5") == 0)
	{
		return IMAGE_FORMAT_DXT5;
	}
	else if(stricmp(cString, "BGRX8888") == 0)
	{
		return IMAGE_FORMAT_BGRX8888;
	}
	else if(stricmp(cString, "BGR565") == 0)
	{
		return IMAGE_FORMAT_BGR565;
	}
	else if(stricmp(cString, "BGRX5551") == 0)
	{
		return IMAGE_FORMAT_BGRX5551;
	}
	else if(stricmp(cString, "BGRA4444") == 0)
	{
		return IMAGE_FORMAT_BGRA4444;
	}
	else if(stricmp(cString, "DXT1_ONEBITALPHA") == 0)
	{
		return IMAGE_FORMAT_DXT1_ONEBITALPHA;
	}
	else if(stricmp(cString, "BGRA5551") == 0)
	{
		return IMAGE_FORMAT_BGRA5551;
	}
	else if(stricmp(cString, "UV88") == 0)
	{
		return IMAGE_FORMAT_UV88;
	}
	else if(stricmp(cString, "UVWQ8888") == 0)
	{
		return IMAGE_FORMAT_UVWQ8888;
	}
	else if(stricmp(cString, "RGBA16161616F") == 0)
	{
		return IMAGE_FORMAT_RGBA16161616F;
	}
	else if(stricmp(cString, "RGBA16161616") == 0)
	{
		return IMAGE_FORMAT_RGBA16161616;
	}
	else if(stricmp(cString, "UVLX8888") == 0)
	{
		return IMAGE_FORMAT_UVLX8888;
	}
	else
	{
		return IMAGE_FORMAT_COUNT;
	}
}

VTFImageFlag StringToImageFlag(const vlChar *cString)
{
	if(stricmp(cString, "POINTSAMPLE") == 0)
	{
		return TEXTUREFLAGS_POINTSAMPLE;
	}
	else if(stricmp(cString, "TRILINEAR") == 0)
	{
		return TEXTUREFLAGS_TRILINEAR;
	}
	else if(stricmp(cString, "CLAMPS") == 0)
	{
		return TEXTUREFLAGS_CLAMPS;
	}
	else if(stricmp(cString, "CLAMPT") == 0)
	{
		return TEXTUREFLAGS_CLAMPT;
	}
	else if(stricmp(cString, "ANISOTROPIC") == 0)
	{
		return TEXTUREFLAGS_ANISOTROPIC;
	}
	else if(stricmp(cString, "HINT_DXT5") == 0)
	{
		return TEXTUREFLAGS_HINT_DXT5;
	}
	else if(stricmp(cString, "NORMAL") == 0)
	{
		return TEXTUREFLAGS_NORMAL;
	}
	else if(stricmp(cString, "NOMIP") == 0)
	{
		return TEXTUREFLAGS_NOMIP;
	}
	else if(stricmp(cString, "NOLOD") == 0)
	{
		return TEXTUREFLAGS_NOLOD;
	}
	else if(stricmp(cString, "MINMIP") == 0)
	{
		return TEXTUREFLAGS_MINMIP;
	}
	else if(stricmp(cString, "PROCEDURAL") == 0)
	{
		return TEXTUREFLAGS_PROCEDURAL;
	}
	else if(stricmp(cString, "RENDERTARGET") == 0)
	{
		return TEXTUREFLAGS_RENDERTARGET;
	}
	else if(stricmp(cString, "DEPTHRENDERTARGET") == 0)
	{
		return TEXTUREFLAGS_DEPTHRENDERTARGET;
	}
	else if(stricmp(cString, "NODEBUGOVERRIDE") == 0)
	{
		return TEXTUREFLAGS_NODEBUGOVERRIDE;
	}
	else if(stricmp(cString, "SINGLECOPY") == 0)
	{
		return TEXTUREFLAGS_SINGLECOPY;
	}
	else if(stricmp(cString, "NODEPTHBUFFER") == 0)
	{
		return TEXTUREFLAGS_NODEPTHBUFFER;
	}
	else if(stricmp(cString, "CLAMPU") == 0)
	{
		return TEXTUREFLAGS_CLAMPU;
	}
	else if(stricmp(cString, "VERTEXTEXTURE") == 0)
	{
		return TEXTUREFLAGS_VERTEXTEXTURE;
	}
	else if(stricmp(cString, "SSBUMP") == 0)
	{
		return TEXTUREFLAGS_SSBUMP;
	}
	else if(stricmp(cString, "BORDER") == 0)
	{
		return TEXTUREFLAGS_BORDER;
	}
	else
	{
		return TEXTUREFLAGS_COUNT;
	}
}

VTFMipmapFilter StringToMipmapFilter(const vlChar *cString)
{
	if(stricmp(cString, "POINT") == 0)
	{
		return MIPMAP_FILTER_POINT;
	}
	else if(stricmp(cString, "BOX") == 0)
	{
		return MIPMAP_FILTER_BOX;
	}
	else if(stricmp(cString, "TRIANGLE") == 0)
	{
		return MIPMAP_FILTER_TRIANGLE;
	}
	else if(stricmp(cString, "QUADRATIC") == 0)
	{
		return MIPMAP_FILTER_QUADRATIC;
	}
	else if(stricmp(cString, "CUBIC") == 0)
	{
		return MIPMAP_FILTER_CUBIC;
	}
	else if(stricmp(cString, "CATROM") == 0)
	{
		return MIPMAP_FILTER_CATROM;
	}
	else if(stricmp(cString, "MITCHELL") == 0)
	{
		return MIPMAP_FILTER_MITCHELL;
	}
	else if(stricmp(cString, "GAUSSIAN") == 0)
	{
		return MIPMAP_FILTER_GAUSSIAN;
	}
	else if(stricmp(cString, "SINC") == 0)
	{
		return MIPMAP_FILTER_SINC;
	}
	else if(stricmp(cString, "BESSEL") == 0)
	{
		return MIPMAP_FILTER_BESSEL;
	}
	else if(stricmp(cString, "HANNING") == 0)
	{
		return MIPMAP_FILTER_HANNING;
	}
	else if(stricmp(cString, "HAMMING") == 0)
	{
		return MIPMAP_FILTER_HAMMING;
	}
	else if(stricmp(cString, "BLACKMAN") == 0)
	{
		return MIPMAP_FILTER_BLACKMAN;
	}
	else if(stricmp(cString, "KAISER") == 0)
	{
		return MIPMAP_FILTER_KAISER;
	}
	else
	{
		return MIPMAP_FILTER_COUNT;
	}
}

VTFSharpenFilter StringToSharpenFilter(const vlChar *cString)
{
	if(stricmp(cString, "NONE") == 0)
	{
		return SHARPEN_FILTER_NONE;
	}
	else if(stricmp(cString, "NEGATIVE") == 0)
	{
		return SHARPEN_FILTER_NEGATIVE;
	}
	else if(stricmp(cString, "LIGHTER") == 0)
	{
		return SHARPEN_FILTER_LIGHTER;
	}
	else if(stricmp(cString, "DARKER") == 0)
	{
		return SHARPEN_FILTER_DARKER;
	}
	else if(stricmp(cString, "CONTRASTMORE") == 0)
	{
		return SHARPEN_FILTER_CONTRASTMORE;
	}
	else if(stricmp(cString, "CONTRASTLESS") == 0)
	{
		return SHARPEN_FILTER_CONTRASTLESS;
	}
	else if(stricmp(cString, "SMOOTHEN") == 0)
	{
		return SHARPEN_FILTER_SMOOTHEN;
	}
	else if(stricmp(cString, "SHARPENSOFT") == 0)
	{
		return SHARPEN_FILTER_SHARPENSOFT;
	}
	else if(stricmp(cString, "SHARPENMEDIUM") == 0)
	{
		return SHARPEN_FILTER_SHARPENMEDIUM;
	}
	else if(stricmp(cString, "SHARPENSTRONG") == 0)
	{
		return SHARPEN_FILTER_SHARPENSTRONG;
	}
	else if(stricmp(cString, "FINDEDGES") == 0)
	{
		return SHARPEN_FILTER_FINDEDGES;
	}
	else if(stricmp(cString, "CONTOUR") == 0)
	{
		return SHARPEN_FILTER_CONTOUR;
	}
	else if(stricmp(cString, "EDGEDETECT") == 0)
	{
		return SHARPEN_FILTER_EDGEDETECT;
	}
	else if(stricmp(cString, "EDGEDETECTSOFT") == 0)
	{
		return SHARPEN_FILTER_EDGEDETECTSOFT;
	}
	else if(stricmp(cString, "EMBOSS") == 0)
	{
		return SHARPEN_FILTER_EMBOSS;
	}
	else if(stricmp(cString, "MEANREMOVAL") == 0)
	{
		return SHARPEN_FILTER_MEANREMOVAL;
	}
	else if(stricmp(cString, "UNSHARP") == 0)
	{
		return SHARPEN_FILTER_UNSHARP;
	}
	else if(stricmp(cString, "XSHARPEN") == 0)
	{
		return SHARPEN_FILTER_XSHARPEN;
	}
	else if(stricmp(cString, "WARPSHARP") == 0)
	{
		return SHARPEN_FILTER_WARPSHARP;
	}
	else
	{
		return SHARPEN_FILTER_COUNT;
	}
}

VTFKernelFilter StringToKernelFilter(const vlChar *cString)
{
	if(stricmp(cString, "4X") == 0)
	{
		return KERNEL_FILTER_4X;
	}
	else if(stricmp(cString, "3X3") == 0)
	{
		return KERNEL_FILTER_3X3;
	}
	else if(stricmp(cString, "5X5") == 0)
	{
		return KERNEL_FILTER_5X5;
	}
	else if(stricmp(cString, "7X7") == 0)
	{
		return KERNEL_FILTER_7X7;
	}
	else if(stricmp(cString, "9X9") == 0)
	{
		return KERNEL_FILTER_9X9;
	}
	else if(stricmp(cString, "DUDV") == 0)
	{
		return KERNEL_FILTER_DUDV;
	}
	else
	{
		return KERNEL_FILTER_COUNT;
	}
}

VTFHeightConversionMethod StringToHeightConversionMethod(const vlChar *cString)
{
	if(stricmp(cString, "ALPHA") == 0)
	{
		return HEIGHT_CONVERSION_METHOD_ALPHA;
	}
	else if(stricmp(cString, "AVERAGERGB") == 0)
	{
		return HEIGHT_CONVERSION_METHOD_AVERAGE_RGB;
	}
	else if(stricmp(cString, "BIASEDRGB") == 0)
	{
		return HEIGHT_CONVERSION_METHOD_BIASED_RGB;
	}
	else if(stricmp(cString, "RED") == 0)
	{
		return HEIGHT_CONVERSION_METHOD_RED;
	}
	else if(stricmp(cString, "GREEN") == 0)
	{
		return HEIGHT_CONVERSION_METHOD_GREEN;
	}
	else if(stricmp(cString, "BLUE") == 0)
	{
		return HEIGHT_CONVERSION_METHOD_BLUE;
	}
	else if(stricmp(cString, "MAXRGB") == 0)
	{
		return HEIGHT_CONVERSION_METHOD_MAX_RGB;
	}
	else if(stricmp(cString, "COLORSPACE") == 0)
	{
		return HEIGHT_CONVERSION_METHOD_COLORSPACE;
	}
	else
	{
		return HEIGHT_CONVERSION_METHOD_COUNT;
	}
}

VTFNormalAlphaResult StringToNormalAlphaResult(const vlChar *cString)
{
	if(stricmp(cString, "NOCHANGE") == 0)
	{
		return NORMAL_ALPHA_RESULT_NOCHANGE;
	}
	else if(stricmp(cString, "HEIGHT") == 0)
	{
		return NORMAL_ALPHA_RESULT_HEIGHT;
	}
	else if(stricmp(cString, "BLACK") == 0)
	{
		return NORMAL_ALPHA_RESULT_BLACK;
	}
	else if(stricmp(cString, "WHITE") == 0)
	{
		return NORMAL_ALPHA_RESULT_WHITE;
	}
	else
	{
		return NORMAL_ALPHA_RESULT_COUNT;
	}
}


VTFResizeMethod StringToResizeMethod(const vlChar *cString)
{
	if(stricmp(cString, "NEAREST") == 0)
	{
		return RESIZE_NEAREST_POWER2;
	}
	else if(stricmp(cString, "BIGGEST") == 0)
	{
		return RESIZE_BIGGEST_POWER2;
	}
	else if(stricmp(cString, "SMALLEST") == 0)
	{
		return RESIZE_SMALLEST_POWER2;
	}
	else
	{
		return RESIZE_COUNT;
	}
}