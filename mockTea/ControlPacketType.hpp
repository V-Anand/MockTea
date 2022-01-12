#pragma once

namespace mockTea {
  // Header byte 1 high 4 bits
  enum ControlPacketType {
    Reserved0 = 0,
    CONNECT, // Connection request
    CONNACK, // Connect ack
    PUBLISH, // Publish message
    PUBACK, // Publish ack Qos 1
    PUBREC, // Publish received Qos 2 del pt 1
    PUBREL,  // Publish Release Qos 2 del pt 2
    PUBCOMP, // Publish complete Qos 2 del pt 3
    SUBSCRIBE, 
    SUBACK,
    UNSUBSCRIBE,
    UNSUBACK,
    PINGREQ,
    PINGRESP,
    DISCONNECT, // Disconnect notification
    AUTH // Authentication exchange
  };
}