#include "pch.h"

#include "ReactPackageProvider.h"
#if __has_include("ReactPackageProvider.g.cpp")
#include "ReactPackageProvider.g.cpp"
#endif

#include "EngineView.h"

using namespace winrt::Microsoft::ReactNative;

namespace winrt::EngineView::implementation
{

void ReactPackageProvider::CreatePackage(IReactPackageBuilder const &packageBuilder) noexcept
{
  AddAttributedModules(packageBuilder, true);
  RegisterComponent(packageBuilder);
}

} // namespace winrt::EngineView::implementation