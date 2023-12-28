# [Spring] Cannot resolve symbol 'Assert' 해결 방법

<br>

<br>

Gradle에 해당 코드를 추가해주니 해결됨
```java
dependencies{
    testCompileOnly 'junit:junit:4.13.2'
}
```

<br>

<br>

!! 하고 나서 Gradle 새로 고침 해줄 것 !!
![Alt text](/images/image.png)

<br>

<br>

# Cannot resolve symbol 'assertThat'

```
문제 상황
위처럼 진행하고 나니 Assert 사용할 수 있었음
근데 Assertions.assertThat도 안된다고 뜸

해결책
import static org.assertj.core.api.Assertions.assertThat;

추가하니깐 해결됨. 근데 안되는 이유와 되는 이유를 모르겠음. 안되는 이유는 버전충돌 혹은 설정 문제인 것 같은데, 각기 다른 버전과 각기 다른 설정 방법으로, 나한테 맞는 해결책을 찾을 수 없었음. 게다가 오픈소스(?)를 활용했던 거라 코드 이해를 못한 상태에서 수정하는 것이 더 어려웠던 것 같음 
```