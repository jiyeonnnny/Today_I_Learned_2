# git flow

```
1. branch 생성

2. git checkout -b fe/login/loginAPI

3. git config user.name = '영어name'
```

<br>

```
git flow

master
master 하위 dev
dev 하위 각각의 branch 생성
```

<br>

```
local단 branch, gitlab branch 별개임

1. gitlab에서 branch 생성
해당 branch를 

git remote update를 통해서
gitlab의 branch를 local단으로 옮김
해당 branch에서 작업하고 add commit하면 됨

2. local단에서
git checkout dev(현재 master라는 전제하에서, dev로 변경)

git checkout -b fe/login/loginAPI(브랜치 생성 및 변경)

git push(git add, commit, push하게되면 upstream을 하라고 뜸)

git upstream(해당 명령어 입력하면 됨)
```

<br>


https://mylko72.gitbooks.io/git/content/