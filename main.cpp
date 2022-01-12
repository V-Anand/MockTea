#include <iostream>
#include "mockTea/ControlPacket.hpp"
#include "mockTea/ControlPacketType.hpp"
#include "mockTea/ControlPacketFlags.hpp"

using namespace mockTea;

namespace {

  const char* assertSame(uint8_t a, uint8_t b) {
    if (a == b) {
      return "PASSED";
    }
    return "FAILED";
  }

}

int main() {
  std::cout << "DB " << std::getenv("REPLIT_DB_URL") << std::endl;
  std::cout << "Test ControlPacket!" << std::endl;
  ControlPacket p{{0,0}};
  p.header[0] |= (SUBSCRIBE << 4);
  p.header[0] |= flags::SUBSCRIBE;
  std::cout << "SUBSCRIBE test " << assertSame(p.header[0], 0b10000010) << std::endl;
} 