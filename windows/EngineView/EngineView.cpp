#include "pch.h"
#include "BabylonNative.h"
#include "EngineView.h"

#include <winrt/Microsoft.ReactNative.Composition.Input.h>
#include <winrt/Microsoft.UI.Composition.h>
#include <winrt/Windows.UI.h>

using namespace winrt::Microsoft::ReactNative;

namespace winrt::EngineView
{
		void EngineView::Initialize(const ComponentView &sender) noexcept {
				auto view = sender.as<Composition::ViewComponentView>();
				m_view = view;
		}

		winrt::Microsoft::UI::Composition::Visual EngineView::CreateVisual(const ComponentView &view) noexcept {
				BabylonNative::RenderView();
        return view.as<winrt::Microsoft::UI::Composition::Visual>();
		}

		void EngineView::UpdateProps(const ComponentView& sender, const winrt::com_ptr<Codegen::EngineViewProps>& newProps, const winrt::com_ptr<Codegen::EngineViewProps>& oldProps) noexcept {
				Codegen::BaseEngineView<EngineView>::UpdateProps(sender, newProps, oldProps);
		}

		void RegisterComponent(IReactPackageBuilder const& builder) noexcept {
				Codegen::RegisterEngineViewNativeComponent<EngineView>(builder, {});
		}
} // namespace winrt::EngineView