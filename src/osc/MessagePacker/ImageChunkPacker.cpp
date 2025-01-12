#include "ImageChunkPacker.hpp"

#include "../ChunkedSend/ChunkedImage.hpp"
#include "../../../dep/oscpack/osc/OscTypes.h"

ImageChunkPacker::ImageChunkPacker(int32_t _chunkNum, ChunkedImage* _chunkedImage):
  ChunkPacker(_chunkNum, _chunkedImage), chunkedImage(_chunkedImage) {
    path = "/chunked_texture";
  }

void ImageChunkPacker::pack(osc::OutboundPacketStream& message) {
  ChunkPacker::pack(message);

  message << chunkedImage->width
    << chunkedImage->height
    ;
}
