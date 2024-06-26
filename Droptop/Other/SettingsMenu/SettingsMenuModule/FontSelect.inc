[Rainmeter]
OnRefreshAction=[!ShowMeterGroup 10][!UpdateMeterGroup 10][!Redraw]

[Variables]
;----------------------------------
LuaLoc=#@#Scripts\Lua\DropScroll.lua
;----------------------------------
MaxItem=10

ScrollTracker=10
AboveTotal=1

ContentFade=1

W=20
U=[!UpdateMeasureGroup Animation][!UpdateMeterGroup Animation][!Redraw]

DropdownItemPadding1=#DropdownNoIconPadding#

[ScrollCheck]
Measure=Calc
IfCondition=AnalyzeTotal = #ScrollTracker#
IfTrueAction=[!SetOptionGroup Items MouseScrollDownAction """[]"""]
IfFalseAction=[!SetOptionGroup Items MouseScrollDownAction ""]
IfCondition2=#ScrollTracker# = #MaxItem#
IfTrueAction2=[!SetOptionGroup Items MouseScrollUpAction """[]"""]
IfFalseAction2=[!SetOptionGroup Items MouseScrollUpAction ""]
DynamicVariables=1

;----------------------------------------------------
; Measures
;----------------------------------------------------

[mPath]
Measure=Plugin
Plugin=FileView
Path="#@#Fonts"
ShowDotDot=0
SortType=Name
SortAscending=1
SortDateType=
ShowFile=1
ShowFolder=0
ShowSystem=0
ShowHidden=0
HideExtensions=1
;WildCardSearch="**"
;Recursive=0
Count=10
FinishAction=[!UpdateMeterGroup Items][!Redraw]

;----------------------------------------------------

[FileCount]
Measure=Plugin
Plugin=FolderInfo
Folder="[mPath]"
InfoType=FileCount
IncludeHiddenFiles=0
IncludeSubFolders=0
IncludeSystemFiles=0
RegExpFilter=(?i).*.*

[AnalyzeTotal]
Measure=Calc
Formula=FileCount

;----------------------------------------------------

