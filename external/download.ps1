[Net.ServicePointManager]::SecurityProtocol = [Net.SecurityProtocolType]::Tls12

# Find path to 7z.
if (-not (test-path "$env:ProgramFiles\7-Zip\7z.exe")) { throw "$env:ProgramFiles\7-Zip\7z.exe needed" } 
set-alias sz "$env:ProgramFiles\7-Zip\7z.exe"
#$7zPath = (Get-ChildItem "C:\Program Files","C:\Program Files (x86)" -Include "7-zip" -Recurse -ErrorAction SilentlyContinue).FullName
#Write-Host "$($7zPath)"

# Add path to 7z to PATH environment variable.
#$env:Path += ";$7zPath;"

function Download([String]$PackageName,[String]$Version){
  [string[]] $Configurations = 'debug', 'release'
  [string[]] $PlatformTargets = 'x86', 'x64'
  Write-Host "Downloading $($PackageName)"  
  ForEach($Configuration in $Configurations) {
    Write-Host "  For Configuration = $($Configuration)"
	ForEach($PlatformTarget in $PlatformTargets) {
	  Write-Host "   For Platform Target = $($PlatformTarget)"
	  $Src = "https://github.com/primordialmachine/$($PackageName)/releases/download/version_$($Version)/primordialmachine-$($PackageName)-v$($Version)-$($Configuration)-$($PlatformTarget).zip";
	  $Dst =  "$PackageName-v$($Version)-$($Configuration)-$($PlatformTarget).zip";
	  if (!($Dst | Test-Path)) {
	    Write-Host "      Download Source := $($Src)"
		Write-Host "      Download Target := $($Dst)"
		wget $Src -outfile $Dst
	  }
	  sz x -y $Dst
	}
  }
}

Download -PackageName 'math-arithmetic-functors' -Version '1.7'
Download -PackageName 'math-relational-functors' -Version '1.4'
Download -PackageName 'math-indices'             -Version '1.0'
#Download -PackageName 'math-matrices'           -Version '0.4'
Download -PackageName 'math-scalars'             -Version '1.0'
#Download -PackageName 'math-trigonometry'       -Version '1.3'
#Download -PackageName 'math-vectors'            -Version '0.3'
Download -PackageName 'one-zero-functors'        -Version '1.5'
Download -PackageName 'errors'                   -Version '1.5'
#Download -PackageName 'byte-orders'             -Version '1.5'
#Download -PackageName 'ranges'                  -Version '1.3'