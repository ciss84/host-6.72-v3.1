var ICONSZ = 150;
var PADDING = 20;
var model = {
  cursor: {
    x: 0,
    y: 0
  },
  columns: {
	 "QUICK": {
      index: 0,
      title: "★QUICK★",
      selectedIndex: 0,
      active: false,
      icon: 'style',
      items: [{title:"Mira Loader Usb 505", desc:"Enable only ELF LOADER function on Usb port", version:"1.1 by Lightningmods", icon:"send", expage:"payloads/mira2.html"}, {title:"Mira Loader Usb 672", desc:"Enable only ELF LOADER function on Usb port", version:"1.1 by Lightningmods", icon:"send", expage:"payloads/miracharger672/miracharger672.html"}, {title:"FTP + FULL R/W", desc:"Starts an ftp server with full R/W on all 16 partitions of your PS4", version:"1.0 by Lightningmods", icon:"warning", expage:"payloads/ftprw.html"}, {title:"WEB-RTE PS4 TRAINER", desc:"Use http://ps4trainer.com/trainer + enter your PS4 IP", version:"1.00 by TylerMods", icon:"whatshot", expage:"payloads/WebRTE.html"}, {title:"WEB-RTE2", desc:"Use Droid App", version:"1.00", icon:"whatshot", expage:"payloads/Webrte2.html"}, {title:"PS4 Trainer", desc:"PS4 Trainer", version:"1.0 by ", icon:"?", expage:"payloads/PS4Trainer.html"}, { title:"★Debug_MiraHen 1", desc:"Furst load ps4debug 1.5 payloads", version:"ps4debug 1.5", icon:"lock", expage:"payloads/ps4debug15.html"}, { title: "★MiraHen 2", desc: "Second load miraCfw patches", version: "by specterdev", icon: "lock", expage: "payloads/PS4Brew5.05.html" }, { title:"★Hen 2.1.4", desc:"Inc: 7.50 PSVR spoof, Debug Trophies Support, Enable UART, Remote Play Enabler", version:"2.1.3 by SiSTRo", icon:"", expage:"payloads/Hen213.html"}, { title: "DUMPER", desc: "Dump disc/PSN games to USB: with/without patches, merged/unmerged", version: "1.8 by xVortex", active: false, icon: "archive", expage: "payloads/vtxdump.html"}, { title: "BINLOADER", desc: "Enable only BIN LOADER function on port:9020", version: "1.7 by OpenOrbisTeam", active: false, icon: "send", expage: "payloads/binloader.html" }]
  },      
  "HEN": {
      index: 1,
      title: "HEN",
      selectedIndex: 0,
      icon: 'gamepad',
      items: [{title:"HEN 2.2 MIRAFtp", desc:"Inc: 7.50 PSVR spoof, Debug Trophies Support, Enable UART, Remote Play Enabler", version:"2.1.1 by SiSTRo", icon:"", expage:"payloads/miraHen18vr.html"}, {title:"HEN 2.1.4", desc:"Inc: 7.50 PSVR spoof, Debug Trophies Support, Enable UART, Remote Play Enabler", version:"2.1.3 by SiSTRo", icon:"", expage:"payloads/Hen213.html"}, {title:"HEN 2.1.2", desc:"Inc: rest mode fix for phat/slim/pro spoof 7.02", version:"2.1.2 by SiSTRo", icon:"", expage:"payloads/Hen212.html"},{title:"HEN 2.1.1", desc:"Inc: rest mode fix for phat/slim/pro spoof 6.70", version:"2.1.1 by SiSTRo", icon:"", expage:"payloads/Hen211.html"}, {title:"HEN 2.1", desc:"Inc: rest mode fix for phat/slim/pro + 9.00 PSVR spoof", version:"2.1 by SiSTRo", icon:"", expage:"payloads/Hen21.html"}, {title:"HEN 2.0", desc:"Inc: rest mode fix for phat/slim/pro + 9.00 PSVR spoof", version:"2.0 by SiSTRo", icon:"", expage:"payloads/Hen20.html"}, {title:"HEN 1.9", desc:"WARNING! Incompatable with some games. Added PKG install from internal HDD support", version:"1.9 by LightningMods", icon:"", expage:"payloads/Hen19.html"}, {title:"HEN 1.8", desc:"Inc: self spawn & usermode printf to klog patches", version:"1.8 by Zecoxao", icon:"", expage:"payloads/Hen18.html"}, {title:"HEN 1.7", desc:"Runs fake signed content from internal & external storage", version:"1.7 by xVortex", icon:"", expage:"payloads/Hen17.html"}, {title:"HEN 1.6", desc:"Runs fake signed content (out dated)", version:"1.6 by xVortex", icon:"", expage:"payloads/Hen16.html"}, {title:"HEN 1.8 + VR", desc:"Enables HEN 1.8 and spoofs 9.00", version:"1.8 by Zecoxao/Stooged", icon:"polymer", expage:"payloads/Hen18_VR.html"}, {title:"HEN 1.7 + VR", desc:"Enable VTX HEN 1.7 and VR all in one", version:"1.7 by xVortex/Stooged", icon:"polymer", expage:"payloads/Hen17_VR.html"}, {title:"HEN + SCREENSHOT", desc:"Enable VTX HEN 1.7 with no in app screenshot limitations", version:"1.7 mod by BIORN", icon:"tab", expage:"payloads/screenshot.html"}, {title:"HEN (LITE)", desc:"Enable VTX HEN 1.7 without the update blocker", version:"1.7 mod by C0d3m4st4", icon:"loupe", expage:"payloads/Hen17_c0d3mod.html"}, {title:"HEN + AUTH", desc:"Enables VTX HEN 1.7 with AUTH patches", version:"1.7 mod by Björn", icon:"texture", expage:"payloads/henauth.html"}, {title:"HEN 1.8 + VR + MIRA", desc:"AIO: PSVR homebrew with klog", version:"1.8 by Zecoxao/Stooged/OpenOrbisTeam", icon:"", expage:"payloads/miraHen18vr.html"}, {title:"HEN 1.8 + MIRA", desc:"Run fake signed content. Inc: debug settings, Kernel logging (port 9999/9998)", version:"1.8 by Zecoxao/OpenOrbisTeam", icon:"apps", expage:"payloads/miraHen18.html"}, {title:"HEN 1.7 + MIRA", desc:"Run fake signed content. Inc: debug settings, Kernel logging (port 9999/9998)", version:"1.7 by xVortex/OpenOrbisTeam", icon:"apps", expage:"payloads/miraHen17.html"}, {title:"HEN 1.7 + MIRA + BINLOADER", desc:"Enable MIRA HEN 1.7 with BINLOADER", version:"1.7 by xVortex/OpenOrbisTeam/Specter", icon:"input", expage:"payloads/miraHen17Bin.html"}]
    },
    "BLOCK": {
      index: 2,
      title: "BLOCK",
      selectedIndex: 0,
      icon: "",
      items: [{title:"UPDATE DISABLER", desc:"Run once to disable updates permanently", version:"1.0 by Al-Azif", icon:"clear", expage:"payloads/blocker.html"}, {title:"UPDATE ENABLER", desc:"Re-allow updates to download/install", version:"1.0 by Al-Azif", icon:"undo", expage:"payloads/unblock.html"}, {title:"BLOCKER + FTP", desc:"Run to block updates permanently, and start FTP server", version:"1.3 by Lightningmods & CelesteBlue", icon:"block", expage:"payloads/blockftp.html"}, {title:"UPDATE BLOCKER EXTREME", desc:"Blocks every possibly update location permanently", version:"1.0 by Lightningmods", icon:"language", expage:"payloads/blockEX.html"}, {title:"UPDATE BLOCKER EXTREME UNDO", desc:"Re-allow updates to download/install", version:"1.0 by Lightningmods", icon:"sync_disabled", expage:"payloads/unblockEX.html"}]
    },
    "LINUX": {
      index: 3,
      title: "LINUX",
      selectedIndex: 0,
      icon: "laptop",
      items: [{title:"INTERNAL LINUX", desc:"Run Linux from the PS4's internal HDD. (Requires Linux files be copied to the PS4 HDD first!)", version:"1.0 by Cedsaill", icon:"", expage:"payloads/linuxInternal.html"},{title:"VRAM1 PSXITARCH LINUX V2", desc:"1GB VRAM + 7GB RAM Linux kernel loader (Requires USB Drive)", version:"VRAM1 by PSXITA", icon:"", expage:"payloads/linux1GB.html"}, {title:"VRAM2 PSXITARCH LINUX V2", desc:"2GB VRAM + 6GB RAM Linux kernel loader (Requires USB Drive)", version:"VRAM2 by PSXITA", icon:"", expage:"payloads/linux2GB.html"},{title:"VRAM3 PSXITARCH LINUX V2 (DON'T USE TO INSTALL)", desc:"3GB VRAM + 5GB RAM Linux kernel loader (Requires USB Drive)", version:"VRAM3 by PSXITA", icon:"", expage:"payloads/linux3GB.html"},{title:"PSXITA NOEDID LINUX V2 (VRAM2)", desc:"Set video out to 1080p + unplug PSVR before use (Requires USB Drive)", version:"NOEDID by PSXITA", icon:"web", expage:"payloads/linuxNOedid.html"}, {title:"LINUX LOADER", desc:"Lightweight Linux kernel loader (Requires USB Drive)", version:"1.0 by EEPLY", icon:"camera", expage:"payloads/linuxEeply.html"}, {title:"LINUX LOADER", desc:"Boots linux kernel from USB - Wait 85 sconds for reboot (Requires USB Drive)", version:"1.0 by Vultra", icon:"keyboard", expage:"payloads/linuxVul.html"}]
    },
    "BACKUP": {
      index: 4,
      title: "BACKUP",
      selectedIndex: 0,
      icon: "backup",
      items: [{title:"GAME DUMPER", desc:"Dump disc/PSN games to USB: with/without patches, merged/unmerged", version:"1.8 by xVortex", icon:"archive", expage:"payloads/vtxdump.html"},{title:"DISC DUMP", desc:"Copy content from disc to USB", version:"1.0 by Stooged", icon:"eject", expage:"payloads/discdump.html"},{title:"PKG BACKUP", desc:"Copy PKG files back to USB easily", version:"2.0 by Stooged", icon:"redo", expage:"payloads/pkgbackup.html"},{title:"DB SG BACKUP", desc:"Back up your game saves and important databases", version:"3.0 by Stooged", icon:"save", expage:"payloads/dbsg.html"}, {title:"DB RESTORE", desc:"Restore your backed up databases", version:"2.0 by Stooged", icon:"publish", expage:"payloads/dbrestore1.html"}, {title:"DB RESTORE UNDO", desc:"Undo an accidental DB restoration", version:"2.0 by Leeful", icon:"delete", expage:"payloads/dbrestoreUNDO1.html"},{title:"APPTOUSB", desc:"Specify mount point and move games to external EXFAT USB for extra storage", version:"5.0 by Stooged", icon:"storage", expage:"payloads/apptousb.html"}, {title:"APPTOUSB ALT", desc:"Like AppToUsb but purely for USB1", version:"1.0 mod by Jakkal", icon:"dns", expage:"payloads/apptousb1alt.html"}, {title:"USB FAKE PACKAGES", desc:"An alternative based on pkg2usb by SiSTRO and AppToUsb by Stooged", version:"1.11 by Specialfood", icon:"usb", expage:"payloads/usbfpkgs.html"}]
    },
    "SYSTEM": {
	  index: 5,
      title: "SYSTEM",
      selectedIndex: 0,
      icon: "home",
	  items: [{title:"FAN CONTROL", desc:"Set the temperature at which the PS4 fans will kick in (79° = PS4 default value)", version:"3.0 by Leeful", icon:"", expage:"payloads/fancontrol.html"}, {title:"FW SPOOF", desc:"Spoof the PS4's Firmware version to anything between 0.00 and 99.99", version:"1.0 by Leeful", icon:"", expage:"payloads/fwspoof.html"},{title:"AVATAR DUMPER", desc:"Dumps avatar files from user profile. Requires exFAT formatted USB", version:"1.0 by Red-J", icon:"contacts", expage:"payloads/avadump.html"},{title:"AVATAR INJECTOR", desc:"Injects avatar files to user profile. Requires files on exFAT formatted USB", version:"1.0 by Red-J", icon:"portrait", expage:"payloads/avainject.html"},{title:"AUTH INFO DUMPER", desc:"Dumps auth_info.log. Requires exFAT formatted USB", version:"1.0 by Stooged", icon:"details", expage:"payloads/authdump.html"}, {title:"EVERSION KERNEL DUMPER", desc:"Dumps kernel to USB. Works on 4.05/4.55/4.74/5.01/5.05 OFW", version:"1.4 by CelesteBlue", icon:"memory", expage:"payloads/everkdump.html"}, {title:"KERNEL DUMPER", desc:"Dumps your kernel to USB", version:"2.0 by Stooged", icon:"work", expage:"payloads/kdumper.html"}, {title:"MODULE DUMPER", desc:"Dumps your consoles file system to USB", version:"1.0", icon:"pageview", expage:"payloads/ps4moduledumper.html"}, {title:"FS DUMPER", desc:"Dumps your consoles file system to USB", version:"1.0 by Stooged", icon:"pageview", expage:"payloads/fsdumper.html"}, {title:"MIRA", desc:"RPC Server Port: 9999 KLog Server Port: 9998", version:"1.0 by OpenOrbisTeam", icon:"nfc", expage:"payloads/mira.html"}, {title:"KERNEL LOGGER", desc:"KLog Server Port: 5656", version:"1.0 by ChendoChap", icon:"", expage:"payloads/klogserver.html"},{title:"BINLOADER", desc:"Enable only BIN LOADER function on port:9020", version:"1.0 by Specter", icon:"send", expage:"payloads/binloader.html"}]
	},
  "TOOLS": {
      index: 6,
      title: "TOOLS",
      selectedIndex: 0,
      icon: "settings",
      items: [{title:"PKG installer", desc:"Package Installer", version:"1.0 by ", icon:"?", expage:"rpi/rpi.html"}, {title:"INFINIX", desc:"Package Installer including HEN", version:"1.0 by LightningMods", icon:"", expage:"payloads/Infinix.html"}, {title:"PUP DECRYPT", desc:"Decrypt updates from USB root (safe.PS4UPDATE.pup)", version:"1.0 by LOLHAX & SocraticBliss", icon:"", expage:"payloads/pupdec.html"}, {title:"SYSCALL 112", desc:"Allow homebrew apps to get root permission by using syscall 112", version:"1.0 by Zecoxao", icon:"", expage:"payloads/syscall112.html"}, {title:"RIF RENAMER", desc:"Converts licences from MIRA to HEN compatible", version:"1.0 by ALAZIF", icon:"", expage:"payloads/rifrenamer.html"}, {title:"PS4REN", desc:"Remote Play Enabler", version:"2.0 by SiSTRO", icon:"tablet", expage:"payloads/PS4ren.html"},{title:"SAVE MOUNTER + FTP", desc:"No need for save wizard! Loads Save Mounter and FTP in one", version:"1.5 by Chendochap", icon:"folder", expage:"payloads/savemounter.html"},{title:"ORBISAFR", desc:"Application file redirector for game modding", version:"1.0 by TheoryWrong", icon:"layers", expage:"payloads/orbisafr.html"},{title:"SYSCALL 9", desc:"Unjail with UART", version:"1.0 by Lightningmods", icon:"", expage:"payloads/syscall9.html"},{title:"VR ENABLER", desc:"Enables VR headset even after HEN has been run", version:"1.0 by Stooged", icon:"visibility", expage:"payloads/vrEnable.html"}, {title:"FTP SERVER", desc:"Start an ftp server and connect your PC to your PS4", version:"1.3 by xVortex", icon:"wifi", expage:"payloads/ftp.html"}, {title:"FTP + FULL R/W", desc:"Starts an ftp server with full R/W on all 16 partitions of your PS4", version:"1.0 by Lightningmods", icon:"warning", expage:"payloads/ftprw.html"}, {title:"REACTPSPLUS", desc:"Turn your consoles internal kernel clock back to Jun 2012 to play expired PSPLUS games", version:"v1.0 by Zer0xFF", icon:"restore", expage:"payloads/react.html"}, {title:"UN-REACTPSPLUS", desc:"Turn your consoles internal kernel clock back to today's date & time", version:"v1.0 by Al-Azif  / Mod by Leeful", icon:"update", expage:"payloads/unreact.html"}, {title:"REACTPSPLUS-MOD", desc:"Change your consoles internal kernel clock to whatever date & time you want", version:"1.0 by Zer0xFF / Mod by Leeful", icon:"timelapse", expage:"payloads/reactmod.html"}]
    },
	"CHEATS": {
      index: 7,
      title: "CHEATS",
      selectedIndex: 0,
      icon: "search",
      items: [{title:"WEB-RTE PS4 TRAINER", desc:"Use http://ps4trainer.com/trainer + enter your PS4 IP", version:"1.00 by TylerMods", icon:"whatshot", expage:"payloads/WebRTE.html"},{title:"ORBISDBG", desc:"Memory/process debugger. (Use: ORBISDBGUI)", version:"1.00 by Skiffaw", icon:"gradient", expage:"payloads/orbdbg.html"},{title:"MEMAPI", desc:"Server, debugger and library tools", version:"1.00 by McCaulay", icon:"subject", expage:"payloads/memapi.html"}, {title:"IH-EDITOR PS4 RTM TOOL", desc:"Cheat tool with RTM functions", version:"1.0.2 by Intention Hackers", icon:"dvr", expage:"payloads/ihrtm.html"},{title:"COMMUNITY TRAINER", desc:"Community driven cheat tool", version:"2.1.0.0 by DeathRGH", icon:"comment", expage:"payloads/community.html"}, {title:"PS4 TRAINER", desc:"Game trainer tool for cheating", version:"1.5.129.127 by TylerMods", icon:"code", expage:"payloads/tylermods.html"}, {title:"DEATHRGH PS4 TOOLBOX", desc:"Cheat toolbox with peek/poke and notifications", version:"1.6.0.0 by DeathRGH", icon:"attachment", expage:"payloads/deathrgh.html"}, {title:"PS4 CHEATER", desc:"Tool to help find and implement cheats", version:"1.4.7 by ChendoChap", icon:"create", expage:"payloads/cheater.html"}, {title:"PS4API SERVER", desc:"Allows control of game memory for RTE/RTM tools", version:"1.2 by Helloitu", icon:"flag", expage:"payloads/ps4api.html"}, {title:"PS4API SERVER", desc:"Allows control of game memory for RTE/RTM tools", version:"1.1 by Bisoon", icon:"transform", expage:"payloads/ps4apiBisoon.html"}, {title:"JKPATCH LOADER", desc:"RPC server for finding cheats", version:"2.0 by GOLDEN", icon:"timeline", expage:"payloads/jkpatch.html"}, {title:"DEBUGWATCH", desc:"Full featured debugging utility", version:"1.0.0.0 by Golden", icon:"watch", expage:"payloads/DebugWatch.html"},{title:"PLAYENGINE", desc:"Scan & edit PS4 process memory", version:"2.0 Berkay2578/EpicFail78", icon:"traffic", expage:"payloads/PlayEngine.html"}]
    },
  "GTAV MENUS": {
      index: 8,
      title: "GTAV",
      selectedIndex: 0,
      icon: "copyright",
	  custom: "GTAV",
	  txt1:"[Press ",
      txt2:"+ ",
      txt3:"to activate]",
      items: [{title:"LOTUS 127 - ", button1:"DRBUTTON", button2:"SBUTTON", desc:"GTAV mod menu for EU/US game version 1.27", version:"1.03 by 0x199", icon:"spa", expage:"payloads/GTA_Lotus127.html"},{title:"NOTYOURDOPES 127 - ", button1: "R1BUTTON", button2: "DDBUTTON", desc:"GTAV mod menu for EU/US game version 1.27", version:"1.0 by Vicodin10", icon:"casino", expage:"payloads/GTA_NotYourDopes127.html"}, {title:"LTSMENU 127 - ", button1: "DRBUTTON", button2: "SBUTTON", desc:"GTAV mod menu for EU/US game version 1.27", version:"1.0 by CMTFrosty (LastTeamStanding)", icon:"group", expage:"payloads/GTA_LTS127.html"}, {title:"NOTANOTHERMENU - ", button1: "DRBUTTON", button2: "SBUTTON", desc:"GTAV mod menu for EU/US game version 1.00", version:"0.1 by David1337hax", icon:"redeem", expage:"payloads/GTA_NotAnother.html"}, {title:"NOTANOTHERMENU 127 - ", button1: "DRBUTTON", button2: "SBUTTON", desc:"GTAV mod menu for EU/US game version 1.27", version:"0.2 by David1337hax", icon:"redeem", expage:"payloads/GTA_NotAnother127.html"}, {title:"AP II INTENSE V2 - ", button1: "R1BUTTON", button2: "SBUTTON", desc:"GTAV mod menu for EU/US game version 1.00", version:"1.1 by EROOTIIK", icon:"extension", expage:"payloads/GTA_Intense.html"}, {title:"AP II INTENSE V2 1.27 - ", button1: "R1BUTTON", button2: "SBUTTON", desc:"GTAV mod menu for EU/US game version 1.27", version:"1.5 by EROOTIIK", icon:"extension", expage:"payloads/GTA_Intense127.html"}, {title:"LAMANCE - ", button1: "DRBUTTON", button2: "SBUTTON", desc:"GTAV mod menu for EU/US game version 1.00", version:"0.8 by David1337hax", icon:"stars", expage:"payloads/GTA_Lamance.html"}, {title:"LAMANCE 1.27 - ", button1: "DRBUTTON", button2: "SBUTTON", desc:"GTAV mod menu for EU/US game version 1.27", version:"0.8 by David1337hax", icon:"stars", expage:"payloads/GTA_Lamance127.html"}, {title:"WILDEMODZ - ", button1: "DLBUTTON", button2: "SBUTTON", desc:"GTAV mod menu for EU/US game version 1.00", version:"1.1 by Wildemodz", icon:"accessibility", expage:"payloads/GTA_WildeModz.html"}, {title:"WILDEMODZ 127 - ", button1: "DLBUTTON", button2: "SBUTTON", desc:"GTAV mod menu for EU/US game version 1.27", version:"1.2 by Wildemodz", icon:"accessibility", expage:"payloads/GTA_WildeModz127.html"}, {title:"TEAM PSYC0S - ", button1: "DLBUTTON", button2: "SBUTTON", desc:"GTAV mod menu for EU/US game version 1.00", version:"1.0 by AlFaMoDz", icon:"build", expage:"payloads/GTA_Psych0s.html"}, {title:"ARABICGUY - ", button1: "L1BUTTON", button2: "R1BUTTON", desc:"GTAV mod menu for EU/US game version 1.00", version:"1.1 by RF0oDxM0Dz", icon:"face", expage:"payloads/GTA_ArabicGuy.html"}, {title:"TRAINER - ", button1: "DRBUTTON", button2: "SBUTTON", desc:"GTAV mod menu for EU/US game version 1.00", version:"1.0 by David1337hax", icon:"shop", expage:"payloads/GTA_Trainer.html"}]
    },
	"OTHER MENUS": {
      index: 9,
      title: "OTHER",
      selectedIndex: 0,
      icon: "copyright",
	  custom: "NDICON",
      items: [{title:"THE LAST OF US 1.08", desc:"", txt4:"[ ", button3:"L3BUTTON", txt5:"+ ", button4:"TLBUTTON", txt6:"] = Quick Menu, ", txt4:"[ ", button5:"L3BUTTON", txt5:"+ ", button6:"TRBUTTON", txt7:"] = Dev Menu, ", txt4:"[ ", button7:"L3BUTTON", txt5:"+ ", button8:"R3BUTTON", txt8:"] = Fly Mode", version:"2.0 by Vicodin10", icon:"accessibility", expage:"payloads/TLOUR.html"},{title:"UNCHARTED 4 1.00/1.18/1.32", desc:"", txt4:"[ ", button3:"L3BUTTON", txt5:"+ ", button4:"TLBUTTON", txt6:"] = Quick Menu, ", txt4:"[ ", button5:"L3BUTTON", txt5:"+ ", button6:"TRBUTTON", txt7:"] = Dev Menu, ", txt4:"[ ", button7:"L3BUTTON", txt5:"+ ", button8:"R3BUTTON", txt8:"] = Fly Mode", button9:"L3BUTTON",button10:"OPBUTTON",txt9:", [ ", txt10:"+ ",txt11:"] = Fav Menu", version:"2.0 by Vicodin10", icon:"exposure", expage:"payloads/UC4.html"},{title:"UNCHARTED THE LOST LEGACY 1.00", desc:"", txt4:"[ ", button3:"L3BUTTON", txt5:"+ ", button4:"TLBUTTON", txt6:"] = Quick Menu, ", txt4:"[ ", button5:"L3BUTTON", txt5:"+ ", button6:"TRBUTTON", txt7:"] = Dev Menu, ", txt4:"[ ", button7:"L3BUTTON", txt5:"+ ", button8:"R3BUTTON", txt8:"] = Fly Mode", button9:"L3BUTTON",button10:"OPBUTTON",txt9:", [ ", txt10:"+ ",txt11:"] = Fav Menu", version:"2.0 by Vicodin10", icon:"motorcycle", expage:"payloads/UCTLL.html"}, {title:"NEED FOR SPEED PAYBACK 1.08", desc:"Unlimited nitrous cheat", version:"1.0 by x3shakir", icon:"", expage:"payloads/NFSP.html"} ] 
	 },
	"LAN PLAY": {
      index: 10,
      title: "LAN",
      selectedIndex: 0,
      icon: "",
      items: [{title:"LAN PLAY", desc:"Play LAN PLAY games online in private servers", version:"1.0 by TheoryWrong", icon:"language", expage:"payloads/BO3.html"}]
	},  
	"MEDIA": {
      index: 11,
      title: "MEDIA",
      selectedIndex: 0,
      icon: "subscriptions",
      items: [{title:"MP4 PLAYER", desc:"Media player for MP4 movies over network", version:"1.0 by DEFAULTDNB", icon:"airplay", expage:"payloads/playerloader.html"}]
	},
	"CACHE": {
      index: 12,
      title: "CACHE",
      selectedIndex: 0,
      icon: "copyright",
      items: [{title:"X-PROJECT CACHE INSTALLER", desc:"Cache X-Project to your web browser for offline use", version:"1.0 by Al-Azif / Mod By Leeful", icon:"", expage:"payloads/xmbcache.html"}, {title:"USB CACHE INSTALL", desc:"Installs an ApplicationCache.db from USB for offline use", version:"10.0 by Stooged", icon:"beenhere", expage:"payloads/usbcacheinstall.html"}, {title:"HISTORY BLOCKER", desc:"Toggle auto loading the last page used in webbrowser", version:"2.0 by Stooged", icon:"bookmark", expage:"payloads/history.html"}, {title:"★TITEL", desc:"Test", version:"1.0", icon:"", expage:"payloads/titel/index.html"}]
	},
	 "ABOUT": {
      index: 13,
      title: "ABOUT",
      selectedIndex: 0,
      icon: "help",
      items: [{title:"CREDITS", desc:"Without these people none of this would be possible", version:"1.5 by DEFAULTDNB", icon:"fingerprint", expage:"payloads/creditsloader.html"}, {title:"PAYLOAD STATISTICS", desc:"Logs how many times a payload has been loaded. (VTX HEN/DUMP/FTP only)", version:"1.0 POC by DEFAULTDNB", icon:"", expage:"payloads/statsloader.html"}]
    },
   "★DEBUG": {
      index: 14,
      title: "★DEBUG Mira",
      selectedIndex: 0,
      icon: "grade",
      items: [{ title:"★PAYLOAD", desc:"ps4debug 1.5 payloads", version:"ps4debug 1.5", icon:"lock", expage:"payloads/ps4debug15.html"}]
	},    
  }
  //add zero position to each column and item
};_.each(model.columns, function (c) {
  c.position = { x: 0, y: 0 };
  _.each(c.items, function (i) {
    i.position = {
      x: 0,
      y: 0
    };
  });
});
	  
