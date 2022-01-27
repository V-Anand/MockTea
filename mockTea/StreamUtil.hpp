#pragma once

namespace mockTea {
  
  template <typename InputStream>
  void writeRemainingLength(InputStream& is, int len)
  {
  }

  template <typename InputStream>
  int readRemainingLength(InputStream& is)
  {
    constexpr auto overflow = 128 * 128 * 128;
    auto multiplier = 1;
    auto value = 0;
    do {
      uint8_t byte = is.nextByte();
      value += (byte & 127) * multiplier;
      if (multiplier > overflow) {
        throw std::exception("malformed variable byte integer");
      }
      multiplier *= 128;
    } while ((byte & 128) != 0);
    return value;
  }

}