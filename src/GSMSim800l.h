//
// Created by denis on 17.09.2020.
//

#ifndef STM32_GPS_GSMSIM800L_H
#define STM32_GPS_GSMSIM800L_H

#include <Arduino.h>
#include "GSMSimGPRS.h"

class GSMSim800l : public GSMSimGPRS {
protected :


public :

    // Sınıfı Başlatıcı...
    GSMSim800l(Stream& s) : GSMSimGPRS(s) {
            RESET_PIN = DEFAULT_RST_PIN;
            LED_PIN = DEFAULT_LED_PIN;
            LED_FLAG = DEFAULT_LED_FLAG;

            APN = DEFAULT_GPRS_APN;
            USER = DEFAULT_GPRS_USER;
            PWD = DEFAULT_GPRS_PWD;
    }

    GSMSim800l(Stream& s, unsigned int resetPin) : GSMSimGPRS(s, resetPin) {
        RESET_PIN = resetPin;
        LED_PIN = DEFAULT_LED_PIN;
        LED_FLAG = DEFAULT_LED_FLAG;

        APN = DEFAULT_GPRS_APN;
        USER = DEFAULT_GPRS_USER;
        PWD = DEFAULT_GPRS_PWD;
    }

    GSMSim800l(Stream& s, unsigned int resetPin, unsigned int ledPin, bool ledFlag) : GSMSimGPRS(s, resetPin, ledPin, ledFlag) {
        RESET_PIN = resetPin;
        LED_PIN = ledPin;
        LED_FLAG = ledFlag;

        APN = DEFAULT_GPRS_APN;
        USER = DEFAULT_GPRS_USER;
        PWD = DEFAULT_GPRS_PWD;
    }

    // HTTP Get
    String send_data(const String& host, const String& port, const String& data);
};


#endif //STM32_GPS_GSMSIM800L_H