var xmbVue = new Vue({
  el: "#xmb",
  data: model,
  methods: {
    handleKey: function handleKey(dir, val) {
      this.cursor[dir] += val;
      var nCols = this.nColumns;
      // wrap x
      this.cursor.x = this.cursor.x % nCols;
      if (this.cursor.x < 0) {
        this.cursor.x = this.cursor.x + nCols;
      }

      //wrap y
      var nRows = this.nRows;
      this.cursor.y = this.cursor.y % nRows;
      if (this.cursor.y < 0) {
        this.cursor.y = this.cursor.y + nRows;
      }

      this.highlightCell(this.cursor.x, this.cursor.y);
    },
    highlightCell: function highlightCell(column, row) {

      console.log(column, row);
	  //alert(column, row);
      //update position of elements as well
      var xAccum = (-column - 1) * (ICONSZ);
      if (column == 0) {
        xAccum += ICONSZ;
      }
      var yAccum;

      _.each(this.columns, function (col, colKey) {
        col.active = false;
        yAccum =  - (ICONSZ) * (row + 1);

        col.position.x = xAccum;
        xAccum += ICONSZ;
        if (column === col.index || column === col.index + 1) {
          xAccum += ICONSZ;
        }

        _.each(col.items, function (item, rowN) {
          if (rowN == row && col.index == column) {
            item.active = true;
            col.active = true;
          } else {
            item.active = false;
          }

          if (rowN == row) {
            yAccum += ICONSZ;
          }
          yAccum += ICONSZ;
          item.position.y = yAccum;
        });
      });
      this.cursor.y = row;
      this.cursor.x = column;
    }
  },
  watch: {
    cursor: function cursor(e) {
      console.log('cursor mutated', e);
    }
  },
  computed: {
    nColumns: function nColumns() {
      return Object.keys(this.columns).length;
    },
    nRows: function nRows() {
      //get the row at the current index
      var row = this.columnsArray[this.cursor.x];
      if (!row) {
        console.log('invalid row index: ', this.cursor.x);
        return 0;
      }
      return row.items.length; //todo: number of columns in this row
    },
    columnsArray: function columnsArray() {
      var _this = this;

      //get columns in an array
      var arr = [];
      Object.keys(this.columns).forEach(function (key) {
        arr.push(_this.columns[key]);
      });
      return _.sortBy(arr, 'index');
    }
  },
  created: function created() {
    _.each(this.columns, function (column) {
      _.each(column.items, function (item) {
        item.active = false;
      });
    });
    this.highlightCell(this.cursor.x, this.cursor.y);
  }
});

