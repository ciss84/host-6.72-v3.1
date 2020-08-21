dir /b /a-d *.mp4 > compile.txt

sort compile.txt > compile2.txt
del compile.txt

@echo off
setlocal DisableDelayedExpansion
set "firstLineReady="
(
    for /F "eol=$ delims=" %%a in (compile2.txt) DO (
        if defined firstLineReady (echo()
        set "firstLineReady=1"
        <nul set /p "=%%a"
    )
) > movielist.txt
del compile2.txt

echo set WshShell = WScript.CreateObject("WScript.Shell") > %tmp%\tmp.vbs
echo WScript.Quit (WshShell.Popup( "MovieList Generated 'OK'." ,1 ,"Success", 0)) >> %tmp%\tmp.vbs
cscript /nologo %tmp%\tmp.vbs
if %errorlevel%==1 (
  echo You Clicked OK
) else (
  echo The Message timed out.
)
del %tmp%\tmp.vbs
