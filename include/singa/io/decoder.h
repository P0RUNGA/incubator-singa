/**
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef SINGA_IO_DECODER_H_
#define SINGA_IO_DECODER_H_

#include <vector>
#include <string>
#include "singa/core/tensor.h"
#include "singa/proto/model.pb.h"

namespace singa {
namespace io {

class Decoder {
  public:
    Decoder() { }
    virtual ~Decoder() { }

    virtual void Setup(const DecoderConf& conf) = 0;

    /**
    * Decode value to get data and labels
    */
    virtual std::vector<Tensor> Decode(std::string value) = 0;
};

class Proto2JPGDecoder : public Decoder {
  public:
    void Setup(const DecoderConf& conf) override;
    std::vector<Tensor> Decode(std::string value) override;
};

} // namespace io
} // namespace singa
#endif // SINGA_IO_DECODER_H_
