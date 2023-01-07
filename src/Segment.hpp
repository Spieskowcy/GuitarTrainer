#ifndef _SEGMENT_H_
#define _SEGMENT_H_

class Segment{
public:
    Segment(int probesNo);
    ~Segment();

    float* rawSignal;
    float* afterFFT;
};

#endif
