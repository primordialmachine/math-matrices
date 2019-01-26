[Net.ServicePointManager]::SecurityProtocol = [Net.SecurityProtocolType]::Tls12

# Find path to 7z.
if (-not (test-path "$env:ProgramFiles\7-Zip\7z.exe")) { throw "$env:ProgramFiles\7-Zip\7z.exe needed" } 
set-alias sz "$env:ProgramFiles\7-Zip\7z.exe"

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

Download -PackageName 'arithmetic-functors' -Version '2.2'
Download -PackageName 'errors'              -Version '1.5'
Download -PackageName 'functors'            -Version '1.2'
Download -PackageName 'relational-functors' -Version '1.7'
Download -PackageName 'math-indices'        -Version '1.1'
Download -PackageName 'math-scalars'        -Version '1.4'
Download -PackageName 'math-non-scalars'    -Version '1.0'
Download -PackageName 'one-zero-functors'   -Version '1.5'
