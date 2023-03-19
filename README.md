> **Warning**
>
> VTFLib project is **no-longer being actively developed** by the original authors and as-such:
> * The current code is unsupported and used at your own risk.
> * The original code was developed from 2005 to 2011 - it likely doesn't run out of the box on modern version of Windows.
> * There may be some basic updates or maintenance but this is strictly limited to tinkering.
> * Pull Requests are welcome so long as they bring some value, i.e. fix issues.
> * Feel free to open issues, however its unlikely much will be fixed.

# VTFLib - A Valve VTF and VMT image format programming library.

VTFLib is a LGPL open source programming library that provides a C and C++ API that, with a few simple functions, can open and save .vtf and .vmt files, providing access to all known features. The library functions independent of Steam, allowing third party applications to use the library without Steam present or running on the target system.

VTFLib includes two GPL example applications, VTFCmd and VTFEdit. VTFCmd is a C command line frontend for VTFLib that can create .vtf and .vmt files from various source formats. It is similar in functionality to Valve's vtex Source SDK utility, but offers a lot more control. VTFEdit is a C++ .NET graphical frontend for VTFLib with viewing and creation capabilities. Both VTFCmd and VTFEdit support several source image formats, including, but not limited to .bmp, .dds, .gif, .jpg, .png and .tga.

## A note from the authors

Between 2005 and 2011 myself and Ryan Gregg developed a number of tools and libraries to help modders and developers create content for Valve's Source game engine - VTFLib was one of them. However, as of time of writing, that was 12 years ago and we've moved onto other things. I'm shocked (and actually pleased) that people are still using VTFLib and VTFEdit despite how old it is.

Though we're not actively developing it, your welcome to make forks and develop your own version (maybe fix a few things) as per the LGPL license. I may *tinker* with the code from time to time though this is for my own curiosity and amusement and not any for of official work.

Thanks to everyone who supported us over the years!

*Neil 'Jed' Jedrzejewski & Ryan Gregg*

## Project Structure

The library contains five folders:

* **Bin** - Contains library and example program binaries.
* **Lib** - Contains library C and C++ header and inline files.
* **Sln** - Contains Solution files for Visual Studio.
* **VTFCmd** - Contains C example program source code.
* **VTFEdit** - Contains C++ .NET example program source code.
* **VTFLib** - Contains C++ library source code.

The original project files were written for Visual Studio 2008 and have been retained for reference. A partial migration to Visual Studio 2022 has been started though at present this is for VTFLib onyl while working out some dependency issues.

[nvDXTLib](http://developer.nvidia.com/object/dds_utilities_legacy.html) is required by VTFLib for DXT compression although it is current not compatible with versions of VSCode later than 2008.

## Changelogs
* [VTFLib](VTFLib_CHANGELOG.md)
* [VTFEdit](VTFEdit_CHANGELOG.md)
* [VTFCmd](VTFCmd_CHANGELOG.md)

## VTFCmd Usage

```
Correct vtfcmd usage:
 -file <path>             (Input file path.)
 -folder <path>           (Input directory search string.)
 -output <path>           (Output directory.)
 -prefix <string>         (Output file prefix.)
 -postfix <string>        (Output file postfix.)
 -version <string>        (Ouput version.)
 -format <string>         (Ouput format to use on non-alpha textures.)
 -alphaformat <string>    (Ouput format to use on alpha textures.)
 -flag <string>           (Output flags to set.)
 -resize                  (Resize the input to a power of 2.)
 -rmethod <string>        (Resize method to use.)
 -rfilter <string>        (Resize filter to use.)
 -rsharpen <string>       (Resize sharpen filter to use.)
 -rwidth <integer>        (Resize to specific width.)
 -rheight <integer>       (Resize to specific height.)
 -rclampwidth <integer>   (Maximum width to resize to.)
 -rclampheight <integer>  (Maximum height to resize to.)
 -gamma                   (Gamma correct image.)
 -gcorrection <single>    (Gamma correction to use.)
 -nomipmaps               (Don't generate mipmaps.)
 -mfilter <string>        (Mipmap filter to use.)
 -msharpen <string>       (Mipmap sharpen filter to use.)
 -normal                  (Convert input file to normal map.)
 -nkernel <string>        (Normal map generation kernel to use.)
 -nheight <string>        (Normal map height calculation to use.)
 -nalpha <string>         (Normal map alpha result to set.)
 -nscale <single>         (Normal map scale to use.)
 -nwrap                   (Wrap the normal map for tiled textures.)
 -bumpscale <single>      (Engine bump mapping scale to use.)
 -nothumbnail             (Don't generate thumbnail image.)
 -noreflectivity          (Don't calculate reflectivity.)
 -shader <string>         (Create a material for the texture.)
 -param <string> <string> (Add a parameter to the material.)
 -recurse                 (Process directories recursively.)
 -exportformat <string>   (Convert VTF files to the format of this extension.)
 -silent                  (Silent mode.)
 -pause                   (Pause when done.)
 -help                    (Display vtfcmd help.)

Example vtfcmd usage:
vtfcmd.exe -file "C:\texture1.bmp" -file "C:\texture2.bmp" -format "dxt1"
vtfcmd.exe -file "C:\texture.bmp" -format "bgr888" -normal -postfix "normal_"
vtfcmd.exe -folder "C:\input\*.tga" -output "C:\output" -recurse -pause
vtfcmd.exe -folder "C:\output\*.vtf" -output "C:\input" -exportformat "jpg"
```
## Program Copyright-Permissions
This software is Copyright *Neil 'Jed' Jedrzejewski & Ryan Gregg and is released under the terms of LGPL. Please see the LICENSE file for details.
