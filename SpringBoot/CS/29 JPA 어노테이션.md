1. Validated

2. 생성자를 만드는 방법
    1. 미리 만들고 setter으로 변경
    2. 생성자 class
        - 3번이랑 다른점 : 입력과 설정할 변수명이랑 mapping 여부
    3. @builder(보통 이걸 사용함)

3. RestController
    - REST API를 위해 사용하는 어노테이션

4. Slf4j
    - log 를 위해 사용하는 어노테이션

5. RequiredArgsConstructor
    - 클래스 자동 생성자

6. NoArgsConstructor
    - 매개변수가 없는 기본 생성자를 생성

7. Validated
    - 유효성 검증해주는 어노테이션인데
    - 일반적으로 Hibernate Validator와 Bean Validation API같은 유효성 검증 프레임워크랑 함께 사용함
    - 예) @NotBlank 를 사용해서, 해당 파라미커가 null인지 아닌지 확인함, NotNull, NotEmpty, NotBlack
    - NotBlank : Null, "" 허용안함
    - NotEmtpy : Null, "", " " 허용안함
    - NotNull : Null 허용안함
    - valid 어노테이션과 분리해서 사용할 것

8. Tag
    - 특정 태그를 할당해서 테스트를 그룹화하고 필터링하는데 사용함
    - 이를 통해 특정 조건 따라 테스트를 선택적으로 실행하거나 무시할 수 있음

9. RequiredArgsConstructor
    - 클래스 필드의 생성자를 생성함