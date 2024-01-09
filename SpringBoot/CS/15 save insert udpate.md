# [update] dirty checking & merge

## dirty checking
1. @Transactional 사용하면, 
   하나의 트랜잭션 끝날때
   변경 사항 감시 및 실행
   commit(해당 영속성 엔티티는 값이 바뀐 체 저장(update))
2. update를 영속성 entity로 할때 사용하는 방법
3. 동작 원리
    - DB에서 해당 id 찾아서 객체 반환
    - 바뀐값 변환
    - 끝(Transaction 끝나면 commit)
4. 영속성 엔티티는 EM(Entity Manager, 영속성 컨텍스트)이 관리해줌

### dirty checking code
```java
@Transactional
void update(Item itemParam){
    Item findItem = em.find(Item.class, itemParam.getId());
    findItem.setPrice(itemParam.getPrice());
}
```


### merge
1. 준영속 엔티티
    - 영속 엔티티는 DB에 저장된 객체
    - 새로운 객체를 만들어, 아이디를, DB에 존재하는 객체의 id로 직접 부여함
    - 그렇기에 EM 관리 범주에서 벗어남
    - 새 객체를 만들어 변경된값을 모두 저장해주고,
      해당 DB에 저장된 객체(동일한 id 객체)와
      변경된 값을 merge 해줘야함
    - bean 영속 객체(??)
    - 아이디를 지정해줬음. 새로운 객체를 만들어서
    - DB에 한번 저장되어 식별자가 존재하는 상황이며. 이렇게 임의로 만들어낸 엔티티도 기존 식별자를 가지고 있으면, 준영속 엔티티로 보는 거임
    - 영속성 컨텍스트가 더는 관리하지 않음(보통 값 변경되면, 트랜잭션 끝나고 감지해서 저장하는데, 얘는 관리 대상이 아닌거지)

### merge code
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