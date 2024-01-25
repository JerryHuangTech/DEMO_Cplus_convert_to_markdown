[Setup]
AppName=Convert_to_markdown
AppVersion=2.0
OutputBaseFilename=Setup convert to markdown
DefaultDirName={pf}\pekora_tech\Convert_to_markdown
AppPublisher=pekora tech

[Files]
Source: "D:\DEV_Code\DEV_Cplus\Context Menu\convert_to_markdown\x64\Debug\convert_to_markdown.exe"; DestDir: "{app}"

[Registry]
Root: HKCR; Subkey: "*\shell\Convert_to_markdown\command"; ValueType: string; ValueName: ""; ValueData: """{app}\convert_to_markdown.exe"" ""%1"""; Flags: uninsdeletekey