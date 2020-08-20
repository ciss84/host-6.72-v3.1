// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "PluginManager.hpp"

// Built in plugins
#include <Plugins/Debugger/Debugger2.hpp>
#include <Plugins/LogServer/LogManager.hpp>
#include <Plugins/FileManager/FileManager.hpp>
#include <Plugins/FakeSelf/FakeSelfManager.hpp>
#include <Plugins/FakePkg/FakePkgManager.hpp>
#include <Plugins/EmuRegistry/EmuRegistryPlugin.hpp>
#include <Plugins/Substitute/Substitute.hpp>
#include <Plugins/BrowserActivator/BrowserActivator.hpp>
#include <Plugins/RemotePkgEnabler/RemotePkgEnabler.hpp>
    #if MIRA_PLATFORM <= MIRA_PLATFORM_ORBIS_BSD_176 || MIRA_PLATFORM > MIRA_PLATFORM_ORBIS_BSD_505
    #else
#include <Plugins/Debugger3/Debugger3.hpp>    
#include <Plugins/RemotePlayEnabler/RemotePlayEnabler.hpp>
#include <Plugins/MorpheusEnabler/MorpheusEnabler.hpp>
#include <Plugins/DebugTrophyEnabler/DebugTrophyEnabler.hpp>
    #endif
#include <Plugins/SyscallGuard/SyscallGuardPlugin.hpp>
#include <Plugins/TTYRedirector/TTYRedirector.hpp>

// Utility functions
#include <Utils/Logger.hpp>
#include <Utils/Span.hpp>

extern "C"
{
    #include <sys/syslimits.h>
};

using namespace Mira::Plugins;

PluginManager::PluginManager() :
	m_Logger(nullptr),
    m_LoggerConsole(nullptr),
    m_Debugger(nullptr),
    m_FileManager(nullptr),
    m_FakeSelfManager(nullptr),
    m_FakePkgManager(nullptr),
    m_EmuRegistry(nullptr),
    m_Substitute(nullptr),
    m_BrowserActivator(nullptr),
    m_SyscallGuard(nullptr)
{
    // Hushes error: private field 'm_FileManager' is not used [-Werror,-Wunused-private-field]
	m_Logger = nullptr;
    m_LoggerConsole = nullptr;
    m_FileManager = nullptr;
}

PluginManager::~PluginManager()
{
}

