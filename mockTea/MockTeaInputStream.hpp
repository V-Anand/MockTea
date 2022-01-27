#pragma once

#include "StreamUtil.hpp"

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

            int readRemainingLength();
            
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
int mockTea::MockTeaInputStream<InputStream>::readRemainingLength()
{
  return getRemainingLengthFromStream(is_);
}