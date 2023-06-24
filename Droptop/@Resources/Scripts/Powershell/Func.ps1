$DesktopPath = [Environment]::GetFolderPath("Desktop")
$Startpath = $env:APPDATA

# ---------------------------------------------------------------------------- #
#                                    Actions                                   #
# ---------------------------------------------------------------------------- #

function Desktop {
    $RainmeterExe = $RmAPI.VariableStr('PROGRAMPATH')
    $ResourceFolder = $RmAPI.VariableStr('@')
    $WScriptShell = New-Object -ComObject WScript.Shell
    $Shortcut = $WScriptShell.CreateShortcut($DesktopPath + "\JaxCore.lnk")
    $Shortcut.TargetPath = $RainmeterExe + "Rainmeter.exe"
    $Shortcut.Arguments = '!ActivateConfig #JaxCore\Main Home.ini'
    $shortcut.IconLocation = $ResourceFolder + "Images\4Logo.ico"
    $Shortcut.Save()
}

function MakeShortcut {
    $RainmeterExe = $RmAPI.VariableStr('PROGRAMPATH')
    $ResourceFolder = $RmAPI.VariableStr('@')
    $WScriptShell = New-Object -ComObject WScript.Shell
    $Shortcut = $WScriptShell.CreateShortcut("$Startpath\Microsoft\Windows\Start Menu\Programs\Droptop Four.lnk")
    $Shortcut.TargetPath = $RainmeterExe + "Rainmeter.exe"
    $Shortcut.Arguments = '!ActivateConfig Droptop\Other\BackgroundProcesses BackgroundProcesses.ini'
    $shortcut.IconLocation = $ResourceFolder + "Images\4Logo.ico"
    $Shortcut.Save()
}

function ExcludeDefender {
	$folderPath = "$env:USERPROFILE\Documents\Rainmeter\Skins"

	$isAdmin = ([Security.Principal.WindowsPrincipal] [Security.Principal.WindowsIdentity]::GetCurrent()).IsInRole([Security.Principal.WindowsBuiltInRole]::Administrator)
	
	if (-not $isAdmin) {
		$startInfo = New-Object System.Diagnostics.ProcessStartInfo
		$startInfo.FileName = 'powershell.exe'
		$startInfo.Arguments = "-Command `"Add-MpPreference -ExclusionPath '$folderPath'`""
		$startInfo.Verb = "runas"
	[System.Diagnostics.Process]::Start($startInfo) | Out-Null
	} else {
		Add-MpPreference -ExclusionPath $folderPath
}
}