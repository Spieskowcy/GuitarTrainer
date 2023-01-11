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
        uint16_t bytesPerSample = wavHeader.bitsPerSample / 8;      //Number     of bytes per sample
        uint64_t numSamples = wavHeader.ChunkSize / bytesPerSample; //How many samples are in the wav file

        filelength = GetFileSize();

        /*
        cout << "File is                    :" << filelength << " bytes." << endl;
        cout << "RIFF header                :" << wavHeader.RIFF[0] << wavHeader.RIFF[1] << wavHeader.RIFF[2] << wavHeader.RIFF[3] << endl;
        cout << "WAVE header                :" << wavHeader.WAVE[0] << wavHeader.WAVE[1] << wavHeader.WAVE[2] << wavHeader.WAVE[3] << endl;
        cout << "FMT                        :" << wavHeader.fmt[0] << wavHeader.fmt[1] << wavHeader.fmt[2] << wavHeader.fmt[3] << endl;
        cout << "Data size                  :" << wavHeader.ChunkSize << endl;

        // Display the sampling Rate from the header
        cout << "Sampling Rate              :" << wavHeader.SamplesPerSec << endl;
        cout << "Number of bits used        :" << wavHeader.bitsPerSample << endl;
        cout << "Number of channels         :" << wavHeader.NumOfChan << endl;
        cout << "Number of bytes per second :" << wavHeader.bytesPerSec << endl;
        cout << "Data length                :" << wavHeader.Subchunk2Size << endl;
        cout << "Audio Format               :" << wavHeader.AudioFormat << endl;
        // Audio format 1=PCM,6=mulaw,7=alaw, 257=IBM Mu-Law, 258=IBM A-Law, 259=ADPCM

        cout << "Block align                :" << wavHeader.blockAlign << endl;
        cout << "Data string                :" << wavHeader.Subchunk2ID[0] << wavHeader.Subchunk2ID[1] << wavHeader.Subchunk2ID[2] << wavHeader.Subchunk2ID[3] << endl;
        */
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
