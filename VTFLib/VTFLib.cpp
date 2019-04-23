/*
 * VTFLib
 * Copyright (C) 2005-2010 Neil Jedrzejewski & Ryan Gregg

 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later
 * version.
 */

#include "VTFLib.h"
#include "VTFFile.h"
#include "VMTFile.h"

using namespace VTFLib;

namespace VTFLib
{
	vlBool bInitialized = vlFalse;
	Diagnostics::CError LastError;

	CVTFFile *Image = 0;
	CImageVector *ImageVector = 0;

	CVMTFile *Material = 0;
	CMaterialVector *MaterialVector = 0;

	vlUInt uiDXTQuality = DXT_QUALITY_HIGH;

	vlSingle sLuminanceWeightR = 0.299f;
	vlSingle sLuminanceWeightG = 0.587f;
	vlSingle sLuminanceWeightB = 0.114f;

	vlUShort uiBlueScreenMaskR = 0x0000;
	vlUShort uiBlueScreenMaskG = 0x0000;
	vlUShort uiBlueScreenMaskB = 0xffff;

	vlUShort uiBlueScreenClearR = 0x0000;
	vlUShort uiBlueScreenClearG = 0x0000;
	vlUShort uiBlueScreenClearB = 0x0000;

	vlSingle sFP16HDRKey = 4.0f;
	vlSingle sFP16HDRShift = 0.0f;
	vlSingle sFP16HDRGamma = 2.25f;

	vlSingle sUnsharpenRadius = 2.0f;
	vlSingle sUnsharpenAmount = 0.5f;
	vlSingle sUnsharpenThreshold = 0.0f;

	vlSingle sXSharpenStrength = 255.0f;
	vlSingle sXSharpenThreshold = 255.0f;

	vlUInt uiVMTParseMode = PARSE_MODE_LOOSE;
}

//
// vlGetVersion()
// Gets the library's version number.
//
VTFLIB_API vlUInt vlGetVersion()
{
	return VL_VERSION;
}

//
// vlGetVersionString()
// Gets the library's version number string.
//
VTFLIB_API const vlChar *vlGetVersionString()
{
	return VL_VERSION_STRING;
}

//
// vlGetLastError()
// Gets the last error of a failed function.
//
VTFLIB_API const vlChar *vlGetLastError()
{
	return LastError.Get();
}

//
// vlInitialize()
// Initializes all resources.
//
VTFLIB_API vlBool vlInitialize()
{
	if(bInitialized)
	{
		LastError.Set("VTFLib already initialized.");
		return vlFalse;
	}

	bInitialized = vlTrue;

	ImageVector = new CImageVector();
	MaterialVector = new CMaterialVector();

	return vlTrue;
}

//
// vlShutdown()
// Frees all resources.
//
VTFLIB_API vlVoid vlShutdown()
{
	if(!bInitialized)
		return;

	vlUInt i;

	bInitialized = vlFalse;

	Image = 0;
	Material = 0;

	for(i = 0; i < ImageVector->size(); i++)
	{
		delete (*ImageVector)[i];
	}

	delete ImageVector;
	ImageVector = 0;

	for(i = 0; i < MaterialVector->size(); i++)
	{
		delete (*MaterialVector)[i];
	}

	delete MaterialVector;
	MaterialVector = 0;
}

VTFLIB_API vlBool vlGetBoolean(VTFLibOption Option)
{
	return vlFalse;
}

VTFLIB_API vlVoid vlSetBoolean(VTFLibOption Option, vlBool bValue)
{

}

VTFLIB_API vlInt vlGetInteger(VTFLibOption Option)
{
	switch(Option)
	{
	case VTFLIB_DXT_QUALITY:
		return (vlInt)uiDXTQuality;

	case VTFLIB_BLUESCREEN_MASK_R:
		return (vlInt)uiBlueScreenMaskR;
	case VTFLIB_BLUESCREEN_MASK_G:
		return (vlInt)uiBlueScreenMaskG;
	case VTFLIB_BLUESCREEN_MASK_B:
		return (vlInt)uiBlueScreenMaskB;

	case VTFLIB_BLUESCREEN_CLEAR_R:
		return (vlInt)uiBlueScreenClearR;
	case VTFLIB_BLUESCREEN_CLEAR_G:
		return (vlInt)uiBlueScreenClearG;
	case VTFLIB_BLUESCREEN_CLEAR_B:
		return (vlInt)uiBlueScreenClearB;

	case VTFLIB_VMT_PARSE_MODE:
		return (vlInt)uiVMTParseMode;
	}

	return 0;
}

