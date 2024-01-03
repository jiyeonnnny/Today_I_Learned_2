# Embedded & Embeddable 어노테이션

<br>
<br>

# 예시
```java
@Entity
@Table( name = "user")
public class User {
	
    @Id
    @GeneratedValue(strategy = GenerationType.Identify)
    @Column( name ="user_id")
    private Long id;
    private String name;
    private String phoneNum;
    
    @Embedded
    private Address address;
    }
```
```java
@Embeddable
public class Address{
	
    private String zipCode;
    private String address;
    private String addressDetail;
    }
```
![image](https://github.com/jiyeonnnny/Today_I_Learned_2/assets/139419091/c0ed5904-3fe9-4877-bdc4-18d654d554af)

<br>
<br>

```
1. Embedded 와 Embeddable을 함께 사용함.
클래스 Embeddable 로 표시하면, 이 클래스는 DB에 별도로 테이블이 존재하지 않음

2. Embedded : 이 클래스는 Embeddable 클래스에 포함됨
3. Embeddable : 이 클래스는 Embedded 클래스 필드로 포함시킴.
4. 둘 중 하나만 표시하면 됨. 
```
