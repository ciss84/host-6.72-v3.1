// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "OptionsBlock.hpp"

using namespace Mira::Boot;

void OptionsBlock::SetDefaults()
{
    IsAdvancedMode = true;

    RpcValidationEnabled = true;
    SyscallGuardEnabled = true;
    FakeSelfEnabled = true;
    FakePkgEnabled = true;

    DebuggerBreakOnAttach = true;
    AslrEnabled = true;
    FuseEnabled = true;

    LogServerEnabled = true;
    LogServerPort = 9998;

    RpcServerEnabled = true;
    RpcServerPort = 9999;
}