VTFLIB_API vlVoid vlSetInteger(VTFLibOption Option, vlInt iValue)
{
	switch(Option)
	{
	case VTFLIB_DXT_QUALITY:
		if(iValue < 0 || iValue >= DXT_QUALITY_COUNT)
			return;
		uiDXTQuality = (vlUInt)iValue;
		break;

	case VTFLIB_BLUESCREEN_MASK_R:
		if(iValue < 0)
			iValue = 0;
		else if(iValue > 65535)
			iValue = 65535;
		uiBlueScreenMaskR = (vlUShort)iValue;
		break;
	case VTFLIB_BLUESCREEN_MASK_G:
		if(iValue < 0)
			iValue = 0;
		else if(iValue > 65535)
			iValue = 65535;
		uiBlueScreenMaskG = (vlUShort)iValue;
		break;
	case VTFLIB_BLUESCREEN_MASK_B:
		if(iValue < 0)
			iValue = 0;
		else if(iValue > 65535)
			iValue = 65535;
		uiBlueScreenMaskB = (vlUShort)iValue;
		break;

	case VTFLIB_BLUESCREEN_CLEAR_R:
		if(iValue < 0)
			iValue = 0;
		else if(iValue > 65535)
			iValue = 65535;
		uiBlueScreenClearR = (vlUShort)iValue;
		break;
	case VTFLIB_BLUESCREEN_CLEAR_G:
		if(iValue < 0)
			iValue = 0;
		else if(iValue > 65535)
			iValue = 65535;
		uiBlueScreenClearG = (vlUShort)iValue;
		break;
	case VTFLIB_BLUESCREEN_CLEAR_B:
		if(iValue < 0)
			iValue = 0;
		else if(iValue > 65535)
			iValue = 65535;
		uiBlueScreenClearB = (vlUShort)iValue;
		break;

	case VTFLIB_VMT_PARSE_MODE:
		if(iValue < 0 || iValue >= PARSE_MODE_COUNT)
			return;
		uiVMTParseMode = (vlUInt)iValue;
		break;
	}
}

VTFLIB_API vlSingle vlGetFloat(VTFLibOption Option)
{
	switch(Option)
	{
	case VTFLIB_LUMINANCE_WEIGHT_R:
		return sLuminanceWeightR;
	case VTFLIB_LUMINANCE_WEIGHT_G:
		return sLuminanceWeightG;
	case VTFLIB_LUMINANCE_WEIGHT_B:
		return sLuminanceWeightB;

	case VTFLIB_FP16_HDR_KEY:
		return sFP16HDRKey;

	case VTFLIB_UNSHARPEN_RADIUS:
		return sUnsharpenRadius;
	case VTFLIB_UNSHARPEN_AMOUNT:
		return sUnsharpenAmount;
	case VTFLIB_UNSHARPEN_THRESHOLD:
		return sUnsharpenThreshold;

	case VTFLIB_XSHARPEN_STRENGTH:
		return sXSharpenStrength;
	case VTFLIB_XSHARPEN_THRESHOLD:
		return sXSharpenThreshold;
	}

	return 0.0f;
}

VTFLIB_API vlVoid vlSetFloat(VTFLibOption Option, vlSingle sValue)
{
	switch(Option)
	{
	case VTFLIB_LUMINANCE_WEIGHT_R:
		if(sValue < 0.0f)
			sValue = 0.0f;
		sLuminanceWeightR = sValue;
		break;
	case VTFLIB_LUMINANCE_WEIGHT_G:
		if(sValue < 0.0f)
			sValue = 0.0f;
		sLuminanceWeightG = sValue;
		break;
	case VTFLIB_LUMINANCE_WEIGHT_B:
		if(sValue < 0.0f)
			sValue = 0.0f;
		sLuminanceWeightB = sValue;
		break;

	case VTFLIB_FP16_HDR_KEY:
		sFP16HDRKey = sValue;
		break;
	case VTFLIB_FP16_HDR_SHIFT:
		sFP16HDRShift = sValue;
		break;
	case VTFLIB_FP16_HDR_GAMMA:
		sFP16HDRGamma = sValue;
		break;

	case VTFLIB_UNSHARPEN_RADIUS:
		if(sValue <= 0.0f)
			sValue = 2.0f;
		sUnsharpenRadius = sValue;
		break;
	case VTFLIB_UNSHARPEN_AMOUNT:
		if(sValue <= 0.0f)
			sValue = 0.5f;
		sUnsharpenAmount = sValue;
		break;
	case VTFLIB_UNSHARPEN_THRESHOLD:
		if(sValue < 0.0f)
			sValue = 0.0f;
		sUnsharpenThreshold = sValue;
		break;

	case VTFLIB_XSHARPEN_STRENGTH:
		if(sValue < 0.0f)
			sValue = 0.0f;
		if(sValue > 255.0f)
			sValue = 255.0f;
		sXSharpenStrength = sValue;
		break;
	case VTFLIB_XSHARPEN_THRESHOLD:
		if(sValue < 0.0f)
			sValue = 0.0f;
		if(sValue > 255.0f)
			sValue = 255.0f;
		sXSharpenThreshold = sValue;
		break;
	}
}

//
// DllMain()
// DLL entry point.
//
BOOL APIENTRY DllMain(HANDLE hModule, DWORD dwReason, LPVOID lpReserved)
{
	switch(dwReason)
	{
	case DLL_PROCESS_ATTACH:
		break;
	case DLL_THREAD_ATTACH:
		break;
	case DLL_THREAD_DETACH:
		break;
	case DLL_PROCESS_DETACH:
		vlShutdown();
		break;
	}
    return TRUE;
}