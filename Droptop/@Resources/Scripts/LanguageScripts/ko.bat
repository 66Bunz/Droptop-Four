chcp 949

@echo off

set gamesfol2="캠페인"
set gamesfol3="캐주얼"
set gamesfol4="인디"
set gamesfol5="로컬 멀티플레이"
set gamesfol6="온라인 멀티플레이"
set gamesfol7="시뮬레이션"
set gamesfol8="스포츠 & 레이싱"
set gamesfol9="가상 현실"
set gamescamfol1="액션"
set gamescamfol2="공포"
set gamescamfol3="(휴식)힐링"
set gamescamfol4="롤 플레잉(RPG)"
set gamescamfol5="생존"
set gameslocfol1="협동"
set gameslocfol2="파티"
set gameslocfol3="대전게임"
set gamesonlfol1="배틀 로얄"
set gamesonlfol2="MMO"
set gamesonlfol3="슈팅"
set gamesonlfol4="전략"

set newsmediafol1="극좌[진보]"
set newsmediafol2="극우[보수]"
set newsmediafol3="국제"

set onlinetools1fol="진단"

set podcastsfol1="범죄 & 극적인 사건"
set podcastsfol2="Past & Present"
set podcastsfol3="정치"
set podcastsfol4="과학 기술"
set podcastsfol5="성별 및 심리학"
set podcastsfol6="스포츠"
set podcastsfol7="토크쇼"

set bookmarksfol1="뉴스 & 미디어"
set bookmarksfol2="온라인 도구"
set bookmarksfol3="팟캐스트"
set bookmarksfol4="쇼핑"
set bookmarks2="Gmail"
set bookmarks3="Google 메모"
set bookmarks4="Google 지도"
set bookmarks5="Google 포토"
set bookmarks6="훌루"
set bookmarks7="넷플릭스"
set bookmarks8="레딧"
set bookmarks9="스팀"
set bookmarks10="트위치"
set bookmarks11="유튜브"

set advanced1="명령 프롬프트"
set advanced2="디바이스 관리자"
set advanced3="디스크 정리"
set advanced4="디스크 관리"
set advanced5="레지스트리 편집기"
set advanced6="리소스 모니터"
set advanced7="시작 앱"
set advanced8="저장공간"
set advanced9="시스템 설정"
set advanced10="Windows 방화벽"
set advanced11="Windows PowerShell"
set advanced12="Windows 서비스"

set controlfol1="고급 컨트롤"
set control1="데스크탑 바탕화면"
set control2="디스플레이 설정"
set control3="확대"
set control4="화상 키보드"
set control5="전원 옵션"
set control6="휴지통"
set control7="디스플레이 전환"
set control8="시스템 정보"
set control9="작업 관리자"
set control10="프로그램 제거"
set control11="사용자 계정"

cd %~dp0

call "RenameShortcuts.bat"