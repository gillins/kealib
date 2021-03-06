
Building the KEA ArcGIS Plugin for Arc 9.3 - 10.5.1 and ArcPro 1.4 - 2.0
========================================================================

Prerequisites
-------------

1. Visual Studio 2008 Express Or Visual C++ for Python 2.7.
2. Visual Studio 2013 Community Edition.
3. Visual Studio 2015 Community Edition.
4. CMake
5. GDAL headers and libraries for the versions of GDAL Arc uses. These are available
     from the kealib downloads as 'arcgdal_for_compilationX.zip' where X is the highest number available.

We prefer to build KEA against static builds of HDF5 since this saves having to match whatever
version Arc itself was built against. If we where to compile against HDF5 dlls we would have to
match the exact version in Arc to avoid a crash.

Refer to the file "buildzlibhdf5.bat" in this directory. You should be able to build static
zlib and hdf5 libraries with this file. Note that you will probably have to set the first
three variables to more sensible locations.

After you have run this, run the file "buildkeastatic.bat". Ensure the INSTALLDIR variable
is set to the same location as it was in "buildzlibhdf5.bat". This creates a static build of 
kealib.

After you have run this, refer to the file "buildkeaforarc.bat". You will need to edit the 
first three variables again. Running this should output the KEA plugin for the various
Arc versions to the directory specified. 

Installing KEA driver for ArcMap Arc 9.3 - 10.5.1 and ArcPro 1.4 - 2.0
----------------------------------------------------------------------

1. Create a 'gdalplugins' directory under the 'bin' directory of your Arc install if it does not already exist.

2. Select the appropriate subfolder for your version of Arc. 

Arc 9.3 = arc93
Arc 10.0 = arc100
Arc 10.1-10.3 = arc101
Arc 10.4 = arc104
Arc 10.5 = arc105
Arc 10.5.1 = arc1051
Arc 10.6 = arc106_arcpro21
Arc 10.6.1 = arc1061_arcpro22
ArcPro 1.4 = arcpro14
ArcPro 2.0 = arcpro20
ArcPro 2.1 = arc106_arcpro21
ArcPro 2.2 = arc1061_arcpro22

Note you may have to select the x86 subfolder for 32bit Arc, or x64 for 64bit Arc.

2. Copy gdal_KEA.dll from the 'lib\gdalplugins' subdirectory into the newly created 'gdalplugins' directory of your
  Arc install (see step 1 above).

3. Edit bin/RasterFormats.dat and add the line:

        <e on="y" nm="KEA" ex="*.kea" et="KEA" at="0x27" />
    
    at the bottom of the section that has a number of lines looking similar
    
4. Restart Arc and you should be all go

