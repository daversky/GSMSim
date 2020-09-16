//
// Created by denis on 17.09.2020.
//
#include "Arduino.h"
#include "GSMSimHTTP.h"
#include "GSMSim800l.h"

String GSMSim800l::send_data(String url, String data) {
    if(isConnected()) {
        // Terminate http connection, if it opened before!
        gsm.print(F("AT+CIPSTATUS\r"));
        _readSerial();
        gsm.print(F("AT+HTTPINIT\r\n"));
        _readSerial();
        if (_buffer.indexOf(F("OK")) != -1) {

        }
    } else {
        return "ERROR:GPRS_NOT_CONNECTED";
    }
}
