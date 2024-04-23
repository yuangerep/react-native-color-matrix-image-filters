/**
 * MIT License
 *
 * Copyright (C) 2024 Huawei Device Co., Ltd.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#ifndef HARMONY_COLOR_MATRIX_IMAGE_FILTERS_SRC_MAIN_CPP_NAPIBINDER_H
#define HARMONY_COLOR_MATRIX_IMAGE_FILTERS_SRC_MAIN_CPP_NAPIBINDER_H
#include "RNOHCorePackage/ComponentBinders/ViewComponentNapiBinder.h"
#include "Props.h"

namespace rnoh{

  class ColorMatrixImageFiltersNapiBinder : public ViewComponentNapiBinder{
    public:
      napi_value createProps(napi_env env,facebook::react::ShadowView const shadowView) override
      {
        napi_value napiViewProps = ViewComponentNapiBinder::createProps(env,shadowView);
        if(auto props = std::dynamic_pointer_cast<const facebook::react::CMIFColorMatrixImageFilterProps>(shadowView.props)){
           auto matrixs = std::vector<napi_value>();
           auto matrixRaw = props->matrix;
           for(auto matrix : matrixRaw){
              auto matrixObjectBuilder = ArkJS(env).createObjectBuilder();
              matrixObjectBuilder.addProperty("matrix",matrix);
              matrixs.push_back(matrixObjectBuilder.build());
           }
           auto matrixsArray = ArkJS(env).createArray(matrixs);
           return ArkJS(env)
              .getObjectBuilder(napiViewProps)
              .addProperty("matrix",matrixsArray)
              .build();
        }
        return napiViewProps;
      };
  };
  
} // namespace rnoh
#endif