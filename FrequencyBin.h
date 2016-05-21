/* 
 * File:   FrequencyBin.h
 * Author: kryszak
 *
 * Created on 25 kwiecień 2016, 16:59
 */

#ifndef FREQUENCYBIN_H
#define	FREQUENCYBIN_H

class FrequencyBin {
public:
    FrequencyBin();
    FrequencyBin(const FrequencyBin& orig);
    virtual ~FrequencyBin();
    
    float power;
    int frequency;
private:

};

#endif	/* FREQUENCYBIN_H */

