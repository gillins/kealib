/*
 *  KEAImageIO.h
 *  LibKEA
 *
 *  Created by Pete Bunting on 02/07/2012.
 *  Copyright 2012 LibKEA. All rights reserved.
 *
 *  This file is part of LibKEA.
 *
 *  Permission is hereby granted, free of charge, to any person 
 *  obtaining a copy of this software and associated documentation 
 *  files (the "Software"), to deal in the Software without restriction, 
 *  including without limitation the rights to use, copy, modify, 
 *  merge, publish, distribute, sublicense, and/or sell copies of the 
 *  Software, and to permit persons to whom the Software is furnished 
 *  to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be 
 *  included in all copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, 
 *  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES 
 *  OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. 
 *  IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR 
 *  ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF 
 *  CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION 
 *  WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 */

#ifndef KEAImageIO_H
#define KEAImageIO_H

#include <iostream>
#include <string>
#include <vector>

#include "H5Cpp.h"

#include "libkea/KEACommon.h"
#include "libkea/KEAException.h"

namespace libkea{
        
    class KEAImageIO
    {
    public:
        KEAImageIO();
        void openKEAImage(H5::H5File *keaImgH5File)throw(KEAIOException);
        
        void writeImageBlock2Band(unsigned int band, void *data, unsigned long xPxl, unsigned long yPxl, unsigned long xSize, unsigned long ySize, KEADataType inDataType)throw(KEAIOException);
        void readImageBlock2Band(unsigned int band, void *data, unsigned long xPxl, unsigned long yPxl, unsigned long xSize, unsigned long ySize, KEADataType inDataType)throw(KEAIOException);

        void setImageMetaData(std::string name, std::string value)throw(KEAIOException);
        std::string getImageMetaData(std::string name)throw(KEAIOException);
        
        void setImageBandMetaData(unsigned int band, std::string name, std::string value)throw(KEAIOException);
        std::string getImageBandMetaData(unsigned int band, std::string name)throw(KEAIOException);
        
        void setImageBandDescription(unsigned int band, std::string description)throw(KEAIOException);
        std::string getImageBandDescription(unsigned int band)throw(KEAIOException);
        
        void setSpatialInfo(KEAImageSpatialInfo *spatialInfo)throw(KEAIOException);
        KEAImageSpatialInfo* getSpatialInfo() throw(KEAIOException);
                
        unsigned int getNumOfImageBands() throw(KEAIOException);
        
        KEADataType getImageDataType() throw(KEAIOException);
        
        void initImageBandATT(unsigned int band, size_t numFeats)throw(KEAIOException);
        
        bool getATTBoolField(unsigned int band, size_t fid, std::string name) throw(KEAATTException);
        long getATTIntField(unsigned int band, size_t fid, std::string name) throw(KEAATTException);
        double getATTDoubleField(unsigned int band, size_t fid, std::string name) throw(KEAATTException);
        
        void setATTBoolField(unsigned int band, size_t fid, std::string name, bool value) throw(KEAATTException);
        void setATTIntField(unsigned int band, size_t fid, std::string name, long value) throw(KEAATTException);
        void setATTDoubleField(unsigned int band, size_t fid, std::string name, double value) throw(KEAATTException);
        
        void setATTBoolValue(unsigned int band, std::string name, bool value) throw(KEAATTException);
        void setATTIntValue(unsigned int band, std::string name, long value) throw(KEAATTException);
        void setATTFloatValue(unsigned int band, std::string name, double value) throw(KEAATTException);
        
        KEAATTFeature* getFeature(unsigned int band, size_t fid) throw(KEAATTException);
        
        void addAttBoolField(unsigned int band, std::string name, bool val) throw(KEAATTException);
        void addAttIntField(unsigned int band, std::string name, long val) throw(KEAATTException);
        void addAttFloatField(unsigned int band, std::string name, double val) throw(KEAATTException);
        
        void addAttributes(unsigned int band, std::vector<KEAATTAttribute*> *attributes) throw(KEAATTException);
        
        void close()throw(KEAIOException);
        
        static H5::H5File* createKEAImage(std::string fileName, KEADataType dataType, unsigned int xSize, unsigned int ySize, unsigned int numImgBands, std::vector<std::string> *bandDescrips=NULL, KEAImageSpatialInfo *spatialInfo=NULL, unsigned int blockSize=KEA_WRITE_CHUNK_SIZE)throw(KEAIOException);
        static H5::H5File* openKEAImageRW(std::string fileName)throw(KEAIOException);
        static H5::H5File* openKEAImageRDOnly(std::string fileName)throw(KEAIOException);
        static bool isKEAImage(std::string fileName)throw(KEAIOException);
        virtual ~KEAImageIO();
    protected:
        H5::H5File *keaImgFile;
        //KEADataType dataType;
        KEAImageSpatialInfo *spatialInfoFile;
        unsigned int numImgBands;
    };
    
}


#endif



