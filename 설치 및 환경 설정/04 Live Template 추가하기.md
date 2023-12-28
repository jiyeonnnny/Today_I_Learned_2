# [Spring] Live Template 추가하기

<br>

1. Files -> Settings -> Live templates

<br>

2. Java 클릭

<br>

3. Preferences 창의 상단에 + 버튼 클릭
Live Template 클릭

<br>

4. 내용 기입
Abbreviation(intellij 에디터 창에서 사용할 명령어 이름): tdd
Description(Live template 설명): test code template

<br>

5. Define 클릭 -> Java 클릭

<br>

6. Template text칸에 내용 기입
```java
@Test
public void $NAME$() throws Exception{
    // given
    $END$
    //when
    
    //then
}
```

<br>

7. Options
(X) Reformat according to style
(X) Use static import if possible
(O) Shorten FQ names

<br>

8. Apply

<br>
