chcp 1256

@echo off

set gamesfol2="����"
set gamesfol3="����"
set gamesfol4="�����"
set gamesfol5="������� ����"
set gamesfol6="������� ������"
set gamesfol7="���� ����"
set gamesfol8="����� � ������ ��"
set gamesfol9="������ �����"
set gamescamfol1="ǘ��"
set gamescamfol2="����ǘ"
set gamescamfol3="����"
set gamescamfol4="��� ������"
set gamescamfol5="���"
set gameslocfol1="������"
set gameslocfol2="�����"
set gameslocfol3="������"
set gamesonlfol1="��� �����"
set gamesonlfol2="������� ����"
set gamesonlfol3="���������"
set gamesonlfol4="�����ʎ�"

set newsmediafol1="����� ���"
set newsmediafol2="���� ���"
set newsmediafol3="�� ������"

set onlinetools1fol="��� ����"

set podcastsfol1="��� � �����"
set podcastsfol2="Past & Present"
set podcastsfol3="�����"
set podcastsfol4="���� � ʘ�����"
set podcastsfol5="���� � ���������"
set podcastsfol6="�����"
set podcastsfol7="�ǘ �� ��"

set bookmarksfol1="����� � �����"
set bookmarksfol2="����� ������"
set bookmarksfol3="��Ϙ�� ��"
set bookmarksfol4="����"
set bookmarks2="�����"
set bookmarks3="��� ��"
set bookmarks4="��� �"
set bookmarks5="��� ����"
set bookmarks6="����"
set bookmarks7="������"
set bookmarks8="����"
set bookmarks9="�����"
set bookmarks10="����"
set bookmarks11="������"

set advanced1="�� �����"
set advanced2="������ ��ʐ�� ��"
set advanced3="�ǘ ���� ��Ә"
set advanced4="������ ��Ә"
set advanced5="�����Ԑ� �������"
set advanced6="������� �����"
set advanced7="������ ��� ����� "
set advanced8="������ ����� ����"
set advanced9="������� �����"
set advanced10="������� ������"
set advanced11="������ ������"
set advanced12="����� ��� ������"

set controlfol1="������� ���� ��"
set control1="�� ����� ��� �Ә�ǁ"
set control2="������� ����Ԑ�"
set control3="��� ���"
set control4="������ �����"
set control5="������� ����"
set control6="��� �����"
set control7="����� ����Ԑ�"
set control8="������ �����"
set control9="�Ә �����"
set control10="�ǘ���� ������"
set control11="���� ��� ������"

cd %~dp0

call "RenameShortcuts.bat"