bool PluginManager::OnLoad()
{
    WriteLog(LL_Debug, "loading all plugins");

    bool s_Success = true;
    do
    {
        // Initialize debugger
        m_Debugger = new Mira::Plugins::Debugger2();
        if (m_Debugger == nullptr)
        {
            WriteLog(LL_Error, "could not allocate debugger.");
            s_Success = false;
            break;
        }

        // Initialize the syscall guard
       /* m_SyscallGuard = new Mira::Plugins::SyscallGuard();
        if (m_SyscallGuard == nullptr)
        {
            WriteLog(LL_Error, "could not allocate syscall guard.");
            s_Success = false;
            break;
        }
        if (!m_SyscallGuard->OnLoad())
            WriteLog(LL_Error, "could not load syscall guard.");*/

        // Initialize Logger
        m_Logger = new Mira::Plugins::LogManagerExtent::LogManager();
        if (m_Logger == nullptr)
        {
            WriteLog(LL_Error, "could not allocate log manager.");
            return false;
        }
        if (!m_Logger->OnLoad())
            WriteLog(LL_Error, "could not load logmanager");
            
        // Initialize Logger Console
        char consolePath[] = "/dev/console";
        m_LoggerConsole = new Mira::Plugins::LogManagerExtent::LogManager(9997, consolePath);
        if (m_LoggerConsole == nullptr)
        {
            WriteLog(LL_Error, "could not allocate log manager.(Console)");
            return false;
        }
        if (!m_LoggerConsole->OnLoad())
            WriteLog(LL_Error, "could not load logmanager (Console)");

        // Initialize file manager
        m_FileManager = new Mira::Plugins::FileManagerExtent::FileManager();
        if (m_FileManager == nullptr)
        {
            WriteLog(LL_Error, "could not allocate file manager.");
            s_Success = false;
            break;
        }

        // Initialize the fself manager
        m_FakeSelfManager = new Mira::Plugins::FakeSelfManager();
        if (m_FakeSelfManager == nullptr)
        {
            WriteLog(LL_Error, "could not allocate fake self manager.");
            s_Success = false;
            break;
        }

        // Initialize the fpkg manager
        m_FakePkgManager = new Mira::Plugins::FakePkgManager();
        if (m_FakePkgManager == nullptr)
        {
            WriteLog(LL_Error, "could not allocate fake pkg manager.");
            s_Success = false;
            break;
        }

        // Initialize emu-registry
        m_EmuRegistry = new Mira::Plugins::EmuRegistryPlugin();
        if (m_EmuRegistry == nullptr)
        {
            WriteLog(LL_Error, "could not allocate emulated registry.");
            s_Success = false;
            break;
        }

        // Initialize Substitute
        m_Substitute = new Mira::Plugins::Substitute();
        if (m_Substitute == nullptr)
        {
            WriteLog(LL_Error, "could not allocate substitute.");
            s_Success = false;
            break;
        }

        // Initialize BrowserActivator
        m_BrowserActivator = new Mira::Plugins::BrowserActivator();
        if (m_BrowserActivator == nullptr)
        {
            WriteLog(LL_Error, "could not allocate browser activator.");
            s_Success = false;
            break;
        }
                
        // Initialize RemotePkgEnabler
        m_RemotePkgEnabler = new Mira::Plugins::RemotePkgEnabler();
        if (m_RemotePkgEnabler == nullptr)
        {
            WriteLog(LL_Error, "could not allocate remote pkg enabler.");
            s_Success = false;
            break;
        }
        
    #if MIRA_PLATFORM <= MIRA_PLATFORM_ORBIS_BSD_176 || MIRA_PLATFORM > MIRA_PLATFORM_ORBIS_BSD_505
    #else 
        m_Debugger3 = new Mira::Plugins::Debugger3();
        if (m_Debugger3 == nullptr)
        {
            WriteLog(LL_Error, "could not allocate debugger.");
            s_Success = false;
            break;
        }

        // Initialize MorpheusEnabler
        m_MorpheusEnabler = new Mira::Plugins::MorpheusEnabler();
        if (m_MorpheusEnabler == nullptr)
        {
            WriteLog(LL_Error, "could not allocate morpheus enabler.");
            s_Success = false;
            break;
        }               
        // Initialize RemotePlayEnabler
        m_RemotePlayEnabler = new Mira::Plugins::RemotePlayEnabler();
        if (m_RemotePlayEnabler == nullptr)
        {
            WriteLog(LL_Error, "could not allocate remote play enabler.");
            s_Success = false;
            break;
        }

        // Initialize DebugTrophyEnabler
        m_DebugTrophyEnabler = new Mira::Plugins::DebugTrophyEnabler();
        if (m_DebugTrophyEnabler == nullptr)
        {
            WriteLog(LL_Error, "could not allocate Debug Trophy Enabler.");
            s_Success = false;
            break;
        }
    #endif        
        // Initialize TTYRedirector
        m_TTYRedirector = new Mira::Plugins::TTYRedirector();
        if (m_TTYRedirector == nullptr)
        {
            WriteLog(LL_Error, "could not allocate tty redirector.");
            s_Success = false;
            break;
        }

    } while (false);

    if (m_Debugger)
    {
        if (!m_Debugger->OnLoad())
            WriteLog(LL_Error, "could not load debugger.");
    }
    
    /*if (m_SyscallGuard)
    {
        if (!m_SyscallGuard->OnLoad())
            WriteLog(LL_Error, "could not load Syscall Guard.");
    }*/

    if (m_FileManager)
    {
        if (!m_FileManager->OnLoad())
            WriteLog(LL_Error, "could not load filemanager");
    }

    if (m_FakeSelfManager)
    {
        if (!m_FakeSelfManager->OnLoad())
            WriteLog(LL_Error, "could not load fake self manager.");
    }

    if (m_FakePkgManager)
    {
        if (!m_FakePkgManager->OnLoad())
            WriteLog(LL_Error, "could not load fake pkg manager.");
    }

    if (m_EmuRegistry)
    {
        if (!m_EmuRegistry->OnLoad())
            WriteLog(LL_Error, "could not load emulated registry.");
    }

    if (m_Substitute)
    {
        if (!m_Substitute->OnLoad())
            WriteLog(LL_Error, "could not load substitute.");
    }

    if (m_BrowserActivator)
    {
        if (!m_BrowserActivator->OnLoad())
            WriteLog(LL_Error, "could not load browser activator.");
    }
    
    if (m_RemotePkgEnabler)
    {
        if (!m_RemotePkgEnabler->OnLoad())
            WriteLog(LL_Error, "could not load remote pkg enabler.");
    } 
    #if MIRA_PLATFORM <= MIRA_PLATFORM_ORBIS_BSD_176 || MIRA_PLATFORM > MIRA_PLATFORM_ORBIS_BSD_505
    #else    
    if (m_Debugger3)
    {
        if (!m_Debugger3->OnLoad())
            WriteLog(LL_Error, "could not load debugger.");
    }   
    if (m_MorpheusEnabler)
    {
        if (!m_MorpheusEnabler->OnLoad())
            WriteLog(LL_Error, "could not load morpheus enabler.");
    }    
    if (m_RemotePlayEnabler)
    {
        if (!m_RemotePlayEnabler->OnLoad())
            WriteLog(LL_Error, "could not load remote play enabler.");
    }       
    if (m_DebugTrophyEnabler)
    {
        if (!m_DebugTrophyEnabler->OnLoad())
            WriteLog(LL_Error, "could not load Debug Trophy Enabler.");
    }
    #endif    
    if (m_TTYRedirector)
    {
        if (!m_TTYRedirector->OnLoad())
            WriteLog(LL_Error, "could not load tty redirector.");
    }
    
    return s_Success;
}

