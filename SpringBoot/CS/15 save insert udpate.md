# [save 함수] create와 update

update하는 방법 2가지
- 변경감지
- 병합

변경감지(= dirty checking)
- 트랜잭션 끝나면 commit되는데
- 바뀐 명령어가 있으면
- 그 명령어를 찾아가서, 수행하고, commit함
- @Transactional 사용하면, 알아서 값 변경을 감지해서, 
  그걸 수행하고 commit(저장)이 됨


### 준영속 entity
```java
@PostMapping("items/{itemId}/edit")
public String updateItem(@ModelAttribute("form") BookForm form){
    Book book = new Book();
    book.setId(form.getId());
    book.setName(form.getName());
    book.setPrice(form.getPrice());
    book.setStockQuantity(form.getStockQuantity());
    book.setAuthor(form.getAuthor());
    book.setIsbn(form.getIsbn());

    itemService.saveItem(book);
    return "redirect:items";
}
```
```java
book.setId(form.getId());
```

<br>

> 영속(persist) entity
> 준영속 entity는? 뭔가?

<br>

- 아이디를 지정해줬음. 새로운 객체를 만들어서
- DB에 한번 저장되어 식별자가 존재하는 상황이며. 이렇게 임의로 만들어낸 엔티티도 기존 식별자를 가지고 있으면, 준영속 엔티티로 보는 거임
- 영속성 컨텍스트가 더는 관리하지 않음(보통 값 변경되면, 트랜잭션 끝나고 감지해서 저장하는데, 얘는 관리 대상이 아닌거지)

<br>
<br>

### update하는 방법
1. 변경 감지
2. 병합

<br>

### 변경 감지 기능 사용
```java
@Transactional
void update(Item itemParam){
    Item findItem = em.find(Item.class, itemParam.getId());
    findItem.setPrice(itemParam.getPrice());
}
```
- 영속성 컨텍스트에서 엔티티를 다시 조회한 후에, 데이터를 수정함
- 트랜잭션 안에 엔티티를 다시 조회, 변경할 값 선택
  -> 트랜잭션 커밋 시점에서 변경감지. DB에 UPDATE SQL실행 후 commit

<br>

### merge 하는 방법
```java
// item controller
    @PostMapping("items/{itemId}/edit")
    public String updateItem(@ModelAttribute("form") BookForm form){
        Book book = new Book();
        book.setId(form.getId());
        book.setName(form.getName());
        book.setPrice(form.getPrice());
        book.setStockQuantity(form.getStockQuantity());
        book.setAuthor(form.getAuthor());
        book.setIsbn(form.getIsbn());

        itemService.saveItem(book);
        return "redirect:items";
    }
```
```java
// ItemService
    @Transactional
    public void saveItem(Item item){
        itemRepository.save(item);
    }
```
```java
// item repository

    public void save(Item item){
        if(item.getId() == null){
            // save
            em.persist(item);
        }else{
            // update
            em.merge(item);
        }
    }
```

<br>

### !merge 주의점!
변경 감지 기능을 사용하면 원하는 속성만 선택해서 변경할 수 있지만,   
병합을 사용하면 모든 속성이 변경됨   
병합할때, 값이 없으면 null로 업데이트되니깐 조심하해야함   
(**병합**은 모든 필드를 교체함)   