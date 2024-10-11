#pragma once

#include "pch.h"
#include "resource.h"
#include "codegen/react/components/EngineView/EngineView.g.h"
#include "NativeModules.h"

namespace winrt::EngineView
{
  struct EngineView : public winrt::implements<EngineView, winrt::IInspectable>, Codegen::BaseEngineView<EngineView> {
    void Initialize(const winrt::Microsoft::ReactNative::ComponentView&) noexcept override;
    winrt::Microsoft::UI::Composition::Visual CreateVisual(const winrt::Microsoft::ReactNative::ComponentView&) noexcept override;
		void UpdateProps(const winrt::Microsoft::ReactNative::ComponentView&, const winrt::com_ptr<Codegen::EngineViewProps>&, const winrt::com_ptr<Codegen::EngineViewProps>&) noexcept override;

		private:
			struct RevokerData
			{
				winrt::Microsoft::UI::Xaml::FrameworkElement::SizeChanged_revoker SizeChangedRevoker{};
				winrt::Microsoft::UI::Xaml::FrameworkElement::Unloaded_revoker UnloadedEventToken{};
				winrt::Microsoft::UI::Xaml::FrameworkElement::Loaded_revoker LoadedEventToken{};
				winrt::Microsoft::UI::Xaml::Media::CompositionTarget::Rendering_revoker RenderingRevoker{};
			};
			RevokerData _revokerData{};
			winrt::Microsoft::ReactNative::Composition::ViewComponentView m_view{ nullptr };
  };

	void RegisterComponent(winrt::Microsoft::ReactNative::IReactPackageBuilder const&) noexcept;
} // namespace winrt::EngineView
