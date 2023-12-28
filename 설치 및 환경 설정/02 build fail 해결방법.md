# 발생한 문제
```
run하면 실행은 잘됨
로컬서버 잘 켜지고, 포트 연결하면 html 잘나옴

근데 stop 버튼 누르면, build fail이 뜸.
```


# 해결방법
```
settings

Build, Execution, Deployment > Gradle

Gradle Projects의 Build and run using을
Gradle(Default) -> IntelliJ IDEA로 변경

Gradle Projects의 Run tests using을
Gradle(Default) -> IntelliJ IDEA로 변경

Apply

다시 Run Stop하면 build success
```