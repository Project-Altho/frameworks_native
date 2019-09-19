/*
 * Copyright 2019 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include <memory>

#include <compositionengine/Layer.h>
#include <compositionengine/LayerFECompositionState.h>
#include <utils/RefBase.h>
#include <utils/StrongPointer.h>

namespace android::compositionengine {

class CompositionEngine;
class LayerFE;

struct LayerCreationArgs;

namespace impl {

class Display;

class Layer : public compositionengine::Layer {
public:
    Layer(const CompositionEngine&, compositionengine::LayerCreationArgs&&);
    ~Layer() override;

    sp<LayerFE> getLayerFE() const override;

    const LayerFECompositionState& getFEState() const override;
    LayerFECompositionState& editFEState() override;

    void dump(std::string& result) const override;

private:
    const compositionengine::CompositionEngine& mCompositionEngine;
    const wp<LayerFE> mLayerFE;

    // State obtained from calls to LayerFE::getCompositionState
    LayerFECompositionState mFrontEndState;
};

std::shared_ptr<compositionengine::Layer> createLayer(const compositionengine::CompositionEngine&,
                                                      compositionengine::LayerCreationArgs&&);

} // namespace impl
} // namespace android::compositionengine
