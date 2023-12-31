# [SpringBoot] Cannot resolve symbol 'Assert' 해결 방법

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

**!! 하고 나서 Gradle 새로 고침 해줄 것 !!**    
![image](https://github.com/jiyeonnnny/Today_I_Learned_2/assets/139419091/51a1730f-4249-439a-8be6-8c8425e9d034)    


<br>
<br>


# [SpringBoot] Cannot resolve symbol 'assertThat'
```
문제 상황
TDD작성하면서 Assertions을 활용하여, 입력값 검증 및 예외처리함.
위처럼 진행하고 나니 Assertions 사용할 수 있었음
근데 Assertions.assertThat도 안된다고 뜸
Cannot resolve symbol "assertThat"
```
```java
// 해결 전
package jpabook.jpashop;
...

public class MemberRepositoryTest {
    ...
    @Test
    public void testMember() throws Exception{
        ...
        Assertions.assertThat(findMember.getId()).isEqualTo(member.getId());
        Assertions.assertThat(findMember.getUsername()).isEqualTo(member.getUsername());
    }
}
```
```java
// 해결

package jpabook.jpashop;

...
import static org.assertj.core.api.Assertions.assertThat;
...

public class MemberRepositoryTest {
    ...
    @Test
    public void testMember() throws Exception{
        ...
        assertThat(findMember.getId()).isEqualTo(member.getId());
        assertThat(findMember.getUsername()).isEqualTo(member.getUsername());
    }
}
```
```
안됐던 이유 추론

버전이 달라서 문법이 달랐던 것 같음
```