bool PluginManager::OnUnload()
{
    WriteLog(LL_Debug, "unloading all plugins");
    bool s_AllUnloadSuccess = true;

    for (auto i = 0; i < m_Plugins.size(); ++i)
    {
        WriteLog(LL_Debug, "unloading plugin idx: (%d).", i);
        auto l_Plugin = m_Plugins[i];

        // Skip any blank spots
        if (l_Plugin == nullptr)
            continue;

        WriteLog(LL_Debug, "unloading plugin: (%s).", l_Plugin->GetName());
        // TODO: Handle multiple unloads
        auto s_UnloadResult = l_Plugin->OnUnload();
        if (!s_UnloadResult)
            s_AllUnloadSuccess = false;

        WriteLog(LL_Info, "plugin (%s) unloaded %s",
            l_Plugin->GetName(), s_UnloadResult ? "successfully" : "unsuccessfully");

        WriteLog(LL_Debug, "freeing plugin");
        // Delete the plugin
        delete l_Plugin;

        WriteLog(LL_Debug, "clearing entry");
        m_Plugins[i] = nullptr;
    }

    WriteLog(LL_Debug, "clearing array");
    // Clear out all entries
    m_Plugins.clear();

    // Free the default plugins
    // Delete the file manager
    if (m_FileManager)
    {
        WriteLog(LL_Debug, "unloading file manager");

        if (!m_FileManager->OnUnload())
            WriteLog(LL_Error, "filemanager could not unload");

        // Free the file manager
        delete m_FileManager;
        m_FileManager = nullptr;
    }

    // Delete the fake self manager
    if (m_FakeSelfManager)
    {
        WriteLog(LL_Debug, "unloading fake self manager");
        if (!m_FakeSelfManager->OnUnload())
            WriteLog(LL_Error, "fake self manager could not unload");

        delete m_FakeSelfManager;
        m_FakeSelfManager = nullptr;
    }

    // Delete the fake pkg manager
    if (m_FakePkgManager)
    {
        WriteLog(LL_Debug, "unloading fake pkg manager");
        if (!m_FakePkgManager->OnUnload())
            WriteLog(LL_Error, "fake pkg manager could not unload");

        delete m_FakePkgManager;
        m_FakePkgManager = nullptr;
    }

    // Delete the emulated registry
    if (m_EmuRegistry)
    {
        WriteLog(LL_Debug, "unloading emulated registry");
        if (!m_EmuRegistry->OnUnload())
            WriteLog(LL_Error, "emuRegistry could not unload");

        delete m_EmuRegistry;
        m_EmuRegistry = nullptr;
    }

    // Delete the log server
    if (m_Logger)
    {
        WriteLog(LL_Debug, "unloading log manager");

        if (!m_Logger->OnUnload())
            WriteLog(LL_Error, "logmanager could not unload");

        // Free the file manager
        delete m_Logger;
        m_Logger = nullptr;
    }

    // Delete the log server (Console)
    if (m_LoggerConsole)
    {
        WriteLog(LL_Debug, "unloading log manager (Console)");

        if (!m_LoggerConsole->OnUnload())
            WriteLog(LL_Error, "logmanager could not unload (Console)");

        // Free the file manager
        delete m_LoggerConsole;
        m_LoggerConsole = nullptr;
    }

    // Delete Substitute
    if (m_Substitute)
    {
        WriteLog(LL_Debug, "unloading substitute");
        if (!m_Substitute->OnUnload())
            WriteLog(LL_Error, "substitute could not unload");

        // Free Substitute
        delete m_Substitute;
        m_Substitute = nullptr;
    }

    // Delete BrowserActivator
    if (m_BrowserActivator)
    {
        WriteLog(LL_Debug, "unloading browser activator");
        if (!m_BrowserActivator->OnUnload())
            WriteLog(LL_Error, "browser activator could not unload");

        // Free BrowserActivator
        delete m_BrowserActivator;
        m_BrowserActivator = nullptr;
    }
    
    // Delete RemotePkgEnabler
    if (m_RemotePkgEnabler)
    {
        WriteLog(LL_Debug, "unloading remote pkg enabler");
        if (!m_RemotePkgEnabler->OnUnload())
            WriteLog(LL_Error, "remote pkg enabler could not unload");

        // Free RemotePkgEnabler
        delete m_RemotePkgEnabler;
        m_RemotePkgEnabler = nullptr;
    } 
    #if MIRA_PLATFORM <= MIRA_PLATFORM_ORBIS_BSD_176 || MIRA_PLATFORM > MIRA_PLATFORM_ORBIS_BSD_505
    #else    
    // Delete the debugger
    // NOTE: Don't unload before the debugger for catch error if something wrong
    if (m_Debugger3)
    {
        WriteLog(LL_Debug, "unloading debugger");
        if (!m_Debugger3->OnUnload())
            WriteLog(LL_Error, "debugger could not unload");

        // Free the debugger
        delete m_Debugger3;
        m_Debugger3 = nullptr;
    }    

    // Delete MorpheusEnabler
    if (m_MorpheusEnabler)
    {
        WriteLog(LL_Debug, "unloading morpheus enabler");
        if (!m_MorpheusEnabler->OnUnload())
            WriteLog(LL_Error, "morpheus enabler could not unload");

        // Free MorpheusEnabler
        delete m_MorpheusEnabler;
        m_MorpheusEnabler = nullptr;
    }
       
    // Delete RemotePlayEnabler
    if (m_RemotePlayEnabler)
    {
        WriteLog(LL_Debug, "unloading remote play enabler");
        if (!m_RemotePlayEnabler->OnUnload())
            WriteLog(LL_Error, "remote play enabler could not unload");

        // Free RemotePlayEnabler
        delete m_RemotePlayEnabler;
        m_RemotePlayEnabler = nullptr;
    }
    
    // Delete DebugTrophyEnabler
    if (m_DebugTrophyEnabler)
    {
        WriteLog(LL_Debug, "unloading remote pkg enabler");
        if (!m_DebugTrophyEnabler->OnUnload())
            WriteLog(LL_Error, "Debug Trophy Enabler could not unload");

        // Free DebugTrophyEnabler
        delete m_DebugTrophyEnabler;
        m_DebugTrophyEnabler = nullptr;
    }
    #endif 
    // Delete the debugger
    // NOTE: Don't unload before the debugger for catch error if something wrong
    if (m_Debugger)
    {
        WriteLog(LL_Debug, "unloading debugger");
        if (!m_Debugger->OnUnload())
            WriteLog(LL_Error, "debugger could not unload");

        // Free the debugger
        delete m_Debugger;
        m_Debugger = nullptr;
    }
    
    // Delete the m_SyscallGuard
    // NOTE: Don't unload before the Syscall Guard for catch error if something wrong
    /*if (m_SyscallGuard)
    {
        WriteLog(LL_Debug, "unloading syscall guard");
        if (!m_SyscallGuard->OnUnload())
            WriteLog(LL_Error, "syscall guard could not unload");

        delete m_SyscallGuard;
        m_SyscallGuard = nullptr;
    }*/
    
    // Unload TTY Redirector
    if (m_TTYRedirector)
    {
        WriteLog(LL_Debug, "unloading tty redirector");
        if (!m_TTYRedirector->OnUnload())
            WriteLog(LL_Error, "tty redirector could not unload");

        // Free TTYRedirector
        delete m_TTYRedirector;
        m_TTYRedirector = nullptr;
    }
    
    WriteLog(LL_Debug, "All Plugins Unloaded %s.", s_AllUnloadSuccess ? "successfully" : "un-successfully");
    return s_AllUnloadSuccess;
}

