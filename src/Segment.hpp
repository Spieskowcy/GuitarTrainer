#ifndef _SEGMENT_H_
#define _SEGMENT_H_

class Segment{
public:
    Segment(int probesNo);
    ~Segment();

    int probesNo;
    float* rawSignal;
    float* afterFFT;
};

#endif
