# 개요
존잘러 다섯이 알고리즘 공부하고 그 내용을 축적하는 repository 입니다.

## 존잘러란?
존나 잘생긴 사람을  지칭하는 말.
허세경, 안창규, 박찬종, 안진홍, 안종현 (잘생긴순)

# 디렉토리와 파일 설명

## week(n)
n주차 공부한 내용.
디렉토리의 내용물은 아래와 같다.
### (changjong).cpp
n주차 문제에 대한 (찬종)이 풀이
### input.txt
입력내용
### ouput.txt
출력내용  

# git 사용방법

## git clone {repository address}
remote repository를 local에 복사해 옴.

## git log
git repository 의 commit history를 조회

## git branch -a
repository의 모든 브랜치 확인

## git checkout {branch name}
{branch name}으로 checkout

## git status
현재 branch, local 파일의 변경 내용과 stage/unstage 내용을 확인할 수 있음.

## git add --all
local 의 변경사항을 stage

## git commit -m "{commit msg}"
git add 로 stage 된 내용을 commit

## git push
현재까지 local repository에 commit된 내용을 remote repository에 반영함.

## git reset --hard
가장 마지막 commit 상태로 local 파일을 되돌림. (이 때, tracking 중이지 않은 파일에는 영향이 없음)