bool PluginManager::OnSuspend()
{
    // Hold our "all success" status
    bool s_AllSuccess = true;

    // Iterate through all of the plugins
    for (auto i = 0; i < m_Plugins.size(); ++i)
    {
        // Validate that this plugin still exists
        auto l_Plugin = m_Plugins[i];
        if (l_Plugin == nullptr)
            continue;

        // Suspend the plugin
        auto s_SuspendResult = l_Plugin->OnSuspend();
        if (!s_SuspendResult)
            s_AllSuccess = false;

        // Debugging status
        WriteLog(LL_Info, "plugin (%s) suspend %s",
            l_Plugin->GetName(),
            s_SuspendResult ? "success" : "failure");
    }

    // Suspend the built in plugins
    if (m_FileManager)
    {
        if (!m_FileManager->OnSuspend())
            WriteLog(LL_Error, "file manager suspend failed");
    }

    if (m_FakeSelfManager)
    {
        if (!m_FakeSelfManager->OnSuspend())
            WriteLog(LL_Error, "fake self manager suspend failed");
    }

    if (m_EmuRegistry)
    {
        if (!m_EmuRegistry->OnSuspend())
            WriteLog(LL_Error, "emuRegistry suspend failed");
    }

    // Suspend both of the loggers (cleans up the sockets)
    if (m_Logger)
    {
        if (!m_Logger->OnSuspend())
            WriteLog(LL_Error, "log manager suspend failed");
    }

    if (m_LoggerConsole)
    {
        if (!m_LoggerConsole->OnSuspend())
            WriteLog(LL_Error, "log manager suspend failed (Console)");
    }

    // Suspend substitute (currently does nothing)
    if (m_Substitute)
    {
        if (!m_Substitute->OnSuspend())
            WriteLog(LL_Error, "substitute suspend failed");
    }

    // Suspend BrowserActivator (does nothing)
    if (m_BrowserActivator)
    {
        if (!m_BrowserActivator->OnSuspend())
            WriteLog(LL_Error, "browser activator suspend failed");
    }
  
    // Suspend RemotePkgEnabler (does nothing)
    if (m_RemotePkgEnabler)
    {
        if (!m_RemotePkgEnabler->OnSuspend())
            WriteLog(LL_Error, "remote pkg enabler suspend failed");
    }
    
    #if MIRA_PLATFORM <= MIRA_PLATFORM_ORBIS_BSD_176 || MIRA_PLATFORM > MIRA_PLATFORM_ORBIS_BSD_505
    #else    
    if (m_Debugger3)
    {
        if (!m_Debugger3->OnSuspend())
            WriteLog(LL_Error, "debugger suspend failed");
    }
        
    // Suspend RemotePlayEnabler (does nothing)
    if (m_RemotePlayEnabler)
    {
        if (!m_RemotePlayEnabler->OnSuspend())
            WriteLog(LL_Error, "remote play enabler suspend failed");
    }

    // Suspend MorpheusEnabler (does nothing)
    if (m_MorpheusEnabler)
    {
        if (!m_MorpheusEnabler->OnSuspend())
            WriteLog(LL_Error, "morpheus enabler suspend failed");
    }
          
    // Suspend DebugTrophyEnabler (does nothing)
    if (m_DebugTrophyEnabler)
    {
        if (!m_DebugTrophyEnabler->OnSuspend())
            WriteLog(LL_Error, "Debug Trophy Enabler suspend failed");
    }
    #endif    
    // Nota: Don't suspend before the debugger for catch error if something when wrong
    if (m_Debugger)
    {
        if (!m_Debugger->OnSuspend())
            WriteLog(LL_Error, "debugger suspend failed");
    }
    
    /*if (m_SyscallGuard)
    {
        if (!m_SyscallGuard->OnSuspend())
            WriteLog(LL_Error, "Syscall Guard suspend failed");
    }*/
    
    // Suspend TTYRedirector (does nothing)
    if (m_TTYRedirector)
    {
        if (!m_TTYRedirector->OnSuspend())
            WriteLog(LL_Error, "tty redirector suspend failed");
    }
    
    // Return final status
    return s_AllSuccess;
}