[ScrollTimer]
Measure=Plugin
Plugin=ActionTimer
Group=Animation
ActionList1=Start1|Wait 100|Start2|Wait 10|Repeat ContentFade,#W#,9|Wait 10|Finish
Start1=
Start2=[!UpdateMeasureGroup IconImage][!SetOptionGroup ItemIcon ImageAlpha #*DropdownItemOpacity*#][!UpdateMeterGroup ItemIcon]
ContentFade=[!SetVariable ContentFade "(Clamp(#ContentFade#+0.1,0,1))"]#U#
Finish=[!SetVariable ContentFade 1][!SetOptionGroup ItemIcon ImageAlpha #*DropdownItemOpacity*#][!UpdateMeterGroup ItemIcon]#U#
DynamicVariables=1
IgnoreWarnings=1

;----------------------------------------------------

[Background]
Shape=Rectangle #DropdownMenuCutout#,#DropdownMenuCutout#,(#DropdownMenuWidth#+2-(#DropdownMenuCutout#*2)),(#DropdownItemHeight#*#NumberOfItems#+((#DropdownIconYoffset#+#DropdownItemYOffset#)*2)+(#DropdownMenuLandingHeight#)-(#DropdownMenuCutout#*2)+(#DividerSpace#*2)+#DividerHeight#),#DropdownBGCorner# | Fill Color #DropdownBGColor1#,(#ForceOpaque#=1?255:(#DropdownMenuOpacity1#<1?1:#DropdownMenuOpacity1#)) | StrokeWidth #DropdownStrokeWidth# | Stroke Color #DropdownStrokeColor#,#DropdownStrokeOpacity#

;----------------------------------------------------

[0]
Meter=String
MeterStyle=InfoStyle
Text=➕ #SettingsFontSelect1#
FontFace=#FontName0#
AntiAlias=#DropdownAntialias#
FontColor=#DropdownFontColor1#,(#DropdownItemOpacity#*#ContentFade#)
Y=((#DropdownIconYoffset#+([#CURRENTSECTION#:H]/2))-((#DropdownIconYoffset#+([#CURRENTSECTION#:H]/2))%1)+#DropdownItemYOffset#)
; LeftMouseDownAction=[!HideFadeGroup SM1][!CommandMeasure FileChoose "ChooseFile 5" "Droptop\DropdownBar"]
LeftMouseDownAction=[!HideMeter HighlightSelected "Droptop\DropdownBar"][!HideFadeGroup SM1][!Redraw "Droptop\DropdownBar"][!CommandMeasure FileChoose "ChooseFile 5" "Droptop\DropdownBar"]
Group=0 | Items | ItemName | Animation

;---

[Divider1]
Meter=Shape
Shape=#DividerShape#
Y=((#DropdownIconYoffset#+(#DropdownItemHeight#/2))-((#DropdownIconYoffset#+(#DropdownItemHeight#/2))%1)+#DropdownItemYOffset#+(#DropdownItemHeight#/2)+#DividerSpace#)
Hidden=0

;---

[1]
; Y=((#DropdownItemHeight#/2)+#DividerSpace#)R
Y=((#DropdownIconYoffset#+(#DropdownItemHeight#/2)+#DropdownItemHeight#)-((#DropdownIconYoffset#+(#DropdownItemHeight#/2))%1)+#DropdownItemYOffset#+(#DividerSpace#*2)+#DividerHeight#)

;----------------------------------------------------
; Name & Icon measures
;----------------------------------------------------

;----------------------------------------------------
; Index 1

[mIndex1Name]
Measure=Plugin
Plugin=FileView
Path=[mPath]
Type=FileName
Index=1
Substitute="^#FontName0#$":"🔳 #FontName0#"
RegExpSubstitute=1
DynamicVariables=1
Group=FontName

;----------------------------------------------------
; Index 2

[mIndex2Name]
Measure=Plugin
Plugin=FileView
Path=[mPath]
Type=FileName
Index=2
Substitute="^#FontName0#$":"🔳 #FontName0#"
RegExpSubstitute=1
DynamicVariables=1
Group=FontName

;----------------------------------------------------
; Index 3

[mIndex3Name]
Measure=Plugin
Plugin=FileView
Path=[mPath]
Type=FileName
Index=3
Substitute="^#FontName0#$":"🔳 #FontName0#"
RegExpSubstitute=1
DynamicVariables=1
Group=FontName

;----------------------------------------------------
; Index 4

[mIndex4Name]
Measure=Plugin
Plugin=FileView
Path=[mPath]
Type=FileName
Index=4
Substitute="^#FontName0#$":"🔳 #FontName0#"
RegExpSubstitute=1
DynamicVariables=1
Group=FontName

;----------------------------------------------------
; Index 5

[mIndex5Name]
Measure=Plugin
Plugin=FileView
Path=[mPath]
Type=FileName
Index=5
Substitute="^#FontName0#$":"🔳 #FontName0#"
RegExpSubstitute=1
DynamicVariables=1
Group=FontName

;----------------------------------------------------
; Index 6

[mIndex6Name]
Measure=Plugin
Plugin=FileView
Path=[mPath]
Type=FileName
Index=6
Substitute="^#FontName0#$":"🔳 #FontName0#"
RegExpSubstitute=1
DynamicVariables=1
Group=FontName

;----------------------------------------------------
; Index 7

[mIndex7Name]
Measure=Plugin
Plugin=FileView
Path=[mPath]
Type=FileName
Index=7
Substitute="^#FontName0#$":"🔳 #FontName0#"
RegExpSubstitute=1
DynamicVariables=1
Group=FontName

;----------------------------------------------------
; Index 8

[mIndex8Name]
Measure=Plugin
Plugin=FileView
Path=[mPath]
Type=FileName
Index=8
Substitute="^#FontName0#$":"🔳 #FontName0#"
RegExpSubstitute=1
DynamicVariables=1
Group=FontName

;----------------------------------------------------
; Index 9

[mIndex9Name]
Measure=Plugin
Plugin=FileView
Path=[mPath]
Type=FileName
Index=9
Substitute="^#FontName0#$":"🔳 #FontName0#"
RegExpSubstitute=1
DynamicVariables=1
Group=FontName

;----------------------------------------------------
; Index 10

[mIndex10Name]
Measure=Plugin
Plugin=FileView
Path=[mPath]
Type=FileName
Index=10
Substitute="^#FontName0#$":"🔳 #FontName0#"
RegExpSubstitute=1
DynamicVariables=1
Group=FontName

;----------------------------------------------------
; Item Names
;----------------------------------------------------

[RunCommand.CopyFont]
Measure=Plugin
Plugin=RunCommand
Parameter=cd "#SKINSPATH#Droptop Folders\Other files\Themes" & del /f /q "*.*tf" & cd "#SKINSPATH#Droptop\@Resources\Fonts" & xcopy /E /I /Y "[#FontName0].*" "#SKINSPATH#Droptop Folders\Other files\Themes"
State=Hide
OutputType=ANSI
OutputFile=
DynamicVariables=1

[InfoStyle]
InlinePattern3=🔳
InlineSetting3=Color | #Lime#,(255*#ContentFade#)
InlinePattern4=🔳
InlineSetting4=Shadow | 0 | 1 | 2 | 0,0,0,(205*#ContentFade#)
InlinePattern5=[#FontName0]
InlineSetting5=Face | [#FontName0]
MeasureName=mIndex#CURRENTSECTION#Name
FontFace=[mIndex#CURRENTSECTION#Name]
FontColor=#DropdownFontColor1#,(#DropdownItemOpacity#*#ContentFade#)
LeftMouseDownAction=#OptionChanged.Suite#[!WriteKeyValue Variables FontName0 "[mIndex#CURRENTSECTION#Name]" "#@#Themes\#ThemeNum#Settings.inc"][!SetVariableGroup FontName0 "[mIndex#CURRENTSECTION#Name]" "DroptopSuite"][!SetVariableGroup TopBarFontName "[mIndex#CURRENTSECTION#Name]" "DroptopSuite"][!UpdateMeasureGroup FontName][!UpdateMeterGroup Items][!UpdateMeter * "Droptop\DropdownBar"][!UpdateMeter * "Droptop\DropdownBar"][!UpdateGroup DroptopSuite][!RedrawGroup DroptopSuite][!Redraw][!UpdateMeasure RunCommand.CopyFont][!CommandMeasure RunCommand.CopyFont "Run"]
MouseOverAction=[!SetVariable [##CURRENTSECTION#]FolderActive 1][!SetVariable CurrentSubFolder #CURRENTSECTION#][!SetOption #CURRENTSECTION#Arrow StrokeColor "Stroke Color #*DropdownFontColor2*#,(#*HighlightFontOpacity2*#*#*ContentFade*#)"][!SetOption #CURRENTSECTION#Arrow FillColor "Fill Color #*DropdownFontColor2*#,(#*HighlightFontOpacity2*#*#*ContentFade*#)"][!SetOption #CURRENTSECTION# FontColor "#*DropdownFontColor2*#,(#*HighlightFontOpacity2*#*#*ContentFade*#)"][!ShowMeterGroup Highlight][!UpdateMeterGroup Highlight][!UpdateMeter #CURRENTSECTION#Arrow][!UpdateMeter FolderBlock][!UpdateMeter #CURRENTSECTION#][!Redraw][!CommandMeasure MeasureActionTimer "Stop 1"][!UpdateMeasure MeasureActionTimer][!CommandMeasure MeasureActionTimer "Execute 1"]
MouseLeaveAction=[!SetVariable [##CURRENTSECTION#]FolderActive 0][!EnableMouseActionGroup "MouseOverAction" Items][!SetOption #CURRENTSECTION#Arrow StrokeColor "Stroke Color #*DropdownFontColor1*#,(#*DropdownItemOpacity*#*#*ContentFade*#)"][!SetOption #CURRENTSECTION#Arrow FillColor "Fill Color #*DropdownFontColor1*#,(#*DropdownItemOpacity*#*#*ContentFade*#)"][!SetOption #CURRENTSECTION# FontColor "#*DropdownFontColor1*#,(#*DropdownItemOpacity*#*#*ContentFade*#)"][!UpdateMeter #CURRENTSECTION#Arrow][!UpdateMeter #CURRENTSECTION#][!HideMeterGroup Highlight][!Redraw]
MiddleMouseDownAction=[!CommandMeasure mIndex#CURRENTSECTION#Name "[#MiddleClickBehavior[#MiddleClickNum]]"][!SetVariable ActiveTray 0 "Droptop\DropdownBar"][!Hide "#CURRENTCONFIG#"][!HideMeterGroup HighlightSelected "Droptop\DropdownBar"][!UpdateMeterGroup SysTray "Droptop\DropdownBar"][!Redraw "Droptop\DropdownBar"]
MouseScrollUpAction=[!SetVariable ScrollTracker (#ScrollTracker#<=#MaxItem#?#MaxItem#:(#ScrollTracker#-#MaxItem#))][!CommandMeasure ScrollbarScript UpdateCurrentPos(-#MaxItem#)][!CommandMeasure mPath "PageUp"][!SetVariable ContentFade 0.1][!SetOptionGroup ItemIcon ImageAlpha "(#*DropdownItemOpacity*#/5)"][!UpdateMeasure *][!UpdateMeter *][!Redraw][#StopMode[#StopModeNum]][!Delay 10][!UpdateMeasure ScrollTimer][!CommandMeasure ScrollTimer "Execute 1"]
MouseScrollDownAction=[!SetVariable ScrollTracker (#ScrollTracker#>=[AnalyzeTotal]?[AnalyzeTotal]:(#ScrollTracker#+#MaxItem#))][!CommandMeasure ScrollbarScript UpdateCurrentPos(#MaxItem#)][!CommandMeasure mPath "PageDown"][!SetVariable ContentFade 0.1][!SetOptionGroup ItemIcon ImageAlpha "(#*DropdownItemOpacity*#/5)"][!UpdateMeasure *][!UpdateMeter *][!Redraw][#StopMode[#StopModeNum]][!Delay 10][!UpdateMeasure ScrollTimer][!CommandMeasure ScrollTimer "Execute 1"]
AntiAlias=1

;----------------------------------------------------
; Scrollbar
;----------------------------------------------------

[ScrollbarTop]
Meter=Image
X=3
Y=(#DropdownItemHeight#+(#DropdownItemHeight#/2)+(#DividerSpace#*1))
; Y=(#DropdownIconYoffset#-((#DropdownIconYoffset#+(#DropdownItemHeight#/2))%1)+#DropdownItemYOffset#+#DropdownItemHeight#-1)
UpdateDivider=-1

[Size]
Measure=Calc
Formula=((#DropdownItemHeight#*#MaxItem#)-#DropdownIconYoffset#)
UpdateDivider=-1
Group=Scrollbar

[ScrollH]
Measure=Calc
Formula=Size * (#MaxItem# / (AnalyzeTotal = 0 ? 1 : AnalyzeTotal))
Group=Scrollbar

[ScrollbarScript]
Measure=Script
ScriptFile=#LuaLoc#
UpdateDivider=-1

[CurrentPos]
Meter=Shape
Shape=Rectangle 0,0,(3*#DroptopSize#),([ScrollH]<1?1:[ScrollH]),2 | Fill Color #DropdownFontColor1#,155 | StrokeWidth 0 | StrokeColor #DropdownBGColor1#,55
X=(#DropdownMenuWidth#-(3*#DroptopSize#)-(#DropdownStrokeWidth#/2))
Y=(#DropdownIconYoffset#-((#DropdownIconYoffset#+(#DropdownItemHeight#/2))%1)+#DropdownItemYOffset#+1)
DynamicVariables=1
Group=ScrollBar | Items

;-------------------------------------------

[OpenFolder]
Meter=Image
ImageName=#@#Icons\Fixed\Medium\dot.png
ImageTint=#DropdownFontColor1#,#DropdownItemOpacity#
ImageAlpha=(#DropdownItemOpacity#/3)
X=(8*#DroptopSize#)
Y=(#DropdownIconYoffset#-(#DropdownIconYoffset#%1)+#DropdownItemYOffset#+(#DropdownItemHeight#*#NumberOfItems#)+((#DropdownMenuLandingHeight#-(16*#DroptopSize#))/2)+(#DividerSpace#*2)+#DividerHeight#)
H=(16*#DroptopSize#)
LeftMouseDownAction=#CloseSettingsMenu#["#@#Fonts"]
MouseOverAction=[!SetOption #CURRENTSECTION# ImageName "#@#Icons\Fixed\Medium\open.png"][!SetOption #CURRENTSECTION# ImageAlpha #DropdownItemOpacity#][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# ImageName "#@#Icons\Fixed\Medium\dot.png"][!SetOption #CURRENTSECTION# ImageAlpha (#*DropdownItemOpacity*#/3)][!UpdateMeter #CURRENTSECTION#][!Redraw]
DynamicVariables=1
UpdateDivider=-1

[DownArrow]
Meter=Shape
Shape=Rectangle (-2*#DroptopSize#),(1*#DroptopSize#),(15*#DroptopSize#),(15*#DroptopSize#),0 | Fill Color 0,0,0,0 | StrokeWidth 0
Shape2=Rectangle 0,0,(11*#DroptopSize#),(11*#DroptopSize#),0 | StrokeWidth 0 | Rotate 45 | Extend Look
Shape3=Rectangle 0,(-2*#DroptopSize#),(11*#DroptopSize#),(11*#DroptopSize#),0 | StrokeWidth 0 | Rotate 45
Shape4=Combine Shape2 | Exclude Shape3
Look=Fill Color #DropdownFontColor1#,(#ScrollTracker#>=[AnalyzeTotal]?0:(#DropdownItemOpacity#/3))
LeftMouseDownAction=[!SetVariable ScrollTracker (#ScrollTracker#>=[AnalyzeTotal]?[AnalyzeTotal]:(#ScrollTracker#+#MaxItem#))][!CommandMeasure ScrollbarScript UpdateCurrentPos(#MaxItem#)][!CommandMeasure mPath "PageDown"][!SetVariable ContentFade 0.1][!SetOptionGroup ItemIcon ImageAlpha "(#*DropdownItemOpacity*#/5)"][!UpdateMeasure *][!UpdateMeter *][!Redraw][#StopMode[#StopModeNum]][!UpdateMeasure ScrollTimer][!CommandMeasure ScrollTimer "Execute 1"]
MouseOverAction=[!SetOption #CURRENTSECTION# Look "Fill Color #*DropdownFontColor1*#,(#*ScrollTracker*#>=[AnalyzeTotal]?0:#DropdownItemOpacity#)"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Look "Fill Color #*DropdownFontColor1*#,(#*ScrollTracker*#>=[AnalyzeTotal]?0:(#DropdownItemOpacity#/3))"][!UpdateMeter #CURRENTSECTION#][!Redraw]
X=(#DropdownMenuWidth#-(25*#DroptopSize#))
Y=r
DynamicVariables=1

[UpArrow]
Meter=Shape
Shape=Rectangle (-2*#DroptopSize#),(1*#DroptopSize#),(15*#DroptopSize#),(15*#DroptopSize#),0 | Fill Color 0,0,0,0 | StrokeWidth 0
Shape2=Rectangle 0,(7*#DroptopSize#),(11*#DroptopSize#),(11*#DroptopSize#),0 | StrokeWidth 0 | Rotate 45 | Extend Look
Shape3=Rectangle 0,(9*#DroptopSize#),(11*#DroptopSize#),(11*#DroptopSize#),0 | StrokeWidth 0 | Rotate 45
Shape4=Combine Shape2 | Exclude Shape3
Look=Fill Color #DropdownFontColor1#,(#ScrollTracker#<=#MaxItem#?0:(#DropdownItemOpacity#/3))
LeftMouseDownAction=[!SetVariable ScrollTracker (#ScrollTracker#<=#MaxItem#?#MaxItem#:(#ScrollTracker#-#MaxItem#))][!CommandMeasure ScrollbarScript UpdateCurrentPos(-#MaxItem#)][!CommandMeasure mPath "PageUp"][!SetVariable ContentFade 0.1][!SetOptionGroup ItemIcon ImageAlpha "(#*DropdownItemOpacity*#/5)"][!UpdateMeasure *][!UpdateMeter *][!Redraw][#StopMode[#StopModeNum]][!UpdateMeasure ScrollTimer][!CommandMeasure ScrollTimer "Execute 1"]
MouseOverAction=[!SetOption #CURRENTSECTION# Look "Fill Color #*DropdownFontColor1*#,(#*ScrollTracker*#<=#MaxItem#?0:#DropdownItemOpacity#)"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Look "Fill Color #*DropdownFontColor1*#,(#*ScrollTracker*#<=#MaxItem#?0:(#DropdownItemOpacity#/3))"][!UpdateMeter #CURRENTSECTION#][!Redraw]
X=(#DropdownMenuWidth#-(45*#DroptopSize#))
Y=r
DynamicVariables=1

;dummy
[0Arrow]
Meter=String
Hidden=1