[Rainmeter]
OnFocusAction=[!SetVariable Focused 1 "Droptop\Other\BackgroundProcesses"][!UpdateMeasure Focus "Droptop\Other\BackgroundProcesses"][!UpdateMeasure MouseY "Droptop\Other\BackgroundProcesses"]
OnUnfocusAction=[!SetVariable Focused 0 "Droptop\Other\BackgroundProcesses"][!UpdateMeasure MeasureIsFullScreen "Droptop\Other\BackgroundProcesses"]
SkinWidth=(#DropdownMenuWidth#+2)
RightMouseDownAction=[]
MouseActionCursor=Arrow
Update=-1
MouseLeaveAction=[!SetVariable FolderMode 0][!UpdateMeasure MeasureActionTimer]
OnRefreshAction=[!UpdateMeasureGroup Scrollbar]

[Variables]
MenuBlur=#DropdownMenuBlur#
ScrollTracker=#MaxItem#

FolderMode=0

ContentFade=1

W=20
U=[!UpdateMeasureGroup Animation][!UpdateMeterGroup Animation][!Redraw]

;-----------------------------------
Padding0=(#HideIcons#=1?#DropdownNoIconPadding#:#DropdownItemPadding1#),#DropdownItemPaddingY#,#DropdownArrowHighlightW#,(#DropdownItemPaddingY#*-1)
Padding1=0,#DropdownItemPaddingY#,0,(#DropdownItemPaddingY#*-1)
;---
Padding0B=(#HideIcons#=1?#DropdownNoIconPadding#:#DropdownItemPadding1#),#DropdownItemPaddingY#,#DropdownArrowHighlightW#,(#DropdownItemPaddingY#*-1)
Padding1B=#DropdownArrowHighlightW#,#DropdownItemPaddingY#,(#HideIcons#=1?#DropdownNoIconPadding#:#DropdownItemPadding1#),(#DropdownItemPaddingY#*-1)

;----------------------------------------------------
; Measures
;----------------------------------------------------

[FocusPlugin]
Measure=Plugin
Plugin=Focus
FocusOnRefresh=0

[BlurBehind]
Measure=Plugin
Plugin=FrostedGlass
BlurEnabled=(#ForceOpaque#=1?0:#DropdownMenuBlur#)
Type=[#BlurType[#BlurTypeNum]0]
Border=[#Shadows[#DropdownMenuShadow]]
Corner=[#BlurCorner[#DropdownRoundCorners]]
DynamicVariables=1

[MeasureActionTimer]
Measure=Plugin
Plugin=ActionTimer
ActionList1=Wait [#FolderMouseOverTime[#FolderMouseOverTimeNum]]|FolderMouseOver#FolderMode#
FolderMouseOver0=[]
FolderMouseOver1=[!CommandMeasure FocusPlugin "Droptop\Other\Folders\Folder#CurrentFolder#"][!HideGroup Folder0][!Refresh "#NextDropdownFolder#"][!ShowMeter HighlightSelected][!SetVariable HighlightSelectedY [[#CurrentSubFolder]:Y]][!WriteKeyValue Variables FolderNum [#FolderNum] "#SKINSPATH#Droptop\Other\Folders\Folder01\Folder01.ini"][!WriteKeyValue Variables SelectedFolderY [[#CurrentSubFolder]:Y] "#SKINSPATH#Droptop\Other\Folders\Folder01\Folder01.ini"][!WriteKeyValue Variables Folder01Loc "[mPath][&mIndex[#CurrentSubFolder]Name]" "#SKINSPATH#Droptop\Other\Folders\Folder01\Folder01.ini"][!UpdateMeter HighlightSelected][!Redraw][!Delay 105][!ActivateConfig "Droptop\Other\Folders\Folder01"][!Move ([#CURRENTCONFIGX]+#DropdownMenuWidth#+#DropdownSubMenuXOffset#) ([#CURRENTCONFIGY]+[[#CurrentSubFolder]:Y]-[1:Y]) "Droptop\Other\Folders\Folder01"][!#Show# "Droptop\Other\Folders\Folder01"][!Update "Droptop\Other\Folders\Folder01"]
DynamicVariables=1
IgnoreWarnings=1
Disabled=1

[CalcFolderNum]
Measure=Calc
Formula=Clamp(([FolderCount]-(#ScrollTracker#-#MaxItem#)),0,#MaxItem#)
OnChangeAction=[!HideMeterGroup F20][!ShowMeterGroup F[CalcFolderNum]][!UpdateMeter FolderBlock]
DynamicVariables=1
Group=Scrollbar

[ScrollCheck]
Measure=Calc
IfCondition=AnalyzeTotal = #ScrollTracker#
IfTrueAction=[!DisableMouseActionGroup "MouseScrollDownAction" ItemName][!DisableMouseAction ScrollDownButton "LeftMouseDownAction"
IfFalseAction=[!EnableMouseActionGroup "MouseScrollDownAction" ItemName][!EnableMouseAction ScrollDownButton "LeftMouseDownAction"
IfCondition2=#ScrollTracker# = #MaxItem#
IfTrueAction2=[!DisableMouseActionGroup "MouseScrollUpAction" ItemName][!DisableMouseAction ScrollUpButton "LeftMouseDownAction"
IfFalseAction2=[!EnableMouseActionGroup "MouseScrollUpAction" ItemName][!EnableMouseAction ScrollUpButton "LeftMouseDownAction"
DynamicVariables=1
UpdateDivider=-1
Group=mPath | Scrollbar

[ScrollTimer]
Measure=Plugin
Plugin=ActionTimer
Group=Animation
ActionList1=Start1|Wait 100|Start2|Wait 10|Repeat ContentFade,#W#,9|Wait 10|Finish
Start1=
Start2=[!UpdateMeasureGroup IconImage][!SetOptionGroup ItemIcon ImageAlpha #*DropdownItemOpacity*#][!UpdateMeterGroup ItemIcon]
ContentFade=[!SetVariable ContentFade "(Clamp(#ContentFade#+0.1,0,1))"]#U#
Finish=[!SetVariable ContentFade 1][!SetOptionGroup ItemIcon ImageAlpha #*DropdownItemOpacity*#][!UpdateMeterGroup ItemIcon]#U#
ActionList2=Wait #ScrollClickWaitTime#|Repeat ScrollClickUp,#ScrollClickStepTime#,23
ScrollClickUp=[!CommandMeasure mPath "PageUp"][!SetVariable ScrollTracker ([#ScrollTracker]-([#ScrollTracker]-[#MaxItem]<=[#MaxItem]?([#ScrollTracker]-[#MaxItem]):[#MaxItem]))][!CommandMeasure ScrollbarScript UpdateCurrentPos(-[#MaxItem])][!HideGroup Folder0][!UpdateMeasureGroup Scrollbar][!HideMeter HighlightSelected][!SetVariable ContentFade 0.1][!SetOptionGroup ItemIcon ImageAlpha "(#*DropdownItemOpacity*#/5)"][!UpdateMeter *][!Redraw]
ActionList3=Wait #ScrollClickWaitTime#|Repeat ScrollClickDown,#ScrollClickStepTime#,23
ScrollClickDown=[!CommandMeasure mPath "PageDown"][!SetVariable ScrollTracker ([#ScrollTracker]+([&AnalyzeTotal]>[#MaxItem]?([#ScrollTracker]+[#MaxItem]>=[&AnalyzeTotal]?([&AnalyzeTotal]-[#ScrollTracker]):[#MaxItem]):0))][!CommandMeasure ScrollbarScript UpdateCurrentPos(#MaxItem#)][!HideGroup Folder0][!UpdateMeasureGroup Scrollbar][!HideMeter HighlightSelected][!SetVariable ContentFade 0.1][!SetOptionGroup ItemIcon ImageAlpha "(#*DropdownItemOpacity*#/5)"][!UpdateMeter *][!Redraw]
DynamicVariables=1
IgnoreWarnings=1

;----------------------------------------------------
; Styles
;----------------------------------------------------

[InfoStyle]
FontColor=#DropdownFontColor1#,(#DropdownItemOpacity#*#ContentFade#)
FontFace=#FontName0#
FontSize=#DropdownItemFontSize#
FontWeight=#FontWeight#
AntiAlias=#DropdownAntiAlias#
InlineSetting=CharacterSpacing | #DropdownCharacterSpacing#
InlineSetting2=[#DropdownTextShadow[#DropdownFontShadow][#ChamLum1]]
StringEffect=#DropdownStringEffect#
FontEffectColor=#DropdownFontEffectColor#

[ItemStyle]
StringAlign=#TextDirection#Center
MeasureName=mIndex#CURRENTSECTION#Name
LeftMouseDownAction=#ResetActiveFolders#[!CommandMeasure mIndex#CURRENTSECTION#Name "Open"][!HideGroup Folders][!SetVariable ActiveFolder 0 "Droptop\DropdownBar"][!HideMeterGroup HighlightSelected "Droptop\DropdownBar"][!UpdateMeterGroup Folders "Droptop\DropdownBar"][!Redraw "Droptop\DropdownBar"]
RightMouseDownAction=[!CommandMeasure MeasureActionTimer "Stop 1"][!Hide "Droptop\Other\PopupMenu"][!HideMeter HighlightSelected][!WriteKeyValue Variables PopupModule "FolderItemSettings" "#SKINSPATH#Droptop\Other\PopupMenu\PopupMenu.ini"][!WriteKeyValue Variables PopupModuleIndex [#CURRENTSECTION] "#SKINSPATH#Droptop\Other\PopupMenu\PopupMenu.ini"][!WriteKeyValue Variables PopupModuleIndex2 [#CurrentFolder] "#SKINSPATH#Droptop\Other\PopupMenu\PopupMenu.ini"][!WriteKeyValue Variables FolderLoc "#FolderLoc#" "#SKINSPATH#Droptop\Other\PopupMenu\PopupMenuModule\FolderItemSettings.inc"][!WriteKeyValue Variables ParentConfig "#CURRENTCONFIG#" "#SKINSPATH#Droptop\Other\PopupMenu\PopupMenuModule\FolderItemSettings.inc"][!Refresh "Droptop\Other\PopupMenu"][!ActivateConfig "Droptop\Other\PopupMenu" "PopupMenu.ini"][!Move (([#CURRENTCONFIGX]+[#CURRENTSECTION#:X]+$MouseX$)-(10*#DroptopSize#)) (([#CURRENTCONFIGY]+[#CURRENTSECTION#:Y]+$MouseY$)-(10*#DroptopSize#)) "Droptop\Other\PopupMenu"][!Delay 105][!#Show# "Droptop\Other\PopupMenu"][!HideFadeGroup Folder0]
MiddleMouseDownAction=#ResetActiveFolders#[!SetVariable FolderMode 0][!UpdateMeasure MeasureActionTimer][!CommandMeasure mIndex#CURRENTSECTION#Name "[#MiddleClickBehavior[#MiddleClickNum]]"][!HideGroup Folders][!SetVariable ActiveFolder 0 "Droptop\DropdownBar"][!SetVariable UnfocusAction 0 "Droptop\DropdownBar"][!HideMeterGroup HighlightSelected "Droptop\DropdownBar"][!UpdateMeterGroup Folders "Droptop\DropdownBar"][!Redraw "Droptop\DropdownBar"]
MouseOverAction=[!SetVariable [##CURRENTSECTION#]FolderActive 1][!SetVariable CurrentSubFolder #CURRENTSECTION#][!SetOption #CURRENTSECTION#Arrow StrokeColor "Stroke Color #*DropdownFontColor2*#,(#*HighlightFontOpacity2*#*#*ContentFade*#)"][!SetOption #CURRENTSECTION#Arrow FillColor "Fill Color #*DropdownFontColor2*#,(#*HighlightFontOpacity2*#*#*ContentFade*#)"][!SetOption #CURRENTSECTION# FontColor "#*DropdownFontColor2*#,(#*HighlightFontOpacity2*#*#*ContentFade*#)"][!ShowMeterGroup Highlight][!UpdateMeterGroup Highlight][!UpdateMeter #CURRENTSECTION#Arrow][!UpdateMeter FolderBlock][!UpdateMeter #CURRENTSECTION#][!Redraw][!UpdateMeasure MeasureActionTimer][!CommandMeasure MeasureActionTimer "Execute 1"]
MouseLeaveAction=[!CommandMeasure MeasureActionTimer "Stop 1"][!SetVariable [##CURRENTSECTION#]FolderActive 0][!EnableMouseActionGroup "MouseOverAction" Items][!SetOption #CURRENTSECTION#Arrow StrokeColor "Stroke Color #*DropdownFontColor1*#,(#*DropdownItemOpacity*#*#*ContentFade*#)"][!SetOption #CURRENTSECTION#Arrow FillColor "Fill Color #*DropdownFontColor1*#,(#*DropdownItemOpacity*#*#*ContentFade*#)"][!SetOption #CURRENTSECTION# FontColor "#*DropdownFontColor1*#,(#*DropdownItemOpacity*#*#*ContentFade*#)"][!UpdateMeter #CURRENTSECTION#Arrow][!UpdateMeter #CURRENTSECTION#][!HideMeterGroup Highlight][!Redraw]
MouseScrollUpAction=[!UpdateMeasure MeasureActionTimer][!CommandMeasure mPath "PageUp"][!SetVariable ScrollTracker ([#ScrollTracker]-([#ScrollTracker]-[#MaxItem]<=[#MaxItem]?([#ScrollTracker]-[#MaxItem]):[#MaxItem]))][!CommandMeasure ScrollbarScript UpdateCurrentPos(-[#MaxItem])][!HideGroup Folder0][!UpdateMeasureGroup Scrollbar][!HideMeter HighlightSelected][!SetVariable ContentFade 0.1][!SetOptionGroup ItemIcon ImageAlpha "(#*DropdownItemOpacity*#/5)"][!UpdateMeter *][!Redraw][#StopMode[#StopModeNum]][!UpdateMeasure ScrollTimer][!CommandMeasure ScrollTimer "Execute 1"]
MouseScrollDownAction=[!UpdateMeasure MeasureActionTimer][!CommandMeasure mPath "PageDown"][!SetVariable ScrollTracker ([#ScrollTracker]+([&AnalyzeTotal]>[#MaxItem]?([#ScrollTracker]+[#MaxItem]>=[&AnalyzeTotal]?([&AnalyzeTotal]-[#ScrollTracker]):[#MaxItem]):0))][!CommandMeasure ScrollbarScript UpdateCurrentPos(#MaxItem#)][!HideGroup Folder0][!UpdateMeasureGroup Scrollbar][!HideMeter HighlightSelected][!SetVariable ContentFade 0.1][!SetOptionGroup ItemIcon ImageAlpha "(#*DropdownItemOpacity*#/5)"][!UpdateMeter *][!Redraw][#StopMode[#StopModeNum]][!UpdateMeasure ScrollTimer][!CommandMeasure ScrollTimer "Execute 1"]
W=(#DropdownMenuWidth#-#DropdownArrowHighlightW#-(#HideIcons#=1?#DropdownNoIconPadding#:#DropdownItemPadding1#))
H=#DropdownItemHeight#
Padding=[#Padding[#RTLText]B]
DynamicVariables=1
ClipString=1
Text="%1"
Hidden=1
X=(1+(#DropdownMenuWidth#*#RTLText#))
Y=R

@IncludeArrowStyle=#@#Meters\ArrowStyle\ArrowStyle#DropdownArrowStyle#.ini

[IconStyle]
MeasureName=mIndex#CURRENTSECTION#
X=(#DropdownIconXoffset#+((#DropdownMenuWidth#-#DropdownIconXoffset#-#IconW#-#DropdownHLOffsetX#-(#DropdownIconPadding#*2))*#RTLText#))
Y=R
W=#IconW#
H=#IconH#
Greyscale=#DropdownIconGreyscale#
ImageAlpha=#DropdownItemOpacity#
ImageTint=#DropdownIconTint#
Padding=#DropdownIconPadding#,#DropdownIconPadding#,#DropdownIconPadding#,(#DropdownIconPadding#+(#DropdownIconPadding#%1))
DynamicVariables=1
UpdateDivider=-1
Hidden=1

[BackgroundStyle]
LeftMouseDownAction=[]
DynamicVariables=1

;----------------------------------------------------
; Background Meters
;----------------------------------------------------

[Background]
Meter=Shape
MeterStyle=BackgroundStyle
Shape=Rectangle #DropdownMenuCutout#,(#DropdownMenuShapeOffsetH#+#DropdownMenuCutout#),(#DropdownMenuWidth#+2-(#DropdownMenuCutout#*2)),(#DropdownItemHeight#*#NumberOfItems#+((#DropdownIconYoffset#+#DropdownItemYOffset#)*2)+(#DropdownMenuLandingHeight#-(#DropdownMenuLandingHeight#*1))-(#DropdownMenuCutout#*2)),#DropdownBGCorner# | Fill Color #DropdownBGColor1#,(#ForceOpaque#=1?255:(#DropdownMenuOpacity1#<1?1:#DropdownMenuOpacity1#)) | StrokeWidth #DropdownStrokeWidth# | Stroke Color #DropdownStrokeColor#,#DropdownStrokeOpacity#
Shape2=#FlatTopShape#
Shape3=Combine Shape | Union Shape2
Shape4=Rectangle #DropdownMenuCutout#,(#DropdownMenuShapeOffsetH#+#DropdownMenuCutout#),1,((#DropdownItemHeight#*#NumberOfItems#+((#DropdownIconYoffset#+#DropdownItemYOffset#)*2)+(#DropdownMenuLandingHeight#-(#DropdownMenuLandingHeight#*1))-(#DropdownMenuCutout#*2))+#DropdownStrokeWidth#),0 | StrokeWidth 0 | Fill Color 0,0,0,0
DynamicVariables=1

;----------------------------------------------------
; Item Highlight
;----------------------------------------------------

[HighlightBackground]
Meter=Shape
Shape=Rectangle (#DropdownMenuCutout#+#DropdownHLOffsetX#),[#CurrentSubFolder#:Y],(#DropdownMenuWidth#-(#DropdownMenuCutout#*2)+((#DropdownMenuWidth#-(#DropdownMenuCutout#*2))%1)-(#DropdownHLOffsetX#*2)),#DropdownItemHeight#,#DropdownHighlightCorner# | Fill Color #DropdownItemHL#,(#DropdownHLOpacity#/#HighlightShapeOpacityDivisor1B#) | StrokeWidth #DropdownHLStrokeWidth# | Stroke Color 0,0,0,#DropdownHLStrokeOpacity#
Shape2=Rectangle (#DropdownMenuCutout#+#DropdownHLOffsetX#),[#CurrentSubFolder#:Y],(#DropdownMenuWidth#-(#DropdownMenuCutout#*2)+((#DropdownMenuWidth#-(#DropdownMenuCutout#*2))%1)-(#DropdownHLOffsetX#*2)),#DropdownItemHeight#,#DropdownHighlightCorner# | Fill Color #DropdownFontColor1#,(25*#ReverseDarkLight#) | StrokeWidth 0
Shape3=Rectangle (#DropdownMenuCutout#+#DropdownHLOffsetX#),[#CurrentSubFolder#:Y],(#DropdownMenuWidth#-(#DropdownMenuCutout#*2)+((#DropdownMenuWidth#-(#DropdownMenuCutout#*2))%1)-(#DropdownHLOffsetX#*2)),#DropdownItemHeight#,#DropdownHighlightCorner# | Fill LinearGradient HLShadowGradient | StrokeWidth 0
Shape4=Rectangle (#DropdownMenuCutout#+#DropdownHLOffsetX#),[#CurrentSubFolder#:Y],(#DropdownMenuWidth#-(#DropdownMenuCutout#*2)+((#DropdownMenuWidth#-(#DropdownMenuCutout#*2))%1)-(#DropdownHLOffsetX#*2)),#DropdownItemHeight#,#DropdownHighlightCorner# | Fill Color 255,255,255,(55*#DropdownHLSolidColor#) | StrokeWidth 0 | Stroke Color 0,0,0,#DropdownHLStrokeOpacity#
HLShadowGradient=90 | 255,255,255,(35*#DropdownHLShadow#) ; 1.0 | 0,0,0,(35*#DropdownHLShadow#) ; 0.0
X=1
Group=Highlight | HL
DynamicVariables=1
Hidden=1

[HighlightSelected]
Meter=Shape
Shape=Rectangle [#HLSelectedShape[#HLSelectedShapeNum]]
Shape2=Rectangle (#DropdownMenuCutout#+#DropdownHLOffsetX#),0,([#DropdownMenuWidth]-(#DropdownMenuCutout#*2)+(([#DropdownMenuWidth]+[#SysAppMenuWOffset]-(#DropdownMenuCutout#*2))%1)-(#DropdownHLOffsetX#*2)),#DropdownItemHeight#,[#DropdownHighlightCorner] | Fill Color #DropdownFontColor1#,(25*#ReverseDarkLight#) | StrokeWidth #DropdownHLStrokeWidth# | Stroke Color 0,0,0,#DropdownHLStrokeOpacity#
Shape3=Rectangle (#DropdownMenuCutout#+#DropdownHLOffsetX#),0,(#DropdownMenuWidth#-(#DropdownMenuCutout#*2)+((#DropdownMenuWidth#-(#DropdownMenuCutout#*2))%1)-(#DropdownHLOffsetX#*2)),#DropdownItemHeight#,#DropdownHighlightCorner# | Fill LinearGradient HLShadowGradient | StrokeWidth 0
Shape4=Rectangle (#DropdownMenuCutout#+#DropdownHLOffsetX#),0,([#DropdownMenuWidth]-(#DropdownMenuCutout#*2)+(([#DropdownMenuWidth]+[#SysAppMenuWOffset]-(#DropdownMenuCutout#*2))%1)-(#DropdownHLOffsetX#*2)),#DropdownItemHeight#,[#DropdownHighlightCorner] | Fill Color 255,255,255,(55*#TopBarHLSolidColor#) | StrokeWidth 0 | Stroke Color 0,0,0,#DropdownHLStrokeOpacity#
ShapeOption=[#HLSelectedOption[#HLSelectedShapeNum]]
HLShadowGradient=90 | 255,255,255,(35*#DropdownHLShadow#) ; 1.0 | 0,0,0,(35*#DropdownHLShadow#) ; 0.0
X=1
Y=#HighlightSelectedY#
Group=HighlightSelected
DynamicVariables=1
Hidden=1

;----------------------------------------------------
; Item Names
;----------------------------------------------------

[NA]
Meter=String
MeterStyle=InfoStyle | ItemStyle
Text="#FoldersItem0A#"
Y=((#DropdownIconYoffset#+(#DropdownItemHeight#/2))-((#DropdownIconYoffset#+(#DropdownItemHeight#/2))%1)+#DropdownItemYOffset#)
RightMouseDownAction=[]
LeftMouseDownAction=["#FolderLoc#"][!HideGroup Folders][!SetVariable ActiveFolder 0 "Droptop\DropdownBar"][!HideMeterGroup HighlightSelected "Droptop\DropdownBar"][!UpdateMeterGroup Folders "Droptop\DropdownBar"][!Redraw "Droptop\DropdownBar"]
MouseOverAction=[!SetVariable CurrentSubFolder #CURRENTSECTION#][!SetOption #CURRENTSECTION#Icon ImageTint "#*DropdownFontColor2*#,#*HighlightFontOpacity2*#"][!SetOption #CURRENTSECTION#Icon ImageAlpha (255-(255*#HideIcons#))][!SetOption #CURRENTSECTION# FontColor "#*DropdownFontColor2*#,#*HighlightFontOpacity2*#"][!ShowMeterGroup Highlight][!SetOptionGroup Highlight W [#CURRENTSECTION#:W]][!UpdateMeterGroup Highlight][!UpdateMeter #CURRENTSECTION#Icon][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!HideMeterGroup Highlight][!SetOption #CURRENTSECTION#Icon ImageTint #*DropdownFontColor1*#][!SetOption #CURRENTSECTION#Icon ImageAlpha (#DropdownItemOpacity#-(#DropdownItemOpacity#*#HideIcons#))][!SetOption #CURRENTSECTION# FontColor "#*DropdownFontColor1*#,#*DropdownItemOpacity*#"][!UpdateMeter #CURRENTSECTION#Icon][!UpdateMeter #CURRENTSECTION#][!Redraw]
Hidden=1
Group=0 | Items | ItemName

[1]
Meter=String
MeterStyle=InfoStyle | ItemStyle
Y=((#DropdownIconYoffset#+(#DropdownItemHeight#/2))-((#DropdownIconYoffset#+(#DropdownItemHeight#/2))%1)+#DropdownItemYOffset#)
Group=1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | Items | ItemName | Animation

[2]
Meter=String
MeterStyle=InfoStyle | ItemStyle
Group=2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | Items | ItemName | Animation

[3]
Meter=String
MeterStyle=InfoStyle | ItemStyle
Group=3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | Items | ItemName | Animation

[4]
Meter=String
MeterStyle=InfoStyle | ItemStyle
Group=4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | Items | ItemName | Animation

[5]
Meter=String
MeterStyle=InfoStyle | ItemStyle
Group=5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | Items | ItemName | Animation

[6]
Meter=String
MeterStyle=InfoStyle | ItemStyle
Group=6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | Items | ItemName | Animation

[7]
Meter=String
MeterStyle=InfoStyle | ItemStyle
Group=7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | Items | ItemName | Animation

[8]
Meter=String
MeterStyle=InfoStyle | ItemStyle
Group=8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | Items | ItemName | Animation

[9]
Meter=String
MeterStyle=InfoStyle | ItemStyle
Group=9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | Items | ItemName | Animation

[10]
Meter=String
MeterStyle=InfoStyle | ItemStyle
Group=10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | Items | ItemName | Animation

[11]
Meter=String
MeterStyle=InfoStyle | ItemStyle
Group=11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | Items | ItemName | Animation

[12]
Meter=String
MeterStyle=InfoStyle | ItemStyle
Group=12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | Items | ItemName | Animation

[13]
Meter=String
MeterStyle=InfoStyle | ItemStyle
Group=13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | Items | ItemName | Animation

[14]
Meter=String
MeterStyle=InfoStyle | ItemStyle
Group=14 | 15 | 16 | 17 | 18 | 19 | 20 | Items | ItemName | Animation

[15]
Meter=String
MeterStyle=InfoStyle | ItemStyle
Group=15 | 16 | 17 | 18 | 19 | 20 | Items | ItemName | Animation

[16]
Meter=String
MeterStyle=InfoStyle | ItemStyle
Group=16 | 17 | 18 | 19 | 20 | Items | ItemName | Animation

[17]
Meter=String
MeterStyle=InfoStyle | ItemStyle
Group=17 | 18 | 19 | 20 | Items | ItemName | Animation

[18]
Meter=String
MeterStyle=InfoStyle | ItemStyle
Group=18 | 19 | 20 | Items | ItemName | Animation

[19]
Meter=String
MeterStyle=InfoStyle | ItemStyle
Group=19 | 20 | Items | ItemName | Animation

[20]
Meter=String
MeterStyle=InfoStyle | ItemStyle
Group=20 | Items | ItemName | Animation

;----------------------------------------------------
; Icons
;----------------------------------------------------

[NAIcon]
Meter=Image
MeterStyle=IconStyle
ImageName=#@#Icons\Fixed\#IconSize#\noitem.png
ImageTint=#DropdownFontColor1#
ImageAlpha=(#DropdownItemOpacity#-(#DropdownItemOpacity#*#HideIcons#))
Y=(#DropdownIconYoffset#+#DropdownItemYOffset#)
DynamicVariables=1
UpdateDivider=1
Group=0 | ItemIcon

[1Icon]
Meter=Image
MeterStyle=IconStyle
Y=(#DropdownIconYoffset#+#DropdownItemYOffset#)
Group=1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | ItemIcon

[2Icon]
Meter=Image
MeterStyle=IconStyle
Group=2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | ItemIcon

[3Icon]
Meter=Image
MeterStyle=IconStyle
Group=3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | ItemIcon

[4Icon]
Meter=Image
MeterStyle=IconStyle
Group=4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | ItemIcon

[5Icon]
Meter=Image
MeterStyle=IconStyle
Group=5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | ItemIcon

[6Icon]
Meter=Image
MeterStyle=IconStyle
Group=6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | ItemIcon

[7Icon]
Meter=Image
MeterStyle=IconStyle
Group=7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | ItemIcon

[8Icon]
Meter=Image
MeterStyle=IconStyle
Group=8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | ItemIcon

[9Icon]
Meter=Image
MeterStyle=IconStyle
Group=9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | ItemIcon

[10Icon]
Meter=Image
MeterStyle=IconStyle
Group=10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | ItemIcon

[11Icon]
Meter=Image
MeterStyle=IconStyle
Group=11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | ItemIcon

[12Icon]
Meter=Image
MeterStyle=IconStyle
Group=12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | ItemIcon

[13Icon]
Meter=Image
MeterStyle=IconStyle
Group=13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | ItemIcon

[14Icon]
Meter=Image
MeterStyle=IconStyle
Group=14 | 15 | 16 | 17 | 18 | 19 | 20 | ItemIcon

[15Icon]
Meter=Image
MeterStyle=IconStyle
Group=15 | 16 | 17 | 18 | 19 | 20 | ItemIcon

[16Icon]
Meter=Image
MeterStyle=IconStyle
Group=16 | 17 | 18 | 19 | 20 | ItemIcon

[17Icon]
Meter=Image
MeterStyle=IconStyle
Group=17 | 18 | 19 | 20 | ItemIcon

[18Icon]
Meter=Image
MeterStyle=IconStyle
Group=18 | 19 | 20 | ItemIcon

[19Icon]
Meter=Image
MeterStyle=IconStyle
Group=19 | 20 | ItemIcon

[20Icon]
Meter=Image
MeterStyle=IconStyle
Group=20 | ItemIcon

;----------------------------------------------------
; Folders
;----------------------------------------------------

[FolderBlock]
Meter=Image
SolidColor=0,0,0,0
X=1
Y=[1:Y]
W=#DropdownMenuWidth#
H=(#DropdownItemHeight#*[CalcFolderNum])
LeftMouseDownAction=#ResetActiveFolders#[!SetTransparencyGroup 0 Folder0][!UpdateMeasure MeasureActionTimer][!Refresh "#NextDropdownFolder#"][!ShowMeter HighlightSelected][!SetVariable HighlightSelectedY ([#CurrentSubFolder#:Y])][!WriteKeyValue Variables CurrentFolder #CurrentFolder# "#SKINSPATH#Droptop\Other\Folders\Folder01\Folder01.ini"][!WriteKeyValue Variables CurrentFolder #CurrentFolder# "#SKINSPATH#Droptop\Other\Folders\Folder02\Folder02.ini"][!WriteKeyValue Variables FolderNum #FolderNum# "#SKINSPATH#Droptop\Other\Folders\Folder01\Folder01.ini"][!WriteKeyValue Variables SelectedFolderY [#CurrentSubFolder#:Y] "#SKINSPATH#Droptop\Other\Folders\Folder01\Folder01.ini"][!WriteKeyValue Variables Folder01Loc "[mPath][&mIndex[#CurrentSubFolder]Name]" "#SKINSPATH#Droptop\Other\Folders\Folder01\Folder01.ini"][!ActivateConfig "Droptop\Other\Folders\Folder01"][!Move ([#CURRENTCONFIGX]+#DropdownMenuWidth#+#DropdownSubMenuXOffset#) ([#CURRENTCONFIGY]+[#CurrentSubFolder#:Y]-[1:Y]) "Droptop\Other\Folders\Folder01"][!#Show# "Droptop\Other\Folders\Folder01"][!Update "Droptop\Other\Folders\Folder01"][!UpdateMeter HighlightSelected][!Redraw]
MouseOverAction=[!SetVariable FolderMode 1]
MouseLeaveAction=[!SetVariable FolderMode 0]
DynamicVariables=1
Group=Item

;----------------------------------------------------
; Arrows
;----------------------------------------------------

[1Arrow]
Meter=Shape
MeterStyle=ArrowStyle
Group=F1 | F2 | F3 | F4 | F5 | F6 | F7 | F8 | F9 | F10 | F11 | F12 | F13 | F14 | F15 | F16 | F17 | F18 | F19 | F20 | Animation
Y=[1Icon:Y]

[2Arrow]
Meter=Shape
MeterStyle=ArrowStyle
Group=F2 | F3 | F4 | F5 | F6 | F7 | F8 | F9 | F10 | F11 | F12 | F13 | F14 | F15 | F16 | F17 | F18 | F19 | F20 | Animation

[3Arrow]
Meter=Shape
MeterStyle=ArrowStyle
Group=F3 | F4 | F5 | F6 | F7 | F8 | F9 | F10 | F11 | F12 | F13 | F14 | F15 | F16 | F17 | F18 | F19 | F20 | Animation

[4Arrow]
Meter=Shape
MeterStyle=ArrowStyle
Group=F4 | F5 | F6 | F7 | F8 | F9 | F10 | F11 | F12 | F13 | F14 | F15 | F16 | F17 | F18 | F19 | F20 | Animation

[5Arrow]
Meter=Shape
MeterStyle=ArrowStyle
Group=F5 | F6 | F7 | F8 | F9 | F10 | F11 | F12 | F13 | F14 | F15 | F16 | F17 | F18 | F19 | F20 | Animation

[6Arrow]
Meter=Shape
MeterStyle=ArrowStyle
Group=F6 | F7 | F8 | F9 | F10 | F11 | F12 | F13 | F14 | F15 | F16 | F17 | F18 | F19 | F20 | Animation

[7Arrow]
Meter=Shape
MeterStyle=ArrowStyle
Group=F7 | F8 | F9 | F10 | F11 | F12 | F13 | F14 | F15 | F16 | F17 | F18 | F19 | F20 | Animation

[8Arrow]
Meter=Shape
MeterStyle=ArrowStyle
Group=F8 | F9 | F10 | F11 | F12 | F13 | F14 | F15 | F16 | F17 | F18 | F19 | F20 | Animation

[9Arrow]
Meter=Shape
MeterStyle=ArrowStyle
Group=F9 | F10 | F11 | F12 | F13 | F14 | F15 | F16 | F17 | F18 | F19 | F20 | Animation

[10Arrow]
Meter=Shape
MeterStyle=ArrowStyle
Group=F10 | F11 | F12 | F13 | F14 | F15 | F16 | F17 | F18 | F19 | F20 | Animation

[11Arrow]
Meter=Shape
MeterStyle=ArrowStyle
Group=F11 | F12 | F13 | F14 | F15 | F16 | F17 | F18 | F19 | F20 | Animation

[12Arrow]
Meter=Shape
MeterStyle=ArrowStyle
Group=F12 | F13 | F14 | F15 | F16 | F17 | F18 | F19 | F20 | Animation

[13Arrow]
Meter=Shape
MeterStyle=ArrowStyle
Group=F13 | F14 | F15 | F16 | F17 | F18 | F19 | F20 | Animation

[14Arrow]
Meter=Shape
MeterStyle=ArrowStyle
Group=F14 | F15 | F16 | F17 | F18 | F19 | F20 | Animation

[15Arrow]
Meter=Shape
MeterStyle=ArrowStyle
Group=F15 | F16 | F17 | F18 | F19 | F20 | Animation

[16Arrow]
Meter=Shape
MeterStyle=ArrowStyle
Group=F16 | F17 | F18 | F19 | F20 | Animation

[17Arrow]
Meter=Shape
MeterStyle=ArrowStyle
Group=F17 | F18 | F19 | F20 | Animation

[18Arrow]
Meter=Shape
MeterStyle=ArrowStyle
Group=F18 | F19 | F20 | Animation

[19Arrow]
Meter=Shape
MeterStyle=ArrowStyle
Group=F19 | F20 | Animation

[20Arrow]
Meter=Shape
MeterStyle=ArrowStyle
Group=F20 | Animation

;----------------------------------------------------
; Scrollbar
;----------------------------------------------------

[ScrollButtonStyle]
SolidColor=#DropdownFontColor1#,0
StringAlign=CenterCenter
FontSize=(25*#DroptopSize#)
FontColor=#DropdownBGColor1#,0
X=((#DropdownArrowHighlightW#+((#DropdownMenuWidth#-((#DropdownMenuWidth#-#DropdownArrowHighlightW#-#DropdownArrowXOffset#-#DropdownStrokeWidth#-(#DropdownHLOffsetX#*2)+1+#DropdownStrokeWidth#+#DropdownHLOffsetX#)+#DropdownArrowHighlightW#))*2))/2)
W=(#DropdownArrowHighlightW#+((#DropdownMenuWidth#-((#DropdownMenuWidth#-#DropdownArrowHighlightW#-#DropdownArrowXOffset#-#DropdownStrokeWidth#-(#DropdownHLOffsetX#*2)+1+#DropdownStrokeWidth#+#DropdownHLOffsetX#)+#DropdownArrowHighlightW#))*2)+1)
H=([Background:H]/2)
DynamicVariables=1
AntiAlias=1
InlineSetting=Shadow | 0 | 1 | 1 | 0,0,0,105
MouseOverAction=[!CommandMeasure MeasureActionTimer "Stop 1"][!SetVariable [##CurrentSubFolder#]FolderActive 0][!DisableMouseActionGroup "MouseOverAction|MouseLeaveAction" ItemName][!SetOption [#CurrentSubFolder]Arrow StrokeColor "Stroke Color #*DropdownFontColor1*#,(#*DropdownItemOpacity*#*#*ContentFade*#)"][!SetOption [#CurrentSubFolder]Arrow FillColor "Fill Color #*DropdownFontColor1*#,(#*DropdownItemOpacity*#*#*ContentFade*#)"][!SetOption [#CurrentSubFolder] FontColor "#*DropdownFontColor1*#,(#*DropdownItemOpacity*#*#*ContentFade*#)"][!SetOption #CURRENTSECTION# SolidColor "#DropdownFontColor1#,105"][!SetOption #CURRENTSECTION# FontColor "#DropdownBGColor1#,200"][!UpdateMeter [#CurrentSubFolder]Arrow][!HideMeterGroup Highlight][!UpdateMeter #CURRENTSECTION#][!UpdateMeter [#CurrentSubFolder]][!Redraw]
MouseLeaveAction=[!CommandMeasure ScrollTimer "Stop 2"][!CommandMeasure ScrollTimer "Stop 3"][!CommandMeasure ScrollTimer "Execute 1"][!EnableMouseActionGroup "MouseOverAction|MouseLeaveAction" ItemName][!SetOption #CURRENTSECTION# SolidColor ""][!SetOption #CURRENTSECTION# FontColor ""][!UpdateMeter #CURRENTSECTION#][!UpdateMeter [#CurrentSubFolder]][!Redraw]
Group=ScrollBar | Items
Container=#CURRENTSECTION#.Container
Hidden=1

[ScrollUpButton.Container]
Meter=Shape
Shape=Rectangle #DropdownMenuCutout#,#DropdownMenuCutout#,(#DropdownMenuWidth#-[#CURRENTSECTION#:X]-#DropdownStrokeWidth#),(([Background:H]/2)-3),10 | StrokeWidth 0
X=((#DropdownMenuWidth#-#DropdownArrowHighlightW#-#DropdownArrowXOffset#-#DropdownStrokeWidth#-(#DropdownHLOffsetX#*2)+2+#DropdownStrokeWidth#+#DropdownHLOffsetX#)-(#DropdownMenuWidth#-(#DropdownMenuWidth#-#DropdownArrowHighlightW#-#DropdownArrowXOffset#-#DropdownStrokeWidth#-(#DropdownHLOffsetX#*2)+#DropdownStrokeWidth#+#DropdownHLOffsetX#+#DropdownArrowHighlightW#)))
Y=2
DynamicVariables=1

[ScrollDownButton.Container]
Meter=Shape
Shape=Rectangle #DropdownMenuCutout#,#DropdownMenuCutout#,(#DropdownMenuWidth#-[#CURRENTSECTION#:X]-#DropdownStrokeWidth#),(([Background:H]/2)-4),#DropdownBGCorner# | StrokeWidth 0
X=((#DropdownMenuWidth#-#DropdownArrowHighlightW#-#DropdownArrowXOffset#-#DropdownStrokeWidth#-(#DropdownHLOffsetX#*2)+2+#DropdownStrokeWidth#+#DropdownHLOffsetX#)-(#DropdownMenuWidth#-(#DropdownMenuWidth#-#DropdownArrowHighlightW#-#DropdownArrowXOffset#-#DropdownStrokeWidth#-(#DropdownHLOffsetX#*2)+#DropdownStrokeWidth#+#DropdownHLOffsetX#+#DropdownArrowHighlightW#)))
Y=([Background:H]/2)
DynamicVariables=1

[ScrollUpButton]
Meter=String
MeterStyle=ScrollButtonStyle
Y=([#CURRENTSECTION#:H]/2)
Text=⬆️
LeftMouseDownAction=[#[#CURRENTSECTION][#DeviceIsNotTouch]]
LeftMouseUpAction=[!CommandMeasure ScrollTimer "Stop 2"][!CommandMeasure mPath "PageUp"][!SetVariable ScrollTracker ([#ScrollTracker]-([#ScrollTracker]-[#MaxItem]<=[#MaxItem]?([#ScrollTracker]-[#MaxItem]):[#MaxItem]))][!CommandMeasure ScrollbarScript UpdateCurrentPos(-[#MaxItem])][!HideGroup Folder0][!UpdateMeasureGroup Scrollbar][!HideMeter HighlightSelected][!SetVariable ContentFade 0.1][!SetOptionGroup ItemIcon ImageAlpha "(#*DropdownItemOpacity*#/5)"][!UpdateMeter *][!Redraw][#StopMode[#StopModeNum]][!UpdateMeasure ScrollTimer][!CommandMeasure ScrollTimer "Execute 1"]

[ScrollDownButton]
Meter=String
MeterStyle=ScrollButtonStyle
Y=([#CURRENTSECTION#:H]/2)
Text=⬇️
LeftMouseDownAction=[#[#CURRENTSECTION][#DeviceIsNotTouch]]
LeftMouseUpAction=[!CommandMeasure ScrollTimer "Stop 3"][!CommandMeasure mPath "PageDown"][!SetVariable ScrollTracker ([#ScrollTracker]+([&AnalyzeTotal]>[#MaxItem]?([#ScrollTracker]+[#MaxItem]>=[&AnalyzeTotal]?([&AnalyzeTotal]-[#ScrollTracker]):[#MaxItem]):0))][!CommandMeasure ScrollbarScript UpdateCurrentPos(#MaxItem#)][!HideGroup Folder0][!UpdateMeasureGroup Scrollbar][!HideMeter HighlightSelected][!SetVariable ContentFade 0.1][!SetOptionGroup ItemIcon ImageAlpha "(#*DropdownItemOpacity*#/5)"][!UpdateMeter *][!Redraw][#StopMode[#StopModeNum]][!UpdateMeasure ScrollTimer][!CommandMeasure ScrollTimer "Execute 1"]

[ScrollbarTop]
Meter=Image
X=3
Y=(#DropdownIconYoffset#-((#DropdownIconYoffset#+(#DropdownItemHeight#/2))%1)+#DropdownItemYOffset#-1)
UpdateDivider=-1

[Size]
Measure=Calc
Formula=((#DropdownItemHeight#*#MaxItem#)-#DropdownIconYoffset#)
UpdateDivider=-1
Group=Scrollbar

[ScrollH]
Measure=Calc
Formula=Size * (#MaxItem# / (AnalyzeTotal = 0 ? 1 : AnalyzeTotal))
UpdateDivider=-1
RegExpSubstitute=1
Substitute="^0$":"#DropdownItemHeight#"
Group=Scrollbar
Disabled=1

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
Hidden=1