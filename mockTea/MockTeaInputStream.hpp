#pragma once

namespace mockTea {
    template <typename InputStream>
    class MockTeaInputStream {
        public:
            MockTeaInputStream(InputStream& is);

            // not copyable
            MockTeaInputStream(MockTeaInputStream const&) = delete;
            MockTeaInputStream& operator=(MockTeaInputStream const&) = delete;

            // not movable
            MockTeaInputStream(MockTeaInputStream &&) = delete;
            MockTeaInputStream& operator=(MockTeaInputStream &&) = delete;

            int readRemainingLength(uint8_t len);
        private:
            InputStream& is_;
    };
}

template <typename InputStream>
mockTea::MockTeaInputStream<InputStream>::MockTeaInputStream(InputStream& is)
    : is_(is)
{
}

template <typename InputStream>
int mockTea::MockTeaInputStream<InputStream>::readRemainingLength(uint8_t len)
{
  constexpr auto overflow = 128 * 128 * 128;
  auto multiplier = 1;
  auto value = 0;
  do {
    uint8_t byte = is_.nextByte();
    value += (byte & 127) * multiplier;
    if (multiplier > overflow) {
      throw std::exception("malformed variable byte integer");
    }
    multiplier *= 128;
  } while ((byte & 128) != 0);
  return value;
}