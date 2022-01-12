#pragma once

#define BITS(name,bits) constexpr uint8_t name = bits

namespace mockTea {
  // Header byte 1 low 4 bits
  namespace flags {
    BITS(CONNECT,0b0000);
    BITS(CONNACK,0b0000);
    BITS(PUBLISH,0b0000);
    BITS(PUBREC,0b0000);
    BITS(PUBREL,0b0010);
    BITS(PUBCOMP,0b0000);
    BITS(SUBSCRIBE,0b0010);
    BITS(SUBACK,0b0000);
    BITS(UNSUBSCRIBE,0b0010);
    BITS(UNSUBACK,0b0000);
    BITS(PINGREQ,0b0000);
    BITS(PINGRESP,0b0000);
    BITS(DISCONNECT,0b0000);
    BITS(AUTH,0b0000);
  }
  
}