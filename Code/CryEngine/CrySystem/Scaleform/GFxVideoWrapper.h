// Copyright 2001-2019 Crytek GmbH / Crytek Group. All rights reserved.

#ifndef _GFXVIDEOWRAPPER_H_
#define _GFXVIDEOWRAPPER_H_

#pragma once

#ifdef INCLUDE_SCALEFORM_SDK

#include <CrySystem/Scaleform/ConfigScaleform.h>

#if defined(USE_GFX_VIDEO)

#pragma warning(push)
#pragma warning(disable : 6326)     // Potential comparison of a constant with another constant
#pragma warning(disable : 6011)     // Dereferencing NULL pointer
#include <CryCore/Platform/CryWindows.h>
#include <GFxVideo.h>               // includes <windows.h>
#pragma warning(pop)

class GFxLoader;

class GFxVideoWrapper
{
public:
	static void SetVideo(GFxLoader* pLoader);
	static int  GetNumVideoInstances();
	static void InitCVars();

private:
	GFxVideoWrapper() {}
	~GFxVideoWrapper() {}
};

static inline bool IsVideoFile(const char* pFilePath)
{
	return pFilePath && strstr(pFilePath, ".usm") != 0;
}

static inline bool IsStereoVideoFile(const char* pFilePath)
{
	return pFilePath && strstr(pFilePath, "_st.usm") != 0;
}

const char internal_video_player[] = "_internal_video_player";

const unsigned char fxvideoplayer_swf[] =
{
	0x43, 0x57, 0x53, 0x09, 0xb8, 0x02, 0x00, 0x00, 0x78, 0x9c, 0x5d, 0x92, 0x4b, 0x4e, 0xeb, 0x30,
	0x14, 0x86, 0xff, 0xa4, 0xa5, 0x31, 0x85, 0x42, 0x49, 0x81, 0xf2, 0x08, 0x0c, 0x59, 0x02, 0xa3,
	0x4a, 0x14, 0x01, 0x03, 0x24, 0x48, 0xa4, 0x16, 0x31, 0xad, 0xdc, 0xc4, 0xa4, 0x46, 0x21, 0x41,
	0x89, 0x05, 0xbd, 0x77, 0x05, 0x77, 0x74, 0x87, 0x99, 0x21, 0xb1, 0x13, 0xd8, 0x02, 0x3b, 0x60,
	0x27, 0xe5, 0x38, 0x09, 0x14, 0xf0, 0xe0, 0xf8, 0xf8, 0x3b, 0xaf, 0xff, 0x48, 0x9e, 0xa2, 0xd1,
	0x07, 0xec, 0x57, 0x60, 0xd9, 0xc0, 0xe9, 0x1a, 0xe8, 0x9c, 0x98, 0xb3, 0xd9, 0xec, 0xa8, 0x76,
	0x63, 0x02, 0xff, 0xde, 0xb1, 0x8b, 0x51, 0x18, 0x25, 0x63, 0x1e, 0x21, 0xbc, 0x99, 0x9e, 0x4d,
	0x95, 0x88, 0x33, 0x99, 0xc4, 0x19, 0x86, 0x8a, 0x87, 0x02, 0x99, 0xcf, 0x23, 0x71, 0x99, 0x04,
	0x02, 0x71, 0x32, 0xd4, 0x3e, 0x78, 0x24, 0xc3, 0x18, 0x57, 0x17, 0x48, 0x45, 0x26, 0xff, 0x8a,
	0x0b, 0x99, 0x51, 0x89, 0x48, 0xe1, 0x8d, 0x6f, 0x85, 0xaf, 0x90, 0xc4, 0x83, 0x82, 0xe3, 0x41,
	0x06, 0x22, 0xc1, 0xe8, 0x51, 0x06, 0x6a, 0x82, 0xd2, 0x8e, 0x26, 0x42, 0x86, 0x13, 0x85, 0xea,
	0xe2, 0x41, 0xf0, 0x55, 0x1d, 0xfb, 0x70, 0x85, 0x3a, 0x49, 0xe2, 0x98, 0x9a, 0xd0, 0x7c, 0xf8,
	0xa5, 0x0b, 0x52, 0x42, 0x81, 0xa1, 0x4a, 0x05, 0xbf, 0xd3, 0x0a, 0xaf, 0x45, 0xaa, 0xf5, 0x69,
	0xf7, 0x38, 0x0d, 0x71, 0x1f, 0xf1, 0x3f, 0xa4, 0x84, 0x12, 0x1f, 0x64, 0x26, 0xc7, 0x91, 0x18,
	0x68, 0x9f, 0x2b, 0xc5, 0xfd, 0xc9, 0x75, 0xa1, 0x20, 0x37, 0xc1, 0xe0, 0xe4, 0x16, 0x98, 0x61,
	0x19, 0xb4, 0xbd, 0xa7, 0x81, 0xe9, 0xe4, 0x75, 0xb0, 0x1a, 0xab, 0x7f, 0x7b, 0x2d, 0xb0, 0x86,
	0x97, 0xb7, 0xc0, 0xac, 0x06, 0xaa, 0xc3, 0x58, 0x7f, 0x4f, 0xc7, 0x2d, 0x47, 0xdb, 0xc5, 0xff,
	0x4c, 0x43, 0xf3, 0x00, 0xbd, 0xa2, 0x69, 0xd3, 0xd1, 0xd9, 0x4b, 0x75, 0xe3, 0x2b, 0xdf, 0xd5,
	0x78, 0xd9, 0xf5, 0xe6, 0xd1, 0xd6, 0xef, 0xe8, 0x8a, 0xeb, 0x79, 0x55, 0x4b, 0x0b, 0x85, 0x1e,
	0x3d, 0x9d, 0xc0, 0xea, 0xa0, 0xab, 0x0b, 0xda, 0xf3, 0xe1, 0x6b, 0xfd, 0x5e, 0xce, 0x60, 0x96,
	0x49, 0xed, 0x22, 0xc9, 0xa6, 0x24, 0x52, 0xda, 0xd1, 0xcf, 0xcf, 0xf2, 0x75, 0x4a, 0x2b, 0x57,
	0x24, 0xbb, 0xe1, 0xe6, 0x06, 0x6a, 0xe7, 0xb6, 0xfd, 0x64, 0xe2, 0x10, 0x73, 0xbe, 0xf9, 0x8d,
	0xef, 0xff, 0xe4, 0x9f, 0x7d, 0x3a, 0x05, 0xe8, 0x96, 0x13, 0xb6, 0x2a, 0x55, 0xdb, 0x6e, 0xaf,
	0x5a, 0x86, 0xe0, 0x12, 0xdb, 0x72, 0x7e, 0x6e, 0x48, 0xb0, 0x55, 0xc1, 0x95, 0x12, 0x76, 0xe6,
	0xc2, 0x9a, 0x05, 0xdf, 0x19, 0x74, 0x71, 0xb4, 0xda, 0x24, 0xa0, 0xe1, 0x33, 0xa6, 0x64, 0x5f,
	0x1a, 0x36, 0xd9, 0x03, 0x83, 0xd0, 0x1b, 0xd0, 0x26, 0xbf, 0xfc, 0x2c, 0xf4, 0x51, 0xf1, 0x01,
	0x32, 0x18, 0x89, 0x93,

	0
};

#endif   // #if defined(USE_GFX_VIDEO)

#endif   // #ifdef INCLUDE_SCALEFORM_SDK

#endif   // #ifndef _GFXVIDEOWRAPPER_H_
