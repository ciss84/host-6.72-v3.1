#pragma once
#include <Utils/IModule.hpp>
#include <Utils/Types.hpp>

namespace Mira
{
		namespace Plugins
		{
				class RemotePkgEnabler : public Mira::Utils::IModule
				{
				public:
						RemotePkgEnabler();
						virtual ~RemotePkgEnabler();

						virtual const char* GetName() override { return "RemotePkgEnabler"; }
						virtual bool OnLoad() override;
						virtual bool OnUnload() override;
						virtual bool OnSuspend() override;
						virtual bool OnResume() override;
				};
		}
}