$('body').on("mousewheel", _.debounce(scrollHandler, 50));

function scrollHandler(e) {
  console.log(e);
  if (e.deltaX) {
    xmbVue.handleKey('x', Math.sign(e.deltaX));
  }
  if (e.deltaY) {
    xmbVue.handleKey('y', Math.sign(e.deltaY));
  }
}
// REMAP TO D-PAD EXPERIMENTAL
// 27 = O, 112 = /\, 113 = [], 114 = options, 
// 116 = L1, 117 = R1, 118 = L2, 119 = R2, 120 = L3, 121 = R3,
// 37 = left dpad, 38 = up dpad, 39 = right dpad, 40 = down dpad,
window.onkeyup = function(e) {
   var key = e.keyCode ? e.keyCode : e.which;
   if (key == 37) {
   xmbVue.handleKey('x', -1);
   } else if (key == 39) {
   xmbVue.handleKey('x', 1);
   } else if (key  == 38) {
   xmbVue.handleKey('y', -1);
   } else if (key  == 40) {
   xmbVue.handleKey('y', 1);
   } else if (key == 116) {
   window.open("payloads/miraHen213.html", "content");
   } else if (key == 118) {
   window.open("payloads/mira2.html", "content");
   } else if (key == 117) {
   window.open("payloads/miraHen18vr.html", "content");
   } else if (key == 119) {
   window.open("payloads/hen22.html", "content");
   }
};
