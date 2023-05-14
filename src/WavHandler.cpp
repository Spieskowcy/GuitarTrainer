#include "WavHandler.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::fstream;
using std::string;

WavHandler::WavHandler(const char* filePath)
{
    this->filePath = filePath;
    wavFile = fopen(filePath, "r");
    buffer = new int8_t[BUFFER_SIZE];
    ProcessHeaders(); 
}

// find the file size
int WavHandler::GetFileSize()
{
    int fileSize = 0;
    fseek(wavFile, 0, SEEK_END);

    fileSize = ftell(wavFile);

    fseek(wavFile, 0, SEEK_SET);
    return fileSize;
}

void WavHandler::ProcessHeaders()
{
    int headerSize = sizeof(wav_hdr), filelength = 0;

    if (wavFile == nullptr)
    {
        fprintf(stderr, "Unable to open wave file: %s\n", filePath);
        return;
    }

    //Read the header
    size_t bytesRead = fread(&wavHeader, 1, headerSize, wavFile);
    
    if (bytesRead > 0)
    {
        filelength = GetFileSize();
    }
}

void WavHandler::ReadRawData(Segment *seg)
{
    size_t bytesRead;
    //data is in little endian

    for(int i=0; i<seg->probesNo; i++)
    {
        float value=0;
        bytesRead = fread(buffer, sizeof buffer[0], BUFFER_SIZE / (sizeof buffer[0]), wavFile);
        if(bytesRead==0)
        {
            finished=true;
            break;
        }
        for(int j=0; j<bytesRead; j++)
        {
            value += buffer[j]<<8*(bytesRead-1-j);
        }
        seg->rawSignal[i] = value;
    }
}

bool WavHandler::FinishedReading()
{
    return finished;
}

WavHandler::~WavHandler()
{
    delete [] buffer;
    fclose(wavFile);
}
