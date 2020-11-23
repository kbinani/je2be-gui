#pragma once

#include "ComponentState.h"
#include <JuceHeader.h>

class ChooseOutputComponent : public juce::Component,
                              public ChooseOutputStateProvider,
                              public ChooseInputStateProvider {
public:
  explicit ChooseOutputComponent(ConvertState const &convertState);
  ~ChooseOutputComponent() override;

  void paint(juce::Graphics &) override;

  ChooseOutputState getChooseOutputState() const override { return fState; }
  ChooseInputState getChooseInputState() const override {
    return fState.fConvertState.fConfigState.fInputState;
  }

  void onBrowseButtonClicked();
  void onBackButtonClicked();
  void onSaveButtonClicked();

private:
  ChooseOutputState fState;
  std::unique_ptr<Label> fMessage;
  std::unique_ptr<TextButton> fBrowseButton;
  std::unique_ptr<TextButton> fBackButton;
  std::unique_ptr<TextEditor> fStat;
  std::unique_ptr<TextButton> fSaveButton;

  JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ChooseOutputComponent)
};
