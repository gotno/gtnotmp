#pragma once

#include "ChunkedSend.hpp"

struct ChunkedImage : ChunkedSend {
  static const int32_t DEPTH{4};
  int32_t width;
  int32_t height;
  bool isCompressed;

  ChunkedImage(uint8_t* _pixels, int32_t _width, int32_t _height);
  MessagePacker* getPackerForChunk(int32_t chunkNum) override;

  bool compressData();
};
