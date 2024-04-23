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
#ifndef HARMONY_COLOR_MATRIX_IMAGE_FILTERS_SRC_MAIN_CPP_RPACKAGE_H
#define HARMONY_PAGERVIEW_SRC_MAIN_CPP_PACKAGE_H
#include "RNOH/Package.h"
#include "ComponentDescriptors.h"
#include "ColorMatrixImageFiltersJSIBinder.h"
#include "ColorMatrixImageFiltersNapiBinder.h"
#include "ColorMatrixImageFiltersComponentInstance.h"

using namespace rnoh;
using namespace facebook;
namespace rnoh{

    class ColorMatrixImageFiltersPackageComponentInstanceFactoryDelegate : public ComponentInstanceFactoryDelegate {
    public:
        using ComponentInstanceFactoryDelegate::ComponentInstanceFactoryDelegate;

        ComponentInstance::Shared create(ComponentInstance::Context ctx) override {
            if (ctx.componentName == "CMIFColorMatrixImageFilter") {
                return std::make_shared<ColorMatrixImageFiltersComponentInstance>(std::move(ctx));
            }
            return nullptr;
        }
    };


  class ColorMatrixImageFiltersPackage : public Package{
    public:
      ColorMatrixImageFiltersPackage(Package::Context ctx) : Package(ctx){}

      ComponentInstanceFactoryDelegate::Shared createComponentInstanceFactoryDelegate() override {
            return std::make_shared<ColorMatrixImageFiltersPackageComponentInstanceFactoryDelegate>();
      }


      std::vector<facebook::react::ComponentDescriptorProvider> createComponentDescriptorProviders() override
      {
        return {
          facebook::react::concreteComponentDescriptorProvider<facebook::react::ColorMatrixImageFiltersComponentDescriptor>()
        };
      }

      ComponentJSIBinderByString createComponentJSIBinderByName() override
      {
        return {{"CMIFColorMatrixImageFilter",std::make_shared<ColorMatrixImageFiltersJSIBinder>()}};
      };

      ComponentNapiBinderByString createComponentNapiBinderByName() override
      {
        return {{"CMIFColorMatrixImageFilter",std::make_shared<ColorMatrixImageFiltersNapiBinder>()}};
      };
    
  };
} // namespace rnoh
#endif