#ifndef DEBUG_H
#define DEBUG_H

#define SERIAL_DEBUG_ENABLED      // Enable this to turn on Serial printing
#ifdef SERIAL_DEBUG_ENABLED
  #define DebugPrint(message) Serial.print(message);
  #define DebugPrintln(message) Serial.println(message);
#else
  #define DebugPrint(...)
  #define DebugPrintln(...) 
#endif

#endif