#pragma once

#include "RNOH/arkui/ArkUINode.h"

namespace rnoh {
class ColorMatrixImageFiltersStackNodeDelegate {
 public:
  virtual ~ColorMatrixImageFiltersStackNodeDelegate() = default;
  virtual void onClick() {};
};

class ColorMatrixImageFiltersStackNode : public ArkUINode {
 protected:
  ColorMatrixImageFiltersStackNodeDelegate* m_stackNodeDelegate;

 public:
  ColorMatrixImageFiltersStackNode();
  ~ColorMatrixImageFiltersStackNode() override;

  void insertChild(ArkUINode& child, std::size_t index);
  void removeChild(ArkUINode& child);
  void onNodeEvent(ArkUI_NodeEventType eventType, EventArgs& eventArgs)
      override;
  void onClick();
  void setStackNodeDelegate(ColorMatrixImageFiltersStackNodeDelegate* stackNodeDelegate);
  ColorMatrixImageFiltersStackNode& setMargin(float left, float top, float right, float bottom);
  ColorMatrixImageFiltersStackNode& setAlign(int32_t align);
};

} // namespace rnoh