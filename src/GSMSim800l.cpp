//
// Created by denis on 17.09.2020.
//
#include "Arduino.h"
#include "GSMSim800l.h"

String GSMSim800l::send_data(const String& host, const String& port, const String& data) {
    String debug = "";
    String cmd_status =          String("AT+CIPSTATUS\r");
    String cmd_set_apn =         String("AT+CSTT=\"" + APN + "\"\r");
    String cmd_send_req_for_IP = String("AT+CIICR\r");
    String cmd_get_local_IP =    String("AT+CIFSR\r");
    String cmd_create_connect =  String("AT+CIPSTART=\"TCP\",\"" + host + "\"," + port + "\r");
    String cmd_send =            String("AT+CIPSEND=" + String(data.length()) + "\r");

    if(isConnected()) {
        //  STATUS
        debug += "cmd:";
        debug += cmd_status;
        gsm.print(cmd_status);
        _readSerial();
        debug += _buffer;
        if (_buffer.indexOf(F("INITIAL")) == -1) {
            gsm.print(F("AT+CIPCLOSE\r"));
            gsm.print(F("AT+CIPSHUT\r"));
        }
        // 1
        debug += "cmd:";
        debug += cmd_set_apn;
        gsm.print(cmd_set_apn);
        _readSerial();
        debug += _buffer;
        // check
        debug += "cmd:";
        debug += cmd_status;
        gsm.print(cmd_status);
        _readSerial();
        debug += _buffer;
        // 2
        debug += "cmd:";
        debug += cmd_send_req_for_IP;
        gsm.print(cmd_send_req_for_IP);
        _readSerial();
        debug += _buffer;
        // check
        debug += "cmd:";
        debug += cmd_status;
        gsm.print(cmd_status);
        _readSerial();
        debug += _buffer;
//        if (_buffer.indexOf(F("GPRSACT")) == -1) {
//            return "ERROR: STATE: IP GPRSACT";
//        }
        // 3
        debug += "cmd:";
        debug += cmd_get_local_IP;
        gsm.print(cmd_get_local_IP);
        _readSerial();
        debug += _buffer;
        // check
        debug += "cmd:";
        debug += cmd_status;
        gsm.print(cmd_status);
        _readSerial();
        debug += _buffer;
//        if (_buffer.indexOf(F("STATUS")) == -1) {
//            return "ERROR: STATE: IP STATUS";
//        }
        // 4
        debug += "cmd:";
        debug += cmd_create_connect;
        gsm.print(cmd_create_connect);
        _readSerial();
        debug += _buffer;
        // check
        debug += "cmd:";
        debug += cmd_status;
        gsm.print(cmd_status);
        _readSerial();
        debug += _buffer;

        // 5
        debug += "cmd:";
        debug += cmd_send;
        gsm.print(cmd_send);
        _readSerial();
        debug += _buffer;

        debug += "cmd:";
        debug += data;
        gsm.print(data);
        gsm.print("\r");
        _readSerial();
        debug += _buffer;

        gsm.print(F("AT+CIPCLOSE\r"));
        _readSerial();
        debug += _buffer;
        gsm.print(F("AT+CIPSHUT\r"));
        _readSerial();
        debug += _buffer;
        return debug;
    } else {
        return "ERROR:GPRS_NOT_CONNECTED";
    }
}