bool PluginManager::OnResume()
{
    // Hold our "all success" status
    bool s_AllSuccess = true;

    WriteLog(LL_Debug, "Resuming all plugins");

    WriteLog(LL_Debug, "resuming debugger");
    if (m_Debugger)
    {
        if (!m_Debugger->OnResume())
            WriteLog(LL_Error, "debugger resume failed");
    }
    
    /*WriteLog(LL_Debug, "resuming Syscall Guard");
    if (m_SyscallGuard)
    {
        if (!m_SyscallGuard->OnResume())
            WriteLog(LL_Error, "Syscall Guard resume failed");
    }*/

    WriteLog(LL_Debug, "resuming log manager");
    if (m_Logger)
    {
        if (!m_Logger->OnResume())
            WriteLog(LL_Error, "log manager resume failed");
    }

    WriteLog(LL_Debug, "resuming log manager (Console)");
    if (m_LoggerConsole)
    {
        if (!m_LoggerConsole->OnResume())
            WriteLog(LL_Error, "log manager resume failed (Console)");
    }

    WriteLog(LL_Debug, "resuming emuRegistry");
    if (m_EmuRegistry)
    {
        if (!m_EmuRegistry->OnResume())
            WriteLog(LL_Error, "emuRegistry resume failed");
    }

    WriteLog(LL_Debug, "resuming substitute");
    if (m_Substitute)
    {
        if (!m_Substitute->OnResume())
            WriteLog(LL_Error, "substitute resume failed");
    }

    WriteLog(LL_Debug, "resuming browser activator");
    if (m_BrowserActivator)
    {
        if (!m_BrowserActivator->OnResume())
            WriteLog(LL_Error, "browser activator resume failed");
    }
       
    WriteLog(LL_Debug, "resuming Remote Pkg Enabler");
    if (m_RemotePkgEnabler)
    {
        if (!m_RemotePkgEnabler->OnResume())
            WriteLog(LL_Error, "Remote Pkg Enabler resume failed");
    }
    #if MIRA_PLATFORM <= MIRA_PLATFORM_ORBIS_BSD_176 || MIRA_PLATFORM > MIRA_PLATFORM_ORBIS_BSD_505
    #else    
    WriteLog(LL_Debug, "resuming debugger");
    if (m_Debugger3)
    {
        if (!m_Debugger3->OnResume())
            WriteLog(LL_Error, "debugger resume failed");
    }
        
    WriteLog(LL_Debug, "resuming Remote Play Enabler");
    if (m_RemotePlayEnabler)
    {
        if (!m_RemotePlayEnabler->OnResume())
            WriteLog(LL_Error, "Remote Play Enabler resume failed");
    }

    WriteLog(LL_Debug, "resuming morpheus enabler");
    if (m_MorpheusEnabler)
    {
        if (!m_MorpheusEnabler->OnResume())
            WriteLog(LL_Error, "morpheus enabler resume failed");
    }
            
    WriteLog(LL_Debug, "resuming Debug Trophy Enabler");
    if (m_DebugTrophyEnabler)
    {
        if (!m_DebugTrophyEnabler->OnResume())
            WriteLog(LL_Error, "Debug Trophy Enabler resume failed");
    }
    #endif    
    WriteLog(LL_Debug, "resuming tty redirector");
    if (m_TTYRedirector)
    {
        if (!m_TTYRedirector->OnResume())
            WriteLog(LL_Error, "tty redirector resume failed");
    }

    // Iterate through all of the plugins
    for (auto i = 0; i < m_Plugins.size(); ++i)
    {
        // Validate that this plugin still exists
        WriteLog(LL_Error, "Resuming plugin idx: (%d).", i);
        auto l_Plugin = m_Plugins[i];
        if (l_Plugin == nullptr)
            continue;

        // Resume the plugin
        WriteLog(LL_Info, "resuming plugin (%s).", l_Plugin->GetName());
        auto s_ResumeResult = l_Plugin->OnResume();
        if (!s_ResumeResult)
            s_AllSuccess = false;

        // Debugging status
        WriteLog(LL_Info, "plugin (%s) resume %s",
            l_Plugin->GetName(),
            s_ResumeResult ? "success" : "failure");
    }

    WriteLog(LL_Debug, "resuming file manager");
    if (m_FileManager)
    {
        if (!m_FileManager->OnResume())
            WriteLog(LL_Error, "file manager resume failed");
    }


    WriteLog(LL_Debug, "resuming fake self manager");
    if (m_FakeSelfManager)
    {
        if (!m_FakeSelfManager->OnResume())
            WriteLog(LL_Error, "fake self manager resume failed");
    }

    WriteLog(LL_Debug, "resume all %s", s_AllSuccess ? "successfully" : "un-successfully");

    // Return final status
    return s_AllSuccess;
